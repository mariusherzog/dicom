if(Boost_FOUND)
   include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(dicom main.cpp)
target_compile_definitions(dicom PUBLIC BOOST_ASIO_HAS_STD_CHRONO)
target_compile_features(dicom PUBLIC cxx_std_11)
target_link_libraries(dicom libdicompp ${Boost_LIBRARIES})


# Copy files necessary at runtime
configure_file(${CMAKE_SOURCE_DIR}/datadictionary.csv
    ${CMAKE_CURRENT_BINARY_DIR}/datadictionary.csv COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/commanddictionary.csv
    ${CMAKE_CURRENT_BINARY_DIR}/commanddictionary.csv COPYONLY)

