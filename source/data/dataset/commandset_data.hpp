#ifndef COMMANDSET_DATA_HPP
#define COMMANDSET_DATA_HPP

#include <exception>

#include "data/attribute/attribute.hpp"

namespace dicom
{

namespace data
{

namespace dataset
{


using commandset_data = std::set<attribute::elementfield>;


enum class DIMSE_SERVICE_GROUP : unsigned
{
   C_STORE_RQ  = 0x0001,
   C_STORE_RSP = 0x8001,
   C_GET_RQ    = 0x0010,
   C_GET_RSP   = 0x8010,
   C_FIND_RQ   = 0x0020,
   C_FIND_RSP  = 0x8020,
   C_MOVE_RQ   = 0x0021,
   C_MOVE_RSP  = 0x8021,
   C_ECHO_RQ   = 0x0030,
   C_ECHO_RSP  = 0x8030,

   N_EVENT_REPORT_RQ    = 0x0100,
   N_EVENT_REPORT_RSP   = 0x8100,
   N_GET_RQ             = 0x0110,
   N_GET_RSP            = 0x8110,
   N_SET_RQ             = 0x0120,
   N_SET_RSP            = 0x8120,
   N_ACTION_RQ          = 0x0130,
   N_ACTION_RSP         = 0x8130,
   N_CREATE_RQ          = 0x0140,
   N_CREATE_RSP         = 0x8140,
   N_DELETE_RQ          = 0x0150,
   N_DELETE_RSP         = 0x8150,

   C_CANCEL_RQ = 0xffff
};

enum class DIMSE_PRIORITY : unsigned
{
   LOW      = 0x0002,
   MEDIUM   = 0x0000,
   HIGH     = 0x0001
};

struct STATUS
{
      enum STAT
      {
         SUCCESS, WARNING, FAILURE, CANCEL, PENDING
      };

      operator int() const
      {
         return code;
      }

      bool operator==(STAT status)
      {
         return stat == status;
      }

      STATUS(int s): code {s}
      {
         if (s == 0x0000)
            stat = SUCCESS;
         else if (s == 0x0001 || (s & 0xf000) == 0xb000)
            stat = WARNING;
         else if ((s & 0xf000) == 0xa000 || (s & 0xf000) == 0xc000)
            stat = FAILURE;
         else if (s == 0xfe00)
            stat = CANCEL;
         else if (s == 0xff00 || s == 0xff01)
            stat = PENDING;
         else
            throw std::runtime_error("Invalid status code " + std::to_string(stat));
      }

   private:
      STAT stat;
      int code;
};

}

}

}


#endif // COMMANDSET_DATA_HPP
