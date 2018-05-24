#ifndef COMMANDDIC_HPP
#define COMMANDDIC_HPP

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
      dictionary_entry({attribute::VR::UL, attribute::VR::NN, attribute::VR::NN}, "Command Group Length", "CommandGroupLength", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0002>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::UI, attribute::VR::NN, attribute::VR::NN}, "Affected SOP Class UID", "AffectedSOPClassUID", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0003>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::UI, attribute::VR::NN, attribute::VR::NN}, "Requested SOP Class UID", "RequestedSOPClassUID", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0100>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::US, attribute::VR::NN, attribute::VR::NN}, "Command Field", "CommandField", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0110>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::US, attribute::VR::NN, attribute::VR::NN}, "Message ID", "MessageID", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0120>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::US, attribute::VR::NN, attribute::VR::NN}, "Message ID Being Responded To", "MessageIDBeingRespondedTo", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0600>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::AE, attribute::VR::NN, attribute::VR::NN}, "Move Destination", "MoveDestination", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0700>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::US, attribute::VR::NN, attribute::VR::NN}, "Priority", "Priority", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0800>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::US, attribute::VR::NN, attribute::VR::NN}, "Command Data Set Type", "CommandDataSetType", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0900>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::US, attribute::VR::NN, attribute::VR::NN}, "Status", "Status", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0901>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::AT, attribute::VR::NN, attribute::VR::NN}, "Offending Element", "OffendingElement", "1-n", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0902>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::LO, attribute::VR::NN, attribute::VR::NN}, "Error Comment", "ErrorComment", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x0903>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::US, attribute::VR::NN, attribute::VR::NN}, "Error ID", "ErrorID", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1000>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::UI, attribute::VR::NN, attribute::VR::NN}, "Affected SOP Instance UID", "AffectedSOPInstanceUID", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1001>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::UI, attribute::VR::NN, attribute::VR::NN}, "Requested SOP Instance UID", "RequestedSOPInstanceUID", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1002>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::US, attribute::VR::NN, attribute::VR::NN}, "Event Type ID", "EventTypeID", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1005>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::AT, attribute::VR::NN, attribute::VR::NN}, "Attribute Identifier List", "AttributeIdentifierList", "1-n", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1008>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::US, attribute::VR::NN, attribute::VR::NN}, "Action Type ID", "ActionTypeID", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1020>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::US, attribute::VR::NN, attribute::VR::NN}, "Number of Remaining Sub-operations", "NumberOfRemainingSuboperations", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1021>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::US, attribute::VR::NN, attribute::VR::NN}, "Number of Completed Sub-operations", "NumberOfCompletedSuboperations", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1022>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::US, attribute::VR::NN, attribute::VR::NN}, "Number of Failed Sub-operations", "NumberOfFailedSuboperations", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1023>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::US, attribute::VR::NN, attribute::VR::NN}, "Number of Warning Sub-operations", "NumberOfWarningSuboperations", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1030>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::AE, attribute::VR::NN, attribute::VR::NN}, "Move Originator Application Entity Title", "MoveOriginatorApplicationEntityTitle", "1", false) {}
};
template<>
struct commanddictionary<0x0000, 0x1031>: dictionary_entry {
   commanddictionary():
      dictionary_entry({attribute::VR::US, attribute::VR::NN, attribute::VR::NN}, "Move Originator Message ID", "MoveOriginatorMessageID", "1", false) {}
};

}

}

}

#endif
