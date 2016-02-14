#include "channel_sev_logger.hpp"



namespace dicom
{

namespace util
{

namespace log
{

void init_log()
{
    logging::add_console_log
    (
        std::cout,
        keywords::format =
        (
            expr::stream
                << "[" << expr::attr<std::string>("Channel")
                << "] [" << logging::trivial::severity
                << "] " << expr::smessage
        )
    );

    logging::add_common_attributes();
}


channel_sev_logger::channel_sev_logger(std::string channel):
   src::severity_channel_logger<logging::trivial::severity_level> {keywords::channel = channel}
{
}

}

}

}



