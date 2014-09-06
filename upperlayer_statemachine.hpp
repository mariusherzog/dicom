#ifndef UPPERLAYER_TRANSITIONS_HPP
#define UPPERLAYER_TRANSITIONS_HPP

#include <map>

#include "upperlayer_properties.hpp"

namespace upperlayer
{

class statemachine
{
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

      statemachine();

      CONN_STATE get_state();
      CONN_STATE transition(TYPE t, bool received);

   private:
      CONN_STATE state;

      static std::map<std::pair<CONN_STATE, TYPE>, CONN_STATE> transition_table_user_primitives;
      static std::map<std::pair<CONN_STATE, TYPE>, CONN_STATE> transition_table_received_pdus;
};


}

#endif // UPPERLAYER_TRANSITIONS_HPP
