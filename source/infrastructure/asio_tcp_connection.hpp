#ifndef ASIO_TCP_CONNECTION_HPP
#define ASIO_TCP_CONNECTION_HPP

#include <boost/optional.hpp>
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/log/trivial.hpp>

#include <functional>
#include <memory>
#include <chrono>

//struct Iinfrastructure_upperlayer_connection;

/**
 * @brief The Iinfrastructure_timeout_connection interface
 */
struct Iinfrastructure_timeout_connection
{
        /**
         * @brief cancel cancels the timer
         */
        virtual void cancel() = 0;

        /**
         * @brief wait_async starts the timer asynchronously
         */
        virtual void wait_async() = 0;

        virtual ~Iinfrastructure_timeout_connection() = 0;
};

/**
 * @brief The timeout_connection class encapsulates a timer functionality
 * for a boost asio tcp connection
 */
class timeout_connection : public Iinfrastructure_timeout_connection
{
   public:
      timeout_connection(boost::asio::io_service& io_svc,
                         std::chrono::duration<int> timeout,
                         std::function<void()> on_timeout);

      void cancel();
      void wait_async();

   private:
      std::function<void()> on_timeout;
      std::shared_ptr<boost::asio::steady_timer> timer;
};

/**
 * @brief The Iinfrastructure_upperlayer_connection interface encapsulates
 * the functionality to acquire data from a given source.
 *
 * Usually this is a network connection of whatever nature (encrypted / plain)
 * but may be used to read from a file to facilitate testing, for example.
 */
struct Iinfrastructure_upperlayer_connection
{
        /**
         * @brief write_data writes data from the buffer and invokes the given
         *        handler upon completion
         * @param buffer data to be written
         * @param on_complete handler when data has been written
         */
        virtual void write_data(std::shared_ptr<std::vector<unsigned char>> buffer,
                        std::function<void(const boost::system::error_code&, std::size_t)> on_complete) = 0;

        /**
         * @brief write_data writes data from a preallocated buffer in a given
         *        range and invokes the completion handler when finished
         * @param data_offset pointer to the beginning of the buffer
         * @param len amount of bytes to be written
         * @param on_complete completion handler when data has been written
         */
        virtual void write_data(void* data_offset, std::size_t len,
                        std::function<void (const boost::system::error_code&, std::size_t)> on_complete) = 0;

        /**
         * @brief read_data read a certain amount of bytes and store it in the given buffer.
         * @param buffer buffer to store the read data in
         * @param len amount of data to read in bytes
         * @param on_complete completion handler when data has been read
         * An implementation of this function may perform the read asynchronously, the invoker
         * has the responsibility that the buffer is valid when the read is performed.
         */
        virtual void read_data(std::shared_ptr<std::vector<unsigned char>> buffer, std::size_t len,
                       std::function<void(const boost::system::error_code&, std::size_t)> on_complete) = 0;

        /**
         * @brief read_data reads data until eof and stores it in the given buffer.
         * @param buffer buffer to store the read data in
         * @param on_complete completion handler when data has been read
         * An implementation of this function may perform the read asynchronously, the invoker
         * has the responsibility that the buffer is valid when the read is performed.
         */
        virtual void read_data(std::shared_ptr<std::vector<unsigned char>> buffer,
                       std::function<void(const boost::system::error_code&, std::size_t)> on_complete) = 0;

        /**
         * @brief timeout_timer is used by a client to acquire and control a timeout
         *        timer from the connection.
         * @param timeout timeout in seconds
         * @param on_timeout handler to be called when the timeout fires
         * @return newly created timer associated to the connection
         */
        virtual std::unique_ptr<Iinfrastructure_timeout_connection> timeout_timer(
                                         std::chrono::duration<int> timeout,
                                         std::function<void()> on_timeout) = 0;

        /**
         * @brief is_stopped is used to check whether the connection is alive
         * @return true if connection is closed, false otherwise
         */
        virtual bool is_stopped() const = 0;

        /**
         * @brief close close the connection
         */
        virtual void close() = 0;

        virtual ~Iinfrastructure_upperlayer_connection() = 0;
};

/**
 * @brief The asio_tcp_connection class encapsulates functionality to
 * communicate over a TCP socket using boost asio.
 */
class asio_tcp_connection : public Iinfrastructure_upperlayer_connection
{
   public:
      asio_tcp_connection(boost::asio::io_service& io_svc,
                          std::shared_ptr<boost::asio::ip::tcp::socket> sock,
                          std::function<void(asio_tcp_connection*)> on_end_connection);

      void write_data(std::shared_ptr<std::vector<unsigned char>> buffer,
                      std::function<void(const boost::system::error_code&, std::size_t)> on_complete) override;

      void write_data(void* data_offset, std::size_t len,
                      std::function<void (const boost::system::error_code&, std::size_t)> on_complete) override;

      void read_data(std::shared_ptr<std::vector<unsigned char>> buffer, std::size_t len,
                     std::function<void(const boost::system::error_code&, std::size_t)> on_complete) override;

      void read_data(std::shared_ptr<std::vector<unsigned char>> buffer,
                     std::function<void(const boost::system::error_code&, std::size_t)> on_complete) override;

      std::unique_ptr<Iinfrastructure_timeout_connection> timeout_timer(
              std::chrono::duration<int> timeout,
              std::function<void()> on_timeout) override;

      bool is_stopped() const override
      {
         return io_s.stopped();
      }

      void close() override;

    private:
      boost::asio::io_service& io_s;
      std::shared_ptr<boost::asio::ip::tcp::socket> socket;

      std::function<void(asio_tcp_connection*)> handler_end_connection;
};

#endif // ASIO_TCP_CONNECTION_HPP
