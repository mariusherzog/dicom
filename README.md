# libdicompp 

## Description
This project is a modern C++ and boost implementation of the DICOM standard. Leveraging the features of C++11, the goal is to realize a type-safe, easy-to-use and abstract framework to build applications based on the DICOM protocol.

## Progress
Regarding networking, currently the upperlayer and the dimse protocol machine are supported. Service classes, like Storage, Query/Retrieve, Worklist, etc. are work-in-progress.
Handling of image data is also work in progress and can be found on the *pixeldata* branch.

## Headers
```c++
#include "libdicompp/all.hpp"
```
will include everything as the name implies. It is also possible to 
```c++
#include "libdicompp/dicomdata.hpp"
```
to not include network related code.

## Example - Reading and Writing Datasets to and from Streams
In the following example a dataset will be read from an inputstream, some attributes are modified and then saved to the stream.

```c++
// get a reference to the dictionaries 
dicom::data::dictionary::dictionaries& dict = get_default_dictionaries();

// declare a dicomfile instance and a dataset object.
// the dataset object will contain the data read from the stream.
// to write a set which exists in memory, set is filled with the data to be written
dataset::iod set;
dicom::filesystem::dicomfile file(set, dict);

// construct the stream and redirect the read data into the dicomfile instance
std::fstream infile("XA-MONO2-8-12x-catheter.dcm", std::ios::in | std::ios::binary);
outfile >> file;


// print some strings
auto patient_name = set[{0x0010, 0x0010}].value<VR::PN>();
auto series_descr = set[{0x0008, 0x103e}].value<VR::LO>();
std::cout << patient_name << " " << series_descr << "\n";

// do some calculations
auto rows = set[{0x0028, 0x0010}].value<VR::US>();
auto cols = set[{0x0028, 0x0011}].value<VR::US>();
auto bits = set[{0x0028, 0x0100}].value<VR::US>();
std::size_t size = rows * cols * bits;

// now write some random new data
// multivalued FD with 3 elements
set[{0x0014, 0x0010}] = value<VR::FD> {1.0, 0.0, -1.0};

// construct an output stream and write the dataset to it
std::fstream outfile("outfile.dcm", std::ios::out | std::ios::binary);
outfile << file;
```


## Example - Networking
The main.cpp file contains an example which will be walked through:

```c++
dicom::data::dictionary::dictionaries& dict = get_default_dictionaries();
```
will get a reference to the dictionaries necessary for the DICOM parser to get information about an attribute. 

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
   asio_tcp_server_acceptor infrstr_scp {1112};
   dicom::network::upperlayer::scp sc {infrstr_scp, dict};
   dicom::network::dimse::dimse_pm dpm {sc, ascdef, dict};
   dpm.run();
} catch (std::exception& ec) {
   std::cout << ec.what();
}
```
The first line creates the infrastructure component which is responsible for the actual network communication and does not contain any DICOM-related code. There is also an implementation which can read from a filestream which is used to facilitate unit testing.
The second line creates an upperlayer SCP which implements the upperlayer protoocol as defined by the DICOM standard. It uses the previously created infrastructure instance for communication. 
Then, an instance of the DIMSE PM is created, taking the upperlayer-object, the association definition, and the dictionary as arguments. The member function call run() instructs the dimse protocol machine to wait for and handle incoming connections.


## Dependencies
* boost 

## Supported Compilers
Tested on:

* gcc 5.4.0
* clang 5.0.1
Visual C++, or any other C++11 conforming compilers,  are not tested but should work as no platform-specific extensions are used

## Build Instructions
This project uses CMake for the build configuration. Invoking the ```cmake CMakeLists.txt``` from the command line or using the CMake GUI should generate a working Makefile / VS project file.
