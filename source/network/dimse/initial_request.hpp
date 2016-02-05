#ifndef INITIAL_REQUEST_HPP
#define INITIAL_REQUEST_HPP

#include <string>
#include <vector>
#include <initializer_list>

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
      initial_request(std::string calling_ae,
                      std::string called_ae,
                      std::initializer_list<std::pair<SOP_class_request, std::vector<std::string>>> pcs);

      /**
       * @brief get_SOP_class returns the SOP_class_request instance with the
       *        given presentation context id.
       * @param pc_id presentation context id
       * @return SOP_class_request instance corresponding to the PC id
       */
      SOP_class_request get_SOP_class(int pc_id) const;

      /**
       * @brief get_initial_request generates a a_associate_rq property
       * @return a_associate_rq property
       */
      upperlayer::a_associate_rq get_initial_request() const;

   private:
      upperlayer::a_associate_rq request;
      std::vector<SOP_class_request> supported_sops;
};

}

}

}

#endif // INITIAL_REQUEST_HPP
