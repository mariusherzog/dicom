#include "upperlayer_properties.hpp"

#include <algorithm>
#include <ostream>
#include <vector>
#include <string>
#include <cassert>

namespace dicom
{

namespace network
{

namespace upperlayer
{

namespace
{
using uchar = unsigned char;

std::size_t be_char_to_16b(std::vector<uchar> bs)
{
   assert(bs.size() == 2);
   std::size_t sz = 0;
   sz |= (static_cast<std::size_t>(bs[0]) << 8);
   sz |= (static_cast<std::size_t>(bs[1]));
   return sz;
}
std::size_t be_char_to_32b(std::vector<uchar> bs)
{
   assert(bs.size() == 4);
   std::size_t sz = 0;
   sz |= (static_cast<std::size_t>(bs[0]) << 24);
   sz |= (static_cast<std::size_t>(bs[1]) << 16);
   sz |= (static_cast<std::size_t>(bs[2]) << 8);
   sz |= (static_cast<std::size_t>(bs[3]));
   return sz;
}
std::vector<uchar> ui_to_16b_be(unsigned val)
{
   std::vector<unsigned char> be_val(2);
   be_val[0] = ((val & 0xFF00) >> 8);
   be_val[1] = (val & 0xFF);
   return be_val;
}
std::vector<uchar> ui_to_32b_be(unsigned val)
{
   std::vector<unsigned char> be_val(4);
   be_val[0] = ((val & 0xFF000000) >> 24);
   be_val[1] = ((val & 0xFF0000)) >> 16;
   be_val[2] = ((val & 0xFF00) >> 8);
   be_val[3] = (val & 0xFF);
   return be_val;
}
}



TYPE get_type(const std::vector<unsigned char>& pdu)
{
   return static_cast<TYPE>(pdu[0]);
}


property::~property()
{
}


void p_data_tf::from_pdu(std::vector<unsigned char> pdu)
{
   std::size_t pos = 0;
   bool pdvs_left = true;
   while (pdvs_left || pos < pdu.size()-1) {
      pos += 6;
      std::size_t pdv_len = be_char_to_32b({pdu.begin()+pos, pdu.begin()+pos+4});
      pos += 4;
      pres_context_id = pdu[pos];

      unsigned char msg_control = pdu[pos+1];

      pos += 2;
      if (msg_control & 0x01) {
         command_set.insert(command_set.end(), pdu.begin()+pos, pdu.begin()+(pos+pdv_len-2));
      } else {
         data_set.insert(data_set.end(), pdu.begin()+pos, pdu.begin()+(pos+pdv_len-2));
      }

      pdvs_left = !(msg_control & 0x02);
      pos += pdv_len-2; // message control id and presentation context id are
                        // included in the length
   }
}

std::vector<uchar> p_data_tf::make_pdu() const
{
   const std::size_t preamble_length = 12;
   const std::size_t m_length = msg_length-preamble_length;
   std::vector<uchar> pack;

   {
      // insert command part
      // one extra byte each for message id and message header
      std::vector<uchar> pdv_len;

      if (!command_set.empty()) {
         auto begin = pack.end()-pack.begin();
         pack.push_back(static_cast<uchar>(TYPE::P_DATA_TF));
         pack.insert(pack.end(), {0x00, 0x00, 0x00, 0x00, 0x00});
         std::size_t len_pos = begin + 2;

         pdv_len = ui_to_32b_be(command_set.size()+2);
         pack.insert(pack.end(), pdv_len.begin(), pdv_len.end());
         pack.push_back(pres_context_id);
//         if (data_set.empty()) {
//            pack.push_back(0x03);
//         } else {
//            pack.push_back(0x01);
//         }
         pack.push_back(0x03);
         pack.insert(pack.end(), command_set.begin(), command_set.end());

         std::size_t pdu_len = pack.size()-6;
         std::vector<uchar> plen = ui_to_32b_be(pdu_len);
         std::copy(plen.begin(), plen.end(), pack.begin()+len_pos);
      }

      // insert pack header
      if (!data_set.empty()) {
         for (std::size_t pos = 0; pos < data_set.size(); pos += m_length) {
            auto begin = pack.end()-pack.begin();
            pack.push_back(static_cast<uchar>(TYPE::P_DATA_TF));
            pack.insert(pack.end(), {0x00, 0x00, 0x00, 0x00, 0x00});
            std::size_t len_pos = begin + 2;

            auto remaining = std::min(m_length, data_set.size()-pos);
            pdv_len = ui_to_32b_be(remaining+2);
            pack.insert(pack.end(), pdv_len.begin(), pdv_len.end());
            pack.push_back(pres_context_id);

            if (remaining < m_length) {
               pack.push_back(0x02);
            } else {
               pack.push_back(0x00);
            }
            pack.insert(pack.end(), data_set.begin()+pos, data_set.begin()+pos+remaining);

            std::size_t pdu_len = remaining+6;
            std::vector<uchar> plen = ui_to_32b_be(pdu_len);
            std::copy(plen.begin(), plen.end(), pack.begin()+len_pos);
         }
      }
   }

   return pack;
}

TYPE p_data_tf::type() const
{
   return TYPE::P_DATA_TF;
}

std::ostream& p_data_tf::print(std::ostream& os) const
{
   return os << "Presentation Context ID: "
             << std::to_string(pres_context_id) << "\n";
}


/**
 * @brief This parse function "deserializes" an a-associate-rq
 *        contained in the parameter pdu and returns a struct
 *        describing properties
 * @param[in] pdu
 *
 * The scope structure of this function resembles the structure
 * of the a-associate-rq pdu.
 * At the beginning of a scope the pos index always points to the
 * first byte of the item, ie the item type.
 */
void a_associate_rq::from_pdu(std::vector<unsigned char> pdu)
{
   called_ae = std::string({pdu.begin()+10, pdu.begin()+26});
   calling_ae = std::string({pdu.begin()+26, pdu.begin()+42});

   std::size_t pos = 74;
   {
      assert(pdu[pos] == 0x10);
      std::size_t appl_cont_len = be_char_to_16b({pdu.begin()+pos+2, pdu.begin()+pos+4});
      application_context = std::string({pdu.begin()+pos+4, pdu.begin()+pos+4+appl_cont_len});

      pos += (4+appl_cont_len);

      // read presentation contexts
      while (pdu[pos] == 0x20) {
         unsigned char id;
         std::string abst_synt;
         std::vector<std::string> trans_synt;

         id = pdu[pos + 4];

         pos += 8;
         // read abstract syntax item (does not exist in a-associate-ac)
         if (pdu[pos] == 0x30)
         {
            std::size_t abst_synt_len = be_char_to_16b({pdu.begin()+pos+2, pdu.begin()+pos+4});
            abst_synt = std::string({pdu.begin()+pos+4, pdu.begin()+pos+4+abst_synt_len});
            pos += abst_synt_len+4;
         }

         assert(pdu[pos] == 0x40);
         // read transfer syntaxes
         while (pdu[pos] == 0x40) {
            assert(pdu[pos] == 0x40);
            std::size_t trans_synt_len = be_char_to_16b({pdu.begin()+pos+2, pdu.begin()+pos+4});
            trans_synt.push_back(std::string({pdu.begin()+pos+4, pdu.begin()+pos+4+trans_synt_len}));
            pos += trans_synt_len+4;
         }

         presentation_context q {id, abst_synt, trans_synt};
         pres_contexts.push_back(q);
      }

      // read user info item
      {
         assert(pdu[pos] == 0x50);
         pos += 4;
         {
            assert(pdu[pos] == 0x51);
            max_message_length = be_char_to_32b({pdu.begin()+pos+4, pdu.begin()+pos+8});
         }
      }

   }
}

/**
 * @brief this function operates on the structured connection properties and
 *        deserializes it into a ready-to-transmit a-associate-rq or an
 *        a-associate-ac pdu
 * @param[in] t
 * @return pdu representing structured data
 */
std::vector<uchar> a_associate_rq::make_pdu() const
{
   std::vector<uchar> pack;
   pack.push_back(static_cast<uchar>(TYPE::A_ASSOCIATE_RQ));
   pack.insert(pack.end(), {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00}); // preamble
   std::size_t len_pos = 2;

   // insert called and calling ae
   assert(called_ae.size() == 16 && calling_ae.size() == 16);
   pack.insert(pack.end(), called_ae.begin(), called_ae.end());
   pack.insert(pack.end(), calling_ae.begin(), calling_ae.end());
   pack.insert(pack.end(), 32, 0x00);

   {
      // insert application context item
      pack.insert(pack.end(), {0x10, 0x00});
      std::vector<uchar> ac_len = ui_to_16b_be(application_context.size());
      pack.insert(pack.end(), ac_len.begin(), ac_len.end());
      pack.insert(pack.end(), application_context.begin(), application_context.end());

      // insert presentation context items
      for (const auto pc : pres_contexts) {
         pack.insert(pack.end(), {0x20, 0x00});

         // Calculating size of presentation context
         std::size_t pcl = 0;
         pcl += pc.abstract_syntax.size()+4; //+4 <=> preamble of abstract syntax item
         for (const auto ts : pc.transfer_syntaxes) {
            pcl += ts.size()+4; //+4 <=> preamble of transfer syntax item
         }
         pcl += 4; //size of presentation context id info

         std::vector<uchar> pc_len = ui_to_16b_be(pcl);
         pack.insert(pack.end(), pc_len.begin(), pc_len.end());
         pack.insert(pack.end(), {pc.id, 0x00, 0x00, 0x00});

         {
            // insert abstract syntax
            pack.insert(pack.end(), {0x30, 0x00});
            std::vector<uchar> as_len = ui_to_16b_be(pc.abstract_syntax.size());
            pack.insert(pack.end(), as_len.begin(), as_len.end());
            pack.insert(pack.end(), pc.abstract_syntax.begin(), pc.abstract_syntax.end());


            for (const auto ts : pc.transfer_syntaxes) {
               pack.insert(pack.end(), {0x40, 0x00});
               std::vector<uchar> ts_len = ui_to_16b_be(ts.size() ); //+4 for padding
               pack.insert(pack.end(), ts_len.begin(), ts_len.end());
               pack.insert(pack.end(), ts.begin(), ts.end());
            }
         }
      }

      // insert user info item
      pack.insert(pack.end(), {0x50, 0x00});
      std::vector<uchar> ui_len = ui_to_16b_be(0x08);
      pack.insert(pack.end(), ui_len.begin(), ui_len.end());

      {
         // insert maximum length item
         pack.insert(pack.end(), {0x51, 0x00, 0x00, 0x04});
         std::vector<uchar> max_len = ui_to_32b_be(max_message_length);
         pack.insert(pack.end(), max_len.begin(), max_len.end());
      }
   }

   std::size_t pdu_len = pack.size()-6;
   std::vector<uchar> plen = ui_to_32b_be(pdu_len);
   std::copy(plen.begin(), plen.end(), pack.begin()+len_pos);

   return pack;
}


TYPE a_associate_rq::type() const
{
   return TYPE::A_ASSOCIATE_RQ;
}

std::ostream& a_associate_rq::print(std::ostream& os) const
{
   os << "Local Application Entity:\t" << called_ae << "\n"
      << "Remote Application Entity:\t" << calling_ae << "\n"
      << "Maximum Message Length:\t\t" << max_message_length << "\n"
      << "Application Context:\t" << application_context << "\n"
      << "Proposed presentation contexts:\n";
   for (const auto pc : pres_contexts) {
      os << "\tContext id: " << static_cast<unsigned>(pc.id) << "\n";
      os << "\tAbstract Syntax: " << pc.abstract_syntax << "\n";
      for (const auto ts : pc.transfer_syntaxes) {
         os << "\t\tTransfer Syntax: " << ts << "\n";
      }
   }
   return os;
}


void a_associate_ac::from_pdu(std::vector<unsigned char> pdu)
{
   called_ae = std::string({pdu.begin()+10, pdu.begin()+26});
   calling_ae = std::string({pdu.begin()+26, pdu.begin()+42});

   std::size_t pos = 74;
   {
      assert(pdu[pos] == 0x10);
      std::size_t appl_cont_len = be_char_to_16b({pdu.begin()+pos+2, pdu.begin()+pos+4});
      application_context = std::string({pdu.begin()+pos+4, pdu.begin()+pos+4+appl_cont_len});

      pos += (4+appl_cont_len);

      // read presentation contexts
      while (pdu[pos] == 0x21) {
         unsigned char id;
         presentation_context::RESULT res;
         std::string trans_synt;

         id = pdu[pos + 4];
         res = static_cast<presentation_context::RESULT>(pdu[pos+6]);

         pos += 8;

         assert(pdu[pos] == 0x40);
         // read transfer syntax
         std::size_t trans_synt_len = be_char_to_16b({pdu.begin()+pos+2, pdu.begin()+pos+4});
         trans_synt = std::string({pdu.begin()+pos+4, pdu.begin()+pos+4+trans_synt_len});
         pos += trans_synt_len+4;

         presentation_context q {id, res, trans_synt};
         pres_contexts.push_back(q);
      }

      // read user info item
      {
         assert(pdu[pos] == 0x50);
         pos += 4;
         {
            assert(pdu[pos] == 0x51);
            max_message_length = be_char_to_32b({pdu.begin()+pos+4, pdu.begin()+pos+8});
         }
      }

   }
}

std::vector<uchar> a_associate_ac::make_pdu() const
{
   std::vector<uchar> pack;
   pack.push_back(static_cast<uchar>(TYPE::A_ASSOCIATE_AC));
   pack.insert(pack.end(), {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00}); // preamble
   std::size_t len_pos = 2;

   // insert called and calling ae
   assert(called_ae.size() == 16 && calling_ae.size() == 16);
   pack.insert(pack.end(), called_ae.begin(), called_ae.end());
   pack.insert(pack.end(), calling_ae.begin(), calling_ae.end());
   pack.insert(pack.end(), 32, 0x00);

   {
      // insert application context item
      pack.insert(pack.end(), {0x10, 0x00});
      std::vector<uchar> ac_len = ui_to_16b_be(application_context.size());
      pack.insert(pack.end(), ac_len.begin(), ac_len.end());
      pack.insert(pack.end(), application_context.begin(), application_context.end());

      // insert presentation context items
      for (const auto pc : pres_contexts) {
         pack.insert(pack.end(), {0x21, 0x00});

         // Calculating size of presentation context
         std::size_t pcl = pc.transfer_syntax.size();

         std::vector<uchar> pc_len = ui_to_16b_be(pcl +4 +4); // 4 bytes padding (pc and ts)
         pack.insert(pack.end(), pc_len.begin(), pc_len.end());
         pack.insert(pack.end(), {pc.id, 0x00, static_cast<uchar>(pc.result_), 0x00});

         {
            pack.insert(pack.end(), {0x40, 0x00});
            std::vector<uchar> ts_len = ui_to_16b_be(pc.transfer_syntax.size() );
            pack.insert(pack.end(), ts_len.begin(), ts_len.end());
            pack.insert(pack.end(), pc.transfer_syntax.begin(), pc.transfer_syntax.end());
         }
      }

      // insert user info item
      pack.insert(pack.end(), {0x50, 0x00});
      std::vector<uchar> ui_len = ui_to_16b_be(0x08);
      pack.insert(pack.end(), ui_len.begin(), ui_len.end());

      {
         // insert maximum length item
         pack.insert(pack.end(), {0x51, 0x00, 0x00, 0x04});
         std::vector<uchar> max_len = ui_to_32b_be(max_message_length);
         pack.insert(pack.end(), max_len.begin(), max_len.end());
      }
   }

   std::size_t pdu_len = pack.size()-6;
   std::vector<uchar> plen = ui_to_32b_be(pdu_len);
   std::copy(plen.begin(), plen.end(), pack.begin()+len_pos);

   return pack;
}

TYPE a_associate_ac::type() const
{
   return TYPE::A_ASSOCIATE_AC;
}

std::ostream& a_associate_ac::print(std::ostream& os) const
{
   os << "Local Application Entity:\t" << called_ae << "\n"
      << "Remote Application Entity:\t" << calling_ae << "\n"
      << "Maximum Message Length:\t\t" << max_message_length << "\n"
      << "Application Context:\t" << application_context << "\n"
      << "Status of proposed presentation contexts:\n";
   for (const auto pc : pres_contexts) {
      os << "\tContext id: " << static_cast<unsigned>(pc.id);
      os << "\tResult: " << pc.result_ << "\n";
      os << "\t\tTransfer Syntax: " << pc.transfer_syntax << "\n";
   }
   return os;
}


void a_associate_rj::from_pdu(std::vector<uchar> pdu)
{
   source_ = static_cast<SOURCE>(pdu[8]);
   reason_ = static_cast<REASON>(pdu[9]);
}

std::vector<uchar> a_associate_rj::make_pdu() const
{
   std::vector<uchar> pack;
   pack.push_back(static_cast<uchar>(TYPE::A_ASSOCIATE_RJ));
   pack.insert(pack.end(), {0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x01});
   pack.push_back(static_cast<uchar>(source_));
   pack.push_back(static_cast<uchar>(reason_));
   return pack;
}

TYPE a_associate_rj::type() const
{
   return TYPE::A_ASSOCIATE_RJ;
}

std::ostream& a_associate_rj::print(std::ostream& os) const
{
   auto sr = std::pair<SOURCE, REASON> {source_, reason_};
   os << "Source: " << source_ << "\n"
      << "Reason: " << sr << "\n";
   return os;
}


void a_release_rq::from_pdu(std::vector<unsigned char>)
{
}

std::vector<uchar> a_release_rq::make_pdu() const
{
   std::vector<uchar> pack;
   pack.push_back(static_cast<uchar>(TYPE::A_RELEASE_RQ));
   pack.insert(pack.end(), {0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00});
   return pack;
}

TYPE a_release_rq::type() const
{
   return TYPE::A_RELEASE_RQ;
}

std::ostream& a_release_rq::print(std::ostream& os) const
{
   return os;
}


void a_release_rp::from_pdu(std::vector<unsigned char>)
{
}

std::vector<uchar> a_release_rp::make_pdu() const
{
   std::vector<uchar> pack;
   pack.push_back(static_cast<uchar>(TYPE::A_RELEASE_RP));
   pack.insert(pack.end(), {0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00});
   return pack;
}

TYPE a_release_rp::type() const
{
   return TYPE::A_RELEASE_RP;
}

std::ostream&a_release_rp::print(std::ostream& os) const
{
   return os;
}


void a_abort::from_pdu(std::vector<unsigned char> pdu)
{
   source_ = static_cast<SOURCE>(pdu[8]);
   reason_ = static_cast<REASON>(pdu[9]);
}

std::vector<uchar> a_abort::make_pdu() const
{
   std::vector<uchar> pack;
   pack.push_back(static_cast<uchar>(TYPE::A_ABORT));
   pack.insert(pack.end(), {0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x01});
   pack.push_back(static_cast<uchar>(source_));
   pack.push_back(static_cast<uchar>(reason_));
   return pack;
}

TYPE a_abort::type() const
{
   return TYPE::A_ABORT;
}

std::ostream& a_abort::print(std::ostream& os) const
{
   os << "Source: " << static_cast<unsigned>(source_) << "\n"
      << "Reason: " << static_cast<unsigned>(reason_) << "\n";
   return os;
}


std::unique_ptr<property> make_property(const std::vector<unsigned char>& pdu)
{
   auto ptype = get_type(pdu);
   switch (ptype) {
      case TYPE::A_ABORT: {
         auto a = new a_abort();
         a->from_pdu(pdu);
         return std::unique_ptr<a_abort>(a);
      }
      case TYPE::A_RELEASE_RQ: {
         auto a = new a_release_rq();
         a->from_pdu(pdu);
         return std::unique_ptr<a_release_rq>(a);
      }
      case TYPE::A_RELEASE_RP: {
         auto a = new a_release_rp();
         a->from_pdu(pdu);
         return std::unique_ptr<a_release_rp>(a);
      }
      case TYPE::A_ASSOCIATE_RQ: {
         auto a = new a_associate_rq();
         a->from_pdu(pdu);
         return std::unique_ptr<a_associate_rq>(a);
      }
      case TYPE::A_ASSOCIATE_AC: {
         auto a = new a_associate_ac();
         a->from_pdu(pdu);
         return std::unique_ptr<a_associate_ac>(a);
      }
      case TYPE::A_ASSOCIATE_RJ: {
         auto a = new a_associate_rj();
         a->from_pdu(pdu);
         return std::unique_ptr<a_associate_rj>(a);
      }
      case TYPE::P_DATA_TF: {
         auto p = new p_data_tf();
         p->from_pdu(pdu);
         return std::unique_ptr<p_data_tf>(p);
      }
   }
   return nullptr;
}

std::ostream& operator<<(std::ostream& os, const property& p)
{
   return p.print(os);
}

std::ostream& operator<<(std::ostream& os, TYPE t)
{
   switch (t) {
      case TYPE::A_ABORT:
         return os << "a_abort";
      case TYPE::A_ASSOCIATE_AC:
         return os << "a_associate_ac";
      case TYPE::A_ASSOCIATE_RQ:
         return os << "a_associate_rq";
      case TYPE::A_ASSOCIATE_RJ:
         return os << "a_associate_rj";
      case TYPE::A_RELEASE_RQ:
         return os << "a_release_rq";
      case TYPE::A_RELEASE_RP:
         return os << "a_release_rp";
      case TYPE::P_DATA_TF:
         return os << "p_data_tf";
      default:
         assert(false);
   }
}

std::ostream& operator<<(std::ostream& os, a_associate_ac::presentation_context::RESULT r)
{
   using pc = a_associate_ac::presentation_context;
   switch (r) {
      case pc::RESULT::ACCEPTANCE:
         return os << "Acceptance";
      case pc::RESULT::ABSTR_CONT_NOT_SUPP:
         return os << "Abstract Syntax not supported";
      case pc::RESULT::PROV_REJEC_NO_REASON:
         return os << "Provider rejection, no reason";
      case pc::RESULT::TRANSF_SYNT_NOT_SUPP:
         return os << "Transfer Syntax not supported";
      case pc::RESULT::USER_REJEC:
         return os << "User rejection";
      default:
         assert(false);
   }
}

std::ostream& operator<<(std::ostream& os, a_associate_rj::SOURCE s)
{
   using rj = a_associate_rj;
   switch (s) {
      case rj::SOURCE::UL_SERVICE_USER:
         return os << "DICOM UL service-user";
      case rj::SOURCE::UL_SERVICE_PROV_ACSE:
         return os << "DICOM UL service-provider (ACSE related function)";
      case rj::SOURCE::UL_SERVICE_PROV_PRESREL:
         return os << "DICOM UL service-provider (Presentation related function)";
      default:
         assert(false);
   }
}

std::ostream& operator<<(std::ostream& os, std::pair<a_associate_rj::SOURCE, a_associate_rj::REASON> sr)
{
   using rj = a_associate_rj;
   if (sr.first == rj::SOURCE::UL_SERVICE_USER) {
      if (static_cast<int>(sr.second) == 1) {
         return os << "no-reason-given";
      } else if (static_cast<int>(sr.second) == 2) {
         return os << "application-context-name-not-supported";
      } else if (static_cast<int>(sr.second) == 3) {
         return os << "calling-AE-title-not-recognized";
      } else if (static_cast<int>(sr.second) == 7) {
         return os << "called-AE-title-not-recognized";
      } else {
         return os << ""; //reserved
      }
   } else if (sr.first == rj::SOURCE::UL_SERVICE_PROV_ACSE) {
      if (static_cast<int>(sr.second) == 1) {
         return os << "no-reason-given";
      } else if (static_cast<int>(sr.second) == 2) {
         return os << "protocol-version-not-supported";
      } else {
         return os << "";
      }
   } else if (sr.first == rj::SOURCE::UL_SERVICE_PROV_PRESREL) {
      if (static_cast<int>(sr.second) == 1) {
         return os << "temporary-congestion";
      } else if (static_cast<int>(sr.second) == 2) {
         return os << "local-limit-exceeded";
      } else {
         return os << "";
      }
   } else {
      assert(false);
   }
}

}

}

}
