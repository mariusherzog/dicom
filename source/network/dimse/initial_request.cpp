#include "initial_request.hpp"

#include <algorithm>

namespace dicom
{

namespace network
{

namespace dimse
{

/**
 * @brief pad_to_16 adds spaces to the given string to get to 16 characters
 *        length.
 * @param[in] s string to be padded
 * @returns padded string
 */
static std::string pad_to_16(std::string s)
{
   int chars = s.size();
   s.resize(16);
   std::fill(s.begin()+chars, s.end(), ' ');
   return s;
}


initial_request::initial_request(std::string calling_ae,
                                 std::string called_ae,
                                 std::initializer_list<std::pair<SOP_class_request, std::vector<std::string>>> pcs)
{
   request.application_context = "1.2.840.10008.3.1.1.1";
   request.called_ae = pad_to_16(called_ae);
   request.calling_ae = pad_to_16(calling_ae);
   request.max_message_length = 0xFFFE;

   supported_sops.reserve(255);
   int pc_id = 1;
   for (auto pc : pcs) {
      dicom::network::upperlayer::a_associate_rq::presentation_context p;
      p.id = pc_id;
      p.abstract_syntax = pc.first.get_SOP_class_UID();
      p.transfer_syntaxes = pc.second;
      request.pres_contexts = {p};
      pc_id += 2;

      supported_sops.push_back({pc.first});
      if (pc_id > 255) {
         break;
      }
   }
}

SOP_class_request initial_request::get_SOP_class(int pc_id) const
{
   return supported_sops[(pc_id-1)/2];
}

upperlayer::a_associate_rq initial_request::get_initial_request() const
{
   return request;
}

}

}

}

