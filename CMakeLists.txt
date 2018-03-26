project(dicom CXX)
cmake_minimum_required(VERSION 3.0)

add_definitions(-DBOOST_LOG_DYN_LINK)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS system log REQUIRED)


add_subdirectory(${CMAKE_SOURCE_DIR}/source)
add_subdirectory(${CMAKE_SOURCE_DIR}/samples)
add_subdirectory(${CMAKE_SOURCE_DIR}/tests)
