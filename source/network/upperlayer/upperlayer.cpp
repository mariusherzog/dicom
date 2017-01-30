#include "upperlayer.hpp"


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
#include <boost/asio.hpp>

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

Iupperlayer_connection_handlers::~Iupperlayer_connection_handlers()
{
}

using namespace dicom::util::log;



scx::scx(data::dictionary::dictionary& dict,
         std::vector<std::pair<TYPE, std::function<void(scx*, std::unique_ptr<property>)>>> l):
   statem {this},
   logger {"upperlayer"},
   proc {data::dataset::commandset_processor {dict}},
   received_pdu {boost::none},
   handlers {}
{
   for (const auto p : l) {
      handlers[p.first] = p.second;
   }
}

scx::~scx()
{
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
         boost::asio::async_write(sock(), boost::asio::buffer(*pdu),
            [this, p, ptype](const boost::system::error_code& error, std::size_t bytes) {
               if (error) {
                  throw boost::system::system_error(error);
               }

               BOOST_LOG_SEV(logger, trace) << "Sent PDU of size " << bytes;
               BOOST_LOG_SEV(logger, info) << "Sent property of type " << ptype;
               BOOST_LOG_SEV(logger, debug) << "Property info: \n" << *p;
               handle_pdu_conf(p, ptype);
         });
      } else {
         auto pdataprop = dynamic_cast<p_data_tf*>(p);
         assert(pdataprop);

         std::size_t len = be_char_to_32b({pdu->begin()+6, pdu->begin()+10});
         auto commandset = std::make_shared<std::vector<unsigned char>>(pdu->begin(), pdu->begin()+10+len);
         boost::asio::async_write(sock(), boost::asio::buffer(*commandset),
            [this, commandset, len, pdu, p, ptype, pdataprop]
               (const boost::system::error_code& error, std::size_t bytes) {
               if (error) {
                  throw boost::system::system_error(error);
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
                     write_complete_dataset(p, {pdu->begin()+10+len, pdu->end()});
                  } else {
                     handle_pdu_conf(p, TYPE::P_DATA_TF);
                  }
               } else {
                  assert(false);
               }
            }
         );
      }
   }
}

void scx::handle_pdu(std::unique_ptr<property> p, TYPE ptype)
{
   handlers[ptype](this, std::move(p));

   if (get_state() == statemachine::CONN_STATE::STA13) {
      close_connection();
   } else {
      // be ready for new data
      if (!io_s().stopped()) {
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

void scx::get_complete_dataset(std::vector<unsigned char> data)
{
   auto nextbuflen = std::make_shared<std::vector<unsigned char>>(6);
   auto nextbufdata = std::make_shared<std::vector<unsigned char>>();
   auto nextbufcompl = std::make_shared<std::vector<unsigned char>>();
   boost::asio::async_read(sock(), boost::asio::buffer(*nextbuflen), boost::asio::transfer_exactly(6),
      [=] (const boost::system::error_code& error, std::size_t bytes) mutable {
         if (error) {
            throw boost::system::system_error(error);
         }
         std::size_t len = be_char_to_32b({nextbuflen->begin()+2, nextbuflen->begin()+6});
         nextbufdata->resize(len);

         BOOST_LOG_SEV(logger, trace) << "Size of incoming data unit: " << len;

         boost::asio::async_read(sock(), boost::asio::buffer(*nextbufdata),
         [=] (const boost::system::error_code& error, std::size_t bytes) mutable {
            if (error) {
               throw boost::system::system_error(error);
            }

            BOOST_LOG_SEV(logger, trace) << "Read data fragment of size " << bytes;

            nextbufcompl->reserve(len+6);
            nextbufcompl->insert(nextbufcompl->end(), nextbuflen->begin(), nextbuflen->end());
            nextbufcompl->insert(nextbufcompl->end(), nextbufdata->begin(), nextbufdata->end());
            data.insert(data.end(), nextbufcompl->begin(), nextbufcompl->end());

            bool lastsegment = ((*nextbufcompl)[11] & 0x02);
            if (lastsegment) {
               BOOST_LOG_SEV(logger, trace) << "Last data fragment";
               auto pdu = make_property(data);
               handle_pdu(std::move(pdu), TYPE::P_DATA_TF);
            } else {
               BOOST_LOG_SEV(logger, trace) << "More data fragments expected";
               get_complete_dataset(data);
            }
         });
   });
}

void scx::write_complete_dataset(property* p, std::vector<unsigned char> data)
{
   std::size_t len = be_char_to_32b({data.begin()+2, data.begin()+6}) + 6;
            // 6 bytes header + length

   auto pdu = std::make_shared<std::vector<unsigned char>>(data.begin(), data.begin()+len);

   boost::asio::async_write(sock(), boost::asio::buffer(*pdu),
      [this, p, data, len, pdu](const boost::system::error_code& error, std::size_t bytes) {
         if (error) {
            throw boost::system::system_error(error);
         }

         BOOST_LOG_SEV(logger, trace) << "Sent data fragment of size " << bytes;

         bool lastsegment = ((*pdu)[11] & 0x02);
         if (lastsegment) {
            BOOST_LOG_SEV(logger, trace) << "Last data fragment";
            handle_pdu_conf(p, TYPE::P_DATA_TF);
         } else {
            BOOST_LOG_SEV(logger, trace) << "More data fragments to be sent";
            write_complete_dataset(p, {data.begin()+len, data.end()});
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

   boost::asio::async_read(sock(), boost::asio::buffer(*size), boost::asio::transfer_exactly(6),
      [=](const boost::system::error_code& error, std::size_t bytes)  {
         if (error) {
            throw boost::system::system_error(error);
         }
         assert(bytes == 6);

         std::size_t len = be_char_to_32b({size->begin()+2, size->begin()+6});
         rem_data->resize(len);

         BOOST_LOG_SEV(logger, trace) << "Size of incoming data unit: " << len;

         boost::asio::async_read(sock(), boost::asio::buffer(*rem_data), boost::asio::transfer_exactly(len),
            [=](const boost::system::error_code& error, std::size_t bytes) {
               if (error) {
                  throw boost::system::system_error(error);
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
                           get_complete_dataset(*compl_data);
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

            }
         );
      }
   );
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
   artim_timer().cancel();
}

void scx::start_artim()
{
   using namespace std::placeholders;
   artim_timer().async_wait(std::bind(&scx::artim_expired, this, _1));
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
   //io_s().reset();
   //io_s().stop();
}

void scx::run()
{
   io_s().run();
}

void scx::artim_expired(const boost::system::error_code& error)
{
   if (error != boost::asio::error::operation_aborted) {
      BOOST_LOG_SEV(this->logger, info) << "ARTIM timer expired";
      statem.transition(statemachine::EVENT::ARTIM_EXPIRED);
   }
}


void scx::inject(TYPE t, std::function<void (scx*, std::unique_ptr<property>)> f)
{
   handlers[t] = f;
}

void scx::inject_conf(TYPE t, std::function<void(scx*, property*)> f)
{
   handlers_conf[t] = f;
}

statemachine::CONN_STATE scx::get_state()
{
   return statem.get_state();
}


scp_connection::scp_connection(boost::asio::io_service& io_service,
         boost::asio::ip::tcp::socket& socket,
         data::dictionary::dictionary& dict,
         short port,
         std::vector<std::pair<TYPE, std::function<void(scx*, std::unique_ptr<property>)>>> l = {{}}):
   scx {dict, l},
   io_service {io_service},
   socket {socket},
   artim {io_service, std::chrono::steady_clock::now() + std::chrono::seconds(10) }
{
   artim.cancel();
   statem.transition(statemachine::EVENT::TRANS_CONN_INDIC);
   do_read();
}

scp::scp(data::dictionary::dictionary& dict,
         short port):
   io_service {},
   port {port},
   dict {dict},
   acptr {io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)}

{
   using namespace std::placeholders;
   //static boost::asio::ip::tcp::socket socket{io_service};
   auto socket = std::make_shared<boost::asio::ip::tcp::socket>(acptr.get_io_service());
   sockets.push_back(socket);
   acptr.async_accept(*socket, std::bind(&scp::accept_new, this, socket.get(), _1));
}

scp::~scp()
{
}

void scp::accept_new(boost::asio::ip::tcp::socket* sock, boost::system::error_code ec)
{
   using namespace std::placeholders;
   if (!ec) {
      connections.push_back(std::unique_ptr<scp_connection> {new scp_connection {io_service, *sock, dict, port}});
      handler_new_connection(connections.back().get());
   } else {
      throw boost::system::system_error(ec);
   }
   auto newsock = std::make_shared<boost::asio::ip::tcp::socket>(acptr.get_io_service());
   sockets.push_back(newsock);
   acptr.async_accept(*newsock, std::bind(&scp::accept_new, this, newsock.get(), _1));
}

void scp::run()
{
   io_service.run();
}
/*
void scp::inject(TYPE t, std::function<void (scx*, std::unique_ptr<property>)> f)
{
//   for (auto it = handlers.begin(); it != handlers.end(); ++it) {
//      if (it->first == t) {
//         it->second = f;
//      }
//   }
//   if (std::find(handlers.begin(), handlers.end(),
//                 [t](std::pair<TYPE, std::function<void (scx*, std::unique_ptr<property>)>> p) { return p.first == t; }) != handlers.end())
//   {
//      for (auto it = handlers.begin(); it != handlers.end(); ++it) {
//         if (it->first == t) {
//            it->second = f;
//         }
//      }
//   } else {
      handlers.push_back(std::make_pair(t, f));
//   }
}*/

void scp::new_connection(std::function<void(Iupperlayer_comm_ops*)> handler)
{
   handler_new_connection = handler;
}

void scp::end_connection(std::function<void(Iupperlayer_comm_ops*)> handler)
{
   handler_end_connection = handler;
}


scu::scu(data::dictionary::dictionary& dict,
         std::string host, std::string port,
         a_associate_rq& rq,
         std::vector<std::pair<TYPE, std::function<void(scx*, std::unique_ptr<property>)>>> l):
   scx {dict, l},
   io_service {},
   resolver {io_service},
   query {host, port},
   endpoint_iterator {resolver.resolve(query)},
   socket {io_service},
   artim {io_service, std::chrono::steady_clock::now() + std::chrono::seconds(10) }
{
   statem.transition(statemachine::EVENT::A_ASSOCIATE_RQ);

   boost::asio::ip::tcp::resolver::iterator end;
   boost::system::error_code error = boost::asio::error::host_not_found;
   while(error && endpoint_iterator != end)
   {
     socket.close();
     socket.connect(*endpoint_iterator++, error);
   }

   if (error) {
      throw boost::system::system_error(error);
   }

   statem.transition(statemachine::EVENT::TRANS_CONN_CONF);

   auto pdu = std::make_shared<std::vector<unsigned char>>(rq.make_pdu());
   boost::asio::async_write(socket, boost::asio::buffer(*pdu),
      [this, pdu, &rq](const boost::system::error_code& error, std::size_t /*bytes*/) mutable {
         if (!error) {
            auto type = TYPE::A_ASSOCIATE_RQ;
            BOOST_LOG_SEV(logger, info) << "Sent property of type " << type;
            BOOST_LOG_SEV(logger, debug) << "Property info: \n" << rq;
            if (handlers_conf.find(type) != handlers_conf.end()) {
               handlers_conf[type](this, &rq);
            }
            do_read();
         } else {
            throw boost::system::system_error(error);
         }
   });
}

boost::asio::ip::tcp::socket& scp_connection::sock()
{
   return socket;
}

boost::asio::io_service&scp_connection::io_s()
{
   return io_service;
}

boost::asio::steady_timer&scp_connection::artim_timer()
{
   return artim;
}

boost::asio::ip::tcp::socket& scu::sock()
{
   return socket;
}

boost::asio::io_service& scu::io_s()
{
   return io_service;
}

boost::asio::steady_timer&scu::artim_timer()
{
   return artim;
}

}

}

}
