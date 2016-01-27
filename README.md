# DICOM

## What is this?

This project is a boost::asio - based implementation of the DICOM network protocol. Leveraging the features of C++11, the goal is to realize a type-safe, easy-to-use and abstract framework to build applications based on the DICOM protocol.

## Progress
Currently, only the upperlayer as described in chapter 8 of the standard is fully 
realized on the master branch. Implementation of the DIMSE layer is currently work-in-progress; The DIMSE protocol machine supports the C-ECHO service group.

## Example
The main.cpp file contains an example which will be walked through:

```c++
dicom::data::dictionary::dictionary dict {"commanddictionary.csv", "datadictionary.csv"};
```
will initialize the dictionary necessary for the DIMSE protocol machine to get the VR of an attribute. 

```c++
dicom::network::dimse::SOP_class echo {"1.2.840.10008.1.1",
{ { dataset::DIMSE_SERVICE_GROUP::C_ECHO_RQ,
   [](std::unique_ptr<dataset::iod> data)  {
      assert(data == nullptr);
      std::cout << "Received C_ECHO_RQ\n";
      return dicom::network::dimse::response {dataset::DIMSE_SERVICE_GROUP::C_ECHO_RSP};
   }}}
};
```
defines the functionality of the SOP class. Each SOP class  consists of one or more Service Groups which operate on an optional IOD.  The first string parameter is the UID of the SOP class. The second parameter consists of a set of pairs of the Service Group, and a corresponding handler function which will be invoked by the protocl machine if  a indication of the respective Service Group was received. It returns a response object with the response Service Group type, and may additionally contain an IOD, status and priority information.

```c++
try
{
   dicom::network::upperlayer::scp sc(11112);
   dicom::network::dimse::dimse_pm dpm(sc,
      {{echo, {"1.2.840.10008.1.2"}}},
      dict
   );
   sc.run();
} catch (std::exception& ec) {
   std::cout << ec.what();
}
```
The first line creates an upperlayer SCP which will be used by the DIMSE PM to communicate over the network. The second line an instance of the DIMSE PM is created, taking the upperlayer-object, a list of SOP classes with their supported transfer syntax UIDs, and the dictionary as arguments.


## Dependencies
* boost 

## Supported Compilers
Tested on:

* gcc 5.85
* clang 3.7.0
* msvc12 (master branch)

## Build Instructions
This project uses CMake for the build configuration. Invoking the ```cmake CMakeLists.txt``` from the command line or using the CMake GUI should generate a working Makefile / VS project file.

