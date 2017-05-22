#include "association_definition.hpp"

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


association_definition::association_definition(std::string calling_ae,
                                 std::string called_ae,
                                 std::vector<presentation_context> pcs,
                                 int max_message_len,
                                 std::string application_context)
{
   request.application_context = application_context;
   request.called_ae = pad_to_16(called_ae);
   request.calling_ae = pad_to_16(calling_ae);
   request.max_message_length = max_message_len;

   supported_sops.reserve(255);
   int pc_id = 1;
   for (auto pc : pcs) {
      if (get_SOP_class(pc.sop_class.get_SOP_class_UID()).empty()) {
         dicom::network::upperlayer::a_associate_rq::presentation_context p;
         p.id = pc_id;
         p.abstract_syntax = pc.sop_class.get_SOP_class_UID();
         p.transfer_syntaxes = pc.transfer_syntaxes;
         request.pres_contexts.push_back(p);
         pc_id += 2;

         if (pc_id > 255) {
            break;
         }
      }
      supported_sops.push_back(pc);
   }
}

association_definition::presentation_context::presentation_context(SOP_class SOP, std::vector<std::string> transfer_syntaxes, DIMSE_MSG_TYPE msg_type):
   sop_class {SOP},
   transfer_syntaxes {transfer_syntaxes},
   msg_type {msg_type}
{

}


std::vector<association_definition::presentation_context>
   association_definition::get_SOP_class(std::string abstract_syntax) const
{
   std::vector<presentation_context> result_set;
   for (auto pc : supported_sops) {
      std::string s = pc.sop_class.get_SOP_class_UID();
      if (s == std::string(abstract_syntax.c_str())) {
         result_set.push_back(pc);
      }
   }
   return result_set;
}

std::vector<association_definition::presentation_context>
   association_definition::get_all_SOP() const
{
   return supported_sops;
}

upperlayer::a_associate_rq association_definition::get_initial_request() const
{
   return request;
}

std::vector<association_definition::presentation_context> make_presentation_contexts(std::vector<SOP_class> sop_classes,
      std::initializer_list<std::string> transfer_syntaxes,
      association_definition::DIMSE_MSG_TYPE msg_type)
{
   std::vector<association_definition::presentation_context> pcs;
   pcs.reserve(sop_classes.size());
   for (auto sop : sop_classes) {
      pcs.emplace_back(sop, transfer_syntaxes, msg_type);
   }
   return pcs;
}

}

}

}

