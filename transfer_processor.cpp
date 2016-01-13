#include "transfer_processor.hpp"

Itransfer_processor::~Itransfer_processor()
{
}


std::vector<unsigned char> commandset_processor::deserialize(iod data) const
{
}

iod commandset_processor::serialize(std::vector<unsigned char> data) const
{
}

std::string commandset_processor::get_transfer_syntax() const
{
   return "1.2.840.10008.1.2";
}
