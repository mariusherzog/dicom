#ifndef COMMANDDIC_TEMPLATE_HPP
#define COMMANDDIC_TEMPLATE_HPP

#include "dictionary_entry.hpp"

namespace dicom
{

namespace data
{

namespace dictionary
{

template<unsigned gid, unsigned eid>
struct commanddictionary;

template<>
struct commanddictionary<0x0000, 0x0000>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::UL, "Command Group Length", "CommandGroupLength", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0002>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::UI, "Affected SOP Class UID", "AffectedSOPClassUID", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0003>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::UI, "Requested SOP Class UID", "RequestedSOPClassUID", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0100>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::US, "Command Field", "CommandField", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0110>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::US, "Message ID", "MessageID", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0120>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::US, "Message ID Being Responded To", "MessageIDBeingRespondedTo", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0600>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::AE, "Move Destination", "MoveDestination", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0700>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::US, "Priority", "Priority", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0800>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::US, "Command Data Set Type", "CommandDataSetType", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0900>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::US, "Status", "Status", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0901>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::AT, "Offending Element", "OffendingElement", "1-n", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0902>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::LO, "Error Comment", "ErrorComment", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0903>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::US, "Error ID", "ErrorID", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1000>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::UI, "Affected SOP Instance UID", "AffectedSOPInstanceUID", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1001>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::UI, "Requested SOP Instance UID", "RequestedSOPInstanceUID", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1002>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::US, "Event Type ID", "EventTypeID", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1005>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::AT, "Attribute Identifier List", "AttributeIdentifierList", "1-n", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1008>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::US, "Action Type ID", "ActionTypeID", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1020>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::US, "Number of Remaining Sub-operations", "NumberOfRemainingSuboperations", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1021>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::US, "Number of Completed Sub-operations", "NumberOfCompletedSuboperations", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1022>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::US, "Number of Failed Sub-operations", "NumberOfFailedSuboperations", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1023>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::US, "Number of Warning Sub-operations", "NumberOfWarningSuboperations", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1030>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::AE, "Move Originator Application Entity Title", "MoveOriginatorApplicationEntityTitle", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1031>: dictionary_entry {
   commanddictionary():
      dictionary_entry(attribute::VR::US, "Move Originator Message ID", "MoveOriginatorMessageID", "1", false) {}
};

}

}

}

#endif
