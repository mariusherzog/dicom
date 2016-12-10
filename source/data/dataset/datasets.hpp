#ifndef DATASETS_HPP
#define DATASETS_HPP


#include <exception>
#include <map>
#include <ostream>

#include "data/attribute/attribute.hpp"

namespace dicom
{

namespace data
{

namespace dataset
{


/**
 * @brief The dataset_type struct defines a new type for the dataset in the
 *        namespace to facilitate ADL (argument dependent lookup).
 */
struct dataset_type : std::map<attribute::tag_type, attribute::elementfield>
{
};

using commandset_data = dataset_type;
using iod = dataset_type;


std::ostream& operator<<(std::ostream& os, const dataset_type& data);

/**
 * @brief dataset_size calculates the size in bytes of the dataset
 * @param data dataset
 * @param explicitvr true if the VR is encoded (adds 2 bytes per attribute)
 * @return size of the dataset in bytes
 * @todo change explicitvr param to enum
 */
std::size_t dataset_size(dataset_type data, bool explicitvr = false);


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

std::ostream& operator<<(std::ostream& os, DIMSE_SERVICE_GROUP dsg);

enum class DIMSE_PRIORITY : unsigned
{
   LOW      = 0x0002,
   MEDIUM   = 0x0000,
   HIGH     = 0x0001
};

std::ostream& operator<<(std::ostream& os, DIMSE_PRIORITY p);

struct STATUS
{
      enum STAT
      {
         SUCCESS, WARNING, FAILURE, CANCEL, PENDING
      };

      operator int() const;

      bool operator==(STAT status);

      STATUS(int s);

      friend std::ostream& operator<<(std::ostream& os, STATUS s);

   private:
      STAT stat;
      int code;
};

}

}

}


#endif // DATASETS_HPP
