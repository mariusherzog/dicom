#include "datasets.hpp"

#include <iostream>
#include <iomanip>
#include <stack>
#include <vector>
#include <map>

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



void traverse(const dataset_type& data, std::function<void(attribute::tag_type, const attribute::elementfield&)> handler)
{
   std::stack<dataset_type> sets;
   std::stack<dataset_type::const_iterator> positions;
   std::stack<std::size_t> pos_cur;
   std::stack<std::size_t> pos_end;

   sets.push(data);
   positions.push(sets.top().begin());

   while (sets.size() > 0) {
      auto& it = positions.top();

      while (it != sets.top().end() && it->second.value_rep != VR::SQ) {
         handler(it->first, it->second);
         ++it;
      }
      if (it != sets.top().end()) {
         handler(it->first, it->second);

         std::vector<dataset_type> data;
         get_value_field<VR::SQ>(it->second, data);

         for (int i=data.size()-1; i >= 0; --i) {
            dataset_type itemset = data[i];
            sets.push(itemset);
            positions.push(sets.top().begin());
         }
         ++it;
      } else {
         // consider emitting a dummy item delimitation item
         sets.pop();
         positions.pop();
      }
   }
}

bool contains_tag(const dataset_type& set, attribute::tag_type tag)
{
   return set.find(tag) != std::end(set);
}

std::ostream& operator<<(std::ostream& os, const dataset_type& data)
{
   int depth = 0;
   traverse(data, [&](attribute::tag_type tag, const attribute::elementfield& ef) mutable
   {
      if (tag == ItemDelimitationItem) {
         --depth;
      }

      std::fill_n(std::ostream_iterator<char>(os), depth, '\t');
      os << tag << " ";
      if (tag != SequenceDelimitationItem
          && tag != ItemDelimitationItem
          && tag != Item
          && ef.value_rep.is_initialized()
          && ef.value_rep.get() != VR::NN
          && ef.value_rep.get() != VR::NI) {
         if (ef.value_rep.get() == VR::SQ ) {
            os << " " << ef.value_len;
            if ((ef.value_len & 0xffffffff) == 0xffffffff) {
               os << "(undefined length)";
            }
            os << "\t\t";
         } else {
            os << " " << ef.value_len << "\t\t";
            ef.value_field->print(os);
         }
      }
      os << "\n";

      if (tag == Item) {
         ++depth;
      }
   });
   return os;
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


std::size_t byte_length(std::vector<dataset::dataset_type>)
{
   return 0xffffffff;
}

}

}

}
