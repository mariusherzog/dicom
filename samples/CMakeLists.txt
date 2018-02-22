#include_directories(${CMAKE_SOURCE_DIR}/source)
#aux_source_directory(./source SRC_EXEC_LIST)

#add_definitions(-DBOOST_LOG_DYN_LINK)
#set(Boost_USE_STATIC_LIBS OFF)
#set(Boost_USE_MULTITHREADED ON)
#set(Boost_USE_STATIC_RUNTIME OFF)
#find_package(Boost COMPONENTS system log REQUIRED)


if(Boost_FOUND)
   include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(dicom main.cpp)
target_link_libraries(dicom libdicompp ${Boost_LIBRARIES})
