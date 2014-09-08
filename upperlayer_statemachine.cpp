#include "upperlayer_statemachine.hpp"

#include <map>
#include <functional>

#include "upperlayer_properties.hpp"


namespace upperlayer
{


statemachine::statemachine():
   state {CONN_STATE::STA2}
{
}

statemachine::CONN_STATE statemachine::get_state()
{
   return state;
}

statemachine::CONN_STATE statemachine::transition(EVENT e)
{
   CONN_STATE next_state;
//   if (received) {
//      next_state = transition_table_received_pdus[{state, t}];
//   } else {
//      next_state = transition_table_user_primitives[{state, t}];
//   }

   if (next_state != CONN_STATE::INV) {
      return state = next_state;
   } else {
      return CONN_STATE::INV;
   }
}


void statemachine::aa1()
{
   a_abort ab;
   auto pdu = ab.make_pdu();

   // reset ARTIM
   boost::asio::write(sc->sock, boost::asio::buffer( pdu ));
   sc->ev = scp::EVENT::NONE;
   sc->state = scp::CONN_STATE::STA13;
}

void statemachine::aa2()
{
   //close artim
   sc->ev = scp::EVENT::NONE;
   sc->state = scp::CONN_STATE::STA1;
}

void statemachine::aa3()
{
   // abort indication primitive
   std::lock_guard<std::mutex> lck(sc->sendmtx);
   sc->ev = scp::EVENT::NONE;
   sc->state = scp::CONN_STATE::STA1;
}

void statemachine::aa4()
{
   //stop artim timer
   std::lock_guard<std::mutex> lck(sc->sendmtx);
   sc->ev = scp::EVENT::NONE;
   sc->state = scp::CONN_STATE::STA1;
}

void statemachine::aa5()
{
   std::lock_guard<std::mutex> lck(sc->sendmtx);
   sc->ev = scp::EVENT::NONE;
   sc->state = scp::CONN_STATE::STA1;
}

void statemachine::aa6()
{
   std::lock_guard<std::mutex> lck(sc->sendmtx);
   sc->sendqueue.pop(); // ignore pdu
   sc->ev = scp::EVENT::NONE;
   sc->state = scp::CONN_STATE::STA13;
}

void statemachine::aa7()
{
   a_abort ab;
   auto pdu = ab.make_pdu();

   {
      std::lock_guard<std::mutex> lck(sc->sendmtx);
      boost::asio::write(sc->sock, boost::asio::buffer( pdu ));
      sc->ev = scp::EVENT::NONE;
      sc->state = scp::CONN_STATE::STA13;
   }
}

void statemachine::aa8()
{
   a_abort ab;
   auto pdu = ab.make_pdu();

   // reset ARTIM
   boost::asio::write(sc->sock, boost::asio::buffer( pdu ));
   sc->ev = scp::EVENT::NONE;
   sc->state = scp::CONN_STATE::STA13;

   abort_handler();
}

void statemachine::ae1()
{
   sc->ev = scp::EVENT::NONE;
   sc->state = scp::CONN_STATE::STA4;
}

void statemachine::ae2()
{
   std::lock_guard<std::mutex> lck(sc->sendmtx);
   auto pdu = sc->sendqueue.front();
   sc->sendqueue.pop();
   assert(get_type(pdu) == TYPE::A_ASSOCIATE_RQ);
   boost::asio::write(sc->sock, boost::asio::buffer( pdu ));
   sc->ev = scp::EVENT::NONE;
   sc->state = scp::CONN_STATE::STA5;
}

void statemachine::ae3()
{
   {
      std::lock_guard<std::mutex> lck(sc->sendmtx);
      sc->ev = scp::EVENT::NONE;
      sc->state = scp::CONN_STATE::STA6;
   }
   associate_accept_handler();
}

void statemachine::ae4()
{
   {
      std::lock_guard<std::mutex> lck(sc->sendmtx);
      sc->ev = scp::EVENT::NONE;
      sc->state = scp::CONN_STATE::STA1;
   }
   associate_reject_handler();
}

void statemachine::ae5()
{
   sc->ev = scp::EVENT::NONE;
   // start ARTIM timer
   sc->state = scp::CONN_STATE::STA2;
}

void statemachine::ae6()
{
   sc->ev = scp::EVENT::NONE;
   sc->state = scp::CONN_STATE::STA3;
   associate_request_handler();
}

void statemachine::ae7()
{
   std::lock_guard<std::mutex> lck(sc->sendmtx);
   auto pdu = sc->sendqueue.front();
   sc->sendqueue.pop();
   assert(get_type(pdu) == TYPE::A_ASSOCIATE_AC);
   boost::asio::write(sc->sock, boost::asio::buffer( pdu ));
   sc->ev = scp::EVENT::NONE;
   sc->state = scp::CONN_STATE::STA6;
}

void statemachine::ae8()
{
   // start ARTIM timer
   std::lock_guard<std::mutex> lck(sc->sendmtx);
   auto pdu = sc->sendqueue.front();
   sc->sendqueue.pop();
   assert(get_type(pdu) == TYPE::A_ASSOCIATE_RJ);
   boost::asio::write(sc->sock, boost::asio::buffer( pdu ));
   sc->ev = scp::EVENT::NONE;
   sc->state = scp::CONN_STATE::STA13;
}

void statemachine::ar1()
{
   std::lock_guard<std::mutex> lck(sc->sendmtx);
   auto pdu = sc->sendqueue.front();
   sc->sendqueue.pop();
   boost::asio::write(sc->sock, boost::asio::buffer( pdu ));
   sc->ev = scp::EVENT::NONE;
   sc->state = scp::CONN_STATE::STA7;
}

void statemachine::ar2()
{
   {
      std::lock_guard<std::mutex> lck(sc->sendmtx);
      sc->ev = scp::EVENT::NONE;
      sc->state = scp::CONN_STATE::STA8;
   }
   release_handler();
}

void statemachine::ar3()
{
   {
      std::lock_guard<std::mutex> lck(sc->sendmtx);
      sc->ev = scp::EVENT::NONE;
      sc->state = scp::CONN_STATE::STA1;
   }
   // release conf handler
}

void statemachine::ar4()
{
   // start ARTIM timer
   std::lock_guard<std::mutex> lck(sc->sendmtx);
   auto pdu = sc->sendqueue.front();
   sc->sendqueue.pop();
   assert(get_type(pdu) == TYPE::A_RELEASE_RP);
   boost::asio::write(sc->sock, boost::asio::buffer( pdu ));
   sc->ev = scp::EVENT::NONE;
   sc->state = scp::CONN_STATE::STA13;
}

void statemachine::ar5()
{
   //stop artim timer
   sc->ev = scp::EVENT::NONE;
   sc->state = scp::CONN_STATE::STA1;
}

void statemachine::ar6()
{
   sc->ev = scp::EVENT::NONE;
   data_handler();
}

void statemachine::ar7()
{
   std::lock_guard<std::mutex> lck(sc->sendmtx);
   auto pdu = sc->sendqueue.front();
   sc->sendqueue.pop();
   boost::asio::write(sc->sock, boost::asio::buffer( pdu ));
   sc->ev = scp::EVENT::NONE;
   sc->state = scp::CONN_STATE::STA8;
}

void statemachine::ar8()
{
   //if scu state = sta10
   sc->ev = scp::EVENT::NONE;
   sc->state = scp::CONN_STATE::STA9;
   // a release indication collision
}

void statemachine::ar9()
{
   std::lock_guard<std::mutex> lck(sc->sendmtx);
   auto pdu = sc->sendqueue.front();
   sc->sendqueue.pop();
   assert(get_type(pdu) == TYPE::A_RELEASE_RP);
   boost::asio::write(sc->sock, boost::asio::buffer( pdu ));
   sc->ev = scp::EVENT::NONE;
   sc->state = scp::CONN_STATE::STA11;
}

void statemachine::ar10()
{
   sc->ev = scp::EVENT::NONE;
   sc->state = scp::CONN_STATE::STA12;
   // a release conf primitive
}

void statemachine::dt1()
{
   std::lock_guard<std::mutex> lck(sc->sendmtx);
   auto pdu = sc->sendqueue.front();
   sc->sendqueue.pop();
   boost::asio::write(sc->sock, boost::asio::buffer( pdu ));
   sc->ev = scp::EVENT::NONE;
   // keep state
}

void statemachine::dt2()
{
   sc->ev = scp::EVENT::NONE;
   data_handler();
}


/**
 * @brief contains the target state as a function of pair of the current state and a primitive received from the user
 *
 */
std::map<std::pair<statemachine::EVENT, statemachine::CONN_STATE>, std::function<void(transition_functions*)>> statemachine::transition_table {
   {{statemachine::EVENT::A_ASSOCIATE_RQ, statemachine::CONN_STATE::STA1}, &statemachine::ae1},

   {{statemachine::EVENT::TRANS_CONN_CONF, statemachine::CONN_STATE::STA4}, &statemachine::ae2},

   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA2}, &statemachine::aa1},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA3}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA5}, &statemachine::ae3},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA6}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA7}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA8}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA9}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA10}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA11}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA12}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA13}, &statemachine::aa6},

   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA2}, &statemachine::aa1},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA3}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA5}, &statemachine::ae4},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA6}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA7}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA8}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA9}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA10}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA11}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA12}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA13}, &statemachine::aa6},

   {{statemachine::EVENT::TRANS_CONN_INDIC, statemachine::CONN_STATE::STA1}, &statemachine::ae5},

   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA2}, &statemachine::ae6},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA3}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA5}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA6}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA7}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA8}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA9}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA10}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA11}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA12}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA13}, &statemachine::aa7},

   {{statemachine::EVENT::LOCL_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA3}, &statemachine::ae7},

   {{statemachine::EVENT::LOCL_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA3}, &statemachine::ae8},

   {{statemachine::EVENT::LOCL_P_DATA_TF_PDU, statemachine::CONN_STATE::STA6}, &statemachine::dt1},
   {{statemachine::EVENT::LOCL_P_DATA_TF_PDU, statemachine::CONN_STATE::STA8}, &statemachine::ar7},

   {{statemachine::EVENT::LOCL_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA6}, &statemachine::ar1},

   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA2}, &statemachine::aa1},
   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA3}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA5}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA6}, &statemachine::ar2},
   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA7}, &statemachine::ar6},
   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA8}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA9}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA10}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA11}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA12}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA13}, &statemachine::aa6},

   {{statemachine::EVENT::LOCL_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA6}, &statemachine::ar1},

   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA2}, &statemachine::aa1},
   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA3}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA5}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA6}, &statemachine::ar2},
   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA7}, &statemachine::ar8},
   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA8}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA9}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA10}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA11}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA12}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA13}, &statemachine::aa6},

   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA2}, &statemachine::aa1},
   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA3}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA5}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA6}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA7}, &statemachine::ar3},
   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA8}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA9}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA10}, &statemachine::ar10},
   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA11}, &statemachine::ar3},
   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA12}, &statemachine::aa8},
   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA13}, &statemachine::aa6},

   {{statemachine::EVENT::LOCL_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA8}, &statemachine::ar4},
   {{statemachine::EVENT::LOCL_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA9}, &statemachine::ar9},
   {{statemachine::EVENT::LOCL_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA12}, &statemachine::ar4},

   {{statemachine::EVENT::LOCL_A_ABORT_PDU, statemachine::CONN_STATE::STA3}, &statemachine::aa1},
   {{statemachine::EVENT::LOCL_A_ABORT_PDU, statemachine::CONN_STATE::STA4}, &statemachine::aa2},
   {{statemachine::EVENT::LOCL_A_ABORT_PDU, statemachine::CONN_STATE::STA5}, &statemachine::aa1},
   {{statemachine::EVENT::LOCL_A_ABORT_PDU, statemachine::CONN_STATE::STA6}, &statemachine::aa1},
   {{statemachine::EVENT::LOCL_A_ABORT_PDU, statemachine::CONN_STATE::STA7}, &statemachine::aa1},
   {{statemachine::EVENT::LOCL_A_ABORT_PDU, statemachine::CONN_STATE::STA8}, &statemachine::aa1},
   {{statemachine::EVENT::LOCL_A_ABORT_PDU, statemachine::CONN_STATE::STA9}, &statemachine::aa1},
   {{statemachine::EVENT::LOCL_A_ABORT_PDU, statemachine::CONN_STATE::STA10}, &statemachine::aa1},
   {{statemachine::EVENT::LOCL_A_ABORT_PDU, statemachine::CONN_STATE::STA11}, &statemachine::aa1},
   {{statemachine::EVENT::LOCL_A_ABORT_PDU, statemachine::CONN_STATE::STA12}, &statemachine::aa1},

   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA2}, &statemachine::aa2},
   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA3}, &statemachine::aa3},
   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA5}, &statemachine::aa3},
   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA6}, &statemachine::aa3},
   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA7}, &statemachine::aa3},
   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA8}, &statemachine::aa3},
   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA9}, &statemachine::aa3},
   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA10}, &statemachine::aa3},
   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA11}, &statemachine::aa3},
   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA12}, &statemachine::aa3},
   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA13}, &statemachine::aa2},

   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA2}, &statemachine::aa5},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA3}, &statemachine::aa4},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA4}, &statemachine::aa4},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA5}, &statemachine::aa4},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA6}, &statemachine::aa4},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA7}, &statemachine::aa4},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA8}, &statemachine::aa4},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA9}, &statemachine::aa4},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA10}, &statemachine::aa4},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA11}, &statemachine::aa4},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA12}, &statemachine::aa4},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA13}, &statemachine::ar5},

   {{statemachine::EVENT::ARTIM_EXPIRED, statemachine::CONN_STATE::STA2}, &statemachine::aa2},
   {{statemachine::EVENT::ARTIM_EXPIRED, statemachine::CONN_STATE::STA13}, &statemachine::aa2},

   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA2}, &statemachine::aa1},
   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA3}, &statemachine::aa8},
   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA5}, &statemachine::aa8},
   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA6}, &statemachine::aa8},
   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA7}, &statemachine::aa8},
   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA8}, &statemachine::aa8},
   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA9}, &statemachine::aa8},
   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA10}, &statemachine::aa8},
   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA11}, &statemachine::aa8},
   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA12}, &statemachine::aa8},
   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA13}, &statemachine::aa7},
};


}

