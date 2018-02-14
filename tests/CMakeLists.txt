set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/source)


set(TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tests/testsmain.cpp)
file(GLOB_RECURSE TEST_SOURCES tests/dataset.cpp tests/types.cpp tests/testsmain.cpp tests/attribute.cpp tests/dimse.cpp tests/upperlayer_connection.cpp tests/stubs/upperlayer_communication_stub.hpp tests/stubs/infrastructure_connection_stub.hpp tests/upperlayer_manager.cpp tests/stubs/upperlayer_server_acceptor_stub.hpp tests/stubs/upperlayer_client_acceptor_stub.hpp tests/dictionaries.cpp tests/transfer_processor_attributes.cpp tests/transfer_processor_dataset.cpp tests/encapsulated_data.cpp)
add_executable(dicom_tests ${TEST_SOURCES})
target_link_libraries(dicom_tests  Catch libdicompp ${Boost_LIBRARIES})

# Copy test data, like prepared serialized sets etc.
file(COPY ${CMAKE_SOURCE_DIR}/tests/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME tests COMMAND dicom_tests)
