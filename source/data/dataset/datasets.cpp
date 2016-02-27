#include "datasets.hpp"

#include <iostream>
#include <iomanip>


#include "data/attribute/constants.hpp"
#include "data/dictionary/dictionary.hpp"
#include "data/dictionary/dictionary_entry.hpp"

#include "dataset_iterator.hpp"

namespace dicom
{

namespace data
{

namespace dataset
{


using namespace attribute;


std::ostream& operator<<(std::ostream& os, const dataset_type& data)
{

   int depth = 0;
   for (const auto attr : dataset_iterator_adaptor(data)) {
      std::fill_n(std::ostream_iterator<char>(os), depth, '\t');

      if (attr.first == SequenceDelimitationItem
          || attr.first == ItemDelimitationItem) {
         depth--;
      }
      if (attr.second.value_rep == VR::SQ) {
         depth++;
      }

      os << attr.first << " ";
      if (attr.second.value_rep.is_initialized() && attr.second.value_rep.get() != VR::NN) {
         os << dictionary::dictionary_entry::vr_of_string.right.at(attr.second.value_rep.get());
      } else {
         os << "(unknown) NN";
      }
      if (attr.first != SequenceDelimitationItem
          && attr.first != ItemDelimitationItem
          && attr.first != Item
          && attr.second.value_rep.is_initialized()
          && attr.second.value_rep.get() != VR::SQ
          && attr.second.value_rep.get() != VR::NN) {
         os << " " << attr.second.value_len << "\t\t";
         attr.second.value_field->print(os);
      }
      os << "\n";

   }

   return os;
}

std::size_t dataset_size(dataset_type data, bool explicitvr)
{
   return std::accumulate(data.begin(), data.end(), 0,
      [explicitvr](int acc, const std::pair<const elementfield::tag_type, elementfield>& attr) {
      return acc += attr.second.value_len + 4 + 4
            + (explicitvr ? 2 : 0);
   });
}


std::ostream& operator<<(std::ostream& os, DIMSE_SERVICE_GROUP dsg)
{
    switch (dsg) {
        case DIMSE_SERVICE_GROUP::C_STORE_RQ:
            return os << "C-STORE-RQ";
        case DIMSE_SERVICE_GROUP::C_STORE_RSP:
            return os << "C-STORE-RSP";
        case DIMSE_SERVICE_GROUP::C_GET_RQ:
            return os << "C-GET-RQ";
        case DIMSE_SERVICE_GROUP::C_GET_RSP:
            return os << "C-GET-RSP";
        case DIMSE_SERVICE_GROUP::C_FIND_RQ:
            return os << "C-FIND-RQ";
        case DIMSE_SERVICE_GROUP::C_FIND_RSP:
            return os << "C-FIND-RSP";
        case DIMSE_SERVICE_GROUP::C_MOVE_RQ:
            return os << "C-MOVE-RQ";
        case DIMSE_SERVICE_GROUP::C_MOVE_RSP:
            return os << "C-MOVE-RSP";
        case DIMSE_SERVICE_GROUP::C_ECHO_RQ:
            return os << "C-ECHO-RQ";
        case DIMSE_SERVICE_GROUP::C_ECHO_RSP:
            return os << "C-ECHO-RSP";

        case DIMSE_SERVICE_GROUP::N_EVENT_REPORT_RQ:
            return os << "N-EVENT-REPORT-RQ";
        case DIMSE_SERVICE_GROUP::N_EVENT_REPORT_RSP:
            return os << "N-EVENT-REPORT-RSP";
        case DIMSE_SERVICE_GROUP::N_GET_RQ:
            return os << "N-GET-RQ";
        case DIMSE_SERVICE_GROUP::N_GET_RSP:
            return os << "N-GET-RSP";
        case DIMSE_SERVICE_GROUP::N_SET_RQ:
            return os << "N-SET-RQ";
        case DIMSE_SERVICE_GROUP::N_SET_RSP:
            return os << "N-SET-RSP";
        case DIMSE_SERVICE_GROUP::N_ACTION_RQ:
            return os << "N-ACTION-RQ";
        case DIMSE_SERVICE_GROUP::N_ACTION_RSP:
            return os << "N-ACTION-RSP";
        case DIMSE_SERVICE_GROUP::N_CREATE_RQ:
            return os << "N-CREATE-RQ";
        case DIMSE_SERVICE_GROUP::N_CREATE_RSP:
            return os << "N-CREATE-RSP";
        case DIMSE_SERVICE_GROUP::N_DELETE_RQ:
            return os << "N-DELETE-RQ";
        case DIMSE_SERVICE_GROUP::N_DELETE_RSP:
            return os << "N-DELETE-RSP";

        case DIMSE_SERVICE_GROUP::C_CANCEL_RQ:
            return os << "C-CANCEL-RQ";

        default:
            assert(false);
    }
}

std::ostream& operator<<(std::ostream& os, DIMSE_PRIORITY p)
{
    switch (p) {
        case DIMSE_PRIORITY::MEDIUM:
            return os << "MEDIUM";
        case DIMSE_PRIORITY::LOW:
            return os << "LOW";
        case DIMSE_PRIORITY::HIGH:
            return os << "HIGH";
        default:
            assert(false);
    }
}

STATUS::operator int() const
{
   return code;
}

bool STATUS::operator==(STATUS::STAT status)
{
   return stat == status;
}

STATUS::STATUS(int s): code {s}
{
   if (s == 0x0000) {
      stat = SUCCESS;
   } else if (s == 0x0001 || (s & 0xf000) == 0xb000) {
      stat = WARNING;
   } else if ((s & 0xf000) == 0xa000 || (s & 0xf000) == 0xc000) {
      stat = FAILURE;
   } else if (s == 0xfe00) {
      stat = CANCEL;
   } else if (s == 0xff00 || s == 0xff01) {
      stat = PENDING;
   } else {
      throw std::runtime_error("Invalid status code " + std::to_string(stat));
   }
}

std::ostream& operator<<(std::ostream& os, STATUS s)
{
   switch (s.stat) {
      case STATUS::STAT::SUCCESS:
         return os << "SUCCESS";
      case STATUS::STAT::WARNING:
         return os << "WARNING";
      case STATUS::STAT::FAILURE:
         return os << "FAILURE";
      case STATUS::STAT::CANCEL:
         return os << "CANCEL";
      case STATUS::STAT::PENDING:
         return os << "PENDING";
      default:
         assert(false);
   }
}


}

}

}
