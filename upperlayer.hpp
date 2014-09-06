#ifndef DICOM_UPPERLAYER_HPP
#define DICOM_UPPERLAYER_HPP

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <functional>
#include <initializer_list>
#include <utility>

#include <boost/asio.hpp>

#include "upperlayer_properties.hpp"


class session
{
};

/**
 * The upperlayer namespace contains classes and functions which implement the upperlayer as
 * described in the DICOM standard chapter 8.
 * @link http://medical.nema.org/Dicom/2011/11_08pu.pdf
 */
namespace upperlayer
{


/**
 * @brief The scx class implements basic functionality used both by the specialed scp and scu
 *        subclasses, like reading and writing to the connected peer. It also manages the
 *        state machine
 * @todo -refactor state machine from class
 *       -extend state machine by release collision states and transitions <BR>
 *       -ARTIM timer <BR>
 *       -
 *
 * upperlayer::scx provides send() and read() functions independetly if the
 * subclass for clients (scu) or servers (scp) is used.
 * It must be noted that the sole responsibility of the upperlayer::scx is to
 * keep the state machine valid. It is not involved in the association
 * negotiation. This has to be done by the user of this class (either a facade
 * or the DIMSE_PM).
 */
class scx
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


      explicit scx(std::initializer_list<std::pair<TYPE, std::function<void(scx*, std::unique_ptr<property>)>>> l);
      virtual ~scx() = 0;

      /**
       * @brief sock is used by send() and receive() to access the socket of the
       *        subclasses
       * @return ref to boost::asio::ip::tcp::socket of the subclass
       *
       * for initalization reasons the socket cannot be declared in this abstract
       * class.
       */
      virtual boost::asio::ip::tcp::socket& sock() = 0;

      /**
       * @brief sock is used by the subclasses to use the ::run() member function
       * @return ref to boost::asio::io_service
       *
       * for initalization reasons the socket cannot be declared in this abstract
       * class.
       */
      virtual boost::asio::io_service& io_s() = 0;

      /**
       * @brief send takes a property and uses its property::make_pdu() function
       *        for serialization. The serialized data is sent to the peer via
       *        the socket.
       * @param[in] p
       */
      void send(property* p);

      /**
       * @brief run blocks until asynchronous operations are completed
       */
      void run();

      /**
       * @brief get_state returns the current state
       * @return
       */
      CONN_STATE get_state();


      /**
       * @brief inject sets a handler for a received property type t.
       * @param[in] t
       * @param[in] f
       */
      void inject(TYPE t, std::function<void(scx*, std::unique_ptr<property>)> f);

      /**
       * @brief scx::do_read reads a pdu asynchronously from the peer
       *
       * The pdu is received in two steps:
       * The first async_read is passed a handler which is called when
       * exactly six bytes are received. These first six bytes contain
       * the size of the pdu _len_.
       * Then, in this first read-handler, another async_read is
       * dispatched which calls its read-handler when exactly _len_
       * bytes (ie the whole pdu) are received. This second read-handler
       * contains the code which actually processes the pdu (calls the
       * appropriate handler, manages state transitions, ...)
       */
      void do_read();

   private:
      CONN_STATE state;
      std::map<TYPE, std::function<void(scx*, std::unique_ptr<property>)>> handlers;
};

/**
 * @brief The scp class acts as a service class provider
 */
class scp: public scx
{
   public:
      scp(short port, std::initializer_list<std::pair<TYPE, std::function<void(scx*, std::unique_ptr<property>)>>> l);
      ~scp() override;
      boost::asio::ip::tcp::socket& sock() override;
      boost::asio::io_service& io_s() override;

   private:
      std::shared_ptr<session> sess;

      boost::asio::io_service io_service;
      boost::asio::ip::tcp::socket socket;
      boost::asio::ip::tcp::acceptor acptr;
};

/**
 * @brief The scu class acts as a service class user
 */
class scu: public scx
{
   public:
      scu(std::string host, std::string port, std::initializer_list<std::pair<TYPE, std::function<void(scx*, std::unique_ptr<property>)>>> l);
      ~scu() override;
      boost::asio::ip::tcp::socket& sock() override;
      boost::asio::io_service&io_s() override;

   private:
      boost::asio::io_service io_service;
      boost::asio::ip::tcp::resolver resolver;
      boost::asio::ip::tcp::resolver::query query;
      boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
      boost::asio::ip::tcp::socket socket;
};



}

#endif // DICOMUPPERLAYER_HPP
