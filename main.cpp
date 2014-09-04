#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <boost/asio.hpp>

#include "dimse_pm.hpp"


void print(std::vector<unsigned char> c, std::vector<unsigned char> d)
{
   std::cout << "Command set: \n";
   for (const auto e : c) {
      std::cout << e;
   }

   std::cout << "Data set: \n";
   for (const auto e : d) {
      std::cout << e;
   }
}

int main()
{
//   dimse_pm dpm;
//   dpm.inject(1, print);
//   dpm.receive();
   upperlayer::scp sc(11112);
   sc.receive();
}
