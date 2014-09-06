#include "upperlayer_statemachine.hpp"

#include <map>

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

statemachine::CONN_STATE statemachine::transition(TYPE t, bool received)
{
   CONN_STATE next_state;
   if (received) {
      next_state = transition_table_received_pdus[{state, t}];
   } else {
      next_state = transition_table_user_primitives[{state, t}];
   }

   if (next_state != CONN_STATE::INV) {
      return state = next_state;
   } else {
      return CONN_STATE::INV;
   }
}


/**
 * @brief contains the target state as a function of pair of the current state and a primitive received from the user
 *
 */
std::map<std::pair<statemachine::CONN_STATE, TYPE>, statemachine::CONN_STATE> statemachine::transition_table_user_primitives {
   {{statemachine::CONN_STATE::STA2, TYPE::A_ASSOCIATE_RQ}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA2, TYPE::A_ASSOCIATE_AC}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA2, TYPE::A_ASSOCIATE_RJ}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA2, TYPE::A_RELEASE_RQ}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA2, TYPE::A_RELEASE_RP}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA2, TYPE::A_ABORT}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA2, TYPE::P_DATA_TF}, statemachine::CONN_STATE::INV},

   {{statemachine::CONN_STATE::STA3, TYPE::A_ASSOCIATE_RQ}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA3, TYPE::A_ASSOCIATE_AC}, statemachine::CONN_STATE::STA6},
   {{statemachine::CONN_STATE::STA3, TYPE::A_ASSOCIATE_RJ}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA3, TYPE::A_RELEASE_RQ}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA3, TYPE::A_RELEASE_RP}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA3, TYPE::A_ABORT}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA3, TYPE::P_DATA_TF}, statemachine::CONN_STATE::INV},

   {{statemachine::CONN_STATE::STA6, TYPE::A_ASSOCIATE_RQ}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA6, TYPE::A_ASSOCIATE_AC}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA6, TYPE::A_ASSOCIATE_RJ}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA6, TYPE::A_RELEASE_RQ}, statemachine::CONN_STATE::STA7},
   {{statemachine::CONN_STATE::STA6, TYPE::A_RELEASE_RP}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA6, TYPE::A_ABORT}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA6, TYPE::P_DATA_TF}, statemachine::CONN_STATE::STA6},

   {{statemachine::CONN_STATE::STA7, TYPE::A_ASSOCIATE_RQ}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA7, TYPE::A_ASSOCIATE_AC}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA7, TYPE::A_ASSOCIATE_RJ}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA7, TYPE::A_RELEASE_RQ}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA7, TYPE::A_RELEASE_RP}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA7, TYPE::A_ABORT}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA7, TYPE::P_DATA_TF}, statemachine::CONN_STATE::INV},

   {{statemachine::CONN_STATE::STA8, TYPE::A_ASSOCIATE_RQ}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA8, TYPE::A_ASSOCIATE_AC}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA8, TYPE::A_ASSOCIATE_RJ}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA8, TYPE::A_RELEASE_RQ}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA8, TYPE::A_RELEASE_RP}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA8, TYPE::A_ABORT}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA8, TYPE::P_DATA_TF}, statemachine::CONN_STATE::STA8},
};

std::map<std::pair<statemachine::CONN_STATE, TYPE>, statemachine::CONN_STATE> statemachine::transition_table_received_pdus {
   {{statemachine::CONN_STATE::STA2, TYPE::A_ASSOCIATE_RQ}, statemachine::CONN_STATE::STA3},
   {{statemachine::CONN_STATE::STA2, TYPE::A_ASSOCIATE_AC}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA2, TYPE::A_ASSOCIATE_RJ}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA2, TYPE::A_RELEASE_RQ}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA2, TYPE::A_RELEASE_RP}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA2, TYPE::A_ABORT}, statemachine::CONN_STATE::INV},
   {{statemachine::CONN_STATE::STA2, TYPE::P_DATA_TF}, statemachine::CONN_STATE::INV},

   {{statemachine::CONN_STATE::STA3, TYPE::A_ASSOCIATE_RQ}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA3, TYPE::A_ASSOCIATE_AC}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA3, TYPE::A_ASSOCIATE_RJ}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA3, TYPE::A_RELEASE_RQ}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA3, TYPE::A_RELEASE_RP}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA3, TYPE::A_ABORT}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA3, TYPE::P_DATA_TF}, statemachine::CONN_STATE::STA2},

   {{statemachine::CONN_STATE::STA6, TYPE::A_ASSOCIATE_RQ}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA6, TYPE::A_ASSOCIATE_AC}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA6, TYPE::A_ASSOCIATE_RJ}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA6, TYPE::A_RELEASE_RQ}, statemachine::CONN_STATE::STA8},
   {{statemachine::CONN_STATE::STA6, TYPE::A_RELEASE_RP}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA6, TYPE::A_ABORT}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA6, TYPE::P_DATA_TF}, statemachine::CONN_STATE::STA6},

   {{statemachine::CONN_STATE::STA7, TYPE::A_ASSOCIATE_RQ}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA7, TYPE::A_ASSOCIATE_AC}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA7, TYPE::A_ASSOCIATE_RJ}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA7, TYPE::A_RELEASE_RQ}, statemachine::CONN_STATE::INV}, //release coll
   {{statemachine::CONN_STATE::STA7, TYPE::A_RELEASE_RP}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA7, TYPE::A_ABORT}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA7, TYPE::P_DATA_TF}, statemachine::CONN_STATE::STA7},

   {{statemachine::CONN_STATE::STA8, TYPE::A_ASSOCIATE_RQ}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA8, TYPE::A_ASSOCIATE_AC}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA8, TYPE::A_ASSOCIATE_RJ}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA8, TYPE::A_RELEASE_RQ}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA8, TYPE::A_RELEASE_RP}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA8, TYPE::A_ABORT}, statemachine::CONN_STATE::STA2},
   {{statemachine::CONN_STATE::STA8, TYPE::P_DATA_TF}, statemachine::CONN_STATE::STA2},
};


}

