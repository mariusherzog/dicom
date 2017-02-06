#ifndef DICOM_UPPERLAYER_HPP
#define DICOM_UPPERLAYER_HPP

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <functional>
#include <initializer_list>
#include <utility>
#include <deque>

#include <boost/optional.hpp>
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/log/trivial.hpp>

#include "upperlayer_properties.hpp"
#include "upperlayer_statemachine.hpp"

#include "data/dataset/transfer_processor.hpp"

#include "util/channel_sev_logger.hpp"


/**
 * The dicom namespace is the global namespace of the project, containing all
 * DICOM related implementations.
 */
namespace dicom
{

/**
 * The network namespace contains all DICOM network-related functionality, like
 * the implementation of the upperlayer or the dimse protocol machine.
 */
namespace network
{

/**
 * The upperlayer namespace contains classes and functions which implement the upperlayer as
 * described in the DICOM standard chapter 8.
 * @link http://medical.nema.org/Dicom/2011/11_08pu.pdf
 */
namespace upperlayer
{

class scx;

/**
 * @brief The Istate_trans_ops struct is an interface which the statemachine class uses to
 *        perform certain operations, like resetting the ARTIM timer or sending an a_abort
 */
struct Istate_trans_ops
{
      virtual void reset_artim() = 0;
      virtual void stop_artim() = 0;
      virtual void start_artim() = 0;
      virtual void ignore_next() = 0;
      virtual void queue_for_write_w_prio(std::unique_ptr<property> p) = 0;
      virtual void close_connection() = 0;
      virtual ~Istate_trans_ops() = 0;
};

/**
 * @brief The Iupperlayer_comm_ops struct is an interface used for writing properties and
 *        injecting handlers for received properties
 */
struct Iupperlayer_comm_ops
{
      virtual void queue_for_write(std::unique_ptr<property> p) = 0;
      virtual void inject(TYPE t, std::function<void(scx*, std::unique_ptr<property>)> f) = 0;
      virtual void inject_conf(TYPE t, std::function<void(scx*, property* f)>) = 0;
      virtual ~Iupperlayer_comm_ops() = 0;
};

/**
 * @brief The Iupperlayer_connection_handlers struct defines an interface to inject callbacks
 *        for the start / termination of a connection.
 */
struct Iupperlayer_connection_handlers
{
      virtual void new_connection(std::function<void(Iupperlayer_comm_ops*)> f) = 0;
      virtual void end_connection(std::function<void(Iupperlayer_comm_ops*)> f) = 0;
      virtual ~Iupperlayer_connection_handlers() = 0;
};



/**
 * @brief The scx class implements basic functionality used both by the specialed scp and scu
 *        subclasses, like reading and writing to the connected peer. It also manages the
 *        state machine
 * @todo  write reconnect() method using unique_ptr<socket>
 *        inherit from a service class interface
 *
 * upperlayer::scx provides send() and read() functions independetly if the
 * subclass for clients (scu) or servers (scp) is used.
 * It must be noted that the sole responsibility of the upperlayer::scx is to
 * keep the state machine valid. It is not involved in the association
 * negotiation. This has to be done by the user of this class (either a facade
 * or the DIMSE_PM).
 */
class scx: public Istate_trans_ops, public Iupperlayer_comm_ops
{
   public:

      explicit scx(data::dictionary::dictionary& dict,
                   std::vector<std::pair<TYPE, std::function<void(scx*, std::unique_ptr<property>)>>> l);
      scx(const scx&) = delete;
      scx& operator=(const scx&) = delete;
      virtual ~scx() = 0;

      /**
       * @brief run blocks until asynchronous operations are completed
       */
      void run();

      /**
       * @brief get_state returns the current state
       * @return
       * @callgraph
       */
      statemachine::CONN_STATE get_state();


      /**
       * @brief inject sets a handler for a received property type t.
       * @param[in] t
       * @param[in] f
       */
      void inject(TYPE t, std::function<void(scx*, std::unique_ptr<property>)> f) override;

      /**
       * @brief inject_conf sets a handler for a sent property type t.
       * @param[in] t
       * @param[in] f
       */
      void inject_conf(TYPE t, std::function<void(scx*, property*)> f) override;

      /**
       * @brief queue_for_write takes ownership of a property and queues it for
       *        writing
       * @param[in] p
       *
       * A write queue is necessary to prevent multiple writes to the socket, which
       * may result in interleaving
       */
      void queue_for_write(std::unique_ptr<property> p) override;

      /**
       * @brief queue_for_write_w_prio queues a property for writing, but moves it
       *        in the front of the queue so it will be retrieved first
       * @param[in] p
       * @see queue_for_write();
       */
      void queue_for_write_w_prio(std::unique_ptr<property> p) override;

      /**
       * @brief reset_artim resets the artim timer
       */
      void reset_artim() override;

      /**
       * @brief stop_artim stops the artim timer
       */
      void stop_artim() override;

      /**
       * @brief start_artim starts the artim timer
       */
      void start_artim() override;

      /**
       * @brief ignore_next indicates whether a received pdu shall be ignored by
       *        not invoking the respective handler
       */
      void ignore_next() override;

      /**
       * @brief close_connection aborts all async operations on the io_service object,
       *        making io_service::run() terminate
       */
      void close_connection() override;


   protected:
      statemachine statem;

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

      /**
       * @brief artim_expired is called when the artim timer expires
       * @param[in] error
       */
      void artim_expired(const boost::system::error_code& error);

      std::map<TYPE, std::function<void(scx*, property*)>> handlers_conf;

      dicom::util::log::channel_sev_logger logger;

   private:
      /**
       * @brief send takes a property and uses its property::make_pdu() function
       *        for serialization. The serialized data is sent to the peer via
       *        the socket.
       * @param[in] p
       */
      void send(property* p);

      /**
       * @brief handle_pdu calls the pdu-type specific handler
       * @param p property containing data
       * @param ptype type of the pdu / property
       */
      void handle_pdu(std::unique_ptr<property> p, TYPE ptype);

      /**
       * @brief handle_pdu_conf
       * @param p
       * @param ptype
       */
      void handle_pdu_conf(property* p, TYPE ptype);

      /**
       * @brief get_complete_dataset reads the complete dataset and stores it
       *        in the property's dataset member.
       * @param[in] data
       */
      void get_complete_dataset(std::vector<unsigned char> data);


      /**
       * @brief write_complete_dataset write the complete dataset to the peer
       * @param p property being written (stored in the write queue)
       * @param data serialized property being written
       */
      void write_complete_dataset(property* p, std::vector<unsigned char> data);

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
       * @brief artim_timer returns a reference to the artim timer
       * @return ref to boost::asio::steady_timer
       */
      virtual boost::asio::steady_timer& artim_timer() = 0;

      data::dataset::commandset_processor proc;

      std::deque<std::unique_ptr<property>> send_queue;
      boost::optional<std::vector<unsigned char>*> received_pdu;
      std::map<TYPE, std::function<void(scx*, std::unique_ptr<property>)>> handlers;

   protected:
      std::function<void(Iupperlayer_comm_ops*)> handler_new_connection;
      std::function<void(Iupperlayer_comm_ops*)> handler_end_connection;
};

class scp_connection: public scx
{
   public:
      scp_connection(boost::asio::io_service& io_service,
          boost::asio::ip::tcp::socket& socket,
          data::dictionary::dictionary& dict,
          short port,
          std::function<void(Iupperlayer_comm_ops*)> handler_new_conn,
          std::function<void(Iupperlayer_comm_ops*)> handler_end_conn,
          std::vector<std::pair<TYPE, std::function<void(scx*, std::unique_ptr<property>)>>> l);
      scp_connection(const scp_connection&) = delete;
      scp_connection& operator=(const scp_connection&) = delete;

   private:
      boost::asio::ip::tcp::socket& sock() override;
      boost::asio::io_service& io_s() override;
      boost::asio::steady_timer& artim_timer() override;

      boost::asio::io_service& io_service;
      boost::asio::ip::tcp::socket& socket;
      boost::asio::steady_timer artim;
};

/**
 * @brief The scp class acts as a service class provider
 */
class scp: public Iupperlayer_connection_handlers
{
   public:
      scp(data::dictionary::dictionary& dict,
          short port);
      scp(const scp&) = delete;
      scp& operator=(const scp&) = delete;

      ~scp();

      void run();

      virtual void new_connection(std::function<void(Iupperlayer_comm_ops*)> handler) override;
      virtual void end_connection(std::function<void(Iupperlayer_comm_ops*)> handler) override;

   private:

      void accept_new(boost::asio::ip::tcp::socket*, boost::system::error_code);

      std::function<void(Iupperlayer_comm_ops*)> handler_new_connection;
      std::function<void(Iupperlayer_comm_ops*)> handler_end_connection;

      std::vector<std::unique_ptr<scp_connection>> connections;
      boost::asio::io_service io_service;
      boost::asio::ip::tcp::acceptor acptr;
      short port;
      data::dictionary::dictionary& dict;

      std::vector<std::shared_ptr<boost::asio::ip::tcp::socket>> sockets;
};


/**
 * @brief The scu class acts as a service class user
 *
 *
 */
class scu: public scx
{
   public:
      scu(data::dictionary::dictionary& dict,
          std::string host, std::string port,
          a_associate_rq& rq,
          std::vector<std::pair<TYPE, std::function<void(scx*, std::unique_ptr<property>)>>> l);
      scu(const scu&) = delete;
      scu& operator=(const scu&) = delete;

   private:
      boost::asio::ip::tcp::socket& sock() override;
      boost::asio::io_service& io_s() override;
      boost::asio::steady_timer& artim_timer() override;

      boost::asio::io_service io_service;
      boost::asio::ip::tcp::resolver resolver;
      boost::asio::ip::tcp::resolver::query query;
      boost::asio::ip::tcp::resolver::iterator endpoint_iterator;
      boost::asio::ip::tcp::socket socket;
      boost::asio::steady_timer artim;
};

}

}

}

#endif // DICOMUPPERLAYER_HPP
