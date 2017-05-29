#ifndef ASSOCIATION_DEFINITION_HPP
#define ASSOCIATION_DEFINITION_HPP

#include <string>
#include <vector>
#include <initializer_list>
#include <tuple>

#include "response.hpp"
#include "sop_class.hpp"
#include "network/upperlayer/upperlayer_properties.hpp"

namespace dicom
{

namespace network
{

namespace dimse
{


/**
 * @brief The initial_request class is used to notify the dimse pm of the
 *        available presentation contexts.
 */
class association_definition
{
   public:
      /**
       * @brief The DIMSE_MSG_TYPE enum defines the type of the DIMSE message
       *        associated to each presentation context.
       */
      enum class DIMSE_MSG_TYPE
      {
         INITIATOR, RESPONSE
      };

      /**
       * @brief The presentation_context struct represents a presentation
       *        context on the DIMSE level.
       * A presentation context on the DIMSE level consists of the SOP class
       * containing the functionality for each DIMSE Service Group, a list of
       * applicable transfer syntaxes, as well as the DIMSE message type which
       * tells the DIMSE Protocol Machine whether the associated functionality
       * is used to respond to or initiate a request.
       */
      struct presentation_context
      {
            SOP_class sop_class;
            std::vector<std::string> transfer_syntaxes;
            DIMSE_MSG_TYPE msg_type;

            presentation_context(SOP_class SOP,
                                 std::vector<std::string> transfer_syntaxes,
                                 DIMSE_MSG_TYPE msg_type);
      };

      association_definition(std::string calling_ae,
                      std::string called_ae,
                      std::vector<presentation_context> pcs,
                      int max_message_len = 0xfffe,
                      std::string application_context = "1.2.840.10008.3.1.1.1");

      /**
       * @brief get_SOP_class returns the SOP_class_request instance with the
       *        given abstract syntax / SOP UID
       * @param abstract_syntax
       * @return SOP class tuple instance corresponding to the abstract syntax
       */
      std::vector<presentation_context> get_SOP_class(std::string abstract_syntax) const;

      /**
       * @brief get_all_SOP returns all SOP classes of the operation
       * @return all SOP classes contained in this operation
       */
      std::vector<presentation_context> get_all_SOP() const;

      /**
       * @brief get_all_SOP returns a reference to the list of supported
       *        presentation contexts
       * @return reference to the list of supported presentation_contexts
       * This method can be used to add / delete / modify the presentation
       * contexts after initialization
       */
      std::vector<presentation_context>& get_all_SOP();


      /**
       * @brief get_initial_request generates a a_associate_rq property
       * @return a_associate_rq property
       */
      upperlayer::a_associate_rq get_initial_request() const;

   private:
      upperlayer::a_associate_rq request;
      std::vector<presentation_context> supported_sops;
};

/**
 * @brief presentation_context is used to set the same
 *        transfer syntaxes for a set of sop classes
 * @param sop_classes set of sop classes
 * @param transfer_syntaxes transfer syntaxes supported
 * @param msg_type message type, response or initiatiator
 * @return
 */
std::vector<association_definition::presentation_context> make_presentation_contexts(
      std::vector<SOP_class> sop_classes,
      std::initializer_list<std::string> transfer_syntaxes,
      association_definition::DIMSE_MSG_TYPE msg_type);

/**
 * @brief operator + is used to concatenate two lists of presentation contexts
 * @param a list of presentation contexts
 * @param b list of presentation contexts
 * @return concatenated list
 */
std::vector<association_definition::presentation_context> operator+(std::vector<association_definition::presentation_context> a,
                                                                    std::vector<association_definition::presentation_context> b);


}

}

}

#endif // ASSOCIATION_DEFINITION_HPP
