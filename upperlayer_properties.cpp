#include "upperlayer_properties.hpp"

#include <algorithm>
#include <ostream>
#include <vector>
#include <string>
#include <cassert>



namespace { using uchar = unsigned char; }

namespace
{
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



TYPE get_type(std::vector<unsigned char> pdu)
{
   return static_cast<TYPE>(pdu[0]);
}


property::~property()
{
}


void p_data_tf::from_pdu(std::vector<unsigned char> pdu)
{
   std::size_t pdu_len = be_char_to_32b({pdu.begin()+2, pdu.begin()+6});

   std::size_t pos = 6;
   bool pdvs_left = true;
   while (pdvs_left) {
      std::size_t pdv_len = be_char_to_32b({pdu.begin()+pos, pdu.begin()+pos+4});
      pos += 4;
      message_id = pdu[pos];

      unsigned char msg_control = pdu[pos+1];

      pos += 2;
      if (msg_control & 0x01) {
         command_set.insert(command_set.end(), pdu.begin()+pos, pdu.begin()+pos+pdv_len-2);
      } else {
         data_set.insert(data_set.end(), pdu.begin()+pos, pdu.begin()+pos+pdv_len-2);
      }

      pdvs_left = !(msg_control & 0x02);
      pos += pdv_len;
   }
}

std::vector<uchar> p_data_tf::make_pdu()
{
   std::vector<uchar> pack;
   pack.push_back(static_cast<uchar>(TYPE::P_DATA_TF));
   pack.insert(pack.end(), {0x00, 0x00, 0x00, 0x00, 0x00});
   std::size_t len_pos = 0x02;

   {
      // insert command part
      // one extra byte each for message id and message header
      std::vector<uchar> pdv_len = ui_to_32b_be(command_set.size()+2);
      pack.insert(pack.end(), pdv_len.begin(), pdv_len.end());
      pack.push_back(message_id);
      pack.push_back(0x01);
      pack.insert(pack.end(), command_set.begin(), command_set.end());

      pdv_len = ui_to_32b_be(data_set.size()+2);
      pack.insert(pack.end(), pdv_len.begin(), pdv_len.end());
      pack.push_back(message_id);
      pack.push_back(0x02);
      pack.insert(pack.end(), data_set.begin(), data_set.end());
   }

   std::size_t pdu_len = pack.size()-6;
   std::vector<uchar> plen = ui_to_32b_be(pdu_len);
   std::copy(plen.begin(), plen.end(), pack.begin()+len_pos);

   return pack;
}

TYPE p_data_tf::type()
{
   return TYPE::P_DATA_TF;
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
std::vector<uchar> a_associate_rq::make_pdu()
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
         pcl += pc.abstract_syntax.size(); // size of underlying type?
         for (const auto ts : pc.transfer_syntaxes) {
            pcl += ts.size();
         }

         std::vector<uchar> pc_len = ui_to_16b_be(pcl +4); // 4 bytes padding
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
         std::vector<uchar> mli_len = ui_to_16b_be(0x04);
         std::vector<uchar> max_len = ui_to_16b_be(max_message_length);
         pack.insert(pack.end(), mli_len.begin(), mli_len.end());
         pack.insert(pack.end(), max_len.begin(), max_len.end());
      }
   }

   std::size_t pdu_len = pack.size()-6;
   std::vector<uchar> plen = ui_to_32b_be(pdu_len);
   std::copy(plen.begin(), plen.end(), pack.begin()+len_pos);

   return pack;
}


TYPE a_associate_rq::type()
{
   return TYPE::A_ASSOCIATE_RQ;
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
      while (pdu[pos] == 0x20) {
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

std::vector<uchar> a_associate_ac::make_pdu()
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
         pack.insert(pack.end(), {0x20, 0x00});

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
         std::vector<uchar> mli_len = ui_to_16b_be(0x04);
         std::vector<uchar> max_len = ui_to_16b_be(max_message_length);
         pack.insert(pack.end(), mli_len.begin(), mli_len.end());
         pack.insert(pack.end(), max_len.begin(), max_len.end());
      }
   }

   std::size_t pdu_len = pack.size()-6;
   std::vector<uchar> plen = ui_to_32b_be(pdu_len);
   std::copy(plen.begin(), plen.end(), pack.begin()+len_pos);

   return pack;
}

TYPE a_associate_ac::type()
{
   return TYPE::A_ASSOCIATE_AC;
}


void a_associate_rj::from_pdu(std::vector<uchar> pdu)
{
   source_ = static_cast<SOURCE>(pdu[8]);
   reason_ = static_cast<REASON>(pdu[9]);
}

std::vector<uchar> a_associate_rj::make_pdu()
{
   std::vector<uchar> pack;
   pack.push_back(static_cast<uchar>(TYPE::A_ASSOCIATE_RJ));
   pack.insert(pack.end(), {0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x01});
   pack.push_back(static_cast<uchar>(source_));
   pack.push_back(static_cast<uchar>(reason_));
   return pack;
}

TYPE a_associate_rj::type()
{
   return TYPE::A_ASSOCIATE_RJ;
}


void a_release_rq::from_pdu(std::vector<unsigned char> pdu)
{
}

std::vector<uchar> a_release_rq::make_pdu()
{
   std::vector<uchar> pack;
   pack.push_back(static_cast<uchar>(TYPE::A_RELEASE_RQ));
   pack.insert(pack.end(), {0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00});
   return pack;
}

TYPE a_release_rq::type()
{
   return TYPE::A_RELEASE_RQ;
}


void a_release_rp::from_pdu(std::vector<unsigned char> pdu)
{
}

std::vector<uchar> a_release_rp::make_pdu()
{
   std::vector<uchar> pack;
   pack.push_back(static_cast<uchar>(TYPE::A_RELEASE_RP));
   pack.insert(pack.end(), {0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00});
   return pack;
}

TYPE a_release_rp::type()
{
   return TYPE::A_RELEASE_RP;
}


void a_abort::from_pdu(std::vector<unsigned char> pdu)
{
   source_ = static_cast<SOURCE>(pdu[8]);
   reason_ = static_cast<REASON>(pdu[9]);
}

std::vector<uchar> a_abort::make_pdu()
{
   std::vector<uchar> pack;
   pack.push_back(static_cast<uchar>(TYPE::A_ABORT));
   pack.insert(pack.end(), {0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x01});
   pack.push_back(static_cast<uchar>(source_));
   pack.push_back(static_cast<uchar>(reason_));
   return pack;
}

TYPE a_abort::type()
{
   return TYPE::A_ABORT;
}



std::ostream& operator<<(std::ostream& os, a_associate_rq t)
{
   os << "Called Application Entity:\t" << t.called_ae << "\n"
      << "Calling Application Entity:\t" << t.calling_ae << "\n"
      << "Application Context:\t" << t.application_context << "\n"
      << "Proposed presentation contexts:\n";
   for (const auto pc : t.pres_contexts) {
      os << "\tContext id: " << static_cast<unsigned>(pc.id) << "\n";
      os << "\tAbstract Syntax: " << pc.abstract_syntax << "\n";
      for (const auto ts : pc.transfer_syntaxes) {
         os << "\t\tPresentation Context: " << ts << "\n";
      }
   }
   return os;
}
