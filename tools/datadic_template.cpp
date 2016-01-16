#ifndef DATADIC_TEMPLATE_HPP
#define DATADIC_TEMPLATE_HPP

#include "dictionary_entry.hpp"


template<bool> struct bool_t;

template<unsigned gid, unsigned eid, typename = bool_t<true>, typename = bool_t<true> >
struct datadictionary;

