#ifndef UPPERLAYER_TRANSITIONS_HPP
#define UPPERLAYER_TRANSITIONS_HPP

#include <map>
#include <functional>
#include <queue>
#include <memory>

#include "upperlayer_properties.hpp"

namespace upperlayer
{

class statemachine
{
      friend class scx;

   public:
      /**
       * @brief The CONN_STATE enum contains the states for the state machine
       * @see DICOM3 standard table 9-10
       */
      enum class CONN_STATE
      {
         INV = 0x00,
         STA1,
         STA2,
         STA3,
         STA4,
         STA5,
         STA6,
         STA7,
         STA8,
         STA9,
         STA10,
         STA11,
         STA12,
         STA13
      };

      enum class EVENT
      {
         NONE = 0x00,
         A_ASSOCIATE_RQ,
         TRANS_CONN_CONF,
         RECV_A_ASSOCIATE_AC_PDU,
         RECV_A_ASSOCIATE_RJ_PDU,
         TRANS_CONN_INDIC,
         RECV_A_ASSOCIATE_RQ_PDU,
         LOCL_A_ASSOCIATE_AC_PDU,
         LOCL_A_ASSOCIATE_RJ_PDU,
         LOCL_P_DATA_TF_PDU,
         RECV_P_DATA_TF_PDU,
         LOCL_A_RELEASE_RQ_PDU,
         RECV_A_RELEASE_RQ_PDU,
         RECV_A_RELEASE_RP_PDU,
         LOCL_A_RELEASE_RP_PDU,
         LOCL_A_ABORT_PDU,
         RECV_A_ABORT_PDU,
         TRANS_CONN_CLOSED,
         ARTIM_EXPIRED,
         UNRECOG_PDU
      };

      statemachine();

      CONN_STATE get_state();
      CONN_STATE transition(EVENT e);

   private:
      CONN_STATE state;
      EVENT event_;

      bool process_next;
      bool reset_artim;
      std::queue<std::unique_ptr<property>> to_send; // for example aa1();

      void aa1(); void aa2(); void aa3(); void aa4();
      void aa5(); void aa6(); void aa7(); void aa8();
      void ae1(); void ae2(); void ae3(); void ae4();
      void ae5(); void ae6(); void ae7(); void ae8();
      void ar1(); void ar2(); void ar3(); void ar4();
      void ar5(); void ar6(); void ar7(); void ar8();
      void ar9(); void ar10();
      void dt1();
      void dt2();

      static std::map<std::pair<EVENT, CONN_STATE>, std::function<void(statemachine*)>> transition_table;
};


}

#endif // UPPERLAYER_TRANSITIONS_HPP
