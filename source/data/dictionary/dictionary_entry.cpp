#include "dictionary_entry.hpp"

#include <algorithm>

using namespace dicom::data::attribute;

namespace dicom
{

namespace data
{

namespace dictionary
{

dictionary_entry::dictionary_entry(std::array<VR, max_vr_options> vr, std::string mf, std::string kw
                                   , std::string vm, bool ret):
   vr {vr},
   message_field {mf},
   keyword {kw},
   vm {vm},
   retired {ret}
{

}

int dictionary_entry::vr_options() const
{
   return std::find_if(vr.begin(), vr.end(),
         [](VR vr) { return vr == VR::NN; }) - vr.begin();
}


template <typename L, typename R>
boost::bimap<L, R>
make_bimap(std::initializer_list<typename boost::bimap<L, R>::value_type> list)
{
    return boost::bimap<L, R>(list.begin(), list.end());
}

const boost::bimap<std::string, VR> dictionary_entry::vr_of_string
= make_bimap<std::string, VR>(
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
}
);

}

}

}

