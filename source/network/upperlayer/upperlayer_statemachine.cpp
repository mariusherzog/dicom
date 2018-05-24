#include "upperlayer_statemachine.hpp"

#include <map>
#include <functional>

#include <boost/log/trivial.hpp>

#include "upperlayer_properties.hpp"
#include "upperlayer_connection.hpp"

namespace dicom
{

namespace network
{

namespace upperlayer
{

using namespace dicom::util::log;


statemachine::statemachine(Istate_trans_ops* ul):
   ul {ul},
   state {CONN_STATE::STA1},
   logger {"upperlayer sm"}
{
}

statemachine::CONN_STATE statemachine::get_state()
{
   return state;
}

statemachine::CONN_STATE statemachine::transition(EVENT e)
{
   if (transition_table.find({e, state}) != transition_table.end()) {
      transition_table[{e, state}](this);
      return state;
   } else {
      return CONN_STATE::INV;
   }
}


void statemachine::aa1()
{
   BOOST_LOG_SEV(logger, trace) << "AA-1";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta13";
   ul->queue_for_write_w_prio(std::unique_ptr<property>(new a_abort {}));
   state = CONN_STATE::STA13;
}

void statemachine::aa2()
{
   BOOST_LOG_SEV(logger, trace) << "AA-2";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta1";
   ul->stop_artim();
   state = CONN_STATE::STA1;
   ul->close_connection();
}

void statemachine::aa3()
{
   BOOST_LOG_SEV(logger, trace) << "AA-3";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta1";
   // call a_abort handler
   state = CONN_STATE::STA1;
   ul->close_connection();
}

void statemachine::aa4()
{
   BOOST_LOG_SEV(logger, trace) << "AA-4";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta1";
   ul->stop_artim();
   state = CONN_STATE::STA1;
}

void statemachine::aa5()
{
   BOOST_LOG_SEV(logger, trace) << "AA-5";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta1";
   ul->stop_artim();
   state = CONN_STATE::STA1;
}

void statemachine::aa6()
{
   BOOST_LOG_SEV(logger, trace) << "AA-6";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta13";
   ul->ignore_next();
   state = CONN_STATE::STA13;
}

void statemachine::aa7()
{
   BOOST_LOG_SEV(logger, trace) << "AA-7";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta13";
   ul->queue_for_write_w_prio(std::unique_ptr<property>(new a_abort {}));
   state = CONN_STATE::STA13;
}

void statemachine::aa8()
{
   BOOST_LOG_SEV(logger, trace) << "AA-8";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta13";
   ul->queue_for_write_w_prio(std::unique_ptr<property>(new a_abort {}));
   ul->start_artim();
   // A-P-Abort indic
   state = CONN_STATE::STA13;
}

void statemachine::ae1()
{
   BOOST_LOG_SEV(logger, trace) << "AE-1";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta4";
   state = CONN_STATE::STA4;
}

void statemachine::ae2()
{
   BOOST_LOG_SEV(logger, trace) << "AE-2";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta5";
   state = CONN_STATE::STA5;
}

void statemachine::ae3()
{
   BOOST_LOG_SEV(logger, trace) << "AE-3";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta6";
   state = CONN_STATE::STA6;
}

void statemachine::ae4()
{
   BOOST_LOG_SEV(logger, trace) << "AE-4";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta1";
   state = CONN_STATE::STA1;
   ul->close_connection();
}

void statemachine::ae5()
{
   BOOST_LOG_SEV(logger, trace) << "AE-5";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta2";
   ul->start_artim();
   state = CONN_STATE::STA2;
}

void statemachine::ae6()
{
   BOOST_LOG_SEV(logger, trace) << "AE-6";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta3";
   ul->stop_artim();
   state = CONN_STATE::STA3;
}

void statemachine::ae7()
{
   BOOST_LOG_SEV(logger, trace) << "AE-7";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta6";
   state = CONN_STATE::STA6;
}

void statemachine::ae8()
{
   BOOST_LOG_SEV(logger, trace) << "AE-8";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta13";
   ul->start_artim();
   state = CONN_STATE::STA13;
}

void statemachine::ar1()
{
   BOOST_LOG_SEV(logger, trace) << "AR-1";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta7";
   state = CONN_STATE::STA7;
}

void statemachine::ar2()
{
   BOOST_LOG_SEV(logger, trace) << "AR-2";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta8";
   state = CONN_STATE::STA8;
}

void statemachine::ar3()
{
   BOOST_LOG_SEV(logger, trace) << "AR-3";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta1";
   state = CONN_STATE::STA1;
   // release conf handler
   ul->close_connection();
}

void statemachine::ar4()
{
   BOOST_LOG_SEV(logger, trace) << "AR-4";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta13";
   ul->start_artim();
   state = CONN_STATE::STA13;
}

void statemachine::ar5()
{
   BOOST_LOG_SEV(logger, trace) << "AR-5";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta1";
   ul->stop_artim();
   state = CONN_STATE::STA1;
}

void statemachine::ar6()
{
   BOOST_LOG_SEV(logger, trace) << "AR-6";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta7";
   state = CONN_STATE::STA7;
}

void statemachine::ar7()
{
   BOOST_LOG_SEV(logger, trace) << "AR-7";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta8";
   state = CONN_STATE::STA8;
}

void statemachine::ar8()
{
   BOOST_LOG_SEV(logger, trace) << "AR-8";
   if (dynamic_cast<upperlayer::scu_connection*>(ul)) {
      BOOST_LOG_SEV(logger, trace) << "Next state is Sta9";
      state = CONN_STATE::STA9;
   } else {
      BOOST_LOG_SEV(logger, trace) << "Next state is Sta10";
      state = CONN_STATE::STA10;
   }
   // a release indication collision
}

void statemachine::ar9()
{
   BOOST_LOG_SEV(logger, trace) << "AR-9";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta11";
   state = CONN_STATE::STA11;
}

void statemachine::ar10()
{
   BOOST_LOG_SEV(logger, trace) << "AR-10";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta12";
   state = CONN_STATE::STA12;
}

void statemachine::dt1()
{
   BOOST_LOG_SEV(logger, trace) << "DT-1";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta6";
   state = CONN_STATE::STA6;
}

void statemachine::dt2()
{
   BOOST_LOG_SEV(logger, trace) << "DT-2";
   BOOST_LOG_SEV(logger, trace) << "Next state is Sta6";
   state = CONN_STATE::STA6;
}


/**
 * @brief contains the target state as a function of pair of the current state and a primitive received from the user
 *
 */
std::map<std::pair<statemachine::EVENT, statemachine::CONN_STATE>, std::function<void(statemachine*)>> statemachine::transition_table {
   {{statemachine::EVENT::A_ASSOCIATE_RQ, statemachine::CONN_STATE::STA1}, std::mem_fn(&statemachine::ae1)},

   {{statemachine::EVENT::TRANS_CONN_CONF, statemachine::CONN_STATE::STA4}, std::mem_fn(&statemachine::ae2)},

   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA2}, std::mem_fn(&statemachine::aa1)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA3}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA5}, std::mem_fn(&statemachine::ae3)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA6}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA7}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA8}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA9}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA10}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA11}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA12}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA13}, std::mem_fn(&statemachine::aa6)},

   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA2}, std::mem_fn(&statemachine::aa1)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA3}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA5}, std::mem_fn(&statemachine::ae4)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA6}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA7}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA8}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA9}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA10}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA11}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA12}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA13}, std::mem_fn(&statemachine::aa6)},

   {{statemachine::EVENT::TRANS_CONN_INDIC, statemachine::CONN_STATE::STA1}, std::mem_fn(&statemachine::ae5)},

   {{statemachine::EVENT::RECV_A_ASSOCIATE_RQ_PDU, statemachine::CONN_STATE::STA2}, std::mem_fn(&statemachine::ae6)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RQ_PDU, statemachine::CONN_STATE::STA3}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RQ_PDU, statemachine::CONN_STATE::STA5}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RQ_PDU, statemachine::CONN_STATE::STA6}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RQ_PDU, statemachine::CONN_STATE::STA7}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RQ_PDU, statemachine::CONN_STATE::STA8}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RQ_PDU, statemachine::CONN_STATE::STA9}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RQ_PDU, statemachine::CONN_STATE::STA10}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RQ_PDU, statemachine::CONN_STATE::STA11}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RQ_PDU, statemachine::CONN_STATE::STA12}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_ASSOCIATE_RQ_PDU, statemachine::CONN_STATE::STA13}, std::mem_fn(&statemachine::aa7)},

   {{statemachine::EVENT::LOCL_A_ASSOCIATE_AC_PDU, statemachine::CONN_STATE::STA3}, std::mem_fn(&statemachine::ae7)},

   {{statemachine::EVENT::LOCL_A_ASSOCIATE_RJ_PDU, statemachine::CONN_STATE::STA3}, std::mem_fn(&statemachine::ae8)},

   {{statemachine::EVENT::LOCL_P_DATA_TF_PDU, statemachine::CONN_STATE::STA6}, std::mem_fn(&statemachine::dt1)},
   {{statemachine::EVENT::LOCL_P_DATA_TF_PDU, statemachine::CONN_STATE::STA8}, std::mem_fn(&statemachine::ar7)},

   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA2}, std::mem_fn(&statemachine::aa1)},
   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA3}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA5}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA6}, std::mem_fn(&statemachine::dt2)},
   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA7}, std::mem_fn(&statemachine::ar6)},
   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA8}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA9}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA10}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA11}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA12}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_P_DATA_TF_PDU, statemachine::CONN_STATE::STA13}, std::mem_fn(&statemachine::aa6)},

   {{statemachine::EVENT::LOCL_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA6}, std::mem_fn(&statemachine::ar1)},

   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA2}, std::mem_fn(&statemachine::aa1)},
   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA3}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA5}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA6}, std::mem_fn(&statemachine::ar2)},
   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA7}, std::mem_fn(&statemachine::ar8)},
   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA8}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA9}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA10}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA11}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA12}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_RELEASE_RQ_PDU, statemachine::CONN_STATE::STA13}, std::mem_fn(&statemachine::aa6)},

   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA2}, std::mem_fn(&statemachine::aa1)},
   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA3}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA5}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA6}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA7}, std::mem_fn(&statemachine::ar3)},
   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA8}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA9}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA10}, std::mem_fn(&statemachine::ar10)},
   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA11}, std::mem_fn(&statemachine::ar3)},
   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA12}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::RECV_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA13}, std::mem_fn(&statemachine::aa6)},

   {{statemachine::EVENT::LOCL_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA8}, std::mem_fn(&statemachine::ar4)},
   {{statemachine::EVENT::LOCL_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA9}, std::mem_fn(&statemachine::ar9)},
   {{statemachine::EVENT::LOCL_A_RELEASE_RP_PDU, statemachine::CONN_STATE::STA12}, std::mem_fn(&statemachine::ar4)},

   {{statemachine::EVENT::LOCL_A_ABORT_PDU, statemachine::CONN_STATE::STA3}, std::mem_fn(&statemachine::aa1)},
   {{statemachine::EVENT::LOCL_A_ABORT_PDU, statemachine::CONN_STATE::STA4}, std::mem_fn(&statemachine::aa2)},
   {{statemachine::EVENT::LOCL_A_ABORT_PDU, statemachine::CONN_STATE::STA5}, std::mem_fn(&statemachine::aa1)},
   {{statemachine::EVENT::LOCL_A_ABORT_PDU, statemachine::CONN_STATE::STA6}, std::mem_fn(&statemachine::aa1)},
   {{statemachine::EVENT::LOCL_A_ABORT_PDU, statemachine::CONN_STATE::STA7}, std::mem_fn(&statemachine::aa1)},
   {{statemachine::EVENT::LOCL_A_ABORT_PDU, statemachine::CONN_STATE::STA8}, std::mem_fn(&statemachine::aa1)},
   {{statemachine::EVENT::LOCL_A_ABORT_PDU, statemachine::CONN_STATE::STA9}, std::mem_fn(&statemachine::aa1)},
   {{statemachine::EVENT::LOCL_A_ABORT_PDU, statemachine::CONN_STATE::STA10}, std::mem_fn(&statemachine::aa1)},
   {{statemachine::EVENT::LOCL_A_ABORT_PDU, statemachine::CONN_STATE::STA11}, std::mem_fn(&statemachine::aa1)},
   {{statemachine::EVENT::LOCL_A_ABORT_PDU, statemachine::CONN_STATE::STA12}, std::mem_fn(&statemachine::aa1)},

   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA2}, std::mem_fn(&statemachine::aa2)},
   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA3}, std::mem_fn(&statemachine::aa3)},
   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA5}, std::mem_fn(&statemachine::aa3)},
   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA6}, std::mem_fn(&statemachine::aa3)},
   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA7}, std::mem_fn(&statemachine::aa3)},
   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA8}, std::mem_fn(&statemachine::aa3)},
   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA9}, std::mem_fn(&statemachine::aa3)},
   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA10}, std::mem_fn(&statemachine::aa3)},
   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA11}, std::mem_fn(&statemachine::aa3)},
   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA12}, std::mem_fn(&statemachine::aa3)},
   {{statemachine::EVENT::RECV_A_ABORT_PDU, statemachine::CONN_STATE::STA13}, std::mem_fn(&statemachine::aa2)},

   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA2}, std::mem_fn(&statemachine::aa5)},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA3}, std::mem_fn(&statemachine::aa4)},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA4}, std::mem_fn(&statemachine::aa4)},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA5}, std::mem_fn(&statemachine::aa4)},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA6}, std::mem_fn(&statemachine::aa4)},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA7}, std::mem_fn(&statemachine::aa4)},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA8}, std::mem_fn(&statemachine::aa4)},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA9}, std::mem_fn(&statemachine::aa4)},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA10}, std::mem_fn(&statemachine::aa4)},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA11}, std::mem_fn(&statemachine::aa4)},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA12}, std::mem_fn(&statemachine::aa4)},
   {{statemachine::EVENT::TRANS_CONN_CLOSED, statemachine::CONN_STATE::STA13}, std::mem_fn(&statemachine::ar5)},

   {{statemachine::EVENT::ARTIM_EXPIRED, statemachine::CONN_STATE::STA2}, std::mem_fn(&statemachine::aa2)},
   {{statemachine::EVENT::ARTIM_EXPIRED, statemachine::CONN_STATE::STA13}, std::mem_fn(&statemachine::aa2)},

   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA2}, std::mem_fn(&statemachine::aa1)},
   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA3}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA5}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA6}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA7}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA8}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA9}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA10}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA11}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA12}, std::mem_fn(&statemachine::aa8)},
   {{statemachine::EVENT::UNRECOG_PDU, statemachine::CONN_STATE::STA13}, std::mem_fn(&statemachine::aa7)},
};

}

}

}

