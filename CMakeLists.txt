project(libdicom)
cmake_minimum_required(VERSION 2.8)

#set(CMAKE_CXX_COMPILER             "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Wno-missing-braces -pthread -g -D BOOST_ASIO_HAS_STD_CHRONO -lboost_thread-mt")


add_definitions(-DBOOST_LOG_DYN_LINK)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS system log REQUIRED)


if(Boost_FOUND)
   include_directories(${Boost_INCLUDE_DIRS})
   include_directories(${CMAKE_SOURCE_DIR}/source)
   aux_source_directory(. SRC_LIST)
   aux_source_directory(./source/data/attribute SRC_LIST)
   aux_source_directory(./source/data/dictionary SRC_LIST)
   aux_source_directory(./source/data/dataset SRC_LIST)
   aux_source_directory(./source/filesystem SRC_LIST)
   aux_source_directory(./source/network/upperlayer SRC_LIST)
   aux_source_directory(./source/network/dimse SRC_LIST)
   aux_source_directory(./source/network SRC_LIST)
   aux_source_directory(./source/serviceclass SRC_LIST)
   aux_source_directory(./source/util SRC_LIST)
   add_library(libdicom ${SRC_LIST})
   target_link_libraries(libdicom ${Boost_LIBRARIES})
endif()

project(dicom)

if(Boost_FOUND)
    include_directories(${CMAKE_SOURCE_DIR}/source)
    aux_source_directory(./source SRC_EXEC_LIST)
    add_executable(${PROJECT_NAME} ${SRC_EXEC_LIST})
    target_link_libraries(dicom libdicom ${Boost_LIBRARIES})
endif()


project(dicom_test)

# Prepare "Catch" library for other executables
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})


# Make test executable
set(TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tests/testsmain.cpp)
file(GLOB_RECURSE TEST_SOURCES tests/dataset.cpp tests/types.cpp tests/testsmain.cpp tests/attribute.cpp)
add_executable(dicom_tests ${TEST_SOURCES})
target_link_libraries(dicom_tests Catch libdicom ${Boost_LIBRARIES})

add_test(NAME tests COMMAND dicom_tests)
