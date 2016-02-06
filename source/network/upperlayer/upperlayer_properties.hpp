#ifndef UPPERLAYER_CONNECTION_PROPERTIES_HPP
#define UPPERLAYER_CONNECTION_PROPERTIES_HPP

#include <vector>
#include <string>
#include <memory>

namespace dicom
{

namespace network
{

namespace upperlayer
{

enum class TYPE : unsigned char
{
   A_ASSOCIATE_RQ = 0x01,
   A_ASSOCIATE_AC = 0x02,
   A_ASSOCIATE_RJ = 0x03,
   P_DATA_TF = 0x04,
   A_RELEASE_RQ = 0x05,
   A_RELEASE_RP = 0x06,
   A_ABORT = 0x07
};

TYPE get_type(const std::vector<unsigned char>& pdu);


/**
 * @brief The property struct or rather its subclasses represent the serial pdu data
 *        in a structured form, so information contained in these pdus can be accessed
 *        easily.
 */
struct property
{
      virtual void from_pdu(std::vector<unsigned char> pdu) = 0;
      virtual std::vector<unsigned char> make_pdu() const = 0;
      virtual TYPE type() const = 0;
      virtual ~property() = 0;
};

/**
 * @brief make_property is a factory function which creates structured data
 *        depending on the type of pdu passed to it
 * @param[in] pdu
 * @return unique_ptr to the structured data
 */
std::unique_ptr<property> make_property(const std::vector<unsigned char>& pdu);



struct p_data_tf: property
{
      p_data_tf() = default;
      void from_pdu(std::vector<unsigned char> pdu) override;
      std::vector<unsigned char> make_pdu() const override;
      TYPE type() const override;

      unsigned char pres_context_id;
      std::vector<unsigned char> command_set;
      std::vector<unsigned char> data_set;
};

/**
 * @brief The upperlayer_connection_property struct contains information about
 *        the offered / negotiated association with the remote application
 *        entity.
 *
 * @see DICOM3 standard, 3.8 .9.3
 */
struct a_associate_rq: property
{
      a_associate_rq() = default;
      void from_pdu(std::vector<unsigned char> pdu) override;
      std::vector<unsigned char> make_pdu() const override;
      TYPE type() const override;


      std::string called_ae;
      std::string calling_ae;
      std::string application_context;

      struct presentation_context
      {
            presentation_context() = default;
            unsigned char id;
            std::string abstract_syntax;
            std::vector<std::string> transfer_syntaxes;
      };

      std::vector<presentation_context> pres_contexts;
      std::size_t max_message_length;
};

struct a_associate_ac: property
{
      a_associate_ac() = default;
      void from_pdu(std::vector<unsigned char> pdu) override;
      std::vector<unsigned char> make_pdu() const override;
      TYPE type() const override;


      std::string called_ae;
      std::string calling_ae;
      std::string application_context;

      struct presentation_context
      {
            enum class RESULT
            {
               ACCEPTANCE = 0x00, USER_REJEC = 0x01,
               PROV_REJEC_NO_REASON = 0x02,
               ABSTR_CONT_NOT_SUPP = 0x03,
               TRANSF_SYNT_NOT_SUPP = 0x04
            };

            presentation_context() = default;
            unsigned char id;
            RESULT result_;
            std::string transfer_syntax;
      };

      std::vector<presentation_context> pres_contexts;
      std::size_t max_message_length;
};

struct a_associate_rj: property
{
      a_associate_rj() = default;
      void from_pdu(std::vector<unsigned char> pdu) override;
      std::vector<unsigned char> make_pdu() const override;
      TYPE type() const override;

      enum class SOURCE : unsigned char
      {
         UL_SERVICE_USER = 0x01, UL_SERVICE_PROV_ACSE = 0x02,
         UL_SERVICE_PROV_PRESREL = 0x03
      };
      enum class REASON : unsigned char
      {
         NOT_SPECIFIED = 0x01, APPL_CONT_NOT_SUPP = 0x02, CALLING_AE_NOT_RECOG = 0x03,
         CALLED_AE_NOT_RECOG = 0x07
      };

      REASON reason_;
      SOURCE source_;
};

struct a_release_rq: property
{
      a_release_rq() = default;
      void from_pdu(std::vector<unsigned char> pdu) override;
      std::vector<unsigned char> make_pdu() const override;
      TYPE type() const override;
};

struct a_release_rp: property
{
      a_release_rp() = default;
      void from_pdu(std::vector<unsigned char> pdu) override;
      std::vector<unsigned char> make_pdu() const override;
      TYPE type() const override;
};

struct a_abort: property
{
      a_abort() = default;
      void from_pdu(std::vector<unsigned char> pdu) override;
      std::vector<unsigned char> make_pdu() const override;
      TYPE type() const override;

      enum class SOURCE : unsigned char
      {
         UL_SERVICE_USER = 0x01,
         UL_SERVICE_PROV = 0x03
      };
      enum class REASON : unsigned char
      {
         NOT_SPECIFIED = 0x00, UNRECOG_PDU = 0x01,
         UNEXPEC_PDU = 0x02,
         UNRECOG_PDU_PARAM = 0x04,
         UNEXPEC_PDU_PARAM = 0x05,
         INVALID_PDU_PARAM = 0x06
      };

      SOURCE source_;
      REASON reason_;
};

std::ostream& operator<<(std::ostream& os, a_associate_rq t);

}

}

}

#endif // DICOM_UPPERLAYER_CONNECTION_PROPERTIES_HPP
