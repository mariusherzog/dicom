# DICOM

## Synopsis

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
{ 
    { 
       dataset::DIMSE_SERVICE_GROUP::C_ECHO_RQ,
       [](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data)  {
            assert(data == nullptr);
            std::cout << "Received C_ECHO_RQ\n";
            pm->send_response({dataset::DIMSE_SERVICE_GROUP::C_ECHO_RQ, command});
        }
    }
}
};
```
defines the functionality of a single SOP class. Each SOP class  consists of one or more Service Groups which operate on an optional IOD.  The first string parameter is the UID of the SOP class. The second parameter consists of a set of pairs of the Service Group, and a corresponding handler function which will be invoked by the protocol machine if an indication of the respective Service Group was received. From this handler, the user can send a response to the peer using the send_response() member function, which takes a response object with the response Service Group type, and may additionally contain an IOD, status and priority information as a parameter. Additionally release_connection() and abort_connection() can be used to gracefully or instantly release the connection respectively.

```c++
dicom::network::dimse::association_definition ascdef {"STORESCP", "ANY-SCU",
   {
       {echo, {"1.2.840.10008.1.2"}, dimse::association_definition::DIMSE_MSG_TYPE::RESPONSE},
   }
};
```
will define the whole functionality of the association. First, the calling and called AE entity names are set. Then, a list of presentation contexts can be set, consisting of the previously defined SOP class, a list of applicable transfer syntaxes and the message type. A message type of RESPONSE means, that the associated SOP functionality is called when a data message of the respective SOP class is received from the peer. In case of a SCU, at least (and usually only) one element needs to be of the type message type INITIATOR. When an associaten is established as a SCU, each presentation context of type INITIATOR will be called to initiate the message exchange.
Optionally, the Association Context UID and the maximum message length can be defined.


```c++
try
{
   dicom::network::upperlayer::scp sc(11112);
   dicom::network::dimse::dimse_pm dpm(sc, ascdef, dict);
   sc.run();
} catch (std::exception& ec) {
   std::cout << ec.what();
}
```
The first line creates an upperlayer SCP which will be used by the DIMSE PM to communicate over the network. In the second one an instance of the DIMSE PM is created, taking the upperlayer-object, the association definition, and the dictionary as arguments. The member function call run() instructs the upper layer to wait for and handle incoming connections.


## Dependencies
* boost 

## Supported Compilers
Tested on:

* gcc 4.8.5
* clang 3.7.0
* msvc12 (master branch)

## Build Instructions
This project uses CMake for the build configuration. Invoking the ```cmake CMakeLists.txt``` from the command line or using the CMake GUI should generate a working Makefile / VS project file.

