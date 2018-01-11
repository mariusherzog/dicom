#include "encapsulated.hpp"

encapsulated::encapsulated()
{

}

void encapsulated::push_fragment(std::vector<unsigned char> data)
{
   fragments.push_back(data);
}
