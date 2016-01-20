project(dicom)
cmake_minimum_required(VERSION 2.8)

#set(CMAKE_CXX_COMPILER             "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -pthread -g -D BOOST_ASIO_HAS_STD_CHRONO")

add_definitions(-DBOOST_LOG_DYN_LINK)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS system log REQUIRED)

if(Boost_FOUND)
   include_directories(${Boost_INCLUDE_DIRS})
   include_directories(${YOUR_DIRECTORY})
   aux_source_directory(. SRC_LIST)
   aux_source_directory(./source SRC_LIST)
   aux_source_directory(./source/attributedata SRC_LIST)
   aux_source_directory(./source/upperlayer SRC_LIST)
   aux_source_directory(./source/dimse SRC_LIST)
   aux_source_directory(./source/dictionary SRC_LIST)
   add_executable(${PROJECT_NAME} ${SRC_LIST})
   target_link_libraries(dicom ${Boost_LIBRARIES})
endif()



