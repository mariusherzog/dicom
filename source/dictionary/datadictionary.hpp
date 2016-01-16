#ifndef DATADIC_TEMPLATE_HPP
#define DATADIC_TEMPLATE_HPP

#include "dictionary_entry.hpp"

template<bool> struct bool_t;

template<unsigned gid, unsigned eid, typename = bool_t<true>, typename = bool_t<true> >
struct datadictionary;

template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Length to End", "LengthToEnd", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Specific Character", "SpecificCharacterSet", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Language Code", "LanguageCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Image Type", "ImageType", "2-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Recognition Code", "RecognitionCode", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Instance Creation", "InstanceCreationDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0013>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Instance Creation", "InstanceCreationTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Instance Creator", "InstanceCreatorUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "SOP Class UID", "SOPClassUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0018>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "SOP Instance UID", "SOPInstanceUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x001A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Related General SOP", "RelatedGeneralSOPClassUID", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x001B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Specialized SOP", "OriginalSpecializedSOPClassUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Study Date", "StudyDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0021>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Series Date", "SeriesDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Acquisition Date", "AcquisitionDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0023>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Content Date", "ContentDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Overlay Date", "OverlayDate", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0025>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Curve Date", "CurveDate", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x002A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Acquisition", "AcquisitionDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Study Time", "StudyTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0031>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Series Time", "SeriesTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Acquisition Time", "AcquisitionTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0033>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Content Time", "ContentTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0034>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Overlay Time", "OverlayTime", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0035>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Curve Time", "CurveTime", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Data Set Type", "DataSetType", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0041>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Data Set Subtype", "DataSetSubtype", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Nuclear Medicine", "NuclearMedicineSeriesType", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Accession Number", "AccessionNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0051>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Issuer of Accession", "IssuerOfAccessionNumberSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Query/Retrieve", "QueryRetrieveLevel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0054>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AE, "Retrieve AE Title", "RetrieveAETitle", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0056>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Instance", "InstanceAvailability", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0058>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Failed SOP Instance", "FailedSOPInstanceUIDList", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Modality", "Modality", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0061>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Modalities in Study", "ModalitiesInStudy", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0062>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "SOP Classes in", "SOPClassesInStudy", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0064>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Conversion Type", "ConversionType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0068>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Presentation Intent", "PresentationIntentType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Manufacturer", "Manufacturer", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Institution Name", "InstitutionName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0081>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Institution Address", "InstitutionAddress", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0082>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Institution Code", "InstitutionCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0090>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Referring", "ReferringPhysicianName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0092>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Physicians", "ReferringPhysicianAddress", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0094>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Physicians", "ReferringPhysicianTelephoneNumbers", "n", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0096>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Identification", "ReferringPhysicianIdentificationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Code Value", "CodeValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0102>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Coding Scheme", "CodingSchemeDesignator", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0103>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Coding Scheme", "CodingSchemeVersion", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0104>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Code Meaning", "CodeMeaning", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0105>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Mapping Resource", "MappingResource", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0106>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Context Group", "ContextGroupVersion", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0107>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Context Group Local", "ContextGroupLocalVersion", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x010B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Context Group", "ContextGroupExtensionFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x010C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Coding Scheme UID", "CodingSchemeUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x010D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Extension Creator", "ContextGroupExtensionCreatorUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x010F>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Context Identifier", "ContextIdentifier", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Identification", "CodingSchemeIdentificationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0112>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Coding Scheme", "CodingSchemeRegistry", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0114>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Coding Scheme", "CodingSchemeExternalID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0115>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Coding Scheme Name", "CodingSchemeName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0116>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Responsible", "CodingSchemeResponsibleOrganization", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0117>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Context UID", "ContextUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x0201>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Timezone Offset", "TimezoneOffsetFromUTC", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AE, "Network ID", "NetworkID", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Station Name", "StationName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Study Description", "StudyDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Procedure Code", "ProcedureCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x103E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Series Description", "SeriesDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x103F>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Series Description", "SeriesDescriptionCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Institutional", "InstitutionalDepartmentName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1048>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Physician(s) of", "PhysiciansOfRecord", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1049>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Record", "PhysiciansOfRecordIdentificationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Performing", "PerformingPhysicianName", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Physician", "PerformingPhysicianIdentificationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Name of Physician", "NameOfPhysiciansReadingStudy", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1062>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Reading Study", "PhysiciansReadingStudyIdentificationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Operators Name", "OperatorsName", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1072>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Identification", "OperatorIdentificationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Admitting Diagnoses", "AdmittingDiagnosesDescription", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1084>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Admitting Diagnoses", "AdmittingDiagnosesCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1090>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Manufacturers", "ManufacturerModelName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Results", "ReferencedResultsSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Study", "ReferencedStudySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1111>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Performed Procedure", "ReferencedPerformedProcedureStepSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1115>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Series", "ReferencedSeriesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1120>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Patient", "ReferencedPatientSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1125>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Visit", "ReferencedVisitSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1130>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Overlay", "ReferencedOverlaySequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1134>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Stereometric", "ReferencedStereometricInstanceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x113A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Waveform", "ReferencedWaveformSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1140>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Image", "ReferencedImageSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1145>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Curve", "ReferencedCurveSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x114A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Instance", "ReferencedInstanceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x114B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "World Value Mapping", "ReferencedRealWorldValueMappingInstanceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1150>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Referenced SOP", "ReferencedSOPClassUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1155>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Referenced SOP", "ReferencedSOPInstanceUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x115A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "SOP Classes", "SOPClassesSupported", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1160>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Referenced Frame", "ReferencedFrameNumber", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1161>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Simple Frame List", "SimpleFrameList", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1162>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Calculated Frame", "CalculatedFrameList", "3-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1163>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Time Range", "TimeRange", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1164>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Frame Extraction", "FrameExtractionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1167>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Multi-Frame Source", "MultiFrameSourceSOPInstanceUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1195>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Transaction UID", "TransactionUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1197>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Failure Reason", "FailureReason", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1198>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Failed SOP Sequence", "FailedSOPSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1199>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced SOP", "ReferencedSOPSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1200>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Other Referenced", "StudiesContainingOtherReferencedInstancesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x1250>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Related Series", "RelatedSeriesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Compression", "LossyImageCompressionRetired", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2111>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Derivation", "DerivationDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2112>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Source Image", "SourceImageSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2120>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Stage Name", "StageName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2122>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Stage Number", "StageNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2124>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Stages", "NumberOfStages", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2127>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "View Name", "ViewName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2128>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "View Number", "ViewNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2129>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Event", "NumberOfEventTimers", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x212A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Views in", "NumberOfViewsInStage", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2130>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Event Elapsed Time", "EventElapsedTimes", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2132>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Event Timer Name(s)", "EventTimerNames", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2133>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Event Timer", "EventTimerSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2134>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Event Time Offset", "EventTimeOffset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2135>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Event Code Sequence", "EventCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2142>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Start Trim", "StartTrim", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2143>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Stop Trim", "StopTrim", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2144>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Recommended Display", "RecommendedDisplayFrameRate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2200>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Transducer Position", "TransducerPosition", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2204>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Transducer", "TransducerOrientation", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2208>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Anatomic Structure", "AnatomicStructure", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2218>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Anatomic Region", "AnatomicRegionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2220>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Anatomic Region", "AnatomicRegionModifierSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2228>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Primary Anatomic", "PrimaryAnatomicStructureSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2229>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Space or Region", "AnatomicStructureSpaceOrRegionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2230>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Structure Modifier", "PrimaryAnatomicStructureModifierSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2240>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Transducer Position", "TransducerPositionSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2242>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Transducer Position", "TransducerPositionModifierSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2244>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Orientation", "TransducerOrientationSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2246>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Orientation", "TransducerOrientationModifierSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2251>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Space Or Region", "AnatomicStructureSpaceOrRegionCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2253>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Entrance Code", "AnatomicPortalOfEntranceCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2255>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Direction Code", "AnatomicApproachDirectionCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2256>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Perspective", "AnatomicPerspectiveDescriptionTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2257>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Perspective Code", "AnatomicPerspectiveCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2258>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Of Examining", "AnatomicLocationOfExaminingInstrumentDescriptionTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x2259>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Of Examining", "AnatomicLocationOfExaminingInstrumentCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x225A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Space Or Region", "AnatomicStructureSpaceOrRegionModifierCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x225C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Anatomic Structure", "OnAxisBackgroundAnatomicStructureCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x3001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Representation", "AlternateRepresentationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x3010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Irradiation Event", "IrradiationEventUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x4000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Identifying", "IdentifyingComments", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x9007>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Frame Type", "FrameType", "4", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x9092>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Image", "ReferencedImageEvidenceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x9121>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Raw Data", "ReferencedRawDataSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x9123>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Creator-Version UID", "CreatorVersionUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x9124>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Derivation Image", "DerivationImageSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x9154>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Source Image", "SourceImageEvidenceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x9205>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Pixel Presentation", "PixelPresentation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x9206>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Volumetric", "VolumetricProperties", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x9207>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Calculation", "VolumeBasedCalculationTechnique", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x9208>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Complex Image", "ComplexImageComponent", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x9209>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Acquisition", "AcquisitionContrast", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x9215>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Derivation Code", "DerivationCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x9237>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Presentation State", "ReferencedPresentationStateSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x9410>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Other", "ReferencedOtherPlaneSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x9458>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Frame Display", "FrameDisplaySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x9459>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Recommended Display", "RecommendedDisplayFrameRateInFloat", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0008>, bool_t<(eid & 0xffff) == 0x9460>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Skip Frame Range", "SkipFrameRangeFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Patients Name", "PatientName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Patient ID", "PatientID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x0021>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Issuer of Patient", "IssuerOfPatientID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x0022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Type of Patient ID", "TypeOfPatientID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x0024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "ID Qualifiers", "IssuerOfPatientIDQualifiersSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Patients Birth", "PatientBirthDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x0032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Patients Birth", "PatientBirthTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Patients Sex", "PatientSex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Insurance Plan Code", "PatientInsurancePlanCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x0101>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Language Code", "PatientPrimaryLanguageCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x0102>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Language Modifier", "PatientPrimaryLanguageModifierCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x1000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Other Patient IDs", "OtherPatientIDs", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x1001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Other Patient Names", "OtherPatientNames", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x1002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Other Patient IDs", "OtherPatientIDsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x1005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Patients Birth", "PatientBirthName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x1010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AS, "Patients Age", "PatientAge", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x1020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Patients Size", "PatientSize", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x1021>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Patients Size", "PatientSizeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x1030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Patients Weight", "PatientWeight", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x1040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Patients Address", "PatientAddress", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x1050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Insurance Plan", "InsurancePlanIdentification", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x1060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Mothers Birth", "PatientMotherBirthName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x1080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Military Rank", "MilitaryRank", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x1081>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Branch of Service", "BranchOfService", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x1090>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Medical Record", "MedicalRecordLocator", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x2000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Medical Alerts", "MedicalAlerts", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x2110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Allergies", "Allergies", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x2150>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Country of", "CountryOfResidence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x2152>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Region of Residence", "RegionOfResidence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x2154>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Patients", "PatientTelephoneNumbers", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x2160>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Ethnic Group", "EthnicGroup", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x2180>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Occupation", "Occupation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x21A0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Smoking Status", "SmokingStatus", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x21B0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Additional Patient", "AdditionalPatientHistory", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x21C0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Pregnancy Status", "PregnancyStatus", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x21D0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Last Menstrual Date", "LastMenstrualDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x21F0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Religious", "PatientReligiousPreference", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x2201>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Patient Species", "PatientSpeciesDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x2202>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Patient Species", "PatientSpeciesCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x2203>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Patients Sex", "PatientSexNeutered", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x2210>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Anatomical", "AnatomicalOrientationType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x2292>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Patient Breed", "PatientBreedDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x2293>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Patient Breed Code", "PatientBreedCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x2294>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Breed Registration", "BreedRegistrationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x2295>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Breed Registration", "BreedRegistrationNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x2296>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Breed Registry Code", "BreedRegistryCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x2297>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Responsible Person", "ResponsiblePerson", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x2298>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Responsible Person", "ResponsiblePersonRole", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x2299>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Responsible", "ResponsibleOrganization", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x4000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Patient Comments", "PatientComments", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0010>, bool_t<(eid & 0xffff) == 0x9431>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Examined Body", "ExaminedBodyThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0012>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Clinical Trial", "ClinicalTrialSponsorName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0012>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Clinical Trial", "ClinicalTrialProtocolID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0012>, bool_t<(eid & 0xffff) == 0x0021>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Clinical Trial", "ClinicalTrialProtocolName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0012>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Clinical Trial Site", "ClinicalTrialSiteID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0012>, bool_t<(eid & 0xffff) == 0x0031>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Clinical Trial Site", "ClinicalTrialSiteName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0012>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Clinical Trial", "ClinicalTrialSubjectID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0012>, bool_t<(eid & 0xffff) == 0x0042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Clinical Trial", "ClinicalTrialSubjectReadingID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0012>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Clinical Trial Time", "ClinicalTrialTimePointID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0012>, bool_t<(eid & 0xffff) == 0x0051>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Clinical Trial Time", "ClinicalTrialTimePointDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0012>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Coordinating Center", "ClinicalTrialCoordinatingCenterName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0012>, bool_t<(eid & 0xffff) == 0x0062>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Patient Identity", "PatientIdentityRemoved", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0012>, bool_t<(eid & 0xffff) == 0x0063>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "De-identification", "DeidentificationMethod", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0012>, bool_t<(eid & 0xffff) == 0x0064>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Method Code", "DeidentificationMethodCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0012>, bool_t<(eid & 0xffff) == 0x0071>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Clinical Trial", "ClinicalTrialSeriesID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0012>, bool_t<(eid & 0xffff) == 0x0072>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Clinical Trial", "ClinicalTrialSeriesDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0012>, bool_t<(eid & 0xffff) == 0x0081>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Protocol Ethics", "ClinicalTrialProtocolEthicsCommitteeName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0012>, bool_t<(eid & 0xffff) == 0x0082>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Protocol Ethics", "ClinicalTrialProtocolEthicsCommitteeApprovalNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0012>, bool_t<(eid & 0xffff) == 0x0083>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Clinical Trial Use", "ConsentForClinicalTrialUseSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0012>, bool_t<(eid & 0xffff) == 0x0084>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Distribution Type", "DistributionType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0012>, bool_t<(eid & 0xffff) == 0x0085>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Consent for", "ConsentForDistributionFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x0023>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "CAD File Format", "CADFileFormat", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x0024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Component Reference", "ComponentReferenceSystem", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x0025>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Manufacturing", "ComponentManufacturingProcedure", "n", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x0028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Component", "ComponentManufacturer", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Material Thickness", "MaterialThickness", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x0032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Material Pipe", "MaterialPipeDiameter", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x0034>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Material Isolation", "MaterialIsolationDiameter", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x0042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Material Grade", "MaterialGrade", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x0044>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Material Properties", "MaterialPropertiesFileID", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x0045>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Material Properties", "MaterialPropertiesFileFormat", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x0046>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Material Notes", "MaterialNotes", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Component Shape", "ComponentShape", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x0052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Curvature Type", "CurvatureType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x0054>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Outer Diameter", "OuterDiameter", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x0056>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Inner Diameter", "InnerDiameter", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x1010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Environmental", "ActualEnvironmentalConditions", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x1020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Expiry Date", "ExpiryDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x1040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Environmental", "EnvironmentalConditions", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x2002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Evaluator Sequence", "EvaluatorSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x2004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Evaluator Number", "EvaluatorNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x2006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Evaluator Name", "EvaluatorName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x2008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Evaluation Attempt", "EvaluationAttempt", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x2012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Indication Sequence", "IndicationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x2014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Indication Number", "IndicationNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x2016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Indication Label", "IndicationLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x2018>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Indication", "IndicationDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x201A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Indication Type", "IndicationType", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x201C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Indication", "IndicationDisposition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x201E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Indication ROI", "IndicationROISequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x2030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Indication Physical", "IndicationPhysicalPropertySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x2032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Property Label", "PropertyLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x2202>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Coordinate System", "CoordinateSystemNumberOfAxes", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x2204>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Coordinate System", "CoordinateSystemAxesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x2206>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Coordinate System", "CoordinateSystemAxisDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x2208>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Coordinate System", "CoordinateSystemDataSetMapping", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x220A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Coordinate System", "CoordinateSystemAxisNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x220C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Coordinate System", "CoordinateSystemAxisType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x220E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Coordinate System", "CoordinateSystemAxisUnits", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x2210>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OB, "Coordinate System", "CoordinateSystemAxisValues", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x2220>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Coordinate System", "CoordinateSystemTransformSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x2222>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Transform", "TransformDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x2224>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Transform Number of", "TransformNumberOfAxes", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x2226>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Transform Order of", "TransformOrderOfAxes", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x2228>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Transformed Axis", "TransformedAxisUnits", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x222A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Transform Rotation", "CoordinateSystemTransformRotationAndScaleMatrix", "n", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x222C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Transform", "CoordinateSystemTransformTranslationMatrix", "n", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x3011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Internal Detector", "InternalDetectorFrameTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x3012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Number of Frames", "NumberOfFramesIntegrated", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x3020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Temperature", "DetectorTemperatureSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x3022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Sensor Name", "SensorName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x3024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Horizontal Offset", "HorizontalOffsetOfSensor", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x3026>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Vertical Offset of", "VerticalOffsetOfSensor", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x3028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Sensor Temperature", "SensorTemperature", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x3040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Dark Current", "DarkCurrentSequence", "1", false) {}
};

template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x3060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Gain Correction", "GainCorrectionReferenceSequence", "1", false) {}
};

template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x3071>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "KV Used in Gain", "KVUsedInGainCalibration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x3072>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "MA Used in Gain", "MAUsedInGainCalibration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x3073>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Used for", "NumberOfFramesUsedForIntegration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x3074>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Used in Gain", "FilterMaterialUsedInGainCalibration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x3075>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Used in Gain", "FilterThicknessUsedInGainCalibration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x3076>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Date of Gain", "DateOfGainCalibration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x3077>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Time of Gain", "TimeOfGainCalibration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x3080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OB, "Bad Pixel Image", "BadPixelImage", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x3099>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Calibration Notes", "CalibrationNotes", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Pulser Equipment", "PulserEquipmentSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Pulser Type", "PulserType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Pulser Notes", "PulserNotes", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Receiver Equipment", "ReceiverEquipmentSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x400A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Amplifier Type", "AmplifierType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x400C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Receiver Notes", "ReceiverNotes", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x400E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Pre-Amplifier", "PreAmplifierEquipmentSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x400F>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Pre-Amplifier Notes", "PreAmplifierNotes", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Transmit Transducer", "TransmitTransducerSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Receive Transducer", "ReceiveTransducerSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Elements", "NumberOfElements", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4013>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Element Shape", "ElementShape", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Element Dimension A", "ElementDimensionA", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4015>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Element Dimension B", "ElementDimensionB", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Element Pitch", "ElementPitch", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4017>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Measured Beam", "MeasuredBeamDimensionA", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4018>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Measured Beam", "MeasuredBeamDimensionB", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4019>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Measured Beam", "LocationOfMeasuredBeamDiameter", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x401A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Nominal Frequency", "NominalFrequency", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x401B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Measured Center", "MeasuredCenterFrequency", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x401C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Measured Bandwidth", "MeasuredBandwidth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Pulser Settings", "PulserSettingsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Pulse Width", "PulseWidth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Excitation", "ExcitationFrequency", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4026>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Modulation Type", "ModulationType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Damping", "Damping", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Receiver Settings", "ReceiverSettingsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4031>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Acquired Soundpath", "AcquiredSoundpathLength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Acquisition", "AcquisitionCompressionType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4033>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Acquisition Sample", "AcquisitionSampleSize", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4034>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Rectifier Smoothing", "RectifierSmoothing", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4035>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "DAC Sequence", "DACSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4036>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "DAC Type", "DACType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4038>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "DAC Gain Points", "DACGainPoints", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x403A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "DAC Time Points", "DACTimePoints", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x403C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "DAC Amplitude", "DACAmplitude", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Pre-Amplifier", "PreAmplifierSettingsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Transmit Transducer", "TransmitTransducerSettingsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4051>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Receive Transducer", "ReceiveTransducerSettingsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Incident Angle", "IncidentAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4054>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Coupling Technique", "CouplingTechnique", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4056>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Coupling Medium", "CouplingMedium", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4057>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Coupling Velocity", "CouplingVelocity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4058>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Crystal Center", "CrystalCenterLocationX", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4059>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Crystal Center", "CrystalCenterLocationZ", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x405A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Sound Path Length", "SoundPathLength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x405C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Delay Law", "DelayLawIdentifier", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Gate Settings", "GateSettingsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4062>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Gate Threshold", "GateThreshold", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4064>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Velocity of Sound", "VelocityOfSound", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Calibration", "CalibrationSettingsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4072>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Calibration", "CalibrationProcedure", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4074>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Procedure Version", "ProcedureVersion", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4076>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Procedure Creation", "ProcedureCreationDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x4078>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Procedure", "ProcedureExpirationDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x407A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Procedure Last", "ProcedureLastModifiedDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x407C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Calibration Time", "CalibrationTime", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x407E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Calibration Date", "CalibrationDate", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x5002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "LINAC Energy", "LINACEnergy", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0014>, bool_t<(eid & 0xffff) == 0x5004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "LINAC Output", "LINACOutput", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Contrast/Bolus", "ContrastBolusAgent", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Contrast/Bolus", "ContrastBolusAgentSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Administration", "ContrastBolusAdministrationRouteSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0015>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Body Part Examined", "BodyPartExamined", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Scanning Sequence", "ScanningSequence", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0021>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Sequence Variant", "SequenceVariant", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Scan Options", "ScanOptions", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0023>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "MR Acquisition Type", "MRAcquisitionType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Sequence Name", "SequenceName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0025>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Angio Flag", "AngioFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0026>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Information", "InterventionDrugInformationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0027>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Intervention Drug", "InterventionDrugStopTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Intervention Drug", "InterventionDrugDose", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0029>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Intervention Drug", "InterventionDrugCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x002A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Additional Drug", "AdditionalDrugSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Radionuclide", "Radionuclide", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0031>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Radiopharmaceutical", "Radiopharmaceutical", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Energy Window", "EnergyWindowCenterline", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0033>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Energy Window Total", "EnergyWindowTotalWidth", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0034>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Intervention Drug", "InterventionDrugName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0035>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Intervention Drug", "InterventionDrugStartTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0036>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Intervention", "InterventionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0037>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Therapy Type", "TherapyType", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0038>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Intervention Status", "InterventionStatus", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0039>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Therapy Description", "TherapyDescription", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x003A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Intervention", "InterventionDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Cine Rate", "CineRate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Initial Cine Run", "InitialCineRunState", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Slice Thickness", "SliceThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "KVP", "KVP", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Counts Accumulated", "CountsAccumulated", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0071>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Termination", "AcquisitionTerminationCondition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0072>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Effective Duration", "EffectiveDuration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0073>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Acquisition Start", "AcquisitionStartCondition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0074>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Acquisition Start", "AcquisitionStartConditionData", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0075>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Termination", "AcquisitionTerminationConditionData", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Repetition Time", "RepetitionTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0081>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Echo Time", "EchoTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0082>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Inversion Time", "InversionTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0083>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Number of Averages", "NumberOfAverages", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0084>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Imaging Frequency", "ImagingFrequency", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0085>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Imaged Nucleus", "ImagedNucleus", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0086>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Echo Number(s)", "EchoNumbers", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0087>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Magnetic Field", "MagneticFieldStrength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0088>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Spacing Between", "SpacingBetweenSlices", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0089>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Phase", "NumberOfPhaseEncodingSteps", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0090>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Data Collection", "DataCollectionDiameter", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0091>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Echo Train Length", "EchoTrainLength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0093>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Percent Sampling", "PercentSampling", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0094>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Percent Phase Field", "PercentPhaseFieldOfView", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x0095>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Pixel Bandwidth", "PixelBandwidth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Device Serial", "DeviceSerialNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Device UID", "DeviceUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Device ID", "DeviceID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Plate ID", "PlateID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Generator ID", "GeneratorID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Grid ID", "GridID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1007>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Cassette ID", "CassetteID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Gantry ID", "GantryID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Secondary Capture", "SecondaryCaptureDeviceID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Hardcopy Creation", "HardcopyCreationDeviceID", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Date of Secondary", "DateOfSecondaryCapture", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Time of Secondary", "TimeOfSecondaryCapture", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Secondary Capture", "SecondaryCaptureDeviceManufacturer", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1017>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Hardcopy Device", "HardcopyDeviceManufacturer", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1018>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Device", "SecondaryCaptureDeviceManufacturerModelName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1019>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Device Software", "SecondaryCaptureDeviceSoftwareVersions", "n", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x101A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Hardcopy Device", "HardcopyDeviceSoftwareVersion", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x101B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Manufacturers", "HardcopyDeviceManufacturerModelName", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Software Version(s)", "SoftwareVersions", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Video Image Format", "VideoImageFormatAcquired", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1023>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Digital Image", "DigitalImageFormatAcquired", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Protocol Name", "ProtocolName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Contrast/Bolus", "ContrastBolusRoute", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1041>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Contrast/Bolus", "ContrastBolusVolume", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Contrast/Bolus", "ContrastBolusStartTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1043>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Contrast/Bolus Stop", "ContrastBolusStopTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1044>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Contrast/Bolus", "ContrastBolusTotalDose", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1045>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Syringe Counts", "SyringeCounts", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1046>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Contrast Flow Rate", "ContrastFlowRate", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1047>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Contrast Flow", "ContrastFlowDuration", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1048>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Contrast/Bolus", "ContrastBolusIngredient", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1049>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Ingredient", "ContrastBolusIngredientConcentration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Spatial Resolution", "SpatialResolution", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Trigger Time", "TriggerTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1061>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Trigger Source or", "TriggerSourceOrType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1062>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Nominal Interval", "NominalInterval", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1063>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Frame Time", "FrameTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1064>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Cardiac Framing", "CardiacFramingType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1065>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Frame Time Vector", "FrameTimeVector", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1066>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Frame Delay", "FrameDelay", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1067>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Image Trigger Delay", "ImageTriggerDelay", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1068>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Multiplex Group", "MultiplexGroupTimeOffset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1069>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Trigger Time Offset", "TriggerTimeOffset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x106A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Synchronization", "SynchronizationTrigger", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x106C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Synchronization", "SynchronizationChannel", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x106E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Trigger Sample", "TriggerSamplePosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Radiopharmaceutical", "RadiopharmaceuticalRoute", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1071>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Radiopharmaceutical", "RadiopharmaceuticalVolume", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1072>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Radiopharmaceutical", "RadiopharmaceuticalStartTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1073>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Radiopharmaceutical", "RadiopharmaceuticalStopTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1074>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Radionuclide Total", "RadionuclideTotalDose", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1075>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Radionuclide Half", "RadionuclideHalfLife", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1076>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Radionuclide", "RadionuclidePositronFraction", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1077>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Radiopharmaceutical", "RadiopharmaceuticalSpecificActivity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1078>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Radiopharmaceutical", "RadiopharmaceuticalStartDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1079>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Radiopharmaceutical", "RadiopharmaceuticalStopDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Beat Rejection Flag", "BeatRejectionFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1081>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Low R-R Value", "LowRRValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1082>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "High R-R Value", "HighRRValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1083>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Intervals Acquired", "IntervalsAcquired", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1084>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Intervals Rejected", "IntervalsRejected", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1085>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "PVC Rejection", "PVCRejection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1086>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Skip Beats", "SkipBeats", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1088>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Heart Rate", "HeartRate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1090>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Cardiac Number of", "CardiacNumberOfImages", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1094>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Trigger Window", "TriggerWindow", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Reconstruction", "ReconstructionDiameter", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Distance Source to", "DistanceSourceToDetector", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1111>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Distance Source to", "DistanceSourceToPatient", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1114>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Radiographic", "EstimatedRadiographicMagnificationFactor", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1120>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Gantry/Detector", "GantryDetectorTilt", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1121>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Gantry/Detector", "GantryDetectorSlew", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1130>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Table Height", "TableHeight", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1131>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Table Traverse", "TableTraverse", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1134>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Table Motion", "TableMotion", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1135>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Table Vertical", "TableVerticalIncrement", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1136>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Table Lateral", "TableLateralIncrement", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1137>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Table Longitudinal", "TableLongitudinalIncrement", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1138>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Table Angle", "TableAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x113A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Table Type", "TableType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1140>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Rotation Direction", "RotationDirection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1141>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Angular Position", "AngularPosition", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1142>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Radial Position", "RadialPosition", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1143>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Scan Arc", "ScanArc", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1144>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Angular Step", "AngularStep", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1145>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Center of Rotation", "CenterOfRotationOffset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1146>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Rotation Offset", "RotationOffset", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1147>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Field of View Shape", "FieldOfViewShape", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1149>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Field of View", "FieldOfViewDimensions", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1150>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Exposure Time", "ExposureTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1151>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "X-Ray Tube Current", "XRayTubeCurrent", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1152>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Exposure", "Exposure", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1153>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Exposure in As", "ExposureInuAs", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1154>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Average Pulse Width", "AveragePulseWidth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1155>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Radiation Setting", "RadiationSetting", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1156>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Rectification Type", "RectificationType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x115A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Radiation Mode", "RadiationMode", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x115E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Fluoroscopy Area", "ImageAndFluoroscopyAreaDoseProduct", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1160>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Filter Type", "FilterType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1161>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Type of Filters", "TypeOfFilters", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1162>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Intensifier Size", "IntensifierSize", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1164>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Imager Pixel", "ImagerPixelSpacing", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1166>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Grid", "Grid", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1170>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Generator Power", "GeneratorPower", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1180>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Collimator/grid", "CollimatorGridName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1181>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Collimator Type", "CollimatorType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1182>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Focal Distance", "FocalDistance", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1183>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "X Focus Center", "XFocusCenter", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1184>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Y Focus Center", "YFocusCenter", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1190>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Focal Spot(s)", "FocalSpots", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1191>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Anode Target", "AnodeTargetMaterial", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x11A0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Body Part Thickness", "BodyPartThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x11A2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Compression Force", "CompressionForce", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1200>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Date of Last", "DateOfLastCalibration", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1201>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Time of Last", "TimeOfLastCalibration", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1210>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Convolution Kernel", "ConvolutionKernel", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1240>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Upper/Lower Pixel", "UpperLowerPixelValues", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1242>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Actual Frame", "ActualFrameDuration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1243>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Count Rate", "CountRate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1244>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Preferred Playback", "PreferredPlaybackSequencing", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1250>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Receive Coil Name", "ReceiveCoilName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1251>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Transmit Coil Name", "TransmitCoilName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1260>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Plate Type", "PlateType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1261>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Phosphor Type", "PhosphorType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1300>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Scan Velocity", "ScanVelocity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1301>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Whole Body", "WholeBodyTechnique", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1302>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Scan Length", "ScanLength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1310>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Acquisition Matrix", "AcquisitionMatrix", "4", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1312>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "In-plane Phase", "InPlanePhaseEncodingDirection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1314>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Flip Angle", "FlipAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1315>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Variable Flip Angle", "VariableFlipAngleFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1316>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "SAR", "SAR", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1318>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "dB/dt", "dBdt", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1400>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Processing", "AcquisitionDeviceProcessingDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1401>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Acquisition Device", "AcquisitionDeviceProcessingCode", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1402>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Cassette", "CassetteOrientation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1403>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Cassette Size", "CassetteSize", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1404>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Exposures on Plate", "ExposuresOnPlate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1405>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Relative X-Ray", "RelativeXRayExposure", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1411>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Exposure Index", "ExposureIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1412>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Target Exposure", "TargetExposureIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1413>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Deviation Index", "DeviationIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1450>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Column Angulation", "ColumnAngulation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1460>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Tomo Layer Height", "TomoLayerHeight", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1470>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Tomo Angle", "TomoAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1480>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Tomo Time", "TomoTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1490>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Tomo Type", "TomoType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1491>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Tomo Class", "TomoClass", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1495>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Tomosynthesis", "NumberOfTomosynthesisSourceImages", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1500>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Positioner Motion", "PositionerMotion", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1508>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Positioner Type", "PositionerType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1510>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Positioner Primary", "PositionerPrimaryAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1511>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Positioner", "PositionerSecondaryAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1520>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Positioner Primary", "PositionerPrimaryAngleIncrement", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1521>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Secondary Angle", "PositionerSecondaryAngleIncrement", "n", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1530>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Detector Primary", "DetectorPrimaryAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1531>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Detector Secondary", "DetectorSecondaryAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1600>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Shutter Shape", "ShutterShape", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1602>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Shutter Left", "ShutterLeftVerticalEdge", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1604>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Shutter Right", "ShutterRightVerticalEdge", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1606>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Shutter Upper", "ShutterUpperHorizontalEdge", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1608>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Shutter Lower", "ShutterLowerHorizontalEdge", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1610>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Center of Circular", "CenterOfCircularShutter", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1612>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Radius of Circular", "RadiusOfCircularShutter", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1620>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Vertices of the", "VerticesOfThePolygonalShutter", "2-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1622>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Shutter", "ShutterPresentationValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1623>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Shutter Overlay", "ShutterOverlayGroup", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1624>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Presentation Color", "ShutterPresentationColorCIELabValue", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1700>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Collimator Shape", "CollimatorShape", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1702>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Collimator Left", "CollimatorLeftVerticalEdge", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1704>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Collimator Right", "CollimatorRightVerticalEdge", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1706>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Collimator Upper", "CollimatorUpperHorizontalEdge", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1708>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Collimator Lower", "CollimatorLowerHorizontalEdge", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1710>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Center of Circular", "CenterOfCircularCollimator", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1712>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Radius of Circular", "RadiusOfCircularCollimator", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1720>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Polygonal", "VerticesOfThePolygonalCollimator", "2n", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1800>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Acquisition Time", "AcquisitionTimeSynchronized", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1801>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Time Source", "TimeSource", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1802>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Time Distribution", "TimeDistributionProtocol", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x1803>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "NTP Source Address", "NTPSourceAddress", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x2001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Page Number Vector", "PageNumberVector", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x2002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Frame Label Vector", "FrameLabelVector", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x2003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Frame Primary Angle", "FramePrimaryAngleVector", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x2004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Frame Secondary", "FrameSecondaryAngleVector", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x2005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Slice Location", "SliceLocationVector", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x2006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Display Window", "DisplayWindowLabelVector", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x2010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Nominal Scanned", "NominalScannedPixelSpacing", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x2020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Digitizing Device", "DigitizingDeviceTransportDirection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x2030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Rotation of Scanned", "RotationOfScannedFilm", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x3100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "IVUS Acquisition", "IVUSAcquisition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x3101>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "IVUS Pullback Rate", "IVUSPullbackRate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x3102>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "IVUS Gated Rate", "IVUSGatedRate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x3103>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "IVUS Pullback Start", "IVUSPullbackStartFrameNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x3104>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "IVUS Pullback Stop", "IVUSPullbackStopFrameNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x3105>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Lesion Number", "LesionNumber", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x4000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Acquisition", "AcquisitionComments", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x5000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Output Power", "OutputPower", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x5010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Transducer Data", "TransducerData", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x5012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Focus Depth", "FocusDepth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x5020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Processing Function", "ProcessingFunction", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x5021>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Postprocessing", "PostprocessingFunction", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x5022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Mechanical Index", "MechanicalIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x5024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Bone Thermal Index", "BoneThermalIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x5026>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Cranial Thermal", "CranialThermalIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x5027>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Soft Tissue Thermal", "SoftTissueThermalIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x5028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Soft Tissue-focus", "SoftTissueFocusThermalIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x5029>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Soft Tissue-surface", "SoftTissueSurfaceThermalIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x5030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Dynamic Range", "DynamicRange", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x5040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Total Gain", "TotalGain", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x5050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Depth of Scan Field", "DepthOfScanField", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x5100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Patient Position", "PatientPosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x5101>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "View Position", "ViewPosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x5104>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Eponymous Name Code", "ProjectionEponymousNameCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x5210>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Transformation", "ImageTransformationMatrix", "6", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x5212>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Image Translation", "ImageTranslationVector", "3", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Sensitivity", "Sensitivity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Sequence of", "SequenceOfUltrasoundRegions", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Region Spatial", "RegionSpatialFormat", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Region Data Type", "RegionDataType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Region Flags", "RegionFlags", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6018>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Region Location Min", "RegionLocationMinX0", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x601A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Region Location Min", "RegionLocationMinY0", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x601C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Region Location Max", "RegionLocationMaxX1", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x601E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Region Location Max", "RegionLocationMaxY1", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SL, "Reference Pixel X0", "ReferencePixelX0", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SL, "Reference Pixel Y0", "ReferencePixelY0", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Physical Units X", "PhysicalUnitsXDirection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6026>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Physical Units Y", "PhysicalUnitsYDirection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Reference Pixel", "ReferencePixelPhysicalValueX", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x602A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Reference Pixel", "ReferencePixelPhysicalValueY", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x602C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Physical Delta X", "PhysicalDeltaX", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x602E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Physical Delta Y", "PhysicalDeltaY", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Transducer", "TransducerFrequency", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6031>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Transducer Type", "TransducerType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Pulse Repetition", "PulseRepetitionFrequency", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6034>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Doppler Correction", "DopplerCorrectionAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6036>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Steering Angle", "SteeringAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6038>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Volume X Position", "DopplerSampleVolumeXPositionRetired", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6039>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SL, "Doppler Sample", "DopplerSampleVolumeXPosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x603A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Volume Y Position", "DopplerSampleVolumeYPositionRetired", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x603B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SL, "Doppler Sample", "DopplerSampleVolumeYPosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x603C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "TM-Line Position X0", "TMLinePositionX0Retired", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x603D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SL, "TM-Line Position X0", "TMLinePositionX0", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x603E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "TM-Line Position Y0", "TMLinePositionY0Retired", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x603F>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SL, "TM-Line Position Y0", "TMLinePositionY0", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "TM-Line Position X1", "TMLinePositionX1Retired", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6041>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SL, "TM-Line Position X1", "TMLinePositionX1", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "TM-Line Position Y1", "TMLinePositionY1Retired", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6043>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SL, "TM-Line Position Y1", "TMLinePositionY1", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6044>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Pixel Component", "PixelComponentOrganization", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6046>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Pixel Component", "PixelComponentMask", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6048>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Pixel Component", "PixelComponentRangeStart", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x604A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Pixel Component", "PixelComponentRangeStop", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x604C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Pixel Component", "PixelComponentPhysicalUnits", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x604E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Pixel Component", "PixelComponentDataType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Number of Table", "NumberOfTableBreakPoints", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Table of X Break", "TableOfXBreakPoints", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6054>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Table of Y Break", "TableOfYBreakPoints", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6056>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Number of Table", "NumberOfTableEntries", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6058>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Table of Pixel", "TableOfPixelValues", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x605A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Table of Parameter", "TableOfParameterValues", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x6060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "R Wave Time Vector", "RWaveTimeVector", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Detector Conditions", "DetectorConditionsNominalFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Detector", "DetectorTemperature", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Detector Type", "DetectorType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Detector", "DetectorConfiguration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Detector", "DetectorDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Detector Mode", "DetectorMode", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x700A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Detector ID", "DetectorID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x700C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Detector", "DateOfLastDetectorCalibration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x700E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Detector", "TimeOfLastDetectorCalibration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Detector Since Last", "ExposuresOnDetectorSinceLastCalibration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Detector Since", "ExposuresOnDetectorSinceManufactured", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Detector Time Since", "DetectorTimeSinceLastExposure", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Detector Active", "DetectorActiveTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Offset From", "DetectorActivationOffsetFromExposure", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x701A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Detector Binning", "DetectorBinning", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Detector Element", "DetectorElementPhysicalSize", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Detector Element", "DetectorElementSpacing", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Detector Active", "DetectorActiveShape", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7026>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Detector Active", "DetectorActiveDimensions", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Detector Active", "DetectorActiveOrigin", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x702A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Detector", "DetectorManufacturerName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x702B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Manufacturers", "DetectorManufacturerModelName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Field of View", "FieldOfViewOrigin", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Field of View", "FieldOfViewRotation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7034>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Field of View", "FieldOfViewHorizontalFlip", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7036>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Origin Relative To", "PixelDataAreaOriginRelativeToFOV", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7038>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Rotation Angle", "PixelDataAreaRotationAngleRelativeToFOV", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Grid Absorbing", "GridAbsorbingMaterial", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7041>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Grid Spacing", "GridSpacingMaterial", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Grid Thickness", "GridThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7044>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Grid Pitch", "GridPitch", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7046>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Grid Aspect Ratio", "GridAspectRatio", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7048>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Grid Period", "GridPeriod", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x704C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Grid Focal Distance", "GridFocalDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Filter Material", "FilterMaterial", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Filter Thickness", "FilterThicknessMinimum", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7054>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Filter Thickness", "FilterThicknessMaximum", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7056>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Filter Beam Path", "FilterBeamPathLengthMinimum", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7058>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Filter Beam Path", "FilterBeamPathLengthMaximum", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Exposure Control", "ExposureControlMode", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7062>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Exposure Control", "ExposureControlModeDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7064>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Exposure Status", "ExposureStatus", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x7065>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Phototimer Setting", "PhototimerSetting", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x8150>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Exposure Time in", "ExposureTimeInuS", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x8151>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "X-Ray Tube Current", "XRayTubeCurrentInuA", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Content", "ContentQualification", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Pulse Sequence Name", "PulseSequenceName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "MR Imaging Modifier", "MRImagingModifierSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Echo Pulse Sequence", "EchoPulseSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9009>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Inversion Recovery", "InversionRecovery", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Flow Compensation", "FlowCompensation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Multiple Spin Echo", "MultipleSpinEcho", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Multi-planar", "MultiPlanarExcitation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Phase Contrast", "PhaseContrast", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9015>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Time of Flight", "TimeOfFlightContrast", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Spoiling", "Spoiling", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9017>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Steady State Pulse", "SteadyStatePulseSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9018>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Echo Planar Pulse", "EchoPlanarPulseSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9019>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Tag Angle First", "TagAngleFirstAxis", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Magnetization", "MagnetizationTransfer", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9021>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "T2 Preparation", "T2Preparation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Blood Signal", "BloodSignalNulling", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Saturation Recovery", "SaturationRecovery", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9025>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Spectrally Selected", "SpectrallySelectedSuppression", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9026>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Spectrally Selected", "SpectrallySelectedExcitation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9027>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Spatial Pre-", "SpatialPresaturation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Tagging", "Tagging", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9029>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Oversampling Phase", "OversamplingPhase", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Tag Spacing First", "TagSpacingFirstDimension", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Geometry of k-Space", "GeometryOfKSpaceTraversal", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9033>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Segmented k-Space", "SegmentedKSpaceTraversal", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9034>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Rectilinear Phase", "RectilinearPhaseEncodeReordering", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9035>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Tag Thickness", "TagThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9036>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Partial Fourier", "PartialFourierDirection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9037>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Synchronization", "CardiacSynchronizationTechnique", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9041>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Receive Coil", "ReceiveCoilManufacturerName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "MR Receive Coil", "MRReceiveCoilSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9043>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Receive Coil Type", "ReceiveCoilType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9044>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Quadrature Receive", "QuadratureReceiveCoil", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9045>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Multi-Coil", "MultiCoilDefinitionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9046>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Multi-Coil", "MultiCoilConfiguration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9047>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Multi-Coil Element", "MultiCoilElementName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9048>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Multi-Coil Element", "MultiCoilElementUsed", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9049>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "MR Transmit Coil", "MRTransmitCoilSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Transmit Coil", "TransmitCoilManufacturerName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9051>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Transmit Coil Type", "TransmitCoilType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Spectral Width", "SpectralWidth", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9053>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Chemical Shift", "ChemicalShiftReference", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9054>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Volume Localization", "VolumeLocalizationTechnique", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9058>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Frequency Encoding", "MRAcquisitionFrequencyEncodingSteps", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9059>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "De-coupling", "Decoupling", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "De-coupled Nucleus", "DecoupledNucleus", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9061>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "De-coupling", "DecouplingFrequency", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9062>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "De-coupling Method", "DecouplingMethod", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9063>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Chemical Shift", "DecouplingChemicalShiftReference", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9064>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "k-space Filtering", "KSpaceFiltering", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9065>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Time Domain", "TimeDomainFiltering", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9066>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Zero", "NumberOfZeroFills", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9067>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Baseline Correction", "BaselineCorrection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9069>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Parallel Reduction", "ParallelReductionFactorInPlane", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "R Interval", "CardiacRRIntervalSpecified", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9073>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Acquisition", "AcquisitionDuration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9074>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Frame Acquisition", "FrameAcquisitionDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9075>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Diffusion", "DiffusionDirectionality", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9076>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Diffusion Gradient", "DiffusionGradientDirectionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9077>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Parallel", "ParallelAcquisition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9078>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Acquisition", "ParallelAcquisitionTechnique", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9079>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Inversion Times", "InversionTimes", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Metabolite Map", "MetaboliteMapDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9081>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Partial Fourier", "PartialFourier", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9082>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Effective Echo Time", "EffectiveEchoTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9083>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Metabolite Map Code", "MetaboliteMapCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9084>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Chemical Shift", "ChemicalShiftSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9085>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Cardiac Signal", "CardiacSignalSource", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9087>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Diffusion b-value", "DiffusionBValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9089>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Diffusion Gradient", "DiffusionGradientOrientation", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9090>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Velocity Encoding", "VelocityEncodingDirection", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9091>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Velocity Encoding", "VelocityEncodingMinimumValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9092>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Acquisition", "VelocityEncodingAcquisitionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9093>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of k-Space", "NumberOfKSpaceTrajectories", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9094>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Coverage of k-Space", "CoverageOfKSpace", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9095>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Acquisition Phase", "SpectroscopyAcquisitionPhaseRows", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9096>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Factor In-plane", "ParallelReductionFactorInPlaneRetired", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9098>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Transmitter", "TransmitterFrequency", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Resonant Nucleus", "ResonantNucleus", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9101>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Frequency", "FrequencyCorrection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9103>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "FOV/Geometry", "MRSpectroscopyFOVGeometrySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9104>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Slab Thickness", "SlabThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9105>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Slab Orientation", "SlabOrientation", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9106>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Mid Slab Position", "MidSlabPosition", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9107>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "MR Spatial", "MRSpatialSaturationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9112>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Related Parameters", "MRTimingAndRelatedParametersSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9114>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "MR Echo Sequence", "MREchoSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9115>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "MR Modifier", "MRModifierSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9117>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "MR Diffusion", "MRDiffusionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9118>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Synchronization", "CardiacSynchronizationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9119>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "MR Averages", "MRAveragesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9125>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "MR FOV/Geometry", "MRFOVGeometrySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9126>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Volume Localization", "VolumeLocalizationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9127>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Acquisition Data", "SpectroscopyAcquisitionDataColumns", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9147>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Diffusion", "DiffusionAnisotropyType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9151>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Frame Reference", "FrameReferenceDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9152>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "MR Metabolite Map", "MRMetaboliteMapSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9155>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Parallel Reduction", "ParallelReductionFactorOutOfPlane", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9159>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Acquisition Out-of-", "SpectroscopyAcquisitionOutOfPlanePhaseSteps", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9166>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Bulk Motion Status", "BulkMotionStatus", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9168>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Factor Second In-", "ParallelReductionFactorSecondInPlane", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9169>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Cardiac Beat", "CardiacBeatRejectionTechnique", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9170>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Compensation", "RespiratoryMotionCompensationTechnique", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9171>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Respiratory Signal", "RespiratorySignalSource", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9172>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Compensation", "BulkMotionCompensationTechnique", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9173>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Bulk Motion Signal", "BulkMotionSignalSource", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9174>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Applicable Safety", "ApplicableSafetyStandardAgency", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9175>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Standard", "ApplicableSafetyStandardDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9176>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Operating Mode", "OperatingModeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9177>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Operating Mode Type", "OperatingModeType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9178>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Operating Mode", "OperatingMode", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9179>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Specific Absorption", "SpecificAbsorptionRateDefinition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9180>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Gradient Output", "GradientOutputType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9181>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Specific Absorption", "SpecificAbsorptionRateValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9182>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Gradient Output", "GradientOutput", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9183>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Flow Compensation", "FlowCompensationDirection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9184>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Tagging Delay", "TaggingDelay", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9185>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Compensation", "RespiratoryMotionCompensationTechniqueDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9186>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Respiratory Signal", "RespiratorySignalSourceID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9195>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Minimum Integration", "ChemicalShiftMinimumIntegrationLimitInHz", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9196>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Maximum Integration", "ChemicalShiftMaximumIntegrationLimitInHz", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9197>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "MR Velocity", "MRVelocityEncodingSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9198>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "First Order Phase", "FirstOrderPhaseCorrection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9199>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Water Referenced", "WaterReferencedPhaseCorrection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9200>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "MR Spectroscopy", "MRSpectroscopyAcquisitionType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9214>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Respiratory Cycle", "RespiratoryCyclePosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9217>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Velocity Encoding", "VelocityEncodingMaximumValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9218>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Tag Spacing Second", "TagSpacingSecondDimension", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9219>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SS, "Tag Angle Second", "TagAngleSecondAxis", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9220>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Frame Acquisition", "FrameAcquisitionDuration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9226>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "MR Image Frame Type", "MRImageFrameTypeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9227>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "MR Spectroscopy", "MRSpectroscopyFrameTypeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9231>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Phase Encoding", "MRAcquisitionPhaseEncodingStepsInPlane", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9232>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Phase Encoding", "MRAcquisitionPhaseEncodingStepsOutOfPlane", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9234>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Acquisition Phase", "SpectroscopyAcquisitionPhaseColumns", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9236>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Cardiac Cycle", "CardiacCyclePosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9239>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Specific Absorption", "SpecificAbsorptionRateSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9240>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "RF Echo Train", "RFEchoTrainLength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9241>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Gradient Echo Train", "GradientEchoTrainLength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9250>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Arterial Spin", "ArterialSpinLabelingContrast", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9251>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "MR Arterial Spin", "MRArterialSpinLabelingSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9252>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "ASL Technique", "ASLTechniqueDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9253>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "ASL Slab Number", "ASLSlabNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9254>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "ASL Slab Thickness", "ASLSlabThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9255>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "ASL Slab", "ASLSlabOrientation", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9256>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "ASL Mid Slab", "ASLMidSlabPosition", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9257>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "ASL Context", "ASLContext", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9258>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "ASL Pulse Train", "ASLPulseTrainDuration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9259>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "ASL Crusher Flag", "ASLCrusherFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x925A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "ASL Crusher Flow", "ASLCrusherFlow", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x925B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "ASL Crusher", "ASLCrusherDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x925C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "ASL Bolus Cut-off", "ASLBolusCutoffFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x925D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "ASL Bolus Cut-off", "ASLBolusCutoffTimingSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x925E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "ASL Bolus Cut-off", "ASLBolusCutoffTechnique", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x925F>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "ASL Bolus Cut-off", "ASLBolusCutoffDelayTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9260>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "ASL Slab Sequence", "ASLSlabSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9295>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Minimum Integration", "ChemicalShiftMinimumIntegrationLimitInppm", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9296>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Maximum Integration", "ChemicalShiftMaximumIntegrationLimitInppm", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9301>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "CT Acquisition Type", "CTAcquisitionTypeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9302>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Acquisition Type", "AcquisitionType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9303>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Tube Angle", "TubeAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9304>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "CT Acquisition", "CTAcquisitionDetailsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9305>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Revolution Time", "RevolutionTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9306>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Single Collimation", "SingleCollimationWidth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9307>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Total Collimation", "TotalCollimationWidth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9308>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "CT Table Dynamics", "CTTableDynamicsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9309>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Table Speed", "TableSpeed", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9310>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Table Feed per", "TableFeedPerRotation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9311>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Spiral Pitch Factor", "SpiralPitchFactor", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9312>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "CT Geometry", "CTGeometrySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9313>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Data Collection", "DataCollectionCenterPatient", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9314>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "CT Reconstruction", "CTReconstructionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9315>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Reconstruction", "ReconstructionAlgorithm", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9316>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Convolution Kernel", "ConvolutionKernelGroup", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9317>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Reconstruction", "ReconstructionFieldOfView", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9318>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Target Center", "ReconstructionTargetCenterPatient", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9319>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Reconstruction", "ReconstructionAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9320>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Image Filter", "ImageFilter", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9321>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "CT Exposure", "CTExposureSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9322>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Reconstruction", "ReconstructionPixelSpacing", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9323>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Exposure Modulation", "ExposureModulationType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9324>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Estimated Dose", "EstimatedDoseSaving", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9325>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "CT X-Ray Details", "CTXRayDetailsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9326>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "CT Position", "CTPositionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9327>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Table Position", "TablePosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9328>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Exposure Time in ms", "ExposureTimeInms", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9329>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "CT Image Frame Type", "CTImageFrameTypeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9330>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "X-Ray Tube Current", "XRayTubeCurrentInmA", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9332>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Exposure in mAs", "ExposureInmAs", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9333>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Constant Volume", "ConstantVolumeFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9334>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Fluoroscopy Flag", "FluoroscopyFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9335>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Data Collection", "DistanceSourceToDataCollectionCenter", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9337>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Contrast/Bolus", "ContrastBolusAgentNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9338>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Ingredient Code", "ContrastBolusIngredientCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9340>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Administration", "ContrastAdministrationProfileSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9341>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Contrast/Bolus", "ContrastBolusUsageSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9342>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Contrast/Bolus", "ContrastBolusAgentAdministered", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9343>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Contrast/Bolus", "ContrastBolusAgentDetected", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9344>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Contrast/Bolus", "ContrastBolusAgentPhase", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9345>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "CTDIvol", "CTDIvol", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9346>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "CTDI Phantom Type", "CTDIPhantomTypeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9351>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Calcium Scoring", "CalciumScoringMassFactorPatient", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9352>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Calcium Scoring", "CalciumScoringMassFactorDevice", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9353>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Energy Weighting", "EnergyWeightingFactor", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9360>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "CT Additional X-Ray", "CTAdditionalXRaySourceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9401>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Calibration", "ProjectionPixelCalibrationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9402>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Distance Source to", "DistanceSourceToIsocenter", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9403>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Distance Object to", "DistanceObjectToTableTop", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9404>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Spacing in Center", "ObjectPixelSpacingInCenterOfBeam", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9405>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Positioner Position", "PositionerPositionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9406>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Table Position", "TablePositionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9407>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Collimator Shape", "CollimatorShapeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9410>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Planes in", "PlanesInAcquisition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9412>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Characteristics", "XAXRFFrameCharacteristicsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9417>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Frame Acquisition", "FrameAcquisitionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9420>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "X-Ray Receptor Type", "XRayReceptorType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9423>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Acquisition", "AcquisitionProtocolName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9424>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Protocol", "AcquisitionProtocolDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9425>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Contrast/Bolus", "ContrastBolusIngredientOpaque", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9426>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Plane to Detector", "DistanceReceptorPlaneToDetectorHousing", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9427>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Intensifier Active", "IntensifierActiveShape", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9428>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Intensifier Active", "IntensifierActiveDimensions", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9429>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Physical Detector", "PhysicalDetectorSize", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9430>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Isocenter", "PositionOfIsocenterProjection", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9432>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Field of View", "FieldOfViewSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9433>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Field of View", "FieldOfViewDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9434>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Sensing Regions", "ExposureControlSensingRegionsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9435>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Sensing Region", "ExposureControlSensingRegionShape", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9436>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SS, "Sensing Region Left", "ExposureControlSensingRegionLeftVerticalEdge", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9437>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SS, "Sensing Region", "ExposureControlSensingRegionRightVerticalEdge", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9438>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SS, "Sensing Region", "ExposureControlSensingRegionUpperHorizontalEdge", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9439>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SS, "Sensing Region", "ExposureControlSensingRegionLowerHorizontalEdge", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9440>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SS, "Exposure Control", "CenterOfCircularExposureControlSensingRegion", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9441>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Exposure Control", "RadiusOfCircularExposureControlSensingRegion", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9442>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SS, "Polygonal Exposure", "VerticesOfThePolygonalExposureControlSensingRegion", "2-", false) {}
};

template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9447>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Column Angulation", "ColumnAngulationPatient", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9449>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Beam Angle", "BeamAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9451>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Frame Detector", "FrameDetectorParametersSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9452>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Calculated Anatomy", "CalculatedAnatomyThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9455>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Calibration", "CalibrationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9456>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Object Thickness", "ObjectThicknessSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9457>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Plane", "PlaneIdentification", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9461>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Dimension(s) in", "FieldOfViewDimensionsInFloat", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9462>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Isocenter Reference", "IsocenterReferenceSystemSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9463>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Isocenter Primary", "PositionerIsocenterPrimaryAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9464>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Isocenter Secondary", "PositionerIsocenterSecondaryAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9465>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Isocenter Detector", "PositionerIsocenterDetectorRotationAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9466>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Table X Position to", "TableXPositionToIsocenter", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9467>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Table Y Position to", "TableYPositionToIsocenter", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9468>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Table Z Position to", "TableZPositionToIsocenter", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9469>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Table Horizontal", "TableHorizontalRotationAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9470>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Table Head Tilt", "TableHeadTiltAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9471>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Table Cradle Tilt", "TableCradleTiltAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9472>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Frame Display", "FrameDisplayShutterSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9473>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Acquired Image Area", "AcquiredImageAreaDoseProduct", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9474>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Tabletop", "CArmPositionerTabletopRelationship", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9476>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "X-Ray Geometry", "XRayGeometrySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9477>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Identification", "IrradiationEventIdentificationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9504>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "X-Ray 3D Frame Type", "XRay3DFrameTypeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9506>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Contributing", "ContributingSourcesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9507>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Acquisition", "XRay3DAcquisitionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9508>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Primary Positioner", "PrimaryPositionerScanArc", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9509>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Secondary", "SecondaryPositionerScanArc", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9510>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Primary Positioner", "PrimaryPositionerScanStartAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9511>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Positioner Scan", "SecondaryPositionerScanStartAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9514>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Primary Positioner", "PrimaryPositionerIncrement", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9515>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Positioner", "SecondaryPositionerIncrement", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9516>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Start Acquisition", "StartAcquisitionDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9517>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "End Acquisition", "EndAcquisitionDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9524>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Application Name", "ApplicationName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9525>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Application Version", "ApplicationVersion", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9526>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Application", "ApplicationManufacturer", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9527>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Algorithm Type", "AlgorithmType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9528>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Algorithm", "AlgorithmDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9530>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Reconstruction", "XRay3DReconstructionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9531>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Reconstruction", "ReconstructionDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9538>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Acquisition", "PerProjectionAcquisitionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9601>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Diffusion b-matrix", "DiffusionBMatrixSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9602>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Diffusion b-value", "DiffusionBValueXX", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9603>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Diffusion b-value", "DiffusionBValueXY", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9604>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Diffusion b-value", "DiffusionBValueXZ", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9605>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Diffusion b-value", "DiffusionBValueYY", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9606>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Diffusion b-value", "DiffusionBValueYZ", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9607>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Diffusion b-value", "DiffusionBValueZZ", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9701>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Decay Correction", "DecayCorrectionDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9715>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Start Density", "StartDensityThreshold", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9716>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Density Difference", "StartRelativeDensityDifferenceThreshold", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9717>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Trigger Count", "StartCardiacTriggerCountThreshold", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9718>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Trigger Count", "StartRespiratoryTriggerCountThreshold", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9719>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Termination Counts", "TerminationCountsThreshold", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9720>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Termination Density", "TerminationDensityThreshold", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9721>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Relative Density", "TerminationRelativeDensityThreshold", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9722>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Termination Time", "TerminationTimeThreshold", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9723>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Trigger Count", "TerminationCardiacTriggerCountThreshold", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9724>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Respiratory Trigger", "TerminationRespiratoryTriggerCountThreshold", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9725>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Detector Geometry", "DetectorGeometry", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9726>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Transverse Detector", "TransverseDetectorSeparation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9727>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Axial Detector", "AxialDetectorDimension", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9729>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Radiopharmaceutical", "RadiopharmaceuticalAgentNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9732>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Acquisition", "PETFrameAcquisitionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9733>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "PET Detector Motion", "PETDetectorMotionDetailsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9734>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "PET Table Dynamics", "PETTableDynamicsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9735>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "PET Position", "PETPositionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9736>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Correction Factors", "PETFrameCorrectionFactorsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9737>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Radiopharmaceutical", "RadiopharmaceuticalUsageSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9738>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Attenuation", "AttenuationCorrectionSource", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9739>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of", "NumberOfIterations", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9740>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Subsets", "NumberOfSubsets", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9749>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "PET Reconstruction", "PETReconstructionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9751>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "PET Frame Type", "PETFrameTypeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9755>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Time of Flight", "TimeOfFlightInformationUsed", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9756>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Reconstruction Type", "ReconstructionType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9758>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Decay Corrected", "DecayCorrected", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9759>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Attenuation", "AttenuationCorrected", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9760>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Scatter Corrected", "ScatterCorrected", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9761>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Dead Time Corrected", "DeadTimeCorrected", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9762>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Gantry Motion", "GantryMotionCorrected", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9763>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Patient Motion", "PatientMotionCorrected", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9764>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Normalization", "CountLossNormalizationCorrected", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9765>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Randoms Corrected", "RandomsCorrected", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9766>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Non-uniform Radial", "NonUniformRadialSamplingCorrected", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9767>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Sensitivity", "SensitivityCalibrated", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9768>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Normalization", "DetectorNormalizationCorrection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9769>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Reconstruction", "IterativeReconstructionMethod", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9770>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Correction Temporal", "AttenuationCorrectionTemporalRelationship", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9771>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Physiological State", "PatientPhysiologicalStateSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9772>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Physiological State", "PatientPhysiologicalStateCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9801>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Depth(s) of Focus", "DepthsOfFocus", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9803>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Excluded Intervals", "ExcludedIntervalsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9804>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Exclusion Start", "ExclusionStartDatetime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9805>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Exclusion Duration", "ExclusionDuration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9806>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Description", "USImageDescriptionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9807>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Image Data Type", "ImageDataTypeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9808>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Data Type", "DataType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x9809>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Pattern Code", "TransducerScanPatternCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x980B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Aliased Data Type", "AliasedDataType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x980C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Position Measuring", "PositionMeasuringDeviceUsed", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x980D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Transducer Geometry", "TransducerGeometryCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x980E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Steering Code", "TransducerBeamSteeringCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0x980F>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Application Code", "TransducerApplicationCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0xA001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Contributing", "ContributingEquipmentSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0xA002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Contribution Date", "ContributionDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0018>, bool_t<(eid & 0xffff) == 0xA003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Contribution", "ContributionDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x000D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Study Instance UID", "StudyInstanceUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x000E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Series Instance UID", "SeriesInstanceUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Study ID", "StudyID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Series Number", "SeriesNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Acquisition Number", "AcquisitionNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0013>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Instance Number", "InstanceNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Isotope Number", "IsotopeNumber", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0015>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Phase Number", "PhaseNumber", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Interval Number", "IntervalNumber", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0017>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Time Slot Number", "TimeSlotNumber", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0018>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Angle Number", "AngleNumber", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0019>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Item Number", "ItemNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Patient Orientation", "PatientOrientation", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Overlay Number", "OverlayNumber", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Curve Number", "CurveNumber", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0026>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "LUT Number", "LUTNumber", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Image Position", "ImagePosition", "3", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Image Position", "ImagePositionPatient", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0035>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Image Orientation", "ImageOrientation", "6", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0037>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Image Orientation", "ImageOrientationPatient", "6", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Location", "Location", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Frame of Reference", "FrameOfReferenceUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Laterality", "Laterality", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0062>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Image Laterality", "ImageLaterality", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Image Geometry Type", "ImageGeometryType", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Masking Image", "MaskingImage", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x00AA>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Report Number", "ReportNumber", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Temporal Position", "TemporalPositionIdentifier", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0105>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Temporal", "NumberOfTemporalPositions", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Temporal Resolution", "TemporalResolution", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0200>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Frame of Reference", "SynchronizationFrameOfReferenceUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x0242>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Concatenation", "SOPInstanceUIDOfConcatenationSource", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x1000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Series in Study", "SeriesInStudy", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x1001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Acquisitions in", "AcquisitionsInSeries", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x1002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Images in", "ImagesInAcquisition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x1003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Images in Series", "ImagesInSeries", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x1004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Acquisitions in", "AcquisitionsInStudy", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x1005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Images in Study", "ImagesInStudy", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x1020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Reference", "Reference", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x1040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Position Reference", "PositionReferenceIndicator", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x1041>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Slice Location", "SliceLocation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x1070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Other Study Numbers", "OtherStudyNumbers", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x1200>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Patient", "NumberOfPatientRelatedStudies", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x1202>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Patient", "NumberOfPatientRelatedSeries", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x1204>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Patient", "NumberOfPatientRelatedInstances", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x1206>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Study", "NumberOfStudyRelatedSeries", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x1208>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Study", "NumberOfStudyRelatedInstances", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x1209>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Series", "NumberOfSeriesRelatedInstances", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x3100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Source Image IDs", "SourceImageIDs", "1-", true) {}
};

template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x3401>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Modifying Device ID", "ModifyingDeviceID", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x3402>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Modified Image ID", "ModifiedImageID", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x3403>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Modified Image Date", "ModifiedImageDate", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x3404>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Modifying Device", "ModifyingDeviceManufacturer", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x3405>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Modified Image Time", "ModifiedImageTime", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x3406>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Modified Image", "ModifiedImageDescription", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x4000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Image Comments", "ImageComments", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x5000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Original Image", "OriginalImageIdentification", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x5002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Identification", "OriginalImageIdentificationNomenclature", "n", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9056>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Stack ID", "StackID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9057>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "In-Stack Position", "InStackPositionNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9071>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Frame Anatomy", "FrameAnatomySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9072>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Frame Laterality", "FrameLaterality", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9111>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Frame Content", "FrameContentSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9113>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Plane Position", "PlanePositionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9116>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Plane Orientation", "PlaneOrientationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9128>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Temporal Position", "TemporalPositionIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9153>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Nominal Cardiac", "NominalCardiacTriggerDelayTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9154>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Trigger Time Prior", "NominalCardiacTriggerTimePriorToRPeak", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9155>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Trigger Time Prior", "ActualCardiacTriggerTimePriorToRPeak", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9156>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Frame Acquisition", "FrameAcquisitionNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9157>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Dimension Index", "DimensionIndexValues", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9158>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Frame Comments", "FrameComments", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9161>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Concatenation UID", "ConcatenationUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9162>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "In-concatenation", "InConcatenationNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9163>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "In-concatenation", "InConcatenationTotalNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9164>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Dimension", "DimensionOrganizationUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9165>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Dimension Index", "DimensionIndexPointer", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9167>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Functional Group", "FunctionalGroupPointer", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9213>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Dimension Index", "DimensionIndexPrivateCreator", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9221>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Organization", "DimensionOrganizationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9222>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Dimension Index", "DimensionIndexSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9228>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Concatenation Frame", "ConcatenationFrameOffsetNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9238>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Functional Group", "FunctionalGroupPrivateCreator", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9241>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Nominal Percentage", "NominalPercentageOfCardiacPhase", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9245>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "of Respiratory", "NominalPercentageOfRespiratoryPhase", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9246>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Respiratory", "StartingRespiratoryAmplitude", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9247>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Starting", "StartingRespiratoryPhase", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9248>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Ending Respiratory", "EndingRespiratoryAmplitude", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9249>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Ending Respiratory", "EndingRespiratoryPhase", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9250>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Respiratory Trigger", "RespiratoryTriggerType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9251>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "R-R Interval Time", "RRIntervalTimeNominal", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9252>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Actual Cardiac", "ActualCardiacTriggerDelayTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9253>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Synchronization", "RespiratorySynchronizationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9254>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Respiratory", "RespiratoryIntervalTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9255>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Nominal Respiratory", "NominalRespiratoryTriggerDelayTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9256>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Respiratory Trigger", "RespiratoryTriggerDelayThreshold", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9257>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Actual Respiratory", "ActualRespiratoryTriggerDelayTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9301>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Image Position", "ImagePositionVolume", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9302>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Image Orientation", "ImageOrientationVolume", "6", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9307>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Acquisition", "UltrasoundAcquisitionGeometry", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9308>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Apex Position", "ApexPosition", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9309>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Transducer Mapping", "VolumeToTransducerMappingMatrix", "16", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x930A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Volume to Table", "VolumeToTableMappingMatrix", "16", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x930C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Patient Frame of", "PatientFrameOfReferenceSource", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x930D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Temporal Position", "TemporalPositionTimeOffset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x930E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Plane Position", "PlanePositionVolumeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x930F>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Plane Orientation", "PlaneOrientationVolumeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9310>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Temporal Position", "TemporalPositionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9311>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Dimension", "DimensionOrganizationType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9312>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Volume Frame of", "VolumeFrameOfReferenceUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9313>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Table Frame of", "TableFrameOfReferenceUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9421>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Dimension", "DimensionDescriptionLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9450>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Patient Orientation", "PatientOrientationInFrameSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9453>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Frame Label", "FrameLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9518>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Acquisition Index", "AcquisitionIndex", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9529>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Instances Reference", "ContributingSOPInstancesReferenceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0020>, bool_t<(eid & 0xffff) == 0x9536>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Reconstruction", "ReconstructionIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Pass-Through", "LightPathFilterPassThroughWavelength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Light Path Filter", "LightPathFilterPassBand", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Pass-Through", "ImagePathFilterPassThroughWavelength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Image Path Filter", "ImagePathFilterPassBand", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Patient Eye", "PatientEyeMovementCommanded", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Movement Command", "PatientEyeMovementCommandCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0007>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Spherical Lens", "SphericalLensPower", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Cylinder Lens Power", "CylinderLensPower", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0009>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Cylinder Axis", "CylinderAxis", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x000A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Emmetropic", "EmmetropicMagnification", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x000B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Intra Ocular", "IntraOcularPressure", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x000C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Horizontal Field of", "HorizontalFieldOfView", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x000D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Pupil Dilated", "PupilDilated", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x000E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Degree of Dilation", "DegreeOfDilation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Stereo Baseline", "StereoBaselineAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Stereo Baseline", "StereoBaselineDisplacement", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Stereo Horizontal", "StereoHorizontalPixelOffset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0013>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Stereo Vertical", "StereoVerticalPixelOffset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Stereo Rotation", "StereoRotation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0015>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Acquisition Device", "AcquisitionDeviceTypeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Illumination Type", "IlluminationTypeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0017>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Type Stack Code", "LightPathFilterTypeStackCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0018>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Type Stack Code", "ImagePathFilterTypeStackCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0019>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Lenses Code", "LensesCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x001A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Channel Description", "ChannelDescriptionCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x001B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Refractive State", "RefractiveStateSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x001C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Mydriatic Agent", "MydriaticAgentCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x001D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Position Code", "RelativeImagePositionCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x001E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Camera Angle of", "CameraAngleOfView", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Stereo Pairs", "StereoPairsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0021>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Left Image Sequence", "LeftImageSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Right Image", "RightImageSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Axial Length of the", "AxialLengthOfTheEye", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0031>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Ophthalmic Frame", "OphthalmicFrameLocationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Reference", "ReferenceCoordinates", "2-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0035>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Depth Spatial", "DepthSpatialResolution", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0036>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Maximum Depth", "MaximumDepthDistortion", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0037>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Along-scan Spatial", "AlongScanSpatialResolution", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0038>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Maximum Along-scan", "MaximumAlongScanDistortion", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0039>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Ophthalmic Image", "OphthalmicImageOrientation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0041>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Depth of Transverse", "DepthOfTransverseImage", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Concentration Units", "MydriaticAgentConcentrationUnitsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0048>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Across-scan Spatial", "AcrossScanSpatialResolution", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0049>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Maximum Across-scan", "MaximumAcrossScanDistortion", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x004E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Mydriatic Agent", "MydriaticAgentConcentration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0055>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Illumination Wave", "IlluminationWaveLength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0056>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Illumination Power", "IlluminationPower", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0057>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Illumination", "IlluminationBandwidth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x0058>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Mydriatic Agent", "MydriaticAgentSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1007>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Measurements Right", "OphthalmicAxialMeasurementsRightEyeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Measurements Left", "OphthalmicAxialMeasurementsLeftEyeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Length Measurements", "OphthalmicAxialLengthMeasurementsType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1019>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Ophthalmic Axial", "OphthalmicAxialLength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Lens Status Code", "LensStatusCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1025>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Vitreous Status", "VitreousStatusCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "IOL Formula Code", "IOLFormulaCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1029>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "IOL Formula Detail", "IOLFormulaDetail", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1033>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Keratometer Index", "KeratometerIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1035>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Ophthalmic Axial", "SourceOfOphthalmicAxialLengthCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1037>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Target Refraction", "TargetRefraction", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1039>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Refractive", "RefractiveProcedureOccurred", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Refractive Surgery", "RefractiveSurgeryTypeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1044>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Ultrasound Axial", "OphthalmicUltrasoundAxialMeasurementsTypeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Length Measurements", "OphthalmicAxialLengthMeasurementsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1053>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "IOL Power", "IOLPower", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1054>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Predicted", "PredictedRefractiveError", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1059>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Ophthalmic Axial", "OphthalmicAxialLengthVelocity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1065>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Lens Status", "LensStatusDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1066>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Vitreous Status", "VitreousStatusDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1090>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "IOL Power Sequence", "IOLPowerSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1092>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Lens Constant", "LensConstantSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1093>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "IOL Manufacturer", "IOLManufacturer", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1094>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Lens Constant", "LensConstantDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1096>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Measurement Type", "KeratometryMeasurementTypeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Ophthalmic Axial", "ReferencedOphthalmicAxialMeasurementsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1101>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Length Measurements", "OphthalmicAxialLengthMeasurementsSegmentNameCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1103>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Before Refractive", "RefractiveErrorBeforeRefractiveSurgeryCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1121>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "IOL Power For Exact", "IOLPowerForExactEmmetropia", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1122>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "IOL Power For Exact", "IOLPowerForExactTargetRefraction", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1125>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Depth Definition", "AnteriorChamberDepthDefinitionCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1130>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Lens Thickness", "LensThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1131>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Anterior Chamber", "AnteriorChamberDepth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1132>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Thickness Data Code", "SourceOfLensThicknessDataCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1133>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Chamber Depth Data", "SourceOfAnteriorChamberDepthDataCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1135>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Refractive Error", "SourceOfRefractiveErrorDataCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1140>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Length Measurement", "OphthalmicAxialLengthMeasurementModified", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1150>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Length Data Source", "OphthalmicAxialLengthDataSourceCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1153>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Length Acquisition", "OphthalmicAxialLengthAcquisitionMethodCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1155>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Signal to Noise", "SignalToNoiseRatio", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1159>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Length Data Source", "OphthalmicAxialLengthDataSourceDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1210>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Length Measurements", "OphthalmicAxialLengthMeasurementsTotalLengthSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1211>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Length Measurements", "OphthalmicAxialLengthMeasurementsSegmentalLengthSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1212>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Length Measurements", "OphthalmicAxialLengthMeasurementsLengthSummationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1220>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Ophthalmic Axial", "UltrasoundOphthalmicAxialLengthMeasurementsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1225>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Axial Length", "OpticalOphthalmicAxialLengthMeasurementsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1230>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Ophthalmic Axial", "UltrasoundSelectedOphthalmicAxialLengthSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1250>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Length Selection", "OphthalmicAxialLengthSelectionMethodCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1255>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Ophthalmic Axial", "OpticalSelectedOphthalmicAxialLengthSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1257>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Ophthalmic Axial", "SelectedSegmentalOphthalmicAxialLengthSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1260>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Ophthalmic Axial", "SelectedTotalOphthalmicAxialLengthSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1262>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Length Quality", "OphthalmicAxialLengthQualityMetricSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1273>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Length Quality", "OphthalmicAxialLengthQualityMetricTypeDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1300>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Calculations Right", "IntraocularLensCalculationsRightEyeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1310>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Calculations Left", "IntraocularLensCalculationsLeftEyeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0022>, bool_t<(eid & 0xffff) == 0x1330>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Ophthalmic Axial", "ReferencedOphthalmicAxialLengthMeasurementQCImageSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Visual Field", "VisualFieldHorizontalExtent", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Visual Field", "VisualFieldVerticalExtent", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Visual Field Shape", "VisualFieldShape", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Screening Test Mode", "ScreeningTestModeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0018>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Maximum Stimulus", "MaximumStimulusLuminance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Background", "BackgroundLuminance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0021>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Stimulus Color Code", "StimulusColorCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Illumination Color", "BackgroundIlluminationColorCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0025>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Stimulus Area", "StimulusArea", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Stimulus", "StimulusPresentationTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Fixation Sequence", "FixationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0033>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Fixation Monitoring", "FixationMonitoringCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0034>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Visual Field Catch", "VisualFieldCatchTrialSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0035>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Fixation Checked", "FixationCheckedQuantity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0036>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Properly Fixated", "PatientNotProperlyFixatedQuantity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0037>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Presented Visual", "PresentedVisualStimuliDataFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0038>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Visual", "NumberOfVisualStimuli", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0039>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Excessive Fixation", "ExcessiveFixationLossesDataFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Excessive Fixation", "ExcessiveFixationLosses", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Stimuli Retesting", "StimuliRetestingQuantity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0044>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Patients", "CommentsOnPatientPerformanceOfVisualField", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0045>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "False Negatives", "FalseNegativesEstimateFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0046>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "False Negatives", "FalseNegativesEstimate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0048>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Negative Catch", "NegativeCatchTrialsQuantity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "False Negatives", "FalseNegativesQuantity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0051>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Excessive False", "ExcessiveFalseNegativesDataFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Excessive False", "ExcessiveFalseNegatives", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0053>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "False Positives", "FalsePositivesEstimateFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0054>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "False Positives", "FalsePositivesEstimate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0055>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Catch Trials Data", "CatchTrialsDataFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0056>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Positive Catch", "PositiveCatchTrialsQuantity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0057>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Test Point Normals", "TestPointNormalsDataFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0058>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Test Point Normals", "TestPointNormalsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0059>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Probability Normals", "GlobalDeviationProbabilityNormalsFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "False Positives", "FalsePositivesQuantity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0061>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Excessive False", "ExcessiveFalsePositivesDataFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0062>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Excessive False", "ExcessiveFalsePositives", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0063>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Visual Field Test", "VisualFieldTestNormalsFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0064>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Results Normals", "ResultsNormalsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0065>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Sensitivity", "AgeCorrectedSensitivityDeviationAlgorithmSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0066>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Global Deviation", "GlobalDeviationFromNormal", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0067>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Sensitivity", "GeneralizedDefectSensitivityDeviationAlgorithmSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0068>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Localized Deviation", "LocalizedDeviationfromNormal", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0069>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Patient Reliability", "PatientReliabilityIndicator", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Visual Field Mean", "VisualFieldMeanSensitivity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0071>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Global Deviation", "GlobalDeviationProbability", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0072>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Probability Normals", "LocalDeviationProbabilityNormalsFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0073>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Localized Deviation", "LocalizedDeviationProbability", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0074>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Fluctuation", "ShortTermFluctuationCalculated", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0075>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Short Term", "ShortTermFluctuation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0076>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Fluctuation", "ShortTermFluctuationProbabilityCalculated", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0077>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Fluctuation", "ShortTermFluctuationProbability", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0078>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Deviation From", "CorrectedLocalizedDeviationFromNormalCalculated", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0079>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Deviation From", "CorrectedLocalizedDeviationFromNormal", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Deviation From", "CorrectedLocalizedDeviationFromNormalProbabilityCalculated", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0081>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Deviation From", "CorrectedLocalizedDeviationFromNormalProbability", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0083>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Probability", "GlobalDeviationProbabilitySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0085>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Probability", "LocalizedDeviationProbabilitySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0086>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Foveal Sensitivity", "FovealSensitivityMeasured", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0087>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Foveal Sensitivity", "FovealSensitivity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0088>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Visual Field Test", "VisualFieldTestDuration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0089>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Visual Field Test", "VisualFieldTestPointSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0090>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Visual Field Test", "VisualFieldTestPointXCoordinate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0091>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Visual Field Test", "VisualFieldTestPointYCoordinate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0092>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Sensitivity", "AgeCorrectedSensitivityDeviationValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0093>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Stimulus Results", "StimulusResults", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0094>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Sensitivity Value", "SensitivityValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0095>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Retest Stimulus", "RetestStimulusSeen", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0096>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Retest Sensitivity", "RetestSensitivityValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0097>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Point Normals", "VisualFieldTestPointNormalsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0098>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Quantified Defect", "QuantifiedDefect", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Sensitivity", "AgeCorrectedSensitivityDeviationProbabilityValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0102>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Corrected", "GeneralizedDefectCorrectedSensitivityDeviationFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0103>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Corrected", "GeneralizedDefectCorrectedSensitivityDeviationValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0104>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Sensitivity", "GeneralizedDefectCorrectedSensitivityDeviationProbabilityValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0105>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Minimum Sensitivity", "MinimumSensitivityValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0106>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Blind Spot", "BlindSpotLocalized", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0107>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Blind Spot X-", "BlindSpotXCoordinate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0108>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Blind Spot Y-", "BlindSpotYCoordinate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Measurement", "VisualAcuityMeasurementSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0112>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Parameters Used on", "RefractiveParametersUsedOnPatientSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0113>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Measurement", "MeasurementLaterality", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0114>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Clinical", "OphthalmicPatientClinicalInformationLeftEyeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0115>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Clinical", "OphthalmicPatientClinicalInformationRightEyeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0117>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Foveal Point", "FovealPointNormativeDataFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0118>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Foveal Point", "FovealPointProbabilityValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0120>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Screening Baseline", "ScreeningBaselineMeasured", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0122>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Screening Baseline", "ScreeningBaselineMeasuredSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0124>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Screening Baseline", "ScreeningBaselineType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0126>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Screening Baseline", "ScreeningBaselineValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0202>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Algorithm Source", "AlgorithmSource", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0306>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Data Set Name", "DataSetName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0307>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Data Set Version", "DataSetVersion", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0308>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Data Set Source", "DataSetSource", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0309>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Data Set", "DataSetDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0317>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Reliability Global", "VisualFieldTestReliabilityGlobalIndexSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0320>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Results Index", "VisualFieldGlobalResultsIndexSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0325>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Data Observation", "DataObservationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0338>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Index Normals Flag", "IndexNormalsFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0341>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Index Probability", "IndexProbability", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0024>, bool_t<(eid & 0xffff) == 0x0344>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Index Probability", "IndexProbabilitySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Samples per Pixel", "SamplesPerPixel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Samples per Pixel", "SamplesPerPixelUsed", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Photometric", "PhotometricInterpretation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Image Dimensions", "ImageDimensions", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Planar", "PlanarConfiguration", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Frames", "NumberOfFrames", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0009>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Frame Increment", "FrameIncrementPointer", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x000A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Frame Dimension", "FrameDimensionPointer", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Rows", "Rows", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Columns", "Columns", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Planes", "Planes", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Ultrasound Color", "UltrasoundColorDataPresent", "1", false) {}
};

template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Pixel Spacing", "PixelSpacing", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0031>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Zoom Factor", "ZoomFactor", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Zoom Center", "ZoomCenter", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0034>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Pixel Aspect Ratio", "PixelAspectRatio", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Image Format", "ImageFormat", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Manipulated Image", "ManipulatedImage", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0051>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Corrected Image", "CorrectedImage", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x005F>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Compression", "CompressionRecognitionCode", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Compression Code", "CompressionCode", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0061>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Compression", "CompressionOriginator", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0062>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Compression Label", "CompressionLabel", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0063>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Compression", "CompressionDescription", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0065>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Compression", "CompressionSequence", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0066>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Compression Step", "CompressionStepPointers", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0068>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Repeat Interval", "RepeatInterval", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0069>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Bits Grouped", "BitsGrouped", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Perimeter Table", "PerimeterTable", "1-", true) {}
};

template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Predictor Rows", "PredictorRows", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0081>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Predictor Columns", "PredictorColumns", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0082>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Predictor Constants", "PredictorConstants", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0090>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Blocked Pixels", "BlockedPixels", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0091>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Block Rows", "BlockRows", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0092>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Block Columns", "BlockColumns", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0093>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Row Overlap", "RowOverlap", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0094>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Column Overlap", "ColumnOverlap", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Bits Allocated", "BitsAllocated", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0101>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Bits Stored", "BitsStored", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0102>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "High Bit", "HighBit", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0103>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Pixel", "PixelRepresentation", "1", false) {}
};

template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0200>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Image Location", "ImageLocation", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0300>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Quality Control", "QualityControlImage", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0301>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Burned In", "BurnedInAnnotation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0302>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Recognizable Visual", "RecognizableVisualFeatures", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0303>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Temporal", "LongitudinalTemporalInformationModified", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0400>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Transform Label", "TransformLabel", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0401>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Transform Version", "TransformVersionNumber", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0402>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Transform", "NumberOfTransformSteps", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0403>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Sequence of", "SequenceOfCompressedData", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0404>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Details of", "DetailsOfCoefficients", "1-", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xff0f) == 0x0400>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Rows For Nth Order", "RowsForNthOrderCoefficients", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xff0f) == 0x0401>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Columns For Nth", "ColumnsForNthOrderCoefficients", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xff0f) == 0x0402>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Coefficient Coding", "CoefficientCoding", "1-", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xff0f) == 0x0403>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Coefficient Coding", "CoefficientCodingPointers", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0700>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "DCT Label", "DCTLabel", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0701>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Data Block", "DataBlockDescription", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0702>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Data Block", "DataBlock", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0710>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Normalization", "NormalizationFactorFormat", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0720>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Zonal Map Number", "ZonalMapNumberFormat", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0721>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Zonal Map Location", "ZonalMapLocation", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0722>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Zonal Map Format", "ZonalMapFormat", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0730>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Adaptive Map Format", "AdaptiveMapFormat", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0740>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Code Number Format", "CodeNumberFormat", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xff0f) == 0x0800>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Code Label", "CodeLabel", "1-", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xff0f) == 0x0802>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Tables", "NumberOfTables", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xff0f) == 0x0803>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Code Table Location", "CodeTableLocation", "1-", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xff0f) == 0x0804>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Bits For Code Word", "BitsForCodeWord", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xff0f) == 0x0808>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Image Data Location", "ImageDataLocation", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0A02>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Pixel Spacing", "PixelSpacingCalibrationType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x0A04>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Calibration", "PixelSpacingCalibrationDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Pixel Intensity", "PixelIntensityRelationship", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1041>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SS, "Pixel Intensity", "PixelIntensityRelationshipSign", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Window Center", "WindowCenter", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1051>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Window Width", "WindowWidth", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Rescale Intercept", "RescaleIntercept", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1053>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Rescale Slope", "RescaleSlope", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1054>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Rescale Type", "RescaleType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1055>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Window Center &amp;", "WindowCenterWidthExplanation", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1056>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "VOI LUT Function", "VOILUTFunction", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Gray Scale", "GrayScale", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1090>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Recommended Viewing", "RecommendedViewingMode", "1", false) {}
};

template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1104>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Lookup Table", "AlphaPaletteColorLookupTableDescriptor", "3", false) {}
};

template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1199>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Palette Color", "PaletteColorLookupTableUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1200>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SS, "Data", "GrayLookupTableData", "n", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1201>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Red Palette Color", "RedPaletteColorLookupTableData", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1202>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Green Palette Color", "GreenPaletteColorLookupTableData", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1203>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Blue Palette Color", "BluePaletteColorLookupTableData", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1204>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Alpha Palette Color", "AlphaPaletteColorLookupTableData", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1211>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Color Lookup Table", "LargeRedPaletteColorLookupTableData", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1212>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Color Lookup Table", "LargeGreenPaletteColorLookupTableData", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1213>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Color Lookup Table", "LargeBluePaletteColorLookupTableData", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1214>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Large Palette Color", "LargePaletteColorLookupTableUID", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1221>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Palette Color", "SegmentedRedPaletteColorLookupTableData", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1222>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Palette Color", "SegmentedGreenPaletteColorLookupTableData", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1223>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Palette Color", "SegmentedBluePaletteColorLookupTableData", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1300>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Breast Implant", "BreastImplantPresent", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1350>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Partial View", "PartialView", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1351>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Partial View", "PartialViewDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1352>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Partial View Code", "PartialViewCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x135A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Spatial Locations", "SpatialLocationsPreserved", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1401>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Data Frame", "DataFrameAssignmentSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1402>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Data Path", "DataPathAssignment", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1403>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Bits Mapped to", "BitsMappedToColorLookupTable", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1404>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Blending LUT 1", "BlendingLUT1Sequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1405>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Blending LUT 1", "BlendingLUT1TransferFunction", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1406>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Blending Weight", "BlendingWeightConstant", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1407>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Blending Lookup", "BlendingLookupTableDescriptor", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1408>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Blending Lookup", "BlendingLookupTableData", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x140B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Color Lookup Table", "EnhancedPaletteColorLookupTableSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x140C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Blending LUT 2", "BlendingLUT2Sequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x140D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Blending LUT 2", "BlendingLUT2TransferFunction", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x140E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Data Path ID", "DataPathID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x140F>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "RGB LUT Transfer", "RGBLUTTransferFunction", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x1410>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Alpha LUT Transfer", "AlphaLUTTransferFunction", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x2000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OB, "ICC Profile", "ICCProfile", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x2110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Lossy Image", "LossyImageCompression", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x2112>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Lossy Image", "LossyImageCompressionRatio", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x2114>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Lossy Image", "LossyImageCompressionMethod", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x3000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Modality LUT", "ModalityLUTSequence", "1", false) {}
};

template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x3003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "LUT Explanation", "LUTExplanation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x3004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Modality LUT Type", "ModalityLUTType", "1", false) {}
};

template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x3010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "VOI LUT Sequence", "VOILUTSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x3110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Softcopy VOI LUT", "SoftcopyVOILUTSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x4000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Image Presentation", "ImagePresentationComments", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x5000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Acquisition", "BiPlaneAcquisitionSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x6010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Representative", "RepresentativeFrameNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x6020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Frame Numbers of", "FrameNumbersOfInterest", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x6022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Frame of Interest", "FrameOfInterestDescription", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x6023>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Frame of Interest", "FrameOfInterestType", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x6030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Mask Pointer(s)", "MaskPointers", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x6040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "R Wave Pointer", "RWavePointer", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x6100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Mask Subtraction", "MaskSubtractionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x6101>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Mask Operation", "MaskOperation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x6102>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Applicable Frame", "ApplicableFrameRange", "2-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x6110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Mask Frame Numbers", "MaskFrameNumbers", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x6112>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Contrast Frame", "ContrastFrameAveraging", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x6114>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Mask Sub-pixel", "MaskSubPixelShift", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x6120>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SS, "TID Offset", "TIDOffset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x6190>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Mask Operation", "MaskOperationExplanation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x7FE0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UT, "Pixel Data Provider", "PixelDataProviderURL", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Data Point Rows", "DataPointRows", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Data Point Columns", "DataPointColumns", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Signal Domain", "SignalDomainColumns", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9099>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Largest Monochrome", "LargestMonochromePixelValue", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9108>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Data Representation", "DataRepresentation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Pixel Measures", "PixelMeasuresSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9132>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Frame VOI LUT", "FrameVOILUTSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9145>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Transformation", "PixelValueTransformationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9235>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Signal Domain Rows", "SignalDomainRows", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9411>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Display Filter", "DisplayFilterPercentage", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9415>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Frame Pixel Shift", "FramePixelShiftSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9416>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Subtraction Item ID", "SubtractionItemID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9422>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Relationship LUT", "PixelIntensityRelationshipLUTSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9443>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Frame Pixel Data", "FramePixelDataPropertiesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9444>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Geometrical", "GeometricalProperties", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9445>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Geometric Maximum", "GeometricMaximumDistortion", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9446>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Image Processing", "ImageProcessingApplied", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9454>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Mask Selection Mode", "MaskSelectionMode", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9474>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "LUT Function", "LUTFunction", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9478>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Mask Visibility", "MaskVisibilityPercentage", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9501>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Pixel Shift", "PixelShiftSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9502>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Region Pixel Shift", "RegionPixelShiftSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9503>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SS, "Vertices of the", "VerticesOfTheRegion", "2-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9505>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Presentation", "MultiFramePresentationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9506>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Pixel Shift Frame", "PixelShiftFrameRange", "2-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9507>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "LUT Frame Range", "LUTFrameRange", "2-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9520>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Image to Equipment", "ImageToEquipmentMappingMatrix", "16", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0028>, bool_t<(eid & 0xffff) == 0x9537>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Coordinate System", "EquipmentCoordinateSystemIdentification", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x000A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Study Status ID", "StudyStatusID", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x000C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Study Priority ID", "StudyPriorityID", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Study ID Issuer", "StudyIDIssuer", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x0032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Study Verified Date", "StudyVerifiedDate", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x0033>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Study Verified Time", "StudyVerifiedTime", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x0034>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Study Read Date", "StudyReadDate", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x0035>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Study Read Time", "StudyReadTime", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x1000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Scheduled Study", "ScheduledStudyStartDate", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x1001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Scheduled Study", "ScheduledStudyStartTime", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x1010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Scheduled Study", "ScheduledStudyStopDate", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x1011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Scheduled Study", "ScheduledStudyStopTime", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x1020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Scheduled Study", "ScheduledStudyLocation", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x1021>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AE, "Scheduled Study", "ScheduledStudyLocationAETitle", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x1030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Reason for Study", "ReasonForStudy", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x1031>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Physician", "RequestingPhysicianIdentificationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x1032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Requesting", "RequestingPhysician", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x1033>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Requesting Service", "RequestingService", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x1034>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Requesting Service", "RequestingServiceCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x1040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Study Arrival Date", "StudyArrivalDate", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x1041>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Study Arrival Time", "StudyArrivalTime", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x1050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Study Completion", "StudyCompletionDate", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x1051>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Study Completion", "StudyCompletionTime", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x1055>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Study Component", "StudyComponentStatusID", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x1060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Requested Procedure", "RequestedProcedureDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x1064>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Requested Procedure", "RequestedProcedureCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x1070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Requested Contrast", "RequestedContrastAgent", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0032>, bool_t<(eid & 0xffff) == 0x4000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Study Comments", "StudyComments", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Patient", "ReferencedPatientAliasSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Visit Status ID", "VisitStatusID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Admission ID", "AdmissionID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Issuer of Admission", "IssuerOfAdmissionID", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Issuer of Admission", "IssuerOfAdmissionIDSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Route of Admissions", "RouteOfAdmissions", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x001A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Scheduled Admission", "ScheduledAdmissionDate", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x001B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Scheduled Admission", "ScheduledAdmissionTime", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x001C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Scheduled Discharge", "ScheduledDischargeDate", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x001D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Scheduled Discharge", "ScheduledDischargeTime", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x001E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Institution", "ScheduledPatientInstitutionResidence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Admitting Date", "AdmittingDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0021>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Admitting Time", "AdmittingTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Discharge Date", "DischargeDate", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Discharge Time", "DischargeTime", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Discharge Diagnosis", "DischargeDiagnosisDescription", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0044>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Discharge Diagnosis", "DischargeDiagnosisCodeSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Special Needs", "SpecialNeeds", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Service Episode ID", "ServiceEpisodeID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0061>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Issuer of Service", "IssuerOfServiceEpisodeID", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0062>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Service Episode", "ServiceEpisodeDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0064>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Issuer of Service", "IssuerOfServiceEpisodeIDSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Pertinent Documents", "PertinentDocumentsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0300>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Current Patient", "CurrentPatientLocation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0400>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Institution", "PatientInstitutionResidence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0500>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Patient State", "PatientState", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x0502>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Trial Participation", "PatientClinicalTrialParticipationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0038>, bool_t<(eid & 0xffff) == 0x4000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Visit Comments", "VisitComments", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Waveform", "WaveformOriginality", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Waveform", "NumberOfWaveformChannels", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Number of Waveform", "NumberOfWaveformSamples", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x001A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Sampling Frequency", "SamplingFrequency", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Multiplex Group", "MultiplexGroupLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0200>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Channel Definition", "ChannelDefinitionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0202>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Waveform Channel", "WaveformChannelNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0203>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Channel Label", "ChannelLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0205>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Channel Status", "ChannelStatus", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0208>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Channel Source", "ChannelSourceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0209>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Channel Source", "ChannelSourceModifiersSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x020A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Source Waveform", "SourceWaveformSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x020C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Channel Derivation", "ChannelDerivationDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0210>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Channel Sensitivity", "ChannelSensitivity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0211>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Channel Sensitivity", "ChannelSensitivityUnitsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0212>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Channel Sensitivity", "ChannelSensitivityCorrectionFactor", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0213>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Channel Baseline", "ChannelBaseline", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0214>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Channel Time Skew", "ChannelTimeSkew", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0215>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Channel Sample Skew", "ChannelSampleSkew", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0218>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Channel Offset", "ChannelOffset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x021A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Waveform Bits", "WaveformBitsStored", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0220>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Filter Low", "FilterLowFrequency", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0221>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Filter High", "FilterHighFrequency", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0222>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Notch Filter", "NotchFilterFrequency", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0223>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Notch Filter", "NotchFilterBandwidth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0230>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Waveform Data", "WaveformDataDisplayScale", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0231>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Background CIELab", "WaveformDisplayBackgroundCIELabValue", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0240>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Presentation Group", "WaveformPresentationGroupSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0241>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Presentation Group", "PresentationGroupNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0242>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Channel Display", "ChannelDisplaySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0244>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Display CIELab", "ChannelRecommendedDisplayCIELabValue", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0245>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Channel Position", "ChannelPosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0246>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Display Shading", "DisplayShadingFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0247>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Fractional Channel", "FractionalChannelDisplayScale", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0248>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Absolute Channel", "AbsoluteChannelDisplayScale", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0300>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Channels", "MultiplexedAudioChannelsDescriptionCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0301>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Channel", "ChannelIdentificationCode", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x003A>, bool_t<(eid & 0xffff) == 0x0302>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Channel Mode", "ChannelMode", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AE, "Scheduled Station", "ScheduledStationAETitle", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Scheduled Procedure", "ScheduledProcedureStepStartDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Scheduled Procedure", "ScheduledProcedureStepStartTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Scheduled Procedure", "ScheduledProcedureStepEndDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Scheduled Procedure", "ScheduledProcedureStepEndTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Performing", "ScheduledPerformingPhysicianName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0007>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Scheduled Procedure", "ScheduledProcedureStepDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Scheduled Protocol", "ScheduledProtocolCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0009>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Scheduled Procedure", "ScheduledProcedureStepID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x000A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Stage Code Sequence", "StageCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x000B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Physician", "ScheduledPerformingPhysicianIdentificationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Scheduled Station", "ScheduledStationName", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Scheduled Procedure", "ScheduledProcedureStepLocation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Pre-Medication", "PreMedication", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Scheduled Procedure", "ScheduledProcedureStepStatus", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0026>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Order Placer", "OrderPlacerIdentifierSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0027>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Order Filler", "OrderFillerIdentifierSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0031>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UT, "Local Namespace", "LocalNamespaceEntityID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UT, "Universal Entity ID", "UniversalEntityID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0033>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Universal Entity ID", "UniversalEntityIDType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0035>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Identifier Type", "IdentifierTypeCode", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0036>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Assigning Facility", "AssigningFacilitySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0039>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Jurisdiction Code", "AssigningJurisdictionCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x003A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Department Code", "AssigningAgencyOrDepartmentCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Scheduled Procedure", "ScheduledProcedureStepSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0220>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Image Composite SOP", "ReferencedNonImageCompositeSOPInstanceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0241>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AE, "Performed Station", "PerformedStationAETitle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0242>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Performed Station", "PerformedStationName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0243>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Performed Location", "PerformedLocation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0244>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Performed Procedure", "PerformedProcedureStepStartDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0245>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Performed Procedure", "PerformedProcedureStepStartTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0250>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Performed Procedure", "PerformedProcedureStepEndDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0251>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Performed Procedure", "PerformedProcedureStepEndTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0252>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Performed Procedure", "PerformedProcedureStepStatus", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0253>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Performed Procedure", "PerformedProcedureStepID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0254>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Performed Procedure", "PerformedProcedureStepDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0255>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Performed Procedure", "PerformedProcedureTypeDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0260>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Performed Protocol", "PerformedProtocolCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0261>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Performed Protocol", "PerformedProtocolType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0270>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Scheduled Step", "ScheduledStepAttributesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0275>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Request Attributes", "RequestAttributesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0280>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Performed Procedure", "CommentsOnThePerformedProcedureStep", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0281>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Discontinuation", "PerformedProcedureStepDiscontinuationReasonCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0293>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Quantity Sequence", "QuantitySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0294>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Quantity", "Quantity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0295>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Measuring Units", "MeasuringUnitsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0296>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Billing Item", "BillingItemSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0300>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Total Time of", "TotalTimeOfFluoroscopy", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0301>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Total Number of", "TotalNumberOfExposures", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0302>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Entrance Dose", "EntranceDose", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0303>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Exposed Area", "ExposedArea", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0306>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Distance Source to", "DistanceSourceToEntrance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0307>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Distance Source to", "DistanceSourceToSupport", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x030E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Exposure Dose", "ExposureDoseSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0310>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Comments on", "CommentsOnRadiationDose", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0312>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "X-Ray Output", "XRayOutput", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0314>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Half Value Layer", "HalfValueLayer", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0316>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Organ Dose", "OrganDose", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0318>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Organ Exposed", "OrganExposed", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0320>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Billing Procedure", "BillingProcedureStepSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0321>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Film Consumption", "FilmConsumptionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0324>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "and Devices", "BillingSuppliesAndDevicesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0330>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Procedure Step", "ReferencedProcedureStepSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0340>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Performed Series", "PerformedSeriesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0400>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Scheduled Procedure", "CommentsOnTheScheduledProcedureStep", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0440>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Protocol Context", "ProtocolContextSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0441>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Content Item", "ContentItemModifierSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0500>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Scheduled Specimen", "ScheduledSpecimenSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x050A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Specimen Accession", "SpecimenAccessionNumber", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0512>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Container", "ContainerIdentifier", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0513>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Container", "IssuerOfTheContainerIdentifierSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0515>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Alternate Container", "AlternateContainerIdentifierSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0518>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Container Type Code", "ContainerTypeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x051A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Container", "ContainerDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0520>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Container Component", "ContainerComponentSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0550>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Specimen Sequence", "SpecimenSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0551>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Specimen Identifier", "SpecimenIdentifier", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0552>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Description", "SpecimenDescriptionSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0553>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Specimen", "SpecimenDescriptionTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0554>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Specimen UID", "SpecimenUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0555>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Acquisition Context", "AcquisitionContextSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0556>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Acquisition Context", "AcquisitionContextDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x059A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Specimen Type Code", "SpecimenTypeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0560>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Description", "SpecimenDescriptionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0562>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Specimen Identifier", "IssuerOfTheSpecimenIdentifierSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0600>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Specimen Short", "SpecimenShortDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0602>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UT, "Specimen Detailed", "SpecimenDetailedDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0610>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Preparation", "SpecimenPreparationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0612>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Preparation Step", "SpecimenPreparationStepContentItemSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x0620>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Localization", "SpecimenLocalizationContentItemSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x06FA>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Slide Identifier", "SlideIdentifier", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x071A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Coordinates", "ImageCenterPointCoordinatesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x072A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "X Offset in Slide", "XOffsetInSlideCoordinateSystem", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x073A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Y Offset in Slide", "YOffsetInSlideCoordinateSystem", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x074A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Z Offset in Slide", "ZOffsetInSlideCoordinateSystem", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x08D8>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Pixel Spacing", "PixelSpacingSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x08DA>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Coordinate System", "CoordinateSystemAxisCodeSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x08EA>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Measurement Units", "MeasurementUnitsCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x09F8>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Vital Stain Code", "VitalStainCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x1001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Requested Procedure", "RequestedProcedureID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x1002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Reason for the", "ReasonForTheRequestedProcedure", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x1003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Requested Procedure", "RequestedProcedurePriority", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x1004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Patient Transport", "PatientTransportArrangements", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x1005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Requested Procedure", "RequestedProcedureLocation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x1006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Placer Order Number", "PlacerOrderNumberProcedure", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x1007>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Filler Order Number", "FillerOrderNumberProcedure", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x1008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Confidentiality", "ConfidentialityCode", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x1009>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Reporting Priority", "ReportingPriority", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x100A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Requested Procedure", "ReasonForRequestedProcedureCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x1010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Recipients of", "NamesOfIntendedRecipientsOfResults", "n", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x1011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "of Results", "IntendedRecipientsOfResultsIdentificationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x1012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Performed Procedure", "ReasonForPerformedProcedureCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x1060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Requested Procedure", "RequestedProcedureDescriptionTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x1101>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Identification Code", "PersonIdentificationCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x1102>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Persons Address", "PersonAddress", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x1103>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Persons", "PersonTelephoneNumbers", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x1400>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Requested Procedure", "RequestedProcedureComments", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x2001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Imaging Service", "ReasonForTheImagingServiceRequest", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x2004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Imaging Service", "IssueDateOfImagingServiceRequest", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x2005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Imaging Service", "IssueTimeOfImagingServiceRequest", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x2006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "/ Imaging Service", "PlacerOrderNumberImagingServiceRequestRetired", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x2007>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "/ Imaging Service", "FillerOrderNumberImagingServiceRequestRetired", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x2008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Order Entered By", "OrderEnteredBy", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x2009>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Order Enterers", "OrderEntererLocation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x2010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Order Callback", "OrderCallbackPhoneNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x2016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "/ Imaging Service", "PlacerOrderNumberImagingServiceRequest", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x2017>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "/ Imaging Service", "FillerOrderNumberImagingServiceRequest", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x2400>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Imaging Service", "ImagingServiceRequestComments", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x3001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Constraint on", "ConfidentialityConstraintOnPatientDataDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Scheduled Procedure", "GeneralPurposeScheduledProcedureStepStatus", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Performed Procedure", "GeneralPurposePerformedProcedureStepStatus", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Scheduled Procedure", "GeneralPurposeScheduledProcedureStepPriority", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Processing", "ScheduledProcessingApplicationsCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Scheduled Procedure", "ScheduledProcedureStepStartDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Multiple Copies", "MultipleCopiesFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4007>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Processing", "PerformedProcessingApplicationsCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4009>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Human Performer", "HumanPerformerCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Step Modification", "ScheduledProcedureStepModificationDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Expected Completion", "ExpectedCompletionDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4015>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Purpose Performed", "ResultingGeneralPurposePerformedProcedureStepsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Purpose Scheduled", "ReferencedGeneralPurposeScheduledProcedureStepSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4018>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Scheduled Workitem", "ScheduledWorkitemCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4019>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Performed Workitem", "PerformedWorkitemCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Input Availability", "InputAvailabilityFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4021>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Input Information", "InputInformationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Information", "RelevantInformationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4023>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Purpose Scheduled", "ReferencedGeneralPurposeScheduledProcedureStepTransactionUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4025>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Scheduled Station", "ScheduledStationNameCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4026>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Scheduled Station", "ScheduledStationClassCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4027>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Geographic Location", "ScheduledStationGeographicLocationCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Performed Station", "PerformedStationNameCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4029>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Performed Station", "PerformedStationClassCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Geographic Location", "PerformedStationGeographicLocationCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4031>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Subsequent Workitem", "RequestedSubsequentWorkitemCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Non-DICOM Output", "NonDICOMOutputCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4033>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Output Information", "OutputInformationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4034>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Scheduled Human", "ScheduledHumanPerformersSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4035>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Actual Human", "ActualHumanPerformersSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4036>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Human Performers", "HumanPerformerOrganization", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4037>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Human Performers", "HumanPerformerName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Raw Data Handling", "RawDataHandling", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4041>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Input Readiness", "InputReadinessState", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Performed Procedure", "PerformedProcedureStepStartDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4051>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Performed Procedure", "PerformedProcedureStepEndDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x4052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Cancellation", "ProcedureStepCancellationDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x8302>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Entrance Dose in", "EntranceDoseInmGy", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x9094>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Real World Value", "ReferencedImageRealWorldValueMappingSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x9096>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Real World Value", "RealWorldValueMappingSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x9098>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Pixel Value Mapping", "PixelValueMappingCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x9210>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "LUT Label", "LUTLabel", "1", false) {}
};

template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x9212>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Real World Value", "RealWorldValueLUTData", "1-", false) {}
};

template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x9224>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Real World Value", "RealWorldValueIntercept", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0x9225>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Real World Value", "RealWorldValueSlope", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA007>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Findings Flag", "FindingsFlagTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Relationship Type", "RelationshipType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Findings Sequence", "FindingsSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA021>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Findings Group UID", "FindingsGroupUIDTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Referenced Findings", "ReferencedFindingsGroupUIDTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA023>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Recording Date", "FindingsGroupRecordingDateTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Recording Time", "FindingsGroupRecordingTimeTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA026>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Category Code", "FindingsSourceCategoryCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA027>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Verifying", "VerifyingOrganization", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Organization", "DocumentingOrganizationIdentifierCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Verification Date", "VerificationDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Observation Date", "ObservationDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Value Type", "ValueType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA043>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Concept Name Code", "ConceptNameCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA047>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Precision", "MeasurementPrecisionDescriptionTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Continuity Of", "ContinuityOfContent", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA057>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Urgency or Priority", "UrgencyOrPriorityAlertsTrial", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Sequencing", "SequencingIndicatorTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA066>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Code Sequence", "DocumentIdentifierCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA067>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Document Author", "DocumentAuthorTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA068>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Identifier Code", "DocumentAuthorIdentifierCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Identifier Code", "IdentifierCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA073>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Verifying Observer", "VerifyingObserverSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA074>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OB, "Object Binary", "ObjectBinaryIdentifierTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA075>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Verifying Observer", "VerifyingObserverName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA076>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Observer Identifier", "DocumentingObserverIdentifierCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA078>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Author Observer", "AuthorObserverSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA07A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Participant", "ParticipantSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA07C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Organization", "CustodialOrganizationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Participation Type", "ParticipationType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA082>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Participation", "ParticipationDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA084>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Observer Type", "ObserverType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA085>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Identifier Code", "ProcedureIdentifierCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA088>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Identification Code", "VerifyingObserverIdentificationCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA089>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OB, "Binary Identifier", "ObjectDirectoryBinaryIdentifierTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA090>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Equivalent CDA", "EquivalentCDADocumentSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA0B0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Referenced Waveform", "ReferencedWaveformChannels", "2-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Verbal Transaction", "DateOfDocumentOrVerbalTransactionTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA112>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Creation or Verbal", "TimeOfDocumentCreationOrVerbalTransactionTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA120>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "DateTime", "DateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA121>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Date", "Date", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA122>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Time", "Time", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA123>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Person Name", "PersonName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA124>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "UID", "UID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA125>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Report Status ID", "ReportStatusIDTrial", "2", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA130>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Temporal Range Type", "TemporalRangeType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA132>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Referenced Sample", "ReferencedSamplePositions", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA136>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Referenced Frame", "ReferencedFrameNumbers", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA138>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Referenced Time", "ReferencedTimeOffsets", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA13A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Referenced DateTime", "ReferencedDateTime", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA160>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UT, "Text Value", "TextValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA167>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Category Code", "ObservationCategoryCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA168>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Concept Code", "ConceptCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA16A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Bibliographic", "BibliographicCitationTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA170>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Reference Code", "PurposeOfReferenceCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA171>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Observation UID", "ObservationUIDTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA172>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Observation UID", "ReferencedObservationUIDTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA173>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Observation Class", "ReferencedObservationClassTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA174>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Observation Class", "ReferencedObjectObservationClassTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA180>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Annotation Group", "AnnotationGroupNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA192>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Observation Date", "ObservationDateTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA193>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Observation Time", "ObservationTimeTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA194>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Measurement", "MeasurementAutomationTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA195>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Modifier Code", "ModifierCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA224>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Identification", "IdentificationDescriptionTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA290>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Geometric Type", "CoordinatesSetGeometricTypeTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA296>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Algorithm Code", "AlgorithmCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA297>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Algorithm", "AlgorithmDescriptionTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA29A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SL, "Pixel Coordinates", "PixelCoordinatesSetTrial", "2-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA300>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Measured Value", "MeasuredValueSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA301>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Qualifier Code", "NumericValueQualifierCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA307>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Current Observer", "CurrentObserverTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA30A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Numeric Value", "NumericValue", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA313>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Accession Sequence", "ReferencedAccessionSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA33A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Report Status", "ReportStatusCommentTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA340>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Procedure Context", "ProcedureContextSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA352>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Verbal Source", "VerbalSourceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA353>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Address (Trial)", "AddressTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA354>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Telephone Number", "TelephoneNumberTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA358>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Identifier Code", "VerbalSourceIdentifierCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA360>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Predecessor", "PredecessorDocumentsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA370>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Request", "ReferencedRequestSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA372>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Performed Procedure", "PerformedProcedureCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA375>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Procedure Evidence", "CurrentRequestedProcedureEvidenceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA380>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Report Detail", "ReportDetailSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA385>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Pertinent Other", "PertinentOtherEvidenceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA390>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Document Reference", "HL7StructuredDocumentReferenceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA402>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Observation Subject", "ObservationSubjectUIDTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA403>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Observation Subject", "ObservationSubjectClassTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA404>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Type Code Sequence", "ObservationSubjectTypeCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA491>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Completion Flag", "CompletionFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA492>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Completion Flag", "CompletionFlagDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA493>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Verification Flag", "VerificationFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA494>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Archive Requested", "ArchiveRequested", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA496>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Preliminary Flag", "PreliminaryFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA504>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Content Template", "ContentTemplateSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA525>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Identical Documents", "IdenticalDocumentsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA600>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Context Flag", "ObservationSubjectContextFlagTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA601>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Observer Context", "ObserverContextFlagTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA603>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Procedure Context", "ProcedureContextFlagTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA730>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Content Sequence", "ContentSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA731>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Relationship", "RelationshipSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA732>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Code Sequence", "RelationshipTypeCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA744>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Language Code", "LanguageCodeSequenceTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xA992>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Uniform Resource", "UniformResourceLocatorTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xB020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Waveform Annotation", "WaveformAnnotationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xDB00>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Template Identifier", "TemplateIdentifier", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xDB06>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Template Version", "TemplateVersion", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xDB07>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Template Local", "TemplateLocalVersion", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xDB0B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Template Extension", "TemplateExtensionFlag", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xDB0C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Template Extension", "TemplateExtensionOrganizationUID", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xDB0D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Template Extension", "TemplateExtensionCreatorUID", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xDB73>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Referenced Content", "ReferencedContentItemIdentifier", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xE001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "HL7 Instance", "HL7InstanceIdentifier", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xE004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "HL7 Document", "HL7DocumentEffectiveTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xE006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "HL7 Document Type", "HL7DocumentTypeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xE008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Document Class Code", "DocumentClassCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xE010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UT, "Retrieve URI", "RetrieveURI", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xE011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Retrieve Location", "RetrieveLocationUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xE020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Type of Instances", "TypeOfInstances", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xE021>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "DICOM Retrieval", "DICOMRetrievalSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xE022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "DICOM Media", "DICOMMediaRetrievalSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xE023>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "WADO Retrieval", "WADORetrievalSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xE024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "XDS Retrieval", "XDSRetrievalSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xE030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Repository Unique", "RepositoryUniqueID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0040>, bool_t<(eid & 0xffff) == 0xE031>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Home Community ID", "HomeCommunityID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0042>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Document Title", "DocumentTitle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0042>, bool_t<(eid & 0xffff) == 0x0011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OB, "Encapsulated", "EncapsulatedDocument", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0042>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Encapsulated", "MIMETypeOfEncapsulatedDocument", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0042>, bool_t<(eid & 0xffff) == 0x0013>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Source Instance", "SourceInstanceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0042>, bool_t<(eid & 0xffff) == 0x0014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "List of MIME Types", "ListOfMIMETypes", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0044>, bool_t<(eid & 0xffff) == 0x0001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Product Package", "ProductPackageIdentifier", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0044>, bool_t<(eid & 0xffff) == 0x0002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Administration", "SubstanceAdministrationApproval", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0044>, bool_t<(eid & 0xffff) == 0x0003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Approval Status", "ApprovalStatusFurtherDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0044>, bool_t<(eid & 0xffff) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Approval Status", "ApprovalStatusDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0044>, bool_t<(eid & 0xffff) == 0x0007>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Product Type Code", "ProductTypeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0044>, bool_t<(eid & 0xffff) == 0x0008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Product Name", "ProductName", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0044>, bool_t<(eid & 0xffff) == 0x0009>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Product Description", "ProductDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0044>, bool_t<(eid & 0xffff) == 0x000A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Product Lot", "ProductLotIdentifier", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0044>, bool_t<(eid & 0xffff) == 0x000B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Product Expiration", "ProductExpirationDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0044>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Administration", "SubstanceAdministrationDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0044>, bool_t<(eid & 0xffff) == 0x0011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Administration", "SubstanceAdministrationNotes", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0044>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Administration", "SubstanceAdministrationDeviceID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0044>, bool_t<(eid & 0xffff) == 0x0013>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Product Parameter", "ProductParameterSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0044>, bool_t<(eid & 0xffff) == 0x0019>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Administration", "SubstanceAdministrationParameterSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Lens Description", "LensDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Right Lens Sequence", "RightLensSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0015>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Left Lens Sequence", "LeftLensSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Laterality Lens", "UnspecifiedLateralityLensSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0018>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Cylinder Sequence", "CylinderSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Prism Sequence", "PrismSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Horizontal Prism", "HorizontalPrismPower", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Horizontal Prism", "HorizontalPrismBase", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0034>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Vertical Prism", "VerticalPrismPower", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0036>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Vertical Prism Base", "VerticalPrismBase", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0038>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Lens Segment Type", "LensSegmentType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Optical", "OpticalTransmittance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Channel Width", "ChannelWidth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0044>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Pupil Size", "PupilSize", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0046>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Corneal Size", "CornealSize", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Autorefraction", "AutorefractionRightEyeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Autorefraction Left", "AutorefractionLeftEyeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Distance Pupillary", "DistancePupillaryDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0062>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Near Pupillary", "NearPupillaryDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0063>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Intermediate", "IntermediatePupillaryDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0064>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Other Pupillary", "OtherPupillaryDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Keratometry Right", "KeratometryRightEyeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0071>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Keratometry Left", "KeratometryLeftEyeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0074>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Steep Keratometric", "SteepKeratometricAxisSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0075>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Radius of Curvature", "RadiusOfCurvature", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0076>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Keratometric Power", "KeratometricPower", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0077>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Keratometric Axis", "KeratometricAxis", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Flat Keratometric", "FlatKeratometricAxisSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0092>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Background Color", "BackgroundColor", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0094>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Optotype", "Optotype", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0095>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Optotype", "OptotypePresentation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0097>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Refraction Right", "SubjectiveRefractionRightEyeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0098>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Refraction Left Eye", "SubjectiveRefractionLeftEyeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Add Near Sequence", "AddNearSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0101>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Add Intermediate", "AddIntermediateSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0102>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Add Other Sequence", "AddOtherSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0104>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Add Power", "AddPower", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0106>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Viewing Distance", "ViewingDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0121>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Visual Acuity Type", "VisualAcuityTypeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0122>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Visual Acuity Right", "VisualAcuityRightEyeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0123>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Visual Acuity Left", "VisualAcuityLeftEyeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0124>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Visual Acuity Both", "VisualAcuityBothEyesOpenSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0125>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Viewing Distance", "ViewingDistanceType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0135>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SS, "Visual Acuity", "VisualAcuityModifiers", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0137>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Decimal Visual", "DecimalVisualAcuity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0139>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Optotype Detailed", "OptotypeDetailedDefinition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0145>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Refractive", "ReferencedRefractiveMeasurementsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0146>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Sphere Power", "SpherePower", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0046>, bool_t<(eid & 0xffff) == 0x0147>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Cylinder Power", "CylinderPower", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Imaged Volume Width", "ImagedVolumeWidth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Imaged Volume", "ImagedVolumeHeight", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Imaged Volume Depth", "ImagedVolumeDepth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Total Pixel Matrix", "TotalPixelMatrixColumns", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0007>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Total Pixel Matrix", "TotalPixelMatrixRows", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Total Pixel Matrix", "TotalPixelMatrixOriginSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Specimen Label in", "SpecimenLabelInImage", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Focus Method", "FocusMethod", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Extended Depth of", "ExtendedDepthOfField", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0013>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Focal", "NumberOfFocalPlanes", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Distance Between", "DistanceBetweenFocalPlanes", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0015>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Recommended Absent", "RecommendedAbsentPixelCIELabValue", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Illuminator Type", "IlluminatorTypeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0102>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Image Orientation", "ImageOrientationSlide", "6", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0105>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Optical Path", "OpticalPathSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0106>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Optical Path", "OpticalPathIdentifier", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0107>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Optical Path", "OpticalPathDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0108>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Illumination Color", "IlluminationColorCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Specimen Reference", "SpecimenReferenceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0111>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Condenser Lens", "CondenserLensPower", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0112>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Objective Lens", "ObjectiveLensPower", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0113>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Objective Lens", "ObjectiveLensNumericalAperture", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0120>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Lookup Table", "PaletteColorLookupTableSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0200>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Image", "ReferencedImageNavigationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0201>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Corner of Localizer", "TopLeftHandCornerOfLocalizerArea", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0202>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Corner of Localizer", "BottomRightHandCornerOfLocalizerArea", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0207>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Identification", "OpticalPathIdentificationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x021A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Plane Position", "PlanePositionSlideSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x021E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SL, "Total Image Pixel", "RowPositionInTotalImagePixelMatrix", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x021F>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SL, "Total Image Pixel", "ColumnPositionInTotalImagePixelMatrix", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0048>, bool_t<(eid & 0xffff) == 0x0301>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Pixel Origin", "PixelOriginInterpretation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0050>, bool_t<(eid & 0xffff) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Calibration Image", "CalibrationImage", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0050>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Device Sequence", "DeviceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0050>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Container Component", "ContainerComponentTypeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0050>, bool_t<(eid & 0xffff) == 0x0013>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Container Component", "ContainerComponentThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0050>, bool_t<(eid & 0xffff) == 0x0014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Device Length", "DeviceLength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0050>, bool_t<(eid & 0xffff) == 0x0015>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Container Component", "ContainerComponentWidth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0050>, bool_t<(eid & 0xffff) == 0x0016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Device Diameter", "DeviceDiameter", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0050>, bool_t<(eid & 0xffff) == 0x0017>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Device Diameter", "DeviceDiameterUnits", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0050>, bool_t<(eid & 0xffff) == 0x0018>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Device Volume", "DeviceVolume", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0050>, bool_t<(eid & 0xffff) == 0x0019>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Inter-Marker", "InterMarkerDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0050>, bool_t<(eid & 0xffff) == 0x001A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Container Component", "ContainerComponentMaterial", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0050>, bool_t<(eid & 0xffff) == 0x001B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Container Component", "ContainerComponentID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0050>, bool_t<(eid & 0xffff) == 0x001C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Container Component", "ContainerComponentLength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0050>, bool_t<(eid & 0xffff) == 0x001D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Container Component", "ContainerComponentDiameter", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0050>, bool_t<(eid & 0xffff) == 0x001E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Container Component", "ContainerComponentDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0050>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Device Description", "DeviceDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Ingredient Percent", "ContrastBolusIngredientPercentByVolume", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "OCT Focal Distance", "OCTFocalDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Beam Spot Size", "BeamSpotSize", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Effective", "EffectiveRefractiveIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "OCT Acquisition", "OCTAcquisitionDomain", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0007>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "OCT Optical Center", "OCTOpticalCenterWavelength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Axial Resolution", "AxialResolution", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0009>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Ranging Depth", "RangingDepth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "A-line Rate", "ALineRate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "A-lines Per Frame", "ALinesPerFrame", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0013>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Catheter Rotational", "CatheterRotationalRate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "A-line Pixel", "ALinePixelSpacing", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Percutaneous Access", "ModeOfPercutaneousAccessSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0025>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Intravascular OCT", "IntravascularOCTFrameTypeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0026>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "OCT Z Offset", "OCTZOffsetApplied", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0027>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Intravascular Frame", "IntravascularFrameContentSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Longitudinal", "IntravascularLongitudinalDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0029>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Frame Content", "IntravascularOCTFrameContentSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SS, "OCT Z Offset", "OCTZOffsetCorrection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0031>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Catheter Direction", "CatheterDirectionOfRotation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0033>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Seam Line Location", "SeamLineLocation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0034>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "First A-line", "FirstALineLocation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0036>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Seam Line Index", "SeamLineIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0038>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Padded A-", "NumberOfPaddedAlines", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x0039>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Interpolation Type", "InterpolationType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0052>, bool_t<(eid & 0xffff) == 0x003A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Refractive Index", "RefractiveIndexApplied", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Energy Window", "EnergyWindowVector", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Energy", "NumberOfEnergyWindows", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Information", "EnergyWindowInformationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0013>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Energy Window Range", "EnergyWindowRangeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Energy Window Lower", "EnergyWindowLowerLimit", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0015>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Energy Window Upper", "EnergyWindowUpperLimit", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Information", "RadiopharmaceuticalInformationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0017>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Residual Syringe", "ResidualSyringeCounts", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0018>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Energy Window Name", "EnergyWindowName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Detector Vector", "DetectorVector", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0021>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Detectors", "NumberOfDetectors", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Information", "DetectorInformationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Phase Vector", "PhaseVector", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0031>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Phases", "NumberOfPhases", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Phase Information", "PhaseInformationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0033>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Frames in", "NumberOfFramesInPhase", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0036>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Phase Delay", "PhaseDelay", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0038>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Pause Between", "PauseBetweenFrames", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0039>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Phase Description", "PhaseDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Rotation Vector", "RotationVector", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0051>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Rotations", "NumberOfRotations", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Information", "RotationInformationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0053>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Frames in", "NumberOfFramesInRotation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "R-R Interval Vector", "RRIntervalVector", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0061>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of R-", "NumberOfRRIntervals", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0062>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Gated Information", "GatedInformationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0063>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Data Information", "DataInformationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Time Slot Vector", "TimeSlotVector", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0071>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Time", "NumberOfTimeSlots", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0072>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Information", "TimeSlotInformationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0073>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Time Slot Time", "TimeSlotTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Slice Vector", "SliceVector", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0081>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Slices", "NumberOfSlices", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0090>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Angular View Vector", "AngularViewVector", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Time Slice Vector", "TimeSliceVector", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0101>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Time", "NumberOfTimeSlices", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0200>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Start Angle", "StartAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0202>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Type of Detector", "TypeOfDetectorMotion", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0210>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Trigger Vector", "TriggerVector", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0211>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Triggers", "NumberOfTriggersInPhase", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0220>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "View Code Sequence", "ViewCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0222>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "View Modifier Code", "ViewModifierCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0300>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Radionuclide Code", "RadionuclideCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0302>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Administration", "AdministrationRouteCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0304>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Radiopharmaceutical", "RadiopharmaceuticalCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0306>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Calibration Data", "CalibrationDataSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0308>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Energy Window", "EnergyWindowNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0400>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Image ID", "ImageID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0410>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Patient Orientation", "PatientOrientationCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0412>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Modifier Code", "PatientOrientationModifierCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0414>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Relationship Code", "PatientGantryRelationshipCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x0500>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Slice Progression", "SliceProgressionDirection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Series Type", "SeriesType", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Units", "Units", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Counts Source", "CountsSource", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Reprojection Method", "ReprojectionMethod", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "SUV Type", "SUVType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Randoms Correction", "RandomsCorrectionMethod", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1101>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Attenuation", "AttenuationCorrectionMethod", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1102>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Decay Correction", "DecayCorrection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1103>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Reconstruction", "ReconstructionMethod", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1104>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Detector Lines of", "DetectorLinesOfResponseUsed", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1105>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Scatter Correction", "ScatterCorrectionMethod", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1200>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Axial Acceptance", "AxialAcceptance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1201>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Axial Mash", "AxialMash", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1202>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Transverse Mash", "TransverseMash", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1203>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Detector Element", "DetectorElementSize", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1210>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Coincidence Window", "CoincidenceWindowWidth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1220>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Secondary Counts", "SecondaryCountsType", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1300>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Frame Reference", "FrameReferenceTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1310>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Primary (Prompts)", "PrimaryPromptsCountsAccumulated", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1311>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Secondary Counts", "SecondaryCountsAccumulated", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1320>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Slice Sensitivity", "SliceSensitivityFactor", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1321>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Decay Factor", "DecayFactor", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1322>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Dose Calibration", "DoseCalibrationFactor", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1323>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Scatter Fraction", "ScatterFractionFactor", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1324>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Dead Time Factor", "DeadTimeFactor", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1330>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Image Index", "ImageIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1400>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Counts Included", "CountsIncluded", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0054>, bool_t<(eid & 0xffff) == 0x1401>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Dead Time", "DeadTimeCorrectionFlag", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0060>, bool_t<(eid & 0xffff) == 0x3000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Histogram Sequence", "HistogramSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0060>, bool_t<(eid & 0xffff) == 0x3002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Histogram Number of", "HistogramNumberOfBins", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0060>, bool_t<(eid & 0xffff) == 0x3008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Histogram Bin Width", "HistogramBinWidth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0060>, bool_t<(eid & 0xffff) == 0x3010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Histogram", "HistogramExplanation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0060>, bool_t<(eid & 0xffff) == 0x3020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Histogram Data", "HistogramData", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0062>, bool_t<(eid & 0xffff) == 0x0001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Segmentation Type", "SegmentationType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0062>, bool_t<(eid & 0xffff) == 0x0002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Segment Sequence", "SegmentSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0062>, bool_t<(eid & 0xffff) == 0x0003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Category Code", "SegmentedPropertyCategoryCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0062>, bool_t<(eid & 0xffff) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Segment Number", "SegmentNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0062>, bool_t<(eid & 0xffff) == 0x0005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Segment Label", "SegmentLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0062>, bool_t<(eid & 0xffff) == 0x0006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Segment Description", "SegmentDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0062>, bool_t<(eid & 0xffff) == 0x0008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Segment Algorithm", "SegmentAlgorithmType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0062>, bool_t<(eid & 0xffff) == 0x0009>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Segment Algorithm", "SegmentAlgorithmName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0062>, bool_t<(eid & 0xffff) == 0x000A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Identification", "SegmentIdentificationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0062>, bool_t<(eid & 0xffff) == 0x000B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Referenced Segment", "ReferencedSegmentNumber", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0062>, bool_t<(eid & 0xffff) == 0x000C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Recommended Display", "RecommendedDisplayGrayscaleValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0062>, bool_t<(eid & 0xffff) == 0x000D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Recommended Display", "RecommendedDisplayCIELabValue", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0062>, bool_t<(eid & 0xffff) == 0x000E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Maximum Fractional", "MaximumFractionalValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0062>, bool_t<(eid & 0xffff) == 0x000F>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Segmented Property", "SegmentedPropertyTypeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0062>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Segmentation", "SegmentationFractionalType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0064>, bool_t<(eid & 0xffff) == 0x0002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Registration", "DeformableRegistrationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0064>, bool_t<(eid & 0xffff) == 0x0003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Source Frame of", "SourceFrameOfReferenceUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0064>, bool_t<(eid & 0xffff) == 0x0005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Registration Grid", "DeformableRegistrationGridSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0064>, bool_t<(eid & 0xffff) == 0x0007>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Grid Dimensions", "GridDimensions", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0064>, bool_t<(eid & 0xffff) == 0x0008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Grid Resolution", "GridResolution", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0064>, bool_t<(eid & 0xffff) == 0x0009>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OF, "Vector Grid Data", "VectorGridData", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0064>, bool_t<(eid & 0xffff) == 0x000F>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Matrix Registration", "PreDeformationMatrixRegistrationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0064>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Matrix Registration", "PostDeformationMatrixRegistrationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Number of Surfaces", "NumberOfSurfaces", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Surface Sequence", "SurfaceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Surface Number", "SurfaceNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Surface Comments", "SurfaceComments", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0009>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Surface Processing", "SurfaceProcessing", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x000A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Surface Processing", "SurfaceProcessingRatio", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x000B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Surface Processing", "SurfaceProcessingDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x000C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Presentation", "RecommendedPresentationOpacity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x000D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Recommended", "RecommendedPresentationType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x000E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Finite Volume", "FiniteVolume", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Manifold", "Manifold", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Surface Points", "SurfacePointsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Surface Points", "SurfacePointsNormalsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0013>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Surface Mesh", "SurfaceMeshPrimitivesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0015>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Number of Surface", "NumberOfSurfacePoints", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OF, "Point Coordinates", "PointCoordinatesData", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0017>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Point Position", "PointPositionAccuracy", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0018>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Mean Point Distance", "MeanPointDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0019>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Maximum Point", "MaximumPointDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x001A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Points Bounding Box", "PointsBoundingBoxCoordinates", "6", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x001B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Axis of Rotation", "AxisOfRotation", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x001C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Center of Rotation", "CenterOfRotation", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x001E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Number of Vectors", "NumberOfVectors", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x001F>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Vector", "VectorDimensionality", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Vector Accuracy", "VectorAccuracy", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0021>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OF, "Vector Coordinate", "VectorCoordinateData", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0023>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Triangle Point", "TrianglePointIndexList", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Edge Point Index", "EdgePointIndexList", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0025>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Vertex Point Index", "VertexPointIndexList", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0026>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Triangle Strip", "TriangleStripSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0027>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Triangle Fan", "TriangleFanSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Line Sequence", "LineSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0029>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Primitive Point", "PrimitivePointIndexList", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x002A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Surface Count", "SurfaceCount", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x002B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Surface", "ReferencedSurfaceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x002C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Referenced Surface", "ReferencedSurfaceNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x002D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Algorithm", "SegmentSurfaceGenerationAlgorithmIdentificationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x002E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Source Instance", "SegmentSurfaceSourceInstanceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x002F>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Algorithm Family", "AlgorithmFamilyCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Algorithm Name Code", "AlgorithmNameCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0031>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Algorithm Version", "AlgorithmVersion", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Algorithm", "AlgorithmParameters", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0034>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Facet Sequence", "FacetSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0035>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Algorithm", "SurfaceProcessingAlgorithmIdentificationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0066>, bool_t<(eid & 0xffff) == 0x0036>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Algorithm Name", "AlgorithmName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6210>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Implant Size", "ImplantSize", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6221>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Implant Template", "ImplantTemplateVersion", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6222>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Replaced Implant", "ReplacedImplantTemplateSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6223>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Implant Type", "ImplantType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6224>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Derivation Implant", "DerivationImplantTemplateSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6225>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Original Implant", "OriginalImplantTemplateSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6226>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Effective DateTime", "EffectiveDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6230>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Implant Target", "ImplantTargetAnatomySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6260>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Manufacturer", "InformationFromManufacturerSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6265>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Manufacturer", "NotificationFromManufacturerSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6270>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Information Issue", "InformationIssueDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6280>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Information Summary", "InformationSummary", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x62A0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Disapproval Code", "ImplantRegulatoryDisapprovalCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x62A5>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Overall Template", "OverallTemplateSpatialTolerance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x62C0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "HPGL Document", "HPGLDocumentSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x62D0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "HPGL Document ID", "HPGLDocumentID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x62D5>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "HPGL Document Label", "HPGLDocumentLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x62E0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "View Orientation", "ViewOrientationCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x62F0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "View Orientation", "ViewOrientationModifier", "9", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x62F2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "HPGL Document", "HPGLDocumentScaling", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6300>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OB, "HPGL Document", "HPGLDocument", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6310>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "HPGL Contour Pen", "HPGLContourPenNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6320>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "HPGL Pen Sequence", "HPGLPenSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6330>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "HPGL Pen Number", "HPGLPenNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6340>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "HPGL Pen Label", "HPGLPenLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6345>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "HPGL Pen", "HPGLPenDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6346>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Recommended", "RecommendedRotationPoint", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6347>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Bounding Rectangle", "BoundingRectangle", "4", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6350>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Model Surface", "ImplantTemplate3DModelSurfaceNumber", "n", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6360>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Description", "SurfaceModelDescriptionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6380>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Surface Model Label", "SurfaceModelLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6390>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Surface Model", "SurfaceModelScalingFactor", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x63A0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Materials Code", "MaterialsCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x63A4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Coating Materials", "CoatingMaterialsCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x63A8>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Implant Type Code", "ImplantTypeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x63AC>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Fixation Method", "FixationMethodCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x63B0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Mating Feature Sets", "MatingFeatureSetsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x63C0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Mating Feature Set", "MatingFeatureSetID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x63D0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Mating Feature Set", "MatingFeatureSetLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x63E0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Mating Feature", "MatingFeatureSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x63F0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Mating Feature ID", "MatingFeatureID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6400>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Degree of Freedom", "MatingFeatureDegreeOfFreedomSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6410>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Degree of Freedom", "DegreeOfFreedomID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6420>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Degree of Freedom", "DegreeOfFreedomType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6430>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Coordinates", "TwoDMatingFeatureCoordinatesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6440>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Referenced HPGL", "ReferencedHPGLDocumentID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6450>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "2D Mating Point", "TwoDMatingPoint", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6460>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "2D Mating Axes", "TwoDMatingAxes", "4", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6470>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "2D Degree of", "TwoDDegreeOfFreedomSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6490>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "3D Degree of", "ThreeDDegreeOfFreedomAxis", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x64A0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Range of Freedom", "RangeOfFreedom", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x64C0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "3D Mating Point", "ThreeDMatingPoint", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x64D0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "3D Mating Axes", "ThreeDMatingAxes", "9", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x64F0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "2D Degree of", "TwoDDegreeOfFreedomAxis", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6500>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Planning Landmark", "PlanningLandmarkPointSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6510>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Planning Landmark", "PlanningLandmarkLineSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6520>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Planning Landmark", "PlanningLandmarkPlaneSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6530>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Planning Landmark", "PlanningLandmarkID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6540>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Planning Landmark", "PlanningLandmarkDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6545>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Identification Code", "PlanningLandmarkIdentificationCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6550>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Coordinates", "TwoDPointCoordinatesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6560>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "2D Point", "TwoDPointCoordinates", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6590>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "3D Point", "ThreeDPointCoordinates", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x65A0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "2D Line Coordinates", "TwoDLineCoordinatesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x65B0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "2D Line Coordinates", "TwoDLineCoordinates", "4", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x65D0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "3D Line Coordinates", "ThreeDLineCoordinates", "6", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x65E0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Coordinates", "TwoDPlaneCoordinatesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x65F0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "2D Plane", "TwoDPlaneIntersection", "4", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6610>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "3D Plane Origin", "ThreeDPlaneOrigin", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0068>, bool_t<(eid & 0xffff) == 0x6620>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "3D Plane Normal", "ThreeDPlaneNormal", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Graphic Annotation", "GraphicAnnotationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Graphic Layer", "GraphicLayer", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Bounding Box", "BoundingBoxAnnotationUnits", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Anchor Point", "AnchorPointAnnotationUnits", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Graphic Annotation", "GraphicAnnotationUnits", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Unformatted Text", "UnformattedTextValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Text Object", "TextObjectSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0009>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Graphic Object", "GraphicObjectSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Bounding Box Top", "BoundingBoxTopLeftHandCorner", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Bounding Box Bottom", "BoundingBoxBottomRightHandCorner", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Horizontal", "BoundingBoxTextHorizontalJustification", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Anchor Point", "AnchorPoint", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0015>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Anchor Point", "AnchorPointVisibility", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Graphic Dimensions", "GraphicDimensions", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0021>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Graphic", "NumberOfGraphicPoints", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Graphic Data", "GraphicData", "2-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0023>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Graphic Type", "GraphicType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Graphic Filled", "GraphicFilled", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Image Rotation", "ImageRotationRetired", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0041>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Image Horizontal", "ImageHorizontalFlip", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Image Rotation", "ImageRotation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Left Hand Corner", "DisplayedAreaTopLeftHandCornerTrial", "2", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0051>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Bottom Right Hand", "DisplayedAreaBottomRightHandCornerTrial", "2", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SL, "Displayed Area Top", "DisplayedAreaTopLeftHandCorner", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0053>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SL, "Bottom Right Hand", "DisplayedAreaBottomRightHandCorner", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x005A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Displayed Area", "DisplayedAreaSelectionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Graphic Layer", "GraphicLayerSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0062>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Graphic Layer Order", "GraphicLayerOrder", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0066>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Recommended Display", "GraphicLayerRecommendedDisplayGrayscaleValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0067>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Recommended Display", "GraphicLayerRecommendedDisplayRGBValue", "3", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0068>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Graphic Layer", "GraphicLayerDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Content Label", "ContentLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0081>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Content Description", "ContentDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0082>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Presentation", "PresentationCreationDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0083>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Presentation", "PresentationCreationTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0084>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Content Creators", "ContentCreatorName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0086>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Identification Code", "ContentCreatorIdentificationCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0087>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Description", "AlternateContentDescriptionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Presentation Size", "PresentationSizeMode", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0101>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Presentation Pixel", "PresentationPixelSpacing", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0102>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Presentation Pixel", "PresentationPixelAspectRatio", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0103>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Presentation Pixel", "PresentationPixelMagnificationRatio", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0207>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Graphic Group Label", "GraphicGroupLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0208>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Graphic Group", "GraphicGroupDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0209>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Compound Graphic", "CompoundGraphicSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0226>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Compound Graphic", "CompoundGraphicInstanceID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0227>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Font Name", "FontName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0228>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Font Name Type", "FontNameType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0229>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "CSS Font Name", "CSSFontName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0230>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Rotation Angle", "RotationAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0231>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Text Style Sequence", "TextStyleSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0232>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Line Style Sequence", "LineStyleSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0233>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Fill Style Sequence", "FillStyleSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0234>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Graphic Group", "GraphicGroupSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0241>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Text Color CIELab", "TextColorCIELabValue", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0242>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Horizontal", "HorizontalAlignment", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0243>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Vertical Alignment", "VerticalAlignment", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0244>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Shadow Style", "ShadowStyle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0245>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Shadow Offset X", "ShadowOffsetX", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0246>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Shadow Offset Y", "ShadowOffsetY", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0247>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Shadow Color CIELab", "ShadowColorCIELabValue", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0248>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Underlined", "Underlined", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0249>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Bold", "Bold", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0250>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Italic", "Italic", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0251>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Pattern On Color", "PatternOnColorCIELabValue", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0252>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Pattern Off Color", "PatternOffColorCIELabValue", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0253>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Line Thickness", "LineThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0254>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Line Dashing Style", "LineDashingStyle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0255>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Line Pattern", "LinePattern", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0256>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OB, "Fill Pattern", "FillPattern", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0257>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Fill Mode", "FillMode", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0258>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Shadow Opacity", "ShadowOpacity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0261>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Gap Length", "GapLength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0262>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Diameter of", "DiameterOfVisibility", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0273>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Rotation Point", "RotationPoint", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0274>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Tick Alignment", "TickAlignment", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0278>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Show Tick Label", "ShowTickLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0279>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Tick Label", "TickLabelAlignment", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0282>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Compound Graphic", "CompoundGraphicUnits", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0284>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Pattern On Opacity", "PatternOnOpacity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0285>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Pattern Off Opacity", "PatternOffOpacity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0287>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Major Ticks", "MajorTicksSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0288>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Tick Position", "TickPosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0289>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Tick Label", "TickLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0294>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Compound Graphic", "CompoundGraphicType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0295>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Graphic Group ID", "GraphicGroupID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0306>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Shape Type", "ShapeType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0308>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Registration", "RegistrationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0309>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Matrix Registration", "MatrixRegistrationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x030A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Matrix Sequence", "MatrixSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x030C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Transformation", "FrameOfReferenceTransformationMatrixType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x030D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Registration Type", "RegistrationTypeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x030F>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Fiducial", "FiducialDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0310>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Fiducial Identifier", "FiducialIdentifier", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0311>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Fiducial Identifier", "FiducialIdentifierCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0312>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Contour Uncertainty", "ContourUncertaintyRadius", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0314>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Used Fiducials", "UsedFiducialsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0318>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Graphic Coordinates", "GraphicCoordinatesDataSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x031A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Fiducial UID", "FiducialUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x031C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Fiducial Set", "FiducialSetSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x031E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Fiducial Sequence", "FiducialSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0401>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Recommended Display", "GraphicLayerRecommendedDisplayCIELabValue", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0402>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Blending Sequence", "BlendingSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0403>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Relative Opacity", "RelativeOpacity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0404>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Registration", "ReferencedSpatialRegistrationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0070>, bool_t<(eid & 0xffff) == 0x0405>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Blending Position", "BlendingPosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Hanging Protocol", "HangingProtocolName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Hanging Protocol", "HangingProtocolDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Hanging Protocol", "HangingProtocolLevel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Hanging Protocol", "HangingProtocolCreator", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x000A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Hanging Protocol", "HangingProtocolCreationDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x000C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Hanging Protocol", "HangingProtocolDefinitionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x000E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "User Identification", "HangingProtocolUserIdentificationCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Hanging Protocol", "HangingProtocolUserGroupName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Source Hanging", "SourceHangingProtocolSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Priors", "NumberOfPriorsReferenced", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Image Sets Sequence", "ImageSetsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Image Set Selector", "ImageSetSelectorSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Image Set Selector", "ImageSetSelectorUsageFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0026>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Selector Attribute", "SelectorAttribute", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Selector Value", "SelectorValueNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Time Based Image", "TimeBasedImageSetsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Image Set Number", "ImageSetNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0034>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Image Set Selector", "ImageSetSelectorCategory", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0038>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Relative Time", "RelativeTime", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x003A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Relative Time Units", "RelativeTimeUnits", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x003C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SS, "Abstract Prior", "AbstractPriorValue", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x003E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Abstract Prior Code", "AbstractPriorCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Image Set Label", "ImageSetLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Selector Attribute", "SelectorAttributeVR", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Selector Sequence", "SelectorSequencePointer", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0054>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Pointer Private", "SelectorSequencePointerPrivateCreator", "n", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0056>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Selector Attribute", "SelectorAttributePrivateCreator", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Selector AT Value", "SelectorATValue", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0062>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Selector CS Value", "SelectorCSValue", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0064>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Selector IS Value", "SelectorISValue", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0066>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Selector LO Value", "SelectorLOValue", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0068>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Selector LT Value", "SelectorLTValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x006A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Selector PN Value", "SelectorPNValue", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x006C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Selector SH Value", "SelectorSHValue", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x006E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Selector ST Value", "SelectorSTValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UT, "Selector UT Value", "SelectorUTValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0072>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Selector DS Value", "SelectorDSValue", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0074>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Selector FD Value", "SelectorFDValue", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0076>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Selector FL Value", "SelectorFLValue", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0078>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Selector UL Value", "SelectorULValue", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x007A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Selector US Value", "SelectorUSValue", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x007C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SL, "Selector SL Value", "SelectorSLValue", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x007E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SS, "Selector SS Value", "SelectorSSValue", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Selector Code", "SelectorCodeSequenceValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Screens", "NumberOfScreens", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0102>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Nominal Screen", "NominalScreenDefinitionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0104>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Vertical", "NumberOfVerticalPixels", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0106>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of", "NumberOfHorizontalPixels", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0108>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Display Environment", "DisplayEnvironmentSpatialPosition", "4", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x010A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Screen Minimum", "ScreenMinimumGrayscaleBitDepth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x010C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Screen Minimum", "ScreenMinimumColorBitDepth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x010E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Application Maximum", "ApplicationMaximumRepaintTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0200>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Display Sets", "DisplaySetsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0202>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Display Set Number", "DisplaySetNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0203>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Display Set Label", "DisplaySetLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0204>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Display Set", "DisplaySetPresentationGroup", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0206>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Presentation Group", "DisplaySetPresentationGroupDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0208>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Partial Data", "PartialDataDisplayHandling", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0210>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Synchronized", "SynchronizedScrollingSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0212>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Display Set", "DisplaySetScrollingGroup", "2-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0214>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Navigation", "NavigationIndicatorSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0216>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Navigation Display", "NavigationDisplaySet", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0218>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Reference Display", "ReferenceDisplaySets", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0300>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Image Boxes", "ImageBoxesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0302>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Image Box Number", "ImageBoxNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0304>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Image Box Layout", "ImageBoxLayoutType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0306>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Horizontal", "ImageBoxTileHorizontalDimension", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0308>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Image Box Tile", "ImageBoxTileVerticalDimension", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0310>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Image Box Scroll", "ImageBoxScrollDirection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0312>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Image Box Small", "ImageBoxSmallScrollType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0314>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Image Box Small", "ImageBoxSmallScrollAmount", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0316>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Image Box Large", "ImageBoxLargeScrollType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0318>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Image Box Large", "ImageBoxLargeScrollAmount", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0320>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Image Box Overlap", "ImageBoxOverlapPriority", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0330>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Cine Relative to", "CineRelativeToRealTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0400>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Filter Operations", "FilterOperationsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0402>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Filter-by Category", "FilterByCategory", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0404>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Filter-by Attribute", "FilterByAttributePresence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0406>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Filter-by Operator", "FilterByOperator", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0420>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Background CIELab", "StructuredDisplayBackgroundCIELabValue", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0421>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Empty Image Box", "EmptyImageBoxCIELabValue", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0422>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Structured Display", "StructuredDisplayImageBoxSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0424>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Structured Display", "StructuredDisplayTextBoxSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0427>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced First", "ReferencedFirstFrameSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0430>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Synchronization", "ImageBoxSynchronizationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0432>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Synchronized Image", "SynchronizedImageBoxList", "2-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0434>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Type of", "TypeOfSynchronization", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0500>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Blending Operation", "BlendingOperationType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0510>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Reformatting", "ReformattingOperationType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0512>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Reformatting", "ReformattingThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0514>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Reformatting", "ReformattingInterval", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0516>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Operation Initial", "ReformattingOperationInitialViewDirection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0520>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "3D Rendering Type", "ThreeDRenderingType", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0600>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Sorting Operations", "SortingOperationsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0602>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Sort-by Category", "SortByCategory", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0604>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Sorting Direction", "SortingDirection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0700>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Display Set Patient", "DisplaySetPatientOrientation", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0702>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "VOI Type", "VOIType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0704>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Pseudo-Color Type", "PseudoColorType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0705>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Palette Instance", "PseudoColorPaletteInstanceReferenceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0706>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Show Grayscale", "ShowGrayscaleInverted", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0710>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Show Image True", "ShowImageTrueSizeFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0712>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Show Graphic", "ShowGraphicAnnotationFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0714>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Show Patient", "ShowPatientDemographicsFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0716>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Show Acquisition", "ShowAcquisitionTechniquesFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0717>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Horizontal", "DisplaySetHorizontalJustification", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0072>, bool_t<(eid & 0xffff) == 0x0718>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Vertical", "DisplaySetVerticalJustification", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x0120>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Continuation Start", "ContinuationStartMeterset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x0121>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Continuation End", "ContinuationEndMeterset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Procedure Step", "ProcedureStepState", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Progress", "ProcedureStepProgressInformationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Procedure Step", "ProcedureStepProgress", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Progress", "ProcedureStepProgressDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Communications URI", "ProcedureStepCommunicationsURISequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x100a>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Contact URI", "ContactURI", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x100c>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Contact Display", "ContactDisplayName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x100e>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Discontinuation", "ProcedureStepDiscontinuationReasonCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Beam Task Sequence", "BeamTaskSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Beam Task Type", "BeamTaskType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Beam Order Index", "BeamOrderIndexTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1026>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Table Top Vertical", "TableTopVerticalAdjustedPosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1027>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Longitudinal", "TableTopLongitudinalAdjustedPosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Table Top Lateral", "TableTopLateralAdjustedPosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x102A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Patient Support", "PatientSupportAdjustedAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x102B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Table Top Eccentric", "TableTopEccentricAdjustedAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x102C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Table Top Pitch", "TableTopPitchAdjustedAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x102D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Table Top Roll", "TableTopRollAdjustedAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Verification Image", "DeliveryVerificationImageSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Verification Image", "VerificationImageTiming", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1034>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Double Exposure", "DoubleExposureFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1036>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Double Exposure", "DoubleExposureOrdering", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1038>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Double Exposure", "DoubleExposureMetersetTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x103A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Double Exposure", "DoubleExposureFieldDeltaTrial", "4", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Related Reference", "RelatedReferenceRTImageSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Verification", "GeneralMachineVerificationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1044>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Machine", "ConventionalMachineVerificationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1046>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Verification", "IonMachineVerificationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1048>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Failed Attributes", "FailedAttributesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x104A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Overridden", "OverriddenAttributesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x104C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Control Point", "ConventionalControlPointVerificationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x104E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Verification", "IonControlPointVerificationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Attribute", "AttributeOccurrenceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Attribute", "AttributeOccurrencePointer", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1054>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Attribute Item", "AttributeItemSelector", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1056>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Occurrence Private", "AttributeOccurrencePrivateCreator", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1057>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Selector Sequence", "SelectorSequencePointerItems", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1200>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Scheduled Procedure", "ScheduledProcedureStepPriority", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1202>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Worklist Label", "WorklistLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1204>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Procedure Step", "ProcedureStepLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1210>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Processing", "ScheduledProcessingParametersSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1212>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Processing", "PerformedProcessingParametersSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1216>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Step Performed", "UnifiedProcedureStepPerformedProcedureSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1220>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Related Procedure", "RelatedProcedureStepSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1222>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Procedure Step", "ProcedureStepRelationshipType", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1224>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Replaced Procedure", "ReplacedProcedureStepSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1230>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Deletion Lock", "DeletionLock", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1234>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AE, "Receiving AE", "ReceivingAE", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1236>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AE, "Requesting AE", "RequestingAE", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1238>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Reason for", "ReasonForCancellation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1242>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "SCP Status", "SCPStatus", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1244>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Subscription List", "SubscriptionListStatus", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1246>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Unified Procedure", "UnifiedProcedureStepListStatus", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1324>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Beam Order Index", "BeamOrderIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x1338>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Double Exposure", "DoubleExposureMeterset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0074>, bool_t<(eid & 0xffff) == 0x133A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Double Exposure", "DoubleExposureFieldDelta", "4", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x0001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Implant Assembly", "ImplantAssemblyTemplateName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x0003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Implant Assembly", "ImplantAssemblyTemplateIssuer", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x0006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Implant Assembly", "ImplantAssemblyTemplateVersion", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x0008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Assembly Template", "ReplacedImplantAssemblyTemplateSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x000A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Implant Assembly", "ImplantAssemblyTemplateType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x000C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Assembly Template", "OriginalImplantAssemblyTemplateSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x000E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Assembly Template", "DerivationImplantAssemblyTemplateSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Template Target", "ImplantAssemblyTemplateTargetAnatomySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Procedure Type Code", "ProcedureTypeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Surgical Technique", "SurgicalTechnique", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x0032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Component Types", "ComponentTypesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x0034>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Component Type Code", "ComponentTypeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x0036>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Exclusive Component", "ExclusiveComponentType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x0038>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Mandatory Component", "MandatoryComponentType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Component Sequence", "ComponentSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x0055>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Component ID", "ComponentID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Component Assembly", "ComponentAssemblySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x0070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Component 1", "Component1ReferencedID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x0080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Referenced Mating", "Component1ReferencedMatingFeatureSetID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x0090>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Referenced Mating", "Component1ReferencedMatingFeatureID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x00A0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Component 2", "Component2ReferencedID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x00B0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Referenced Mating", "Component2ReferencedMatingFeatureSetID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0076>, bool_t<(eid & 0xffff) == 0x00C0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Referenced Mating", "Component2ReferencedMatingFeatureID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0078>, bool_t<(eid & 0xffff) == 0x0001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Implant Template", "ImplantTemplateGroupName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0078>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Implant Template", "ImplantTemplateGroupDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0078>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Implant Template", "ImplantTemplateGroupIssuer", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0078>, bool_t<(eid & 0xffff) == 0x0024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Implant Template", "ImplantTemplateGroupVersion", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0078>, bool_t<(eid & 0xffff) == 0x0026>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Template Group", "ReplacedImplantTemplateGroupSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0078>, bool_t<(eid & 0xffff) == 0x0028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Group Target", "ImplantTemplateGroupTargetAnatomySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0078>, bool_t<(eid & 0xffff) == 0x002A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Group Members", "ImplantTemplateGroupMembersSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0078>, bool_t<(eid & 0xffff) == 0x002E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Implant Template", "ImplantTemplateGroupMemberID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0078>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Group Member", "ThreeDImplantTemplateGroupMemberMatchingPoint", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0078>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Group Member", "ThreeDImplantTemplateGroupMemberMatchingAxes", "9", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0078>, bool_t<(eid & 0xffff) == 0x0070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Matching 2D", "ImplantTemplateGroupMemberMatching2DCoordinatesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0078>, bool_t<(eid & 0xffff) == 0x0090>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Group Member", "TwoDImplantTemplateGroupMemberMatchingPoint", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0078>, bool_t<(eid & 0xffff) == 0x00A0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FD, "Group Member", "TwoDImplantTemplateGroupMemberMatchingAxes", "4", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0078>, bool_t<(eid & 0xffff) == 0x00B0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Group Variation", "ImplantTemplateGroupVariationDimensionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0078>, bool_t<(eid & 0xffff) == 0x00B2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Group Variation", "ImplantTemplateGroupVariationDimensionName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0078>, bool_t<(eid & 0xffff) == 0x00B4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Group Variation", "ImplantTemplateGroupVariationDimensionRankSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0078>, bool_t<(eid & 0xffff) == 0x00B6>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Template Group", "ReferencedImplantTemplateGroupMemberID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0078>, bool_t<(eid & 0xffff) == 0x00B8>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Group Variation", "ImplantTemplateGroupVariationDimensionRank", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0088>, bool_t<(eid & 0xffff) == 0x0130>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Storage Media File-", "StorageMediaFileSetID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0088>, bool_t<(eid & 0xffff) == 0x0140>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Storage Media File-", "StorageMediaFileSetUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0088>, bool_t<(eid & 0xffff) == 0x0200>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Icon Image Sequence", "IconImageSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0088>, bool_t<(eid & 0xffff) == 0x0904>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Topic Title", "TopicTitle", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0088>, bool_t<(eid & 0xffff) == 0x0906>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Topic Subject", "TopicSubject", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0088>, bool_t<(eid & 0xffff) == 0x0910>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Topic Author", "TopicAuthor", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0088>, bool_t<(eid & 0xffff) == 0x0912>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Topic Keywords", "TopicKeywords", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0100>, bool_t<(eid & 0xffff) == 0x0410>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "SOP Instance Status", "SOPInstanceStatus", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0100>, bool_t<(eid & 0xffff) == 0x0420>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "SOP Authorization", "SOPAuthorizationDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0100>, bool_t<(eid & 0xffff) == 0x0424>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "SOP Authorization", "SOPAuthorizationComment", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0100>, bool_t<(eid & 0xffff) == 0x0426>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Equipment", "AuthorizationEquipmentCertificationNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "MAC ID Number", "MACIDNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "MAC Calculation", "MACCalculationTransferSyntaxUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0015>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "MAC Algorithm", "MACAlgorithm", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Data Elements", "DataElementsSigned", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Digital Signature", "DigitalSignatureUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0105>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Digital Signature", "DigitalSignatureDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Certificate Type", "CertificateType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0115>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OB, "Certificate of", "CertificateOfSigner", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0120>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OB, "Signature", "Signature", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0305>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Certified Timestamp", "CertifiedTimestampType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0310>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OB, "Certified Timestamp", "CertifiedTimestamp", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0401>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Purpose Code", "DigitalSignaturePurposeCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0402>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Digital", "ReferencedDigitalSignatureSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0403>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Instance MAC", "ReferencedSOPInstanceMACSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0404>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OB, "MAC", "MAC", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0500>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Encrypted", "EncryptedAttributesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0510>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Encrypted Content", "EncryptedContentTransferSyntaxUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0520>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OB, "Encrypted Content", "EncryptedContent", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0550>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Modified Attributes", "ModifiedAttributesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0561>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Original Attributes", "OriginalAttributesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0562>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Modification", "AttributeModificationDateTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0563>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Modifying System", "ModifyingSystem", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0564>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Source of Previous", "SourceOfPreviousValues", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x0400>, bool_t<(eid & 0xffff) == 0x0565>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Attribute", "ReasonForTheAttributeModification", "1", false) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x1000>, bool_t<(eid & 0x000f) == 0x0000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Escape Triplet", "EscapeTriplet", "3", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x1000>, bool_t<(eid & 0x000f) == 0x0001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Run Length Triplet", "RunLengthTriplet", "3", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x1000>, bool_t<(eid & 0x000f) == 0x0002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Huffman Table Size", "HuffmanTableSize", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x1000>, bool_t<(eid & 0x000f) == 0x0003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Huffman Table", "HuffmanTableTriplet", "3", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x1000>, bool_t<(eid & 0x000f) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Shift Table Size", "ShiftTableSize", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x1000>, bool_t<(eid & 0x000f) == 0x0005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Shift Table Triplet", "ShiftTableTriplet", "3", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x1010>, bool_t<(eid & 0x0000) == 0x0000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Zonal Map", "ZonalMap", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Copies", "NumberOfCopies", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x001E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Configuration", "PrinterConfigurationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Print Priority", "PrintPriority", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Medium Type", "MediumType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Film Destination", "FilmDestination", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Film Session Label", "FilmSessionLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Memory Allocation", "MemoryAllocation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x0061>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Maximum Memory", "MaximumMemoryAllocation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x0062>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Color Image", "ColorImagePrintingFlag", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x0063>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Collation Flag", "CollationFlag", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x0065>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Annotation Flag", "AnnotationFlag", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x0067>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Image Overlay Flag", "ImageOverlayFlag", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x0069>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Presentation LUT", "PresentationLUTFlag", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x006A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Presentation LUT", "ImageBoxPresentationLUTFlag", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x00A0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Memory Bit Depth", "MemoryBitDepth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x00A1>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Printing Bit Depth", "PrintingBitDepth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x00A2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Media Installed", "MediaInstalledSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x00A4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Other Media", "OtherMediaAvailableSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x00A8>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Display Formats", "SupportedImageDisplayFormatsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x0500>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Film Box", "ReferencedFilmBoxSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2000>, bool_t<(eid & 0xffff) == 0x0510>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Stored", "ReferencedStoredPrintSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Image Display", "ImageDisplayFormat", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Annotation Display", "AnnotationDisplayFormatID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Film Orientation", "FilmOrientation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Film Size ID", "FilmSizeID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Printer Resolution", "PrinterResolutionID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0054>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Default Printer", "DefaultPrinterResolutionID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Magnification Type", "MagnificationType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Smoothing Type", "SmoothingType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x00A6>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Default", "DefaultMagnificationType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x00A7>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Other Magnification", "OtherMagnificationTypesAvailable", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x00A8>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Default Smoothing", "DefaultSmoothingType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x00A9>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Other Smoothing", "OtherSmoothingTypesAvailable", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Border Density", "BorderDensity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Empty Image Density", "EmptyImageDensity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0120>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Min Density", "MinDensity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0130>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Max Density", "MaxDensity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0140>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Trim", "Trim", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0150>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Configuration", "ConfigurationInformation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0152>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Information", "ConfigurationInformationDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0154>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Maximum Collated", "MaximumCollatedFilms", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x015E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Illumination", "Illumination", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0160>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Reflected Ambient", "ReflectedAmbientLight", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0376>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Printer Pixel", "PrinterPixelSpacing", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0500>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Film", "ReferencedFilmSessionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0510>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Image", "ReferencedImageBoxSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2010>, bool_t<(eid & 0xffff) == 0x0520>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Annotation Box", "ReferencedBasicAnnotationBoxSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2020>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Image Box Position", "ImageBoxPosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2020>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Polarity", "Polarity", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2020>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Requested Image", "RequestedImageSize", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2020>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Requested Decimate/", "RequestedDecimateCropBehavior", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2020>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Requested", "RequestedResolutionID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2020>, bool_t<(eid & 0xffff) == 0x00A0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Requested Image", "RequestedImageSizeFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2020>, bool_t<(eid & 0xffff) == 0x00A2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Decimate/Crop", "DecimateCropResult", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2020>, bool_t<(eid & 0xffff) == 0x0110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Basic Grayscale", "BasicGrayscaleImageSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2020>, bool_t<(eid & 0xffff) == 0x0111>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Basic Color Image", "BasicColorImageSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2020>, bool_t<(eid & 0xffff) == 0x0130>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Overlay Box", "ReferencedImageOverlayBoxSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2020>, bool_t<(eid & 0xffff) == 0x0140>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced VOI LUT", "ReferencedVOILUTBoxSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2030>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Annotation Position", "AnnotationPosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2030>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Text String", "TextString", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2040>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Overlay", "ReferencedOverlayPlaneSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2040>, bool_t<(eid & 0xffff) == 0x0011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Referenced Overlay", "ReferencedOverlayPlaneGroups", "1-", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2040>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Overlay Pixel Data", "OverlayPixelDataSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2040>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Overlay", "OverlayMagnificationType", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2040>, bool_t<(eid & 0xffff) == 0x0070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Overlay Smoothing", "OverlaySmoothingType", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2040>, bool_t<(eid & 0xffff) == 0x0072>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Overlay or Image", "OverlayOrImageMagnification", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2040>, bool_t<(eid & 0xffff) == 0x0074>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Magnify to Number", "MagnifyToNumberOfColumns", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2040>, bool_t<(eid & 0xffff) == 0x0080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Overlay Foreground", "OverlayForegroundDensity", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2040>, bool_t<(eid & 0xffff) == 0x0082>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Overlay Background", "OverlayBackgroundDensity", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2040>, bool_t<(eid & 0xffff) == 0x0090>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Overlay Mode", "OverlayMode", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2040>, bool_t<(eid & 0xffff) == 0x0100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Threshold Density", "ThresholdDensity", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2040>, bool_t<(eid & 0xffff) == 0x0500>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Box Sequence", "ReferencedImageBoxSequenceRetired", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2050>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Presentation LUT", "PresentationLUTSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2050>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Presentation LUT", "PresentationLUTShape", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2050>, bool_t<(eid & 0xffff) == 0x0500>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Presentation LUT", "ReferencedPresentationLUTSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2100>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Print Job ID", "PrintJobID", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2100>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Execution Status", "ExecutionStatus", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2100>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Execution Status", "ExecutionStatusInfo", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2100>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Creation Date", "CreationDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2100>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Creation Time", "CreationTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2100>, bool_t<(eid & 0xffff) == 0x0070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AE, "Originator", "Originator", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2100>, bool_t<(eid & 0xffff) == 0x0140>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AE, "Destination AE", "DestinationAE", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2100>, bool_t<(eid & 0xffff) == 0x0160>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Owner ID", "OwnerID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2100>, bool_t<(eid & 0xffff) == 0x0170>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Films", "NumberOfFilms", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2100>, bool_t<(eid & 0xffff) == 0x0500>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Job Sequence (Pull", "ReferencedPrintJobSequencePullStoredPrint", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2110>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Printer Status", "PrinterStatus", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2110>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Printer Status Info", "PrinterStatusInfo", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2110>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Printer Name", "PrinterName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2110>, bool_t<(eid & 0xffff) == 0x0099>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Print Queue ID", "PrintQueueID", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2120>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Queue Status", "QueueStatus", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2120>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Description", "PrintJobDescriptionSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2120>, bool_t<(eid & 0xffff) == 0x0070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Print", "ReferencedPrintJobSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2130>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Capabilities", "PrintManagementCapabilitiesSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2130>, bool_t<(eid & 0xffff) == 0x0015>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Characteristics", "PrinterCharacteristicsSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2130>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Film Box Content", "FilmBoxContentSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2130>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Image Box Content", "ImageBoxContentSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2130>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Annotation Content", "AnnotationContentSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2130>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Image Overlay Box", "ImageOverlayBoxContentSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2130>, bool_t<(eid & 0xffff) == 0x0080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Presentation LUT", "PresentationLUTContentSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2130>, bool_t<(eid & 0xffff) == 0x00A0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Proposed Study", "ProposedStudySequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2130>, bool_t<(eid & 0xffff) == 0x00C0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Original Image", "OriginalImageSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2200>, bool_t<(eid & 0xffff) == 0x0001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Information", "LabelUsingInformationExtractedFromInstances", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2200>, bool_t<(eid & 0xffff) == 0x0002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UT, "Label Text", "LabelText", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2200>, bool_t<(eid & 0xffff) == 0x0003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Label Style", "LabelStyleSelection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2200>, bool_t<(eid & 0xffff) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Media Disposition", "MediaDisposition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2200>, bool_t<(eid & 0xffff) == 0x0005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Barcode Value", "BarcodeValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2200>, bool_t<(eid & 0xffff) == 0x0006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Barcode Symbology", "BarcodeSymbology", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2200>, bool_t<(eid & 0xffff) == 0x0007>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Allow Media", "AllowMediaSplitting", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2200>, bool_t<(eid & 0xffff) == 0x0008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Include Non-DICOM", "IncludeNonDICOMObjects", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2200>, bool_t<(eid & 0xffff) == 0x0009>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Include Display", "IncludeDisplayApplication", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2200>, bool_t<(eid & 0xffff) == 0x000A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Instances After", "PreserveCompositeInstancesAfterMediaCreation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2200>, bool_t<(eid & 0xffff) == 0x000B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Pieces of Media", "TotalNumberOfPiecesOfMediaCreated", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2200>, bool_t<(eid & 0xffff) == 0x000C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Requested Media", "RequestedMediaApplicationProfile", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2200>, bool_t<(eid & 0xffff) == 0x000D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Storage", "ReferencedStorageMediaSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2200>, bool_t<(eid & 0xffff) == 0x000E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Failure Attributes", "FailureAttributes", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2200>, bool_t<(eid & 0xffff) == 0x000F>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Allow Lossy", "AllowLossyCompression", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x2200>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Request Priority", "RequestPriority", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "RT Image Label", "RTImageLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "RT Image Name", "RTImageName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "RT Image", "RTImageDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x000A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Reported Values", "ReportedValuesOrigin", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x000C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "RT Image Plane", "RTImagePlane", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x000D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Receptor", "XRayImageReceptorTranslation", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x000E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "X-Ray Image", "XRayImageReceptorAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "RT Image", "RTImageOrientation", "6", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Image Plane Pixel", "ImagePlanePixelSpacing", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "RT Image Position", "RTImagePosition", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Radiation Machine", "RadiationMachineName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Radiation Machine", "RadiationMachineSAD", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Radiation Machine", "RadiationMachineSSD", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0026>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "RT Image SID", "RTImageSID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Source to Reference", "SourceToReferenceObjectDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0029>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Fraction Number", "FractionNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Exposure Sequence", "ExposureSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Meterset Exposure", "MetersetExposure", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0034>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Diaphragm Position", "DiaphragmPosition", "4", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Fluence Map", "FluenceMapSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0041>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Fluence Data Source", "FluenceDataSource", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Fluence Data Scale", "FluenceDataScale", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Primary Fluence", "PrimaryFluenceModeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0051>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Fluence Mode", "FluenceMode", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3002>, bool_t<(eid & 0xffff) == 0x0052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Fluence Mode ID", "FluenceModeID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x0001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "DVH Type", "DVHType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x0002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Dose Units", "DoseUnits", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Dose Type", "DoseType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x0006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Dose Comment", "DoseComment", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x0008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Normalization Point", "NormalizationPoint", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x000A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Dose Summation Type", "DoseSummationType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x000C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Grid Frame Offset", "GridFrameOffsetVector", "2-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x000E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Dose Grid Scaling", "DoseGridScaling", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "RT Dose ROI", "RTDoseROISequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Dose Value", "DoseValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x0014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Heterogeneity", "TissueHeterogeneityCorrection", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "DVH Normalization", "DVHNormalizationPoint", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x0042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "DVH Normalization", "DVHNormalizationDoseValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "DVH Sequence", "DVHSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x0052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "DVH Dose Scaling", "DVHDoseScaling", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x0054>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "DVH Volume Units", "DVHVolumeUnits", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x0056>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "DVH Number of Bins", "DVHNumberOfBins", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x0058>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "DVH Data", "DVHData", "2-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "DVH Referenced ROI", "DVHReferencedROISequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x0062>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "DVH ROI", "DVHROIContributionType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x0070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "DVH Minimum Dose", "DVHMinimumDose", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x0072>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "DVH Maximum Dose", "DVHMaximumDose", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3004>, bool_t<(eid & 0xffff) == 0x0074>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "DVH Mean Dose", "DVHMeanDose", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Structure Set Label", "StructureSetLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Structure Set Name", "StructureSetName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Structure Set", "StructureSetDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Structure Set Date", "StructureSetDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0009>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Structure Set Time", "StructureSetTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Frame of", "ReferencedFrameOfReferenceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "RT Referenced Study", "RTReferencedStudySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "RT Referenced", "RTReferencedSeriesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Contour Image", "ContourImageSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Structure Set ROI", "StructureSetROISequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "ROI Number", "ROINumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Referenced Frame of", "ReferencedFrameOfReferenceUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0026>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "ROI Name", "ROIName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "ROI Description", "ROIDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x002A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "ROI Display Color", "ROIDisplayColor", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x002C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "ROI Volume", "ROIVolume", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "RT Related ROI", "RTRelatedROISequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0033>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "RT ROI Relationship", "RTROIRelationship", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0036>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "ROI Generation", "ROIGenerationAlgorithm", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0038>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "ROI Generation", "ROIGenerationDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0039>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "ROI Contour", "ROIContourSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Contour Sequence", "ContourSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Contour Geometric", "ContourGeometricType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0044>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Contour Slab", "ContourSlabThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0045>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Contour Offset", "ContourOffsetVector", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0046>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Contour", "NumberOfContourPoints", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0048>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Contour Number", "ContourNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0049>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Attached Contours", "AttachedContours", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Contour Data", "ContourData", "3-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "RT ROI Observations", "RTROIObservationsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0082>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Observation Number", "ObservationNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0084>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Referenced ROI", "ReferencedROINumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0085>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "ROI Observation", "ROIObservationLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0086>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Identification Code", "RTROIIdentificationCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x0088>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "ROI Observation", "ROIObservationDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x00A0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Observations", "RelatedRTROIObservationsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x00A4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "RT ROI Interpreted", "RTROIInterpretedType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x00A6>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "ROI Interpreter", "ROIInterpreter", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x00B0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "ROI Physical", "ROIPhysicalPropertiesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x00B2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "ROI Physical", "ROIPhysicalProperty", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x00B4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "ROI Physical", "ROIPhysicalPropertyValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x00B6>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Composition", "ROIElementalCompositionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x00B7>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Composition Atomic", "ROIElementalCompositionAtomicNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x00B8>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Composition Atomic", "ROIElementalCompositionAtomicMassFraction", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x00C0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Relationship", "FrameOfReferenceRelationshipSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x00C2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Related Frame of", "RelatedFrameOfReferenceUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x00C4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Frame of Reference", "FrameOfReferenceTransformationType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x00C6>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Transformation", "FrameOfReferenceTransformationMatrix", "16", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3006>, bool_t<(eid & 0xffff) == 0x00C8>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Transformation", "FrameOfReferenceTransformationComment", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Measured Dose", "MeasuredDoseReferenceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Measured Dose", "MeasuredDoseDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Measured Dose Type", "MeasuredDoseType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Measured Dose Value", "MeasuredDoseValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Treatment Session", "TreatmentSessionBeamSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0021>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Treatment Session", "TreatmentSessionIonBeamSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Current Fraction", "CurrentFractionNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Treatment Control", "TreatmentControlPointDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0025>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Treatment Control", "TreatmentControlPointTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x002A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Treatment", "TreatmentTerminationStatus", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x002B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Treatment", "TreatmentTerminationCode", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x002C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Treatment", "TreatmentVerificationStatus", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Treatment Record", "ReferencedTreatmentRecordSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0032>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Specified Primary", "SpecifiedPrimaryMeterset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0033>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Specified Secondary", "SpecifiedSecondaryMeterset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0036>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Delivered Primary", "DeliveredPrimaryMeterset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0037>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Delivered Secondary", "DeliveredSecondaryMeterset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x003A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Specified Treatment", "SpecifiedTreatmentTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x003B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Delivered Treatment", "DeliveredTreatmentTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Control Point", "ControlPointDeliverySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0041>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Ion Control Point", "IonControlPointDeliverySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Specified Meterset", "SpecifiedMeterset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0044>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Delivered Meterset", "DeliveredMeterset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0045>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Meterset Rate Set", "MetersetRateSet", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0046>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Meterset Rate", "MetersetRateDelivered", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0047>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Scan Spot Metersets", "ScanSpotMetersetsDelivered", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0048>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Dose Rate Delivered", "DoseRateDelivered", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Calculated Dose", "TreatmentSummaryCalculatedDoseReferenceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Cumulative Dose to", "CumulativeDoseToDoseReference", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0054>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "First Treatment", "FirstTreatmentDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0056>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Most Recent", "MostRecentTreatmentDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x005A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Fractions", "NumberOfFractionsDelivered", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Override Sequence", "OverrideSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0061>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Parameter Sequence", "ParameterSequencePointer", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0062>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Override Parameter", "OverrideParameterPointer", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0063>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Parameter Item", "ParameterItemIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0064>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Measured Dose", "MeasuredDoseReferenceNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0065>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Parameter Pointer", "ParameterPointer", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0066>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Override Reason", "OverrideReason", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0068>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Corrected Parameter", "CorrectedParameterSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x006A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Correction Value", "CorrectionValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Calculated Dose", "CalculatedDoseReferenceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0072>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Calculated Dose", "CalculatedDoseReferenceNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0074>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Reference", "CalculatedDoseReferenceDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0076>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Reference Dose", "CalculatedDoseReferenceDoseValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0078>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Start Meterset", "StartMeterset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x007A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "End Meterset", "EndMeterset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Dose Reference", "ReferencedMeasuredDoseReferenceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0082>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Dose Reference", "ReferencedMeasuredDoseReferenceNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0090>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Calculated Dose", "ReferencedCalculatedDoseReferenceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0092>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Calculated Dose", "ReferencedCalculatedDoseReferenceNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x00A0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Device Leaf Pairs", "BeamLimitingDeviceLeafPairsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x00B0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Recorded Wedge", "RecordedWedgeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x00C0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Compensator", "RecordedCompensatorSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x00D0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Recorded Block", "RecordedBlockSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x00E0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Measured Dose", "TreatmentSummaryMeasuredDoseReferenceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x00F0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Recorded Snout", "RecordedSnoutSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x00F2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Recorded Range", "RecordedRangeShifterSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x00F4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Spreading Device", "RecordedLateralSpreadingDeviceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x00F6>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Recorded Range", "RecordedRangeModulatorSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Recorded Source", "RecordedSourceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0105>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Source Serial", "SourceSerialNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Application Setup", "TreatmentSessionApplicationSetupSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0116>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Application Setup", "ApplicationSetupCheck", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0120>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Accessory Device", "RecordedBrachyAccessoryDeviceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0122>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Accessory Device", "ReferencedBrachyAccessoryDeviceNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0130>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Recorded Channel", "RecordedChannelSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0132>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Specified Channel", "SpecifiedChannelTotalTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0134>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Delivered Channel", "DeliveredChannelTotalTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0136>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Specified Number of", "SpecifiedNumberOfPulses", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0138>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Delivered Number of", "DeliveredNumberOfPulses", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x013A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Specified Pulse", "SpecifiedPulseRepetitionInterval", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x013C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Delivered Pulse", "DeliveredPulseRepetitionInterval", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0140>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Recorded Source", "RecordedSourceApplicatorSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0142>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Referenced Source", "ReferencedSourceApplicatorNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0150>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Recorded Channel", "RecordedChannelShieldSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0152>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Referenced Channel", "ReferencedChannelShieldNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0160>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Point Delivered", "BrachyControlPointDeliveredSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0162>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Safe Position Exit", "SafePositionExitDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0164>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Safe Position Exit", "SafePositionExitTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0166>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Safe Position", "SafePositionReturnDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0168>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Safe Position", "SafePositionReturnTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0200>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Current Treatment", "CurrentTreatmentStatus", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0202>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Treatment Status", "TreatmentStatusComment", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0220>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Fraction Group", "FractionGroupSummarySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0223>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Referenced Fraction", "ReferencedFractionNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0224>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Fraction Group Type", "FractionGroupType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0230>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Beam Stopper", "BeamStopperPosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0240>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Fraction Status", "FractionStatusSummarySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0250>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Treatment Date", "TreatmentDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x3008>, bool_t<(eid & 0xffff) == 0x0251>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Treatment Time", "TreatmentTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "RT Plan Label", "RTPlanLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0003>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "RT Plan Name", "RTPlanName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "RT Plan Description", "RTPlanDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "RT Plan Date", "RTPlanDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0007>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "RT Plan Time", "RTPlanTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0009>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Treatment Protocols", "TreatmentProtocols", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x000A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Plan Intent", "PlanIntent", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x000B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Treatment Sites", "TreatmentSites", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x000C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "RT Plan Geometry", "RTPlanGeometry", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x000E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Prescription", "PrescriptionDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Dose Reference", "DoseReferenceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Dose Reference", "DoseReferenceNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0013>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UI, "Dose Reference UID", "DoseReferenceUID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Dose Reference", "DoseReferenceStructureType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0015>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Nominal Beam Energy", "NominalBeamEnergyUnit", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Dose Reference", "DoseReferenceDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0018>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Dose Reference", "DoseReferencePointCoordinates", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x001A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Nominal Prior Dose", "NominalPriorDose", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Dose Reference Type", "DoseReferenceType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0021>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Constraint Weight", "ConstraintWeight", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Delivery Warning", "DeliveryWarningDose", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0023>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Delivery Maximum", "DeliveryMaximumDose", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0025>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Target Minimum Dose", "TargetMinimumDose", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0026>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Target Prescription", "TargetPrescriptionDose", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0027>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Target Maximum Dose", "TargetMaximumDose", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Target Underdose", "TargetUnderdoseVolumeFraction", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x002A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Organ at Risk Full-", "OrganAtRiskFullVolumeDose", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x002B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Organ at Risk Limit", "OrganAtRiskLimitDose", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x002C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Organ at Risk", "OrganAtRiskMaximumDose", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x002D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Overdose Volume", "OrganAtRiskOverdoseVolumeFraction", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Tolerance Table", "ToleranceTableSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Tolerance Table", "ToleranceTableNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0043>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Tolerance Table", "ToleranceTableLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0044>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Gantry Angle", "GantryAngleTolerance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0046>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Device Angle", "BeamLimitingDeviceAngleTolerance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0048>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Device Tolerance", "BeamLimitingDeviceToleranceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x004A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Device Position", "BeamLimitingDevicePositionTolerance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x004B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Snout Position", "SnoutPositionTolerance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x004C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Patient Support", "PatientSupportAngleTolerance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x004E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Table Top Eccentric", "TableTopEccentricAngleTolerance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x004F>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Table Top Pitch", "TableTopPitchAngleTolerance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Table Top Roll", "TableTopRollAngleTolerance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0051>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Table Top Vertical", "TableTopVerticalPositionTolerance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Longitudinal", "TableTopLongitudinalPositionTolerance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0053>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Table Top Lateral", "TableTopLateralPositionTolerance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0055>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "RT Plan", "RTPlanRelationship", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0070>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Fraction Group", "FractionGroupSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0071>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Fraction Group", "FractionGroupNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0072>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Fraction Group", "FractionGroupDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0078>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Fractions", "NumberOfFractionsPlanned", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0079>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Pattern Digits Per", "NumberOfFractionPatternDigitsPerDay", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x007A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Repeat Fraction", "RepeatFractionCycleLength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x007B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Fraction Pattern", "FractionPattern", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Beams", "NumberOfBeams", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0082>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Beam Dose", "BeamDoseSpecificationPoint", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0084>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Beam Dose", "BeamDose", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0086>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Beam Meterset", "BeamMeterset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0088>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Beam Dose Point", "BeamDosePointDepth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0089>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Beam Dose Point", "BeamDosePointEquivalentDepth", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x008A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Beam Dose Point SSD", "BeamDosePointSSD", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00A0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Brachy", "NumberOfBrachyApplicationSetups", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00A2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Setup Dose", "BrachyApplicationSetupDoseSpecificationPoint", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00A4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Brachy Application", "BrachyApplicationSetupDose", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00B0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Beam Sequence", "BeamSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00B2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Treatment Machine", "TreatmentMachineName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00B3>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Primary Dosimeter", "PrimaryDosimeterUnit", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00B4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Source-Axis", "SourceAxisDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00B6>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Beam Limiting", "BeamLimitingDeviceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00B8>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "RT Beam Limiting", "RTBeamLimitingDeviceType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00BA>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Limiting Device", "SourceToBeamLimitingDeviceDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00BB>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Limiting Device", "IsocenterToBeamLimitingDeviceDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00BC>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Leaf/Jaw", "NumberOfLeafJawPairs", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00BE>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Leaf Position", "LeafPositionBoundaries", "3-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00C0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Beam Number", "BeamNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00C2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Beam Name", "BeamName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00C3>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Beam Description", "BeamDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00C4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Beam Type", "BeamType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00C6>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Radiation Type", "RadiationType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00C7>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "High-Dose Technique", "HighDoseTechniqueType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00C8>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Reference Image", "ReferenceImageNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00CA>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Verification Image", "PlannedVerificationImageSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00CC>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Specific", "ImagingDeviceSpecificAcquisitionParameters", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00CE>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Treatment Delivery", "TreatmentDeliveryType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00D0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Wedges", "NumberOfWedges", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00D1>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Wedge Sequence", "WedgeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00D2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Wedge Number", "WedgeNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00D3>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Wedge Type", "WedgeType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00D4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Wedge ID", "WedgeID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00D5>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Wedge Angle", "WedgeAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00D6>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Wedge Factor", "WedgeFactor", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00D7>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Water-Equivalent", "TotalWedgeTrayWaterEquivalentThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00D8>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Wedge Orientation", "WedgeOrientation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00D9>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Isocenter to Wedge", "IsocenterToWedgeTrayDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00DA>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Source to Wedge", "SourceToWedgeTrayDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00DB>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Wedge Thin Edge", "WedgeThinEdgePosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00DC>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Bolus ID", "BolusID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00DD>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Bolus Description", "BolusDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00E0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of", "NumberOfCompensators", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00E1>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Material ID", "MaterialID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00E2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Total Compensator", "TotalCompensatorTrayFactor", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00E3>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Compensator", "CompensatorSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00E4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Compensator Number", "CompensatorNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00E5>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Compensator ID", "CompensatorID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00E6>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Compensator Tray", "SourceToCompensatorTrayDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00E7>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Compensator Rows", "CompensatorRows", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00E8>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Compensator Columns", "CompensatorColumns", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00E9>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Compensator Pixel", "CompensatorPixelSpacing", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00EA>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Compensator", "CompensatorPosition", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00EB>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Compensator", "CompensatorTransmissionData", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00EC>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Compensator", "CompensatorThicknessData", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00ED>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Boli", "NumberOfBoli", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00EE>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Compensator Type", "CompensatorType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00F0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Blocks", "NumberOfBlocks", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00F2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Total Block Tray", "TotalBlockTrayFactor", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00F3>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Water-Equivalent", "TotalBlockTrayWaterEquivalentThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00F4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Block Sequence", "BlockSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00F5>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Block Tray ID", "BlockTrayID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00F6>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Source to Block", "SourceToBlockTrayDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00F7>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Isocenter to Block", "IsocenterToBlockTrayDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00F8>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Block Type", "BlockType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00F9>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Accessory Code", "AccessoryCode", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00FA>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Block Divergence", "BlockDivergence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00FB>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Block Mounting", "BlockMountingPosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00FC>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Block Number", "BlockNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x00FE>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Block Name", "BlockName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Block Thickness", "BlockThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0102>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Block Transmission", "BlockTransmission", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0104>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Block Number of", "BlockNumberOfPoints", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0106>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Block Data", "BlockData", "2-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0107>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Applicator Sequence", "ApplicatorSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0108>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Applicator ID", "ApplicatorID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0109>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Applicator Type", "ApplicatorType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x010A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Applicator", "ApplicatorDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x010C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Reference", "CumulativeDoseReferenceCoefficient", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x010E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Final Cumulative", "FinalCumulativeMetersetWeight", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Control", "NumberOfControlPoints", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0111>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Control Point", "ControlPointSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0112>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Control Point Index", "ControlPointIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0114>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Nominal Beam Energy", "NominalBeamEnergy", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0115>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Dose Rate Set", "DoseRateSet", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0116>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Wedge Position", "WedgePositionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0118>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Wedge Position", "WedgePosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x011A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Device Position", "BeamLimitingDevicePositionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x011C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Leaf/Jaw Positions", "LeafJawPositions", "2-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x011E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Gantry Angle", "GantryAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x011F>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Gantry Rotation", "GantryRotationDirection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0120>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Beam Limiting", "BeamLimitingDeviceAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0121>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Device Rotation", "BeamLimitingDeviceRotationDirection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0122>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Patient Support", "PatientSupportAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0123>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Patient Support", "PatientSupportRotationDirection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0124>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Table Top Eccentric", "TableTopEccentricAxisDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0125>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Table Top Eccentric", "TableTopEccentricAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0126>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Table Top Eccentric", "TableTopEccentricRotationDirection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0128>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Table Top Vertical", "TableTopVerticalPosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0129>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Longitudinal", "TableTopLongitudinalPosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x012A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Table Top Lateral", "TableTopLateralPosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x012C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Isocenter Position", "IsocenterPosition", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x012E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Surface Entry Point", "SurfaceEntryPoint", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0130>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Source to Surface", "SourceToSurfaceDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0134>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Cumulative Meterset", "CumulativeMetersetWeight", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0140>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Table Top Pitch", "TableTopPitchAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0142>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Table Top Pitch", "TableTopPitchRotationDirection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0144>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Table Top Roll", "TableTopRollAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0146>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Table Top Roll", "TableTopRollRotationDirection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0148>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Head Fixation Angle", "HeadFixationAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x014A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Gantry Pitch Angle", "GantryPitchAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x014C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Gantry Pitch", "GantryPitchRotationDirection", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x014E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Gantry Pitch Angle", "GantryPitchAngleTolerance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0180>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Patient Setup", "PatientSetupSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0182>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Patient Setup", "PatientSetupNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0183>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Patient Setup Label", "PatientSetupLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0184>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Patient Additional", "PatientAdditionalPosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0190>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Fixation Device", "FixationDeviceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0192>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Fixation Device", "FixationDeviceType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0194>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Fixation Device", "FixationDeviceLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0196>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Fixation Device", "FixationDeviceDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0198>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Fixation Device", "FixationDevicePosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0199>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Fixation Device", "FixationDevicePitchAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x019A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Fixation Device", "FixationDeviceRollAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x01A0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Shielding Device", "ShieldingDeviceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x01A2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Shielding Device", "ShieldingDeviceType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x01A4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Shielding Device", "ShieldingDeviceLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x01A6>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Shielding Device", "ShieldingDeviceDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x01A8>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Shielding Device", "ShieldingDevicePosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x01B0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Setup Technique", "SetupTechnique", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x01B2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Setup Technique", "SetupTechniqueDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x01B4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Setup Device", "SetupDeviceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x01B6>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Setup Device Type", "SetupDeviceType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x01B8>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Setup Device Label", "SetupDeviceLabel", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x01BA>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Setup Device", "SetupDeviceDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x01BC>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Setup Device", "SetupDeviceParameter", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x01D0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Setup Reference", "SetupReferenceDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x01D2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Table Top Vertical", "TableTopVerticalSetupDisplacement", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x01D4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Longitudinal Setup", "TableTopLongitudinalSetupDisplacement", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x01D6>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Table Top Lateral", "TableTopLateralSetupDisplacement", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0200>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Brachy Treatment", "BrachyTreatmentTechnique", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0202>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Brachy Treatment", "BrachyTreatmentType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0206>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Treatment Machine", "TreatmentMachineSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0210>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Source Sequence", "SourceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0212>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Source Number", "SourceNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0214>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Source Type", "SourceType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0216>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Source Manufacturer", "SourceManufacturer", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0218>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Active Source", "ActiveSourceDiameter", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x021A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Active Source", "ActiveSourceLength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0222>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Encapsulation", "SourceEncapsulationNominalThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0224>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Encapsulation", "SourceEncapsulationNominalTransmission", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0226>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Source Isotope Name", "SourceIsotopeName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0228>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Source Isotope Half", "SourceIsotopeHalfLife", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0229>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Source Strength", "SourceStrengthUnits", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x022A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Reference Air Kerma", "ReferenceAirKermaRate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x022B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Source Strength", "SourceStrength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x022C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Source Strength", "SourceStrengthReferenceDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x022E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Source Strength", "SourceStrengthReferenceTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0230>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Application Setup", "ApplicationSetupSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0232>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Application Setup", "ApplicationSetupType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0234>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Application Setup", "ApplicationSetupNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0236>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Application Setup", "ApplicationSetupName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0238>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Application Setup", "ApplicationSetupManufacturer", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0240>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Template Number", "TemplateNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0242>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Template Type", "TemplateType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0244>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Template Name", "TemplateName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0250>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Total Reference Air", "TotalReferenceAirKerma", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0260>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Brachy Accessory", "BrachyAccessoryDeviceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0262>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Brachy Accessory", "BrachyAccessoryDeviceNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0263>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Brachy Accessory", "BrachyAccessoryDeviceID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0264>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Brachy Accessory", "BrachyAccessoryDeviceType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0266>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Brachy Accessory", "BrachyAccessoryDeviceName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x026A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Device Nominal", "BrachyAccessoryDeviceNominalThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x026C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Device Nominal", "BrachyAccessoryDeviceNominalTransmission", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0280>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Channel Sequence", "ChannelSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0282>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Channel Number", "ChannelNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0284>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Channel Length", "ChannelLength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0286>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Channel Total Time", "ChannelTotalTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0288>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Source Movement", "SourceMovementType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x028A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Pulses", "NumberOfPulses", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x028C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Pulse Repetition", "PulseRepetitionInterval", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0290>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Source Applicator", "SourceApplicatorNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0291>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Source Applicator", "SourceApplicatorID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0292>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Source Applicator", "SourceApplicatorType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0294>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Source Applicator", "SourceApplicatorName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0296>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Source Applicator", "SourceApplicatorLength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0298>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Source Applicator", "SourceApplicatorManufacturer", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x029C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Wall Nominal", "SourceApplicatorWallNominalThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x029E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Wall Nominal", "SourceApplicatorWallNominalTransmission", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02A0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Source Applicator", "SourceApplicatorStepSize", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02A2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Transfer Tube", "TransferTubeNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02A4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Transfer Tube", "TransferTubeLength", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02B0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Channel Shield", "ChannelShieldSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02B2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Channel Shield", "ChannelShieldNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02B3>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Channel Shield ID", "ChannelShieldID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02B4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Channel Shield Name", "ChannelShieldName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02B8>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Channel Shield", "ChannelShieldNominalThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02BA>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Nominal", "ChannelShieldNominalTransmission", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02C8>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Final Cumulative", "FinalCumulativeTimeWeight", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02D0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Brachy Control", "BrachyControlPointSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02D2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Control Point", "ControlPointRelativePosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02D4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Control Point 3D", "ControlPoint3DPosition", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02D6>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Cumulative Time", "CumulativeTimeWeight", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02E0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Compensator", "CompensatorDivergence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02E1>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Compensator", "CompensatorMountingPosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02E2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Compensator", "SourceToCompensatorDistance", "n", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02E3>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Tray Water-", "TotalCompensatorTrayWaterEquivalentThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02E4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Compensator Tray", "IsocenterToCompensatorTrayDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02E5>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Compensator Column", "CompensatorColumnOffset", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02E6>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Compensator", "IsocenterToCompensatorDistances", "n", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02E7>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Relative Stopping", "CompensatorRelativeStoppingPowerRatio", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02E8>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Compensator Milling", "CompensatorMillingToolDiameter", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02EA>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Compensator", "IonRangeCompensatorSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x02EB>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Compensator", "CompensatorDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0302>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Radiation Mass", "RadiationMassNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0304>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Radiation Atomic", "RadiationAtomicNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0306>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SS, "Radiation Charge", "RadiationChargeState", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0308>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Scan Mode", "ScanMode", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x030A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Virtual Source-Axis", "VirtualSourceAxisDistances", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x030C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Snout Sequence", "SnoutSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x030D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Snout Position", "SnoutPosition", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x030F>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Snout ID", "SnoutID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0312>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Range", "NumberOfRangeShifters", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0314>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Range Shifter", "RangeShifterSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0316>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Range Shifter", "RangeShifterNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0318>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Range Shifter ID", "RangeShifterID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0320>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Range Shifter Type", "RangeShifterType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0322>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Range Shifter", "RangeShifterDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0330>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Lateral", "NumberOfLateralSpreadingDevices", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0332>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Lateral Spreading", "LateralSpreadingDeviceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0334>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Lateral Spreading", "LateralSpreadingDeviceNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0336>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Lateral Spreading", "LateralSpreadingDeviceID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0338>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Lateral Spreading", "LateralSpreadingDeviceType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x033A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Lateral Spreading", "LateralSpreadingDeviceDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x033C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Device Water", "LateralSpreadingDeviceWaterEquivalentThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0340>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Range", "NumberOfRangeModulators", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0342>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Range Modulator", "RangeModulatorSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0344>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Range Modulator", "RangeModulatorNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0346>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Range Modulator ID", "RangeModulatorID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0348>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Range Modulator", "RangeModulatorType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x034A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Range Modulator", "RangeModulatorDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x034C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Beam Current", "BeamCurrentModulationID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0350>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Patient Support", "PatientSupportType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0352>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Patient Support ID", "PatientSupportID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0354>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Patient Support", "PatientSupportAccessoryCode", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0356>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Fixation Light", "FixationLightAzimuthalAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0358>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Fixation Light", "FixationLightPolarAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x035A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Meterset Rate", "MetersetRate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0360>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Range Shifter", "RangeShifterSettingsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0362>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Range Shifter", "RangeShifterSetting", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0364>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Isocenter to Range", "IsocenterToRangeShifterDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0366>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Equivalent", "RangeShifterWaterEquivalentThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0370>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Device Settings", "LateralSpreadingDeviceSettingsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0372>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Lateral Spreading", "LateralSpreadingDeviceSetting", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0374>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Lateral Spreading", "IsocenterToLateralSpreadingDeviceDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0380>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Range Modulator", "RangeModulatorSettingsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0382>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Range Modulator", "RangeModulatorGatingStartValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0384>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Range Modulator", "RangeModulatorGatingStopValue", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0386>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Gating Start Water", "RangeModulatorGatingStartWaterEquivalentThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0388>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Gating Stop Water", "RangeModulatorGatingStopWaterEquivalentThickness", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x038A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Isocenter to Range", "IsocenterToRangeModulatorDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0390>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Scan Spot Tune ID", "ScanSpotTuneID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0392>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Scan Spot", "NumberOfScanSpotPositions", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0394>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Scan Spot Position", "ScanSpotPositionMap", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0396>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Scan Spot Meterset", "ScanSpotMetersetWeights", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0398>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Scanning Spot Size", "ScanningSpotSize", "2", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x039A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Paintings", "NumberOfPaintings", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x03A0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Ion Tolerance Table", "IonToleranceTableSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x03A2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Ion Beam Sequence", "IonBeamSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x03A4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Ion Beam Limiting", "IonBeamLimitingDeviceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x03A6>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Ion Block Sequence", "IonBlockSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x03A8>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Ion Control Point", "IonControlPointSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x03AA>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Ion Wedge Sequence", "IonWedgeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x03AC>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Ion Wedge Position", "IonWedgePositionSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0401>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Setup", "ReferencedSetupImageSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0402>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Setup Image Comment", "SetupImageComment", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0410>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Synchronization", "MotionSynchronizationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0412>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Control Point", "ControlPointOrientation", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0420>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "General Accessory", "GeneralAccessorySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0421>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "General Accessory", "GeneralAccessoryID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0422>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "General Accessory", "GeneralAccessoryDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0423>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "General Accessory", "GeneralAccessoryType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0424>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "General Accessory", "GeneralAccessoryNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0431>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Applicator Geometry", "ApplicatorGeometrySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0432>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Applicator Aperture", "ApplicatorApertureShape", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0433>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Applicator Opening", "ApplicatorOpening", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0434>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Applicator Opening", "ApplicatorOpeningX", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0435>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Applicator Opening", "ApplicatorOpeningY", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300A>, bool_t<(eid & 0xffff) == 0x0436>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Applicator Mounting", "SourceToApplicatorMountingPositionDistance", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x0002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced RT Plan", "ReferencedRTPlanSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Beam", "ReferencedBeamSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x0006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Referenced Beam", "ReferencedBeamNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x0007>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Reference Image", "ReferencedReferenceImageNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x0008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "Start Cumulative", "StartCumulativeMetersetWeight", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x0009>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "End Cumulative", "EndCumulativeMetersetWeight", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x000A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Application Setup", "ReferencedBrachyApplicationSetupSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x000C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Application Setup", "ReferencedBrachyApplicationSetupNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x000E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Referenced Source", "ReferencedSourceNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Fraction", "ReferencedFractionGroupSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x0022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Referenced Fraction", "ReferencedFractionGroupNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Verification Image", "ReferencedVerificationImageSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x0042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Reference Image", "ReferencedReferenceImageSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Dose", "ReferencedDoseReferenceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x0051>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Referenced Dose", "ReferencedDoseReferenceNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x0055>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Dose Reference", "BrachyReferencedDoseReferenceSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Structure Set", "ReferencedStructureSetSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x006A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Referenced Patient", "ReferencedPatientSetupNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x0080>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Dose", "ReferencedDoseSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x00A0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Tolerance Table", "ReferencedToleranceTableNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x00B0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Bolus", "ReferencedBolusSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x00C0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Referenced Wedge", "ReferencedWedgeNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x00D0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Referenced", "ReferencedCompensatorNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x00E0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Referenced Block", "ReferencedBlockNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x00F0>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Referenced Control", "ReferencedControlPointIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x00F2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Referenced Control", "ReferencedControlPointSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x00F4>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Referenced Start", "ReferencedStartControlPointIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x00F6>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Referenced Stop", "ReferencedStopControlPointIndex", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x0100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Referenced Range", "ReferencedRangeShifterNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x0102>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Spreading Device", "ReferencedLateralSpreadingDeviceNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300C>, bool_t<(eid & 0xffff) == 0x0104>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Referenced Range", "ReferencedRangeModulatorNumber", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300E>, bool_t<(eid & 0xffff) == 0x0002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Approval Status", "ApprovalStatus", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300E>, bool_t<(eid & 0xffff) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Review Date", "ReviewDate", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300E>, bool_t<(eid & 0xffff) == 0x0005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Review Time", "ReviewTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x300E>, bool_t<(eid & 0xffff) == 0x0008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Reviewer Name", "ReviewerName", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4000>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Arbitrary", "Arbitrary", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4000>, bool_t<(eid & 0xffff) == 0x4000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Text Comments", "TextComments", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Results ID", "ResultsID", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Results ID Issuer", "ResultsIDIssuer", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Interpretation", "ReferencedInterpretationSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x00FF>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Report Production", "ReportProductionStatusTrial", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Interpretation", "InterpretationRecordedDate", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0101>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Interpretation", "InterpretationRecordedTime", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0102>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Interpretation", "InterpretationRecorder", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0103>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Reference to", "ReferenceToRecordedSound", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0108>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Interpretation", "InterpretationTranscriptionDate", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0109>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Interpretation", "InterpretationTranscriptionTime", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x010A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Interpretation", "InterpretationTranscriber", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x010B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Interpretation Text", "InterpretationText", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x010C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Interpretation", "InterpretationAuthor", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0111>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Interpretation", "InterpretationApproverSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0112>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DA, "Interpretation", "InterpretationApprovalDate", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0113>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::TM, "Interpretation", "InterpretationApprovalTime", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0114>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Physician Approving", "PhysicianApprovingInterpretation", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0115>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Diagnosis", "InterpretationDiagnosisDescription", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0117>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Diagnosis Code", "InterpretationDiagnosisCodeSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0118>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Distribution List", "ResultsDistributionListSequence", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0119>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::PN, "Distribution Name", "DistributionName", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x011A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Distribution", "DistributionAddress", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0200>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Interpretation ID", "InterpretationID", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0202>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Interpretation ID", "InterpretationIDIssuer", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0210>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Interpretation Type", "InterpretationTypeID", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0212>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Interpretation", "InterpretationStatusID", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x0300>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Impressions", "Impressions", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4008>, bool_t<(eid & 0xffff) == 0x4000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::ST, "Results Comments", "ResultsComments", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x0001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Low Energy", "LowEnergyDetectors", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x0002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "High Energy", "HighEnergyDetectors", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x0004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Detector Geometry", "DetectorGeometrySequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Threat ROI Voxel", "ThreatROIVoxelSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Threat ROI Base", "ThreatROIBase", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Threat ROI Extents", "ThreatROIExtents", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OB, "Threat ROI Bitmap", "ThreatROIBitmap", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1007>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Route Segment ID", "RouteSegmentID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Gantry Type", "GantryType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1009>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "OOI Owner Type", "OOIOwnerType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x100A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Route Segment", "RouteSegmentSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Potential Threat", "PotentialThreatObjectID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Threat Sequence", "ThreatSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Threat Category", "ThreatCategory", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1013>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Threat Category", "ThreatCategoryDescription", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1014>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "ATD Ability", "ATDAbilityAssessment", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1015>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "ATD Assessment Flag", "ATDAssessmentFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1016>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "ATD Assessment", "ATDAssessmentProbability", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1017>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Mass", "Mass", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1018>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Density", "Density", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1019>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Z Effective", "ZEffective", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x101A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Boarding Pass ID", "BoardingPassID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x101B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Center of Mass", "CenterOfMass", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x101C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Center of PTO", "CenterOfPTO", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x101D>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Bounding Polygon", "BoundingPolygon", "6-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x101E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Route Segment Start", "RouteSegmentStartLocationID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x101F>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Route Segment End", "RouteSegmentEndLocationID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Route Segment", "RouteSegmentLocationIDType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1021>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Abort Reason", "AbortReason", "1-", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1023>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Volume of PTO", "VolumeOfPTO", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1024>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Abort Flag", "AbortFlag", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1025>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Route Segment Start", "RouteSegmentStartTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1026>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Route Segment End", "RouteSegmentEndTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1027>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "TDR Type", "TDRType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1028>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "International Route", "InternationalRouteSegment", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1029>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Algorithm and", "ThreatDetectionAlgorithmandVersion", "n", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x102A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Assigned Location", "AssignedLocation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x102B>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "Alarm Decision Time", "AlarmDecisionTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1031>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Alarm Decision", "AlarmDecision", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1033>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Total", "NumberOfTotalObjects", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1034>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Alarm", "NumberOfAlarmObjects", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1037>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "PTO Representation", "PTORepresentationSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1038>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "ATD Assessment", "ATDAssessmentSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1039>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "TIP Type", "TIPType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x103A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "DICOS Version", "DICOSVersion", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1041>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DT, "OOI Owner Creation", "OOIOwnerCreationTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1042>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "OOI Type", "OOIType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1043>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "OOI Size", "OOISize", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1044>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Acquisition Status", "AcquisitionStatus", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1045>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Basis Materials", "BasisMaterialsCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1046>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Phantom Type", "PhantomType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1047>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "OOI Owner Sequence", "OOIOwnerSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1048>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Scan Type", "ScanType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1051>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Itinerary ID", "ItineraryID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Itinerary ID Type", "ItineraryIDType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1053>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Itinerary ID", "ItineraryIDAssigningAuthority", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1054>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Route ID", "RouteID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1055>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Route ID Assigning", "RouteIDAssigningAuthority", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1056>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Inbound Arrival", "InboundArrivalType", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1058>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Carrier ID", "CarrierID", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1059>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Carrier ID", "CarrierIDAssigningAuthority", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Source Orientation", "SourceOrientation", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1061>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Source Position", "SourcePosition", "3", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1062>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Belt Height", "BeltHeight", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1064>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Algorithm Routing", "AlgorithmRoutingCodeSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1067>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Transport", "TransportClassification", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1068>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "OOI Type Descriptor", "OOITypeDescriptor", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x1069>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::FL, "Total Processing", "TotalProcessingTime", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4010>, bool_t<(eid & 0xffff) == 0x106C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OB, "Detector", "DetectorCalibrationData", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x4FFE>, bool_t<(eid & 0xffff) == 0x0001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "MAC Parameters", "MACParametersSequence", "1", false) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x0005>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Curve Dimensions", "CurveDimensions", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of Points", "NumberOfPoints", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Type of Data", "TypeOfData", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x0022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Curve Description", "CurveDescription", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Axis Units", "AxisUnits", "1-n", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Axis Labels", "AxisLabels", "1-n", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x0103>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Data Value", "DataValueRepresentation", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x0104>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Minimum", "MinimumCoordinateValue", "1-n", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x0105>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Maximum", "MaximumCoordinateValue", "1-n", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x0106>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Curve Range", "CurveRange", "1-n", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x0110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Curve Data", "CurveDataDescriptor", "1-n", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x0112>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Coordinate Start", "CoordinateStartValue", "1-n", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x0114>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Coordinate Step", "CoordinateStepValue", "1-n", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x1001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Curve Activation", "CurveActivationLayer", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x2000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Audio Type", "AudioType", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x2002>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Audio Sample", "AudioSampleFormat", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x2004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Number of", "NumberOfChannels", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x2006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Number of Samples", "NumberOfSamples", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x2008>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Sample Rate", "SampleRate", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x200A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::UL, "Total Time", "TotalTime", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x200C>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OB, "Audio Sample Data AudioSampleData OW", "or", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x200E>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Audio Comments", "AudioComments", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x2500>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Curve Label", "CurveLabel", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x2600>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Curve Referenced", "CurveReferencedOverlaySequence", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x2610>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Curve Referenced", "CurveReferencedOverlayGroup", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x5000>, bool_t<(eid & 0xffff) == 0x3000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OB, "Curve Data CurveData OW", "or", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x5200>, bool_t<(eid & 0xffff) == 0x9229>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Shared Functional", "SharedFunctionalGroupsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x5200>, bool_t<(eid & 0xffff) == 0x9230>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Functional Groups", "PerFrameFunctionalGroupsSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x5400>, bool_t<(eid & 0xffff) == 0x0100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Waveform Sequence", "WaveformSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x5400>, bool_t<(eid & 0xffff) == 0x0110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Channel Minimum ChannelMinimumValue OB", "or", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x5400>, bool_t<(eid & 0xffff) == 0x0112>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Channel Maximum ChannelMaximumValue OB", "or", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x5400>, bool_t<(eid & 0xffff) == 0x1004>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Waveform Bits", "WaveformBitsAllocated", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x5400>, bool_t<(eid & 0xffff) == 0x1006>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Waveform Sample", "WaveformSampleInterpretation", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x5400>, bool_t<(eid & 0xffff) == 0x100A>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Waveform Padding WaveformPaddingValue OB", "or", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x5400>, bool_t<(eid & 0xffff) == 0x1010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Waveform Data WaveformData OB", "or", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x5600>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OF, "First Order Phase", "FirstOrderPhaseCorrectionAngle", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x5600>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OF, "Spectroscopy Data", "SpectroscopyData", "1", false) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Overlay Rows", "OverlayRows", "1", false) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Overlay Columns", "OverlayColumns", "1", false) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0012>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Overlay Planes", "OverlayPlanes", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0015>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "Number of Frames", "NumberOfFramesInOverlay", "1", false) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0022>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Overlay", "OverlayDescription", "1", false) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Overlay Type", "OverlayType", "1", false) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0045>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Overlay Subtype", "OverlaySubtype", "1", false) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0050>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SS, "Overlay Origin", "OverlayOrigin", "2", false) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0051>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Image Frame", "ImageFrameOrigin", "1", false) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0052>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Overlay Plane", "OverlayPlaneOrigin", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0060>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Overlay", "OverlayCompressionCode", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0061>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Compression", "OverlayCompressionOriginator", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0062>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SH, "Overlay", "OverlayCompressionLabel", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0063>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Compression", "OverlayCompressionDescription", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0066>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Compression Step", "OverlayCompressionStepPointers", "1-n", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0068>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Overlay Repeat", "OverlayRepeatInterval", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0069>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Overlay Bits", "OverlayBitsGrouped", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Overlay Bits", "OverlayBitsAllocated", "1", false) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0102>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Overlay Bit", "OverlayBitPosition", "1", false) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0110>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Overlay Format", "OverlayFormat", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0200>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Overlay Location", "OverlayLocation", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0800>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Overlay Code", "OverlayCodeLabel", "1-n", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0802>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Overlay Number of", "OverlayNumberOfTables", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0803>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::AT, "Overlay Code", "OverlayCodeTableLocation", "1-n", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x0804>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Overlay Bits For", "OverlayBitsForCodeWord", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x1001>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::CS, "Overlay", "OverlayActivationLayer", "1", false) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x1100>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Overlay", "OverlayDescriptorGray", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x1101>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Overlay", "OverlayDescriptorRed", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x1102>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Descriptor -", "OverlayDescriptorGreen", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x1103>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Overlay", "OverlayDescriptorBlue", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x1200>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Overlays - Gray", "OverlaysGray", "1-n", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x1201>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Overlays - Red", "OverlaysRed", "1-n", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x1202>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Overlays - Green", "OverlaysGreen", "1-n", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x1203>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Overlays - Blue", "OverlaysBlue", "1-n", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x1301>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::IS, "ROI Area", "ROIArea", "1", false) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x1302>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "ROI Mean", "ROIMean", "1", false) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x1303>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::DS, "ROI Standard", "ROIStandardDeviation", "1", false) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x1500>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LO, "Overlay Label", "OverlayLabel", "1", false) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x3000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Overlay Data OverlayData OB", "or", "1", false) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x6000>, bool_t<(eid & 0xffff) == 0x4000>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::LT, "Overlay Comments", "OverlayComments", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x7FE0>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OB, "Pixel Data PixelData OW", "or", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x7FE0>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Coefficients SDVN", "CoefficientsSDVN", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x7FE0>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Coefficients SDHN", "CoefficientsSDHN", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0x7FE0>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Coefficients SDDN", "CoefficientsSDDN", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x7F00>, bool_t<(eid & 0xffff) == 0x0010>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OB, "Variable Pixel VariablePixelData OW", "or", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x7F00>, bool_t<(eid & 0xffff) == 0x0011>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::US, "Variable Next", "VariableNextDataGroup", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x7F00>, bool_t<(eid & 0xffff) == 0x0020>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Variable", "VariableCoefficientsSDVN", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x7F00>, bool_t<(eid & 0xffff) == 0x0030>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Variable", "VariableCoefficientsSDHN", "1", true) {}
};
template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xff00) == 0x7F00>, bool_t<(eid & 0xffff) == 0x0040>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OW, "Variable", "VariableCoefficientsSDDN", "1", true) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0xFFFA>, bool_t<(eid & 0xffff) == 0xFFFA>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::SQ, "Signatures", "DigitalSignaturesSequence", "1", false) {}
};
template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == 0xFFFC>, bool_t<(eid & 0xffff) == 0xFFFC>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::OB, "Data Set Trailing", "DataSetTrailingPadding", "1", false) {}
};


#endif
