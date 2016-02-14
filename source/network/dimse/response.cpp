#include "response.hpp"

namespace dicom
{

namespace network
{

namespace dimse
{

response::response(data::dataset::DIMSE_SERVICE_GROUP dsg,
                   data::dataset::commandset_data last_command,
                   boost::optional<data::dataset::iod> data,
                   data::dataset::STATUS status,
                   data::dataset::DIMSE_PRIORITY prio):
   response_type {dsg},
   last_command {last_command},
   data {data},
   status {status},
   prio {prio}

{
}

data::dataset::DIMSE_SERVICE_GROUP response::get_response_type() const
{
   return response_type;
}

const data::dataset::commandset_data&response::get_command() const
{
   return last_command;
}

const boost::optional<data::dataset::iod>& response::get_data() const
{
   return data;
}

data::dataset::STATUS response::get_status() const
{
   return status;
}

data::dataset::DIMSE_PRIORITY response::get_priority() const
{
   return prio;
}

std::ostream& operator<<(std::ostream& os, const response& r)
{
   auto rt = r.get_response_type();
   auto pr = r.get_priority();
   auto st = r.get_status();
   return os << "Service Group: \t" << rt << std::hex << "\t(" << static_cast<unsigned>(rt) << ")\n"
             << "Priority: \t\t" << pr << "\t(" << static_cast<unsigned>(pr) << ")\n"
             << "Status: \t\t" << st << "\t(" << static_cast<unsigned>(st) << ")\n";
}



}

}

}
