#include "upperlayer_connection.hpp"


#include <utility>
#include <vector>
#include <ostream>
#include <cassert>
#include <initializer_list>
#include <chrono>
#include <deque>
#include <functional>
#include <exception>

#include <boost/optional.hpp>

#include "upperlayer_properties.hpp"


namespace dicom
{

namespace network
{

namespace upperlayer
{

namespace
{
using uchar = unsigned char;

std::size_t be_char_to_16b(std::vector<uchar> bs)
{
   assert(bs.size() == 2);
   std::size_t sz = 0;
   sz |= (static_cast<std::size_t>(bs[0]) << 8);
   sz |= (static_cast<std::size_t>(bs[1]));
   return sz;
}
std::size_t be_char_to_32b(std::vector<uchar> bs)
{
   assert(bs.size() == 4);
   std::size_t sz = 0;
   sz |= (static_cast<std::size_t>(bs[0]) << 24);
   sz |= (static_cast<std::size_t>(bs[1]) << 16);
   sz |= (static_cast<std::size_t>(bs[2]) << 8);
   sz |= (static_cast<std::size_t>(bs[3]));
   return sz;
}

}

Istate_trans_ops::~Istate_trans_ops()
{
}

Iupperlayer_comm_ops::~Iupperlayer_comm_ops()
{
}

using namespace dicom::util::log;



scx::scx(data::dictionary::dictionary& dict,
         std::function<void(Iupperlayer_comm_ops*, std::exception_ptr)> on_error,
         std::vector<std::pair<TYPE, std::function<void(scx*, std::unique_ptr<property>)>>> l):
   statem {this},
   error_handler {on_error},
   logger {"upperlayer"},
   proc {data::dataset::commandset_processor {dict}},
   received_pdu {boost::none},
   handlers {},
   shutdown_requested {false}
{
   for (const auto p : l) {
      handlers[p.first] = p.second;
   }
}

scx::~scx()
{
   // closing of the connection may only be done when there are no
   // outstanding operations
}


void scx::send(property* p)
{
   auto pdu = std::make_shared<std::vector<unsigned char>>(p->make_pdu());
   auto ptype = get_type(*pdu);

   statemachine::EVENT e;
   switch (ptype) {
      case TYPE::A_ABORT:
         e = statemachine::EVENT::LOCL_A_ABORT_PDU;
         break;
      case TYPE::A_ASSOCIATE_AC:
         e = statemachine::EVENT::LOCL_A_ASSOCIATE_AC_PDU;
         break;
      case TYPE::A_ASSOCIATE_RJ:
         e = statemachine::EVENT::LOCL_A_ASSOCIATE_RJ_PDU;
         break;
      case TYPE::A_ASSOCIATE_RQ:
         assert(false);
         break;
      case TYPE::A_RELEASE_RQ:
         e = statemachine::EVENT::LOCL_A_RELEASE_RQ_PDU;
         break;
      case TYPE::A_RELEASE_RP:
         e = statemachine::EVENT::LOCL_A_RELEASE_RP_PDU;
         break;
      case TYPE::P_DATA_TF:
         e = statemachine::EVENT::LOCL_P_DATA_TF_PDU;
         break;
      default:
         e = statemachine::EVENT::UNRECOG_PDU;
   }

   if (statem.transition(e) != statemachine::CONN_STATE::INV) {
      // call async_write after each sent property until the queue is
      // empty
      if (ptype != TYPE::P_DATA_TF) {
         connection()->write_data(pdu,
            [this, p, ptype](const boost::system::error_code& err, std::size_t bytes) {
            try
            {
               if (err) {
                  throw boost::system::system_error(err);
               }

               BOOST_LOG_SEV(logger, trace) << "Sent PDU of size " << bytes;
               BOOST_LOG_SEV(logger, info) << "Sent property of type " << ptype;
               BOOST_LOG_SEV(logger, debug) << "Property info: \n" << *p;
               handle_pdu_conf(p, ptype);
            } catch (std::exception& excep) {
               BOOST_LOG_SEV(logger, error) << "Error occured writing to connection\n"
                                            << excep.what();
               error_handler(this, std::current_exception());
            }
         });
      } else {
         auto pdataprop = dynamic_cast<p_data_tf*>(p);
         assert(pdataprop);

         std::size_t len = be_char_to_32b({pdu->begin()+6, pdu->begin()+10});
         auto commandset = std::make_shared<std::vector<unsigned char>>(pdu->begin(), pdu->begin()+10+len);
         connection()->write_data(commandset,
            [this, commandset, len, pdu, p, ptype, pdataprop]
               (const boost::system::error_code& err, std::size_t bytes) {
            try
            {
               if (err) {
                  throw boost::system::system_error(err);
               }

               BOOST_LOG_SEV(logger, trace) << "Sent data fragment of size " << bytes;
               BOOST_LOG_SEV(logger, info) << "Sent property of type " << ptype;
               BOOST_LOG_SEV(logger, debug) << "Property info: \n" << *p;

               using namespace data::attribute;
               if (!pdataprop->command_set.empty()) {
                  // check if a dataset is present in the message
                  auto commandset = proc.deserialize(pdataprop->command_set);
                  unsigned short datasetpresent;
                  get_value_field<VR::US>(commandset.at({0x0000, 0x0800}), datasetpresent);
                  if (datasetpresent != 0x0101) {
                     auto dataset = std::make_shared<std::vector<unsigned char>>(pdu->begin()+10+len, pdu->end());
                     write_complete_dataset(p, dataset);
                  } else {
                     handle_pdu_conf(p, TYPE::P_DATA_TF);
                  }
               } else {
                  assert(false);
               }
            } catch (std::exception& excep) {
               BOOST_LOG_SEV(logger, error) << "Error occured writing command set"
                                            << "of p_data_tf to connection"
                                            << excep.what();
               error_handler(this, std::current_exception());
            }
         });
      }
   }
}

void scx::handle_pdu(std::unique_ptr<property> p, TYPE ptype)
{
   if (handlers[ptype])
   {
      handlers[ptype](this, std::move(p));
   }

   if (get_state() == statemachine::CONN_STATE::STA13) {
      close_connection();
   } else {
      // be ready for new data
      if (!connection()->is_stopped() && !shutdown_requested) {
         do_read();
      }
   }

}

void scx::handle_pdu_conf(property* p, TYPE ptype)
{
   if (handlers_conf.find(ptype) != handlers_conf.end()) {
      handlers_conf[ptype](this, p);
   }
   send_queue.pop_front();
   if (!send_queue.empty()) {
      send(send_queue.front().get());
   }
}

void scx::get_complete_dataset(std::shared_ptr<std::vector<unsigned char>> data)
{
   auto nextbuflen = std::make_shared<std::vector<unsigned char>>(6);
   auto nextbufdata = std::make_shared<std::vector<unsigned char>>();
   auto nextbufcompl = std::make_shared<std::vector<unsigned char>>();


   connection()->read_data(nextbuflen, 6, [=] (const boost::system::error_code& err, std::size_t bytes) mutable {
      try
      {
         if (err) {
            throw boost::system::system_error(err);
         }
         std::size_t len = be_char_to_32b({nextbuflen->begin()+2, nextbuflen->begin()+6});
         nextbufdata->resize(len);

         BOOST_LOG_SEV(logger, trace) << "Size of incoming data unit: " << len;

         connection()->read_data(nextbufdata, [=] (const boost::system::error_code& err, std::size_t bytes) mutable {
            try
            {
               if (err) {
                  throw boost::system::system_error(err);
               }

               BOOST_LOG_SEV(logger, trace) << "Read data fragment of size " << bytes;

               nextbufcompl->reserve(len+6);
               nextbufcompl->insert(nextbufcompl->end(), std::make_move_iterator(nextbuflen->begin()), std::make_move_iterator(nextbuflen->end()));
               nextbufcompl->insert(nextbufcompl->end(), std::make_move_iterator(nextbufdata->begin()), std::make_move_iterator(nextbufdata->end()));
               data->insert(data->end(), std::make_move_iterator(nextbufcompl->begin()), std::make_move_iterator(nextbufcompl->end()));

               bool lastsegment = ((*nextbufcompl)[11] & 0x02);
               if (lastsegment) {
                  BOOST_LOG_SEV(logger, trace) << "Last data fragment";
                  auto pdu = make_property(*data);
                  handle_pdu(std::move(pdu), TYPE::P_DATA_TF);
               } else {
                  BOOST_LOG_SEV(logger, trace) << "More data fragments expected";
                  get_complete_dataset(data);
               }
            } catch (std::exception& excep) {
               BOOST_LOG_SEV(logger, error) << "Error occured reading from connection\n"
                                            << "For the rest of the data\n"
                                            << excep.what();
               error_handler(this, std::current_exception());
            }
         });
      } catch (std::exception& excep) {
         BOOST_LOG_SEV(logger, error) << "Error occured reading from connection\n"
                                      << "During read of first 6 bytes (length)\n"
                                      << excep.what();
         error_handler(this, std::current_exception());
      }
   });
}

void scx::write_complete_dataset(property* p, std::shared_ptr<std::vector<unsigned char>> data, std::size_t begin)
{
   std::size_t len = be_char_to_32b({data->begin()+begin+2, data->begin()+begin+6}) + 6;
            // 6 bytes header + length

   void* data_offset = (static_cast<void*>(data->data()+begin));

   connection()->write_data(data_offset, len,
      [this, p, data, len, begin, data_offset](const boost::system::error_code& err, std::size_t bytes) {
      try
      {
         if (err) {
            throw boost::system::system_error(err);
         }

         BOOST_LOG_SEV(logger, trace) << "Sent data fragment of size " << bytes;

         bool lastsegment = ((static_cast<unsigned char*>(data_offset))[11] & 0x02);
         if (lastsegment) {
            BOOST_LOG_SEV(logger, trace) << "Last data fragment";
            handle_pdu_conf(p, TYPE::P_DATA_TF);
         } else {
            BOOST_LOG_SEV(logger, trace) << "More data fragments to be sent";
            std::size_t newbegin = begin + len;
            write_complete_dataset(p, data, newbegin);
         }
      } catch (std::exception& excep) {
         BOOST_LOG_SEV(logger, error) << "Error writing fragment of p_data_tf\n"
                                      << excep.what();
         error_handler(this, std::current_exception());
      }
   });

}

void scx::do_read()
{
   // because the async operations terminate immediately the containers would go out of scope
   // and async_write would write into "unallocated" memory. To prevent this, reference-counting
   // shared_ptrs are used, which are captured, copied and therefore held alive by the lambda
   // passed to the read handler.
   // There may only be one async_read at a time. This is ensured by calling async_reads _only_
   // in the read handlers, i.e. when the previous read has completed.
   auto size = std::make_shared<std::vector<unsigned char>>(6);
   auto rem_data = std::make_shared<std::vector<unsigned char>>();
   auto compl_data = std::make_shared<std::vector<unsigned char>>();


   connection()->read_data(size, 6, [=](const boost::system::error_code& err, std::size_t bytes)  {
      try
      {
         if (err) {
            throw boost::system::system_error(err);
         }
         assert(bytes == 6);

         std::size_t len = be_char_to_32b({size->begin()+2, size->begin()+6});
         rem_data->resize(len);

         BOOST_LOG_SEV(logger, trace) << "Size of incoming data unit: " << len;

         connection()->read_data(rem_data, len,
            [=](const boost::system::error_code& err, std::size_t bytes) {
            try
            {
               if (err) {
                  throw boost::system::system_error(err);
               }

               compl_data->reserve(size->size() + rem_data->size());
               compl_data->insert(compl_data->end(), size->begin(), size->end());
               compl_data->insert(compl_data->end(), rem_data->begin(), rem_data->end());
               received_pdu = compl_data.get();

               auto ptype = get_type(*compl_data);
               BOOST_LOG_SEV(logger, info) << "Received property of type " << ptype;
               statemachine::EVENT e;
               switch (ptype) {
                  case TYPE::A_ABORT:
                     e = statemachine::EVENT::RECV_A_ABORT_PDU;
                     break;
                  case TYPE::A_ASSOCIATE_AC:
                     e = statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU;
                     break;
                  case TYPE::A_ASSOCIATE_RJ:
                     e = statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU;
                     break;
                  case TYPE::A_ASSOCIATE_RQ:
                     e = statemachine::EVENT::RECV_A_ASSOCIATE_RQ_PDU;
                     break;
                  case TYPE::A_RELEASE_RQ:
                     e = statemachine::EVENT::RECV_A_RELEASE_RQ_PDU;
                     break;
                  case TYPE::A_RELEASE_RP:
                     e = statemachine::EVENT::RECV_A_RELEASE_RP_PDU;
                     break;
                  case TYPE::P_DATA_TF:
                     e = statemachine::EVENT::RECV_P_DATA_TF_PDU;
                     break;
                  default:
                     e = statemachine::EVENT::UNRECOG_PDU;
               }

               statem.transition(e); // side effects of the statemachine's transition function

               if (received_pdu != boost::none) {
                  auto property = make_property(*compl_data);
                  BOOST_LOG_SEV(logger, debug) << "Property info: \n" << *property;

                  // PDUs of type p_data_tf may come in fragments and with a
                  // data set, which needs to be received.
                  if (ptype == TYPE::P_DATA_TF) {
                     BOOST_LOG_SEV(logger, trace) << "Read data fragment of size " << bytes;
                     using namespace data::attribute;
                     auto pdataprop = dynamic_cast<p_data_tf*>(property.get());
                     assert(pdataprop);
                     if (!pdataprop->command_set.empty()) {
                        // check if a dataset is present in the message
                        auto commandset = proc.deserialize(pdataprop->command_set);
                        unsigned short datasetpresent;
                        get_value_field<VR::US>(commandset.at({0x0000, 0x0800}), datasetpresent);
                        if (datasetpresent != 0x0101) {
                           BOOST_LOG_SEV(logger, trace) << "Dataset present in the PDU ("
                                                        << "(0000,0800) = " << datasetpresent << ")";
                           get_complete_dataset(compl_data);
                        } else {
                           handle_pdu(std::move(property), TYPE::P_DATA_TF);
                        }
                     } else {
                        BOOST_LOG_SEV(logger, warning) << "No commandset present in the received data PDU. " <<
                                                        "Ignoring Message";
                     }
                  } else {
                     BOOST_LOG_SEV(logger, trace) << "Read PDU of size " << bytes;
                     handle_pdu(std::move(property), ptype);
                  }
               }
            } catch (std::exception& excep) {
               BOOST_LOG_SEV(logger, error) << "Error occured reading from connection\n"
                                            << "For the rest of the data\n"
                                            << excep.what();
               error_handler(this, std::current_exception());
            }
         });
      } catch (std::exception& excep) {
         BOOST_LOG_SEV(logger, error) << "Error occured reading from connection\n"
                                      << "During read of first 6 bytes (length)\n"
                                      << excep.what();
         error_handler(this, std::current_exception());
      }
   });
}


void scx::queue_for_write(std::unique_ptr<property> p)
{
   // when send_queue.size() is greater than 1, there are still properties being
   // written by scx::send(). To prevent interleaving, we do not call send here
   // and just leave the property in the queue
   send_queue.emplace_back(std::move(p));
   if (send_queue.size() > 1) {
      return;
   }
   send(send_queue.front().get());
}

void scx::queue_for_write_w_prio(std::unique_ptr<property> p)
{
   // see scx::queue_for_write for explanation
   send_queue.emplace_front(std::move(p));
   if (send_queue.size() > 1) {
      return;
   }
   send(send_queue.front().get());
}

void scx::reset_artim()
{
   stop_artim();
   start_artim();
}

void scx::stop_artim()
{
   artim_timer()->cancel();
}

void scx::start_artim()
{
   using namespace std::placeholders;
   artim_timer()->wait_async();
      //member function artim_expired has implicit scx* as first parameter
}

void scx::ignore_next()
{
   received_pdu = boost::none;
   assert(!received_pdu.is_initialized());
}


void scx::close_connection()
{
   statem.transition(statemachine::EVENT::TRANS_CONN_CLOSED);

   shutdown_requested = true;

   // closing of the connection may only be done when there are no
   // outstanding operations

   connection()->close();

   // TODO: update shutdown_requested

//   io_s().post([this]() {
//      sock().shutdown(boost::asio::ip::tcp::socket::shutdown_both);
//      sock().close();
//      handler_end_connection(this);
//      shutdown_requested = false;
//   });
}

void scx::run()
{
//   io_s().run();
}

void scx::artim_expired()
{
   BOOST_LOG_SEV(this->logger, info) << "ARTIM timer expired";
   statem.transition(statemachine::EVENT::ARTIM_EXPIRED);
}


void scx::inject(TYPE t, std::function<void (Iupperlayer_comm_ops*, std::unique_ptr<property>)> f)
{
   handlers[t] = f;
}

void scx::inject_conf(TYPE t, std::function<void(Iupperlayer_comm_ops*, property*)> f)
{
   handlers_conf[t] = f;
}

statemachine::CONN_STATE scx::get_state()
{
   return statem.get_state();
}


scp_connection::scp_connection(Iinfrastructure_upperlayer_connection* tcp_conn,
                               data::dictionary::dictionary& dict,
                               std::function<void(Iupperlayer_comm_ops*)> handler_new_conn,
                               std::function<void(Iupperlayer_comm_ops*)> handler_end_conn,
                               std::function<void(Iupperlayer_comm_ops*, std::exception_ptr)> on_error,
                               std::vector<std::pair<TYPE, std::function<void(scx*,std::unique_ptr<property>)>>> l):
   scx {dict, on_error, l},
   conn {tcp_conn},
   artim {conn->timeout_timer(std::chrono::seconds(10), [this](){ artim_expired(); })}
{
   handler_new_connection = handler_new_conn;
   handler_end_connection = handler_end_conn;
   artim->cancel();
   statem.transition(statemachine::EVENT::TRANS_CONN_INDIC);
   handler_new_connection(this);
   do_read();
}

Iinfrastructure_timeout_connection* scp_connection::artim_timer()
{
   return artim.get();
}

scu_connection::scu_connection(Iinfrastructure_upperlayer_connection* conn,
         data::dictionary::dictionary& dict,
         a_associate_rq& rq,
         std::function<void(Iupperlayer_comm_ops*)> handler_new_conn,
         std::function<void(Iupperlayer_comm_ops*)> handler_end_conn,
         std::function<void(Iupperlayer_comm_ops*, std::exception_ptr)> on_error,
         std::vector<std::pair<TYPE, std::function<void(scx*, std::unique_ptr<property>)>>> l):
   scx {dict, on_error, l},
   conn {conn},
   artim {conn->timeout_timer(std::chrono::seconds(10), [this](){ artim_expired(); })}
{
   handler_new_connection = handler_new_conn;
   handler_end_connection = handler_end_conn;
   statem.transition(statemachine::EVENT::A_ASSOCIATE_RQ);

   statem.transition(statemachine::EVENT::TRANS_CONN_CONF);

   handler_new_connection(this);

   auto pdu = std::make_shared<std::vector<unsigned char>>(rq.make_pdu());
   //this->queue_for_write(std::unique_ptr<property>(new a_associate_rq {rq}));/*
   conn->write_data(pdu, [this, pdu, &rq](const boost::system::error_code& err, std::size_t) mutable {
      try
      {
         if (!err) {
            auto type = TYPE::A_ASSOCIATE_RQ;
            BOOST_LOG_SEV(logger, info) << "Sent property of type " << type;
            BOOST_LOG_SEV(logger, debug) << "Property info: \n" << rq;
            if (handlers_conf.find(type) != handlers_conf.end()) {
               handlers_conf[type](this, &rq);
            }
            do_read();
         } else {
            throw boost::system::system_error(err);
         }
      } catch (std::exception& excep) {
         BOOST_LOG_SEV(logger, error) << "Error occured writing initial a_associate_rq\n"
                                      << excep.what();
         error_handler(this, std::current_exception());
      }
   });
}


Iinfrastructure_timeout_connection* scu_connection::artim_timer()
{
   return artim.get();
}

}

}

}
