#include "upperlayer.hpp"

#include <map>
#include <utility>
#include <vector>
#include <algorithm>
#include <ostream>
#include <cassert>
#include <functional>

#include <boost/asio.hpp>

#include "upperlayer_properties.hpp"
#include "upperlayer_transitions.hpp"


namespace { using uchar = unsigned char; }

namespace
{


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


scp::scp(short port):
   state(CONN_STATE::STA2),
   io_service(),
   acptr(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
   sock(io_service)
{
   acptr.accept(sock);
}

scp::~scp()
{
   switch (state) {
      case CONN_STATE::STA2: break;
      default: {
         a_abort ab;
         boost::asio::write(sock, boost::asio::buffer(ab.make_pdu()));
         state = CONN_STATE::STA2;
      }
   }
}

void scp::send(property* p)
{
   auto pdu = p->make_pdu();
   auto ptype = get_type(pdu);

   CONN_STATE next_state = transition_table_user_primitives[std::make_pair(state, ptype)];
   if (next_state != CONN_STATE::INV) {
      boost::asio::write(sock, boost::asio::buffer(pdu));
      state = next_state;
   }
}


std::unique_ptr<property> scp::receive()
{
   boost::system::error_code error;

   std::vector<uchar> size(6);
   boost::asio::read(sock, boost::asio::buffer(size), boost::asio::transfer_exactly(6), error);
   std::size_t len = be_char_to_32b({size.begin()+2, size.begin()+6});

   std::vector<uchar> data(len);
   boost::asio::read(sock, boost::asio::buffer(data), boost::asio::transfer_exactly(len), error);

   std::vector<uchar> resp;
   resp.reserve(size.size() + data.size());
   resp.insert(resp.end(), size.begin(), size.end());
   resp.insert(resp.end(), data.begin(), data.end());

   auto ptype = get_type(resp);

   // failed assertion would indicate an error in the remote state machine
   assert(transition_table_received_pdus[std::make_pair(state, ptype)] != CONN_STATE::INV);
   state = transition_table_received_pdus[std::make_pair(state, ptype)];


   switch (ptype) {
      case TYPE::A_ABORT: {
         a_abort* a = new a_abort();
         a->from_pdu(resp);
         return std::unique_ptr<a_abort>(a);
      }
      case TYPE::A_RELEASE_RQ: {
         a_release_rq* a = new a_release_rq();
         a->from_pdu(resp);
         return std::unique_ptr<a_release_rq>(a);
      }
      case TYPE::A_RELEASE_RP: {
         a_release_rp* a = new a_release_rp();
         a->from_pdu(resp);
         return std::unique_ptr<a_release_rp>(a);
      }
      case TYPE::A_ASSOCIATE_RQ: {
         a_associate_rq* a = new a_associate_rq();
         a->from_pdu(resp);
         return std::unique_ptr<a_associate_rq>(a);
      }
      case TYPE::A_ASSOCIATE_AC: {
         a_associate_ac* a = new a_associate_ac();
         a->from_pdu(resp);
         return std::unique_ptr<a_associate_ac>(a);
      }
      case TYPE::A_ASSOCIATE_RJ: {
         a_associate_rj* a = new a_associate_rj();
         a->from_pdu(resp);
         return std::unique_ptr<a_associate_rj>(a);
      }
      case TYPE::P_DATA_TF: {
         p_data_tf* p = new p_data_tf();
         p->from_pdu(resp);
         return std::unique_ptr<p_data_tf>(p);
      }
   }
   return nullptr;
}

