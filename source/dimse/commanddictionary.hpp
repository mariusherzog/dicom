#ifndef COMMANDDIC_TEMPLATE_HPP
#define COMMANDDIC_TEMPLATE_HPP

#include <string>
#include "iod.hpp"

struct commanddictionary_type 
{
   protected:
      commanddictionary_type(VR vr, std::string mf, std::string kw, std::string vm):
         vr {vr}, message_field {mf}, keyword {kw}, vm {vm}
      {

      }

   public:
      const VR vr;
      const std::string message_field;
      const std::string keyword;
      const std::string vm;
};

template<unsigned gid, unsigned eid>
struct commanddictionary;

template<>
struct commanddictionary<0x0000, 0x0000>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::UL, "Command Group Length", "CommandGroupLength", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x0002>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::UI, "Affected SOP Class UID", "AffectedSOPClassUID", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x0003>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::UI, "Requested SOP Class UID", "RequestedSOPClassUID", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x0100>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::US, "Command Field", "CommandField", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x0110>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::US, "Message ID", "MessageID", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x0120>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::US, "Message ID Being Responded To", "MessageIDBeingRespondedTo", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x0600>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::AE, "Move Destination", "MoveDestination", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x0700>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::US, "Priority", "Priority", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x0800>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::US, "Command Data Set Type", "CommandDataSetType", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x0900>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::US, "Status", "Status", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x0901>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::AT, "Offending Element", "OffendingElement", "1-n") {}
};
template<>
struct commanddictionary<0x0000, 0x0902>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::LO, "Error Comment", "ErrorComment", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x0903>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::US, "Error ID", "ErrorID", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x1000>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::UI, "Affected SOP Instance UID", "AffectedSOPInstanceUID", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x1001>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::UI, "Requested SOP Instance UID", "RequestedSOPInstanceUID", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x1002>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::US, "Event Type ID", "EventTypeID", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x1005>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::AT, "Attribute Identifier List", "AttributeIdentifierList", "1-n") {}
};
template<>
struct commanddictionary<0x0000, 0x1008>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::US, "Action Type ID", "ActionTypeID", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x1020>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::US, "Number of Remaining Sub-operations", "NumberOfRemainingSuboperations", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x1021>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::US, "Number of Completed Sub-operations", "NumberOfCompletedSuboperations", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x1022>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::US, "Number of Failed Sub-operations", "NumberOfFailedSuboperations", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x1023>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::US, "Number of Warning Sub-operations", "NumberOfWarningSuboperations", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x1030>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::AE, "Move Originator Application Entity Title", "MoveOriginatorApplicationEntityTitle", "1") {}
};
template<>
struct commanddictionary<0x0000, 0x1031>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::US, "Move Originator Message ID", "MoveOriginatorMessageID", "1") {}
};

#endif
