#ifndef INFRASTRUCTURE_CONNECTION_STUB_HPP
#define INFRASTRUCTURE_CONNECTION_STUB_HPP

#include <iostream>
#include <fstream>

#include "../source/infrastructure/asio_tcp_connection.hpp"
#include "../source/infrastructure/asio_tcp_connection_manager.hpp"


/**
 * @brief The infrastrustructure_timer_stub does nothing
 */
class infrastrustructure_timer_stub : public Iinfrastructure_timeout_connection
{
      // Iinfrastructure_timeout_connection interface
   public:
      void cancel() override
      {
      }
      void wait_async() override
      {
      }
};


/**
 * @brief The infrastructure_read_connection_stub reads predefined data and
 *        returns it as canned response -> writing to it does not do anything.
 */
class infrastructure_read_connection_stub : public Iinfrastructure_upperlayer_connection
{
   private:
      std::unique_ptr<std::ifstream> in;
      boost::system::error_code ec;
      const boost::system::error_code success_ec;
      std::size_t error_after_bytecount;

      std::function<void(std::size_t)> write_handler;

   public:
      infrastructure_read_connection_stub():
         in {nullptr},
         ec {},
         success_ec {},
         error_after_bytecount {0},
         write_handler {nullptr}
      {
      }

      void set_write_handler(decltype(write_handler) on_write)
      {
         write_handler = on_write;
      }

      void set_next_segment(std::string file)
      {
         in = std::unique_ptr<std::ifstream> {new std::ifstream{file, std::ios::binary}};
      }

      void set_error_on_next(boost::system::errc::errc_t error = boost::system::errc::broken_pipe)
      {
         ec.assign(error, boost::system::generic_category());
      }

      void set_error_after_bytecount(std::size_t bytes = 0, boost::system::errc::errc_t error = boost::system::errc::broken_pipe)
      {
         set_error_on_next(error);
         error_after_bytecount = bytes;
      }


      // Iinfrastructure_upperlayer_connection interface
      void write_data(std::shared_ptr<std::vector<unsigned char>> buffer,
                      std::function<void(const boost::system::error_code&, std::size_t)> on_complete) override
      {
         if (write_handler) {
            write_handler(buffer->size());
         }
         if (error_after_bytecount == 0) {
            on_complete(ec, buffer->size());
         } else {
            if (buffer->size() <= error_after_bytecount) {
               on_complete(success_ec, buffer->size());
            } else {
               on_complete(ec, error_after_bytecount);
            }
         }
         set_error_on_next(boost::system::errc::success);
      }

      void write_data(void*, std::size_t len,
                      std::function<void (const boost::system::error_code&, std::size_t)> on_complete) override
      {
         if (write_handler) {
            write_handler(len);
         }
         if (error_after_bytecount == 0) {
            on_complete(ec, len);
         } else {
            if (len <= error_after_bytecount) {
               on_complete(success_ec, len);
            } else {
               on_complete(ec, error_after_bytecount);
            }
         }
         set_error_on_next(boost::system::errc::success);
      }

      void read_data(std::shared_ptr<std::vector<unsigned char>> buffer,
                     std::size_t len, std::function<void(const boost::system::error_code&, std::size_t)> on_complete) override
      {
         std::istreambuf_iterator<char> instream {*in};
         std::copy_n(instream, len, std::begin(*buffer));
         std::advance(instream, 1);

         if (error_after_bytecount == 0) {
            on_complete(ec, len);
         } else {
            if (len <= error_after_bytecount) {
               on_complete(success_ec, len);
            } else {
               on_complete(ec, error_after_bytecount);
            }
         }
         set_error_on_next(boost::system::errc::success);
      }

      void read_data(std::shared_ptr<std::vector<unsigned char>> buffer,
                     std::function<void (const boost::system::error_code&, std::size_t)> on_complete) override
      {
         auto size = buffer->size();
         std::istreambuf_iterator<char> instream {*in};
         //std::copy(instream, std::istreambuf_iterator<char>(), std::begin(*buffer));
         std::copy_n(instream, size, std::begin(*buffer));
         std::advance(instream, 1);

         if (error_after_bytecount == 0) {
            on_complete(ec, size);
         } else {
            if (buffer->size() <= error_after_bytecount) {
               on_complete(success_ec, buffer->size());
            } else {
               on_complete(ec, error_after_bytecount);
            }
         }
         set_error_on_next(boost::system::errc::success);
      }

      std::unique_ptr<Iinfrastructure_timeout_connection> timeout_timer(std::chrono::duration<int>, std::function<void ()>) override
      {
         return std::unique_ptr<Iinfrastructure_timeout_connection> {new infrastrustructure_timer_stub{}};
      }

      bool is_stopped() const override
      {
         return false;
      }

      void close() override
      {

      }
};



#endif // INFRASTRUCTURE_CONNECTION_STUB_HPP
