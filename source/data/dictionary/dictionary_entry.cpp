#include "dictionary_entry.hpp"

using namespace dicom::data::attribute;

namespace dicom
{

namespace data
{

namespace dictionary
{

dictionary_entry::dictionary_entry(VR vr, std::string mf, std::string kw
                                   , std::string vm, bool ret):
   vr {vr}, message_field {mf}, keyword {kw}, vm {vm}, retired {ret}
{

}

const std::map<std::string, VR> dictionary_entry::vr_of_string
{
   {"AE", VR::AE},
   {"AS", VR::AS},
   {"AT", VR::AT},
   {"CS", VR::CS},
   {"DA", VR::DA},
   {"DS", VR::DS},
   {"DT", VR::DT},
   {"FL", VR::FL},
   {"FD", VR::FD},
   {"IS", VR::IS},
   {"LO", VR::LO},
   {"LT", VR::LT},
   {"OB", VR::OB},
   {"OF", VR::OF},
   {"OW", VR::OW},
   {"PN", VR::PN},
   {"SH", VR::SH},
   {"SL", VR::SL},
   {"SQ", VR::SQ},
   {"SS", VR::SS},
   {"ST", VR::ST},
   {"TM", VR::TM},
   {"UI", VR::UI},
   {"UL", VR::UL},
   {"UN", VR::UN},
   {"US", VR::US},
   {"UT", VR::UT}
};

}

}

}

