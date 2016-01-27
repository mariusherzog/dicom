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

data::dataset::DIMSE_SERVICE_GROUP response::get_response_type()
{
   return response_type;
}

boost::optional<data::dataset::iod>& response::get_data()
{
   return data;
}

data::dataset::STATUS response::get_status()
{
   return status;
}

data::dataset::DIMSE_PRIORITY response::get_priority()
{
   return prio;
}



}

}

}
