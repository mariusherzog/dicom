#ifndef DATADIC_HPP
#define DATADIC_HPP

#include "dictionary_entry.hpp"

namespace dicom
{

namespace data
{

namespace dictionary
{

template<bool> struct bool_t;

template<unsigned gid, unsigned eid, typename = bool_t<true>, typename = bool_t<true> >
struct datadictionary;

