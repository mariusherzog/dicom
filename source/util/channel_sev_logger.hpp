#ifndef CHANNEL_SEV_LOGGER_HPP
#define CHANNEL_SEV_LOGGER_HPP

#include <string>

#include <boost/shared_ptr.hpp>

#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>

namespace dicom
{

namespace util
{

namespace log
{


namespace logging = boost::log;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;
using namespace logging::trivial;

void init_log();


struct channel_sev_logger:
    src::severity_channel_logger<severity_level>
{
    explicit channel_sev_logger(std::string channel);
};


}

}

}


#endif // CHANNEL_SEV_LOGGER_HPP
