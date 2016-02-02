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



}

}

}
