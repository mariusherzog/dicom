#ifndef INITIAL_REQUEST_HPP
#define INITIAL_REQUEST_HPP

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
class initial_request
{
   public:
      enum class DIMSE_MSG_TYPE
      {
         INITIATOR, RESPONSE
      };

      initial_request(std::string calling_ae,
                      std::string called_ae,
                      std::initializer_list<std::tuple<
                        SOP_class,
                        std::vector<std::string>,
                        DIMSE_MSG_TYPE
                      >> pcs);

      /**
       * @brief get_SOP_class returns the SOP_class_request instance with the
       *        given abstract syntax / SOP UID
       * @param abstract_syntax
       * @return SOP class tuple instance corresponding to the abstract syntax
       */
      std::vector<std::tuple<SOP_class, std::vector<std::string>, DIMSE_MSG_TYPE>>
         get_SOP_class(std::string abstract_syntax) const;

      /**
       * @brief get_all_SOP returns all SOP classes of the operation
       * @return all SOP classes contained in this operation
       */
      std::vector<std::tuple<SOP_class, std::vector<std::string>, DIMSE_MSG_TYPE>>
         get_all_SOP() const;

      /**
       * @brief get_initial_request generates a a_associate_rq property
       * @return a_associate_rq property
       */
      upperlayer::a_associate_rq get_initial_request() const;

   private:
      upperlayer::a_associate_rq request;
      std::vector<std::tuple<SOP_class, std::vector<std::string>, DIMSE_MSG_TYPE>> supported_sops;
};

}

}

}

#endif // INITIAL_REQUEST_HPP
