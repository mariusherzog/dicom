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
   dataset_type() = default;
   dataset_type(const dataset_type&) = default;
   dataset_type& operator=(const dataset_type&) = default;
   dataset_type(dataset_type&& set) noexcept: std::map<attribute::tag_type, attribute::elementfield> {std::move(set)} {}
   dataset_type& operator=(dataset_type&& set) noexcept 
   {
      std::map<attribute::tag_type, attribute::elementfield>::operator=(std::move(set));
      return *this;
   }
};

using commandset_data = dataset_type;
using iod = dataset_type;

/**
 * @brief traverse a dicom dataset in "normal" order, ie. stepping into
 *        sequences and call a user-specified handler
 * @param data dataset to traverse
 * @param handler handler to be called for each attribute
 */
void traverse(const dataset_type& data, std::function<void(attribute::tag_type, const attribute::elementfield&)> handler);

/**
 * @brief contains_tag checks whether a set contains a certain tag
 * @param set set to check
 * @param tag tag to look for
 * @return true if found, false otherwise
 */
bool contains_tag(const dataset_type& set, attribute::tag_type tag);

/**
 * @brief operator << prints the dataset in a human - readable form
 * @param os output stream
 * @param data dataset to print
 * @return modified stream the dataset was printed to
 */
std::ostream& operator<<(std::ostream& os, const dataset_type& data);


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

std::size_t byte_length(std::vector<dataset::dataset_type>);

}

}

}


#endif // DATASETS_HPP
