#include "upperlayer.hpp"


#include <utility>
#include <vector>
#include <ostream>
#include <cassert>
#include <initializer_list>
#include <chrono>
#include <deque>
#include <exception>

#include <boost/optional.hpp>
#include <boost/asio.hpp>

#include "upperlayer_properties.hpp"


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





scx::scx(std::initializer_list<std::pair<TYPE, std::function<void(scx*, std::unique_ptr<property>)>>> l):
   statem {this},
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
         e = statemachine::EVENT::LOCL_A_ASSOCIATE_RJ_PDU;
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
      boost::asio::async_write(sock(), boost::asio::buffer(*pdu),
         [=](const boost::system::error_code& error, std::size_t /*bytes*/) {
            if (error) {
               throw boost::system::error_code(error);
            }
            send_queue.pop_front();
            if (!send_queue.empty()) {
               send(send_queue.front().get());
            }
         }
      );
   }
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
            throw boost::system::error_code(error);
         }
         assert(bytes == 6);

         std::size_t len = be_char_to_32b({size->begin()+2, size->begin()+6});
         rem_data->resize(len);
         boost::asio::async_read(sock(), boost::asio::buffer(*rem_data), boost::asio::transfer_exactly(len),
            [=](const boost::system::error_code& error, std::size_t /*bytes*/) {
               if (error) {
                  throw boost::system::error_code(error);
               }

               compl_data->reserve(size->size() + rem_data->size());
               compl_data->insert(compl_data->end(), size->begin(), size->end());
               compl_data->insert(compl_data->end(), rem_data->begin(), rem_data->end());
               received_pdu = compl_data.get();

               auto ptype = get_type(*compl_data);
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

               // call appropriate handler
               if (received_pdu != boost::none) {
                  handlers[ptype](this, make_property(*compl_data));
               }
               received_pdu = boost::none;

               if (get_state() == statemachine::CONN_STATE::STA13) {
                  close_connection();
               }

               // be ready for new data
               if (!io_s().stopped()) {
                  do_read();
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

void upperlayer::scx::queue_for_write_w_prio(std::unique_ptr<upperlayer::property> p)
{
   // see scx::queue_for_write for explanation
   send_queue.emplace_front(std::move(p));
   if (send_queue.size() > 1) {
      return;
   }
   send(send_queue.front().get());
}

void upperlayer::scx::reset_artim()
{
   stop_artim();
   start_artim();
}

void upperlayer::scx::stop_artim()
{
   artim_timer().cancel();
}

void upperlayer::scx::start_artim()
{
   using namespace std::placeholders;
   artim_timer().async_wait(std::bind(&scx::artim_expired, this, _1));
      //member function artim_expired has implicit scx* as first parameter
}

void upperlayer::scx::ignore_next()
{
   received_pdu = boost::none;
   assert(!received_pdu.is_initialized());
}


void upperlayer::scx::close_connection()
{
   io_s().reset();
   io_s().stop();
}


void scx::run()
{
   io_s().run();
}

void scx::artim_expired(const boost::system::error_code& error)
{
   if (error != boost::asio::error::operation_aborted) {
      BOOST_LOG_TRIVIAL(warning) << "ARTIM timer expired";
      statem.transition(statemachine::EVENT::ARTIM_EXPIRED);
   }
}


void scx::inject(TYPE t, std::function<void (scx*, std::unique_ptr<property>)> f)
{
   handlers[t] = f;
}

statemachine::CONN_STATE scx::get_state()
{
   return statem.get_state();
}


scp::scp(short port, std::initializer_list<std::pair<TYPE, std::function<void(scx*, std::unique_ptr<property>)>>> l):
   scx {l},
   io_service(),
   socket(io_service),
   acptr(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
   artim(io_service, std::chrono::steady_clock::now() + std::chrono::seconds(10))
{
   artim.cancel();
   statem.transition(statemachine::EVENT::TRANS_CONN_INDIC);
   acptr.async_accept(socket,
      [=](boost::system::error_code ec) {
         if (!ec) {
            do_read();
         } else {
            throw boost::system::error_code(ec);
         }
      });
}

scu::scu(std::string host, std::string port, a_associate_rq& rq, std::initializer_list<std::pair<TYPE, std::function<void(scx*, std::unique_ptr<property>)>>> l):
   scx{l},
   io_service(),
   resolver(io_service),
   query(host, port),
   endpoint_iterator(resolver.resolve(query)),
   socket(io_service),
   artim(io_service, std::chrono::steady_clock::now() + std::chrono::seconds(10))
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
      throw boost::system::error_code(error);
   }

   statem.transition(statemachine::EVENT::TRANS_CONN_CONF);


   auto pdu = std::make_shared<std::vector<unsigned char>>(rq.make_pdu());
   boost::asio::async_write(socket, boost::asio::buffer(*pdu),
      [this, pdu](const boost::system::error_code& error, std::size_t /*bytes*/) {
         if (!error) {
            do_read();
         } else {
            throw boost::system::error_code(error);
         }
   });
}

boost::asio::ip::tcp::socket& scp::sock()
{
   return socket;
}

boost::asio::io_service&scp::io_s()
{
   return io_service;
}

boost::asio::steady_timer&scp::artim_timer()
{
   return artim;
}

scp::~scp()
{
   statem.transition(statemachine::EVENT::TRANS_CONN_CLOSED);
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

scu::~scu()
{
   statem.transition(statemachine::EVENT::TRANS_CONN_CLOSED);
}

}
