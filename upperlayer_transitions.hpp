#ifndef UPPERLAYER_TRANSITIONS_HPP
#define UPPERLAYER_TRANSITIONS_HPP

#include <map>

#include "upperlayer.hpp"
#include "upperlayer_properties.hpp"

namespace upperlayer
{

extern std::map<std::pair<scp::CONN_STATE, TYPE>, scp::CONN_STATE> transition_table_user_primitives;
extern std::map<std::pair<scp::CONN_STATE, TYPE>, scp::CONN_STATE> transition_table_received_pdus;

}

#endif // UPPERLAYER_TRANSITIONS_HPP
