#ifndef DICOM_UPPERLAYER_HPP
#define DICOM_UPPERLAYER_HPP

#include <string>
#include <vector>
#include <memory>

#include <boost/asio.hpp>

#include "upperlayer_properties.hpp"




/**
 * @brief The dicom_upperlayer class implements the Upper Layer as described
 *        in the DICOM3 standard, part 8.
 * @link http://medical.nema.org/Dicom/2011/11_08pu.pdf
 * @todo -currently only as a SCP <BR>
 *       -extend state machine by release collision states and transitions <BR>
 *       -ARTIM timer <BR>
 *       -
 *
 * It must be noted that the sole responsibility of the upperlayer-scp is to
 * keep the state machine valid. It is not involved in the association
 * negotiation. This has to be done by the user of this class (either a facade
 * or the DIMSE_PM).
 */
class scp
{
   public:
      /**
       * @brief The CONN_STATE enum contains the states for the state machine
       * @see DICOM3 standard table 9-10
       */
      enum class CONN_STATE
      {
         INV = 0x00,
         STA1,
         STA2,
         STA3,
         STA5,
         STA6,
         STA7,
         STA8,
         STA9,
         STA10,
         STA11,
         STA12,
         STA13
      };


      explicit scp(short port);
      ~scp();

      void send(property* p);
      std::unique_ptr<property> receive();



   private:
      CONN_STATE state;

      boost::asio::io_service io_service;
      boost::asio::ip::tcp::acceptor acptr;
      boost::asio::ip::tcp::socket sock;
};


#endif // DICOMUPPERLAYER_HPP
