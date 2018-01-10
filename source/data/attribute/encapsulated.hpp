#ifndef ENCAPSULATED_HPP
#define ENCAPSULATED_HPP

#include <vector>
#include <ostream>

#include "boost/variant.hpp"

class encapsulated
{
   public:
      encapsulated();
};

class byte_length : public boost::static_visitor<std::size_t>
{
public:

    std::size_t operator()(const encapsulated& encapsulated_data) const
    {
        return 0;
    }

    std::size_t operator()(const std::vector<unsigned char>& str) const
    {
        return str.size();
    }

};

class printer : public boost::static_visitor<std::ostream&>
{
    private:
        std::ostream& os;

public:
        printer(std::ostream& os): os{os}
        {

        }

    std::ostream& operator()(const encapsulated& encapsulated_data) const
    {
        return os << "tt";
    }

    std::ostream& operator()(const std::vector<unsigned char>& data) const
    {
        std::size_t printsize = std::min(data.size(), 128ul);
        std::copy(data.begin(), data.begin()+printsize, std::ostream_iterator<char>(os, " "));
        return os;
    }

};

#endif // ENCAPSULATED_HPP
