#ifndef SERVICECLASS_HPP
#define SERVICECLASS_HPP

/**
 * @brief The serviceclass interface contains all common operations performed
 *        with a concrete service class
 */
class Iserviceclass
{
   public:
      virtual ~Iserviceclass() = 0;

      /**
       * @brief run starts listening as scp or initiates contact as scu
       */
      virtual void run() = 0;
};

#endif // SERVICECLASS_HPP
