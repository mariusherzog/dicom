project(dicom_tests)

set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/source)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-missing-braces -Wextra")

set(TEST_SOURCES ${CMAKE_SOURCE_DIR}/testsmain.cpp)
file(GLOB_RECURSE TEST_SOURCES dataset.cpp types.cpp testsmain.cpp attribute.cpp dimse.cpp upperlayer_connection.cpp stubs/upperlayer_communication_stub.hpp stubs/infrastructure_connection_stub.hpp upperlayer_manager.cpp stubs/upperlayer_server_acceptor_stub.hpp stubs/upperlayer_client_acceptor_stub.hpp dictionaries.cpp transfer_processor_attributes.cpp transfer_processor_dataset.cpp encapsulated_data.cpp)
message(${TEST_SOURCES})
add_executable(dicom_tests ${TEST_SOURCES})
target_link_libraries(dicom_tests  Catch libdicompp ${Boost_LIBRARIES})

# Copy test data, like prepared serialized sets etc.
file(COPY data/. DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME tests COMMAND dicom_tests)
