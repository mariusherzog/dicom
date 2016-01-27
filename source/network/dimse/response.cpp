#include "response.hpp"

namespace dicom
{

namespace network
{

namespace dimse
{

response::response(data::dataset::DIMSE_SERVICE_GROUP dsg,
                   boost::optional<data::dataset::iod> data,
                   data::dataset::STATUS status,
                   data::dataset::DIMSE_PRIORITY prio):
   response_type {dsg},
   data {data},
   status {status},
   prio {prio}

{
}

data::dataset::DIMSE_SERVICE_GROUP response::get_response_type() const
{
   return response_type;
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
