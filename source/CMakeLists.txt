#set(CMAKE_CXX_COMPILER             "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Wno-missing-braces -pthread -g  -D BOOST_ASIO_HAS_STD_CHRONO -lboost_thread-mt")


#add_definitions(-DBOOST_LOG_DYN_LINK)
#set(Boost_USE_STATIC_LIBS OFF)
#set(Boost_USE_MULTITHREADED ON)
#set(Boost_USE_STATIC_RUNTIME OFF)
#find_package(Boost COMPONENTS system log REQUIRED)


if(Boost_FOUND)
   #include_directories(${Boost_INCLUDE_DIRS})
   #include_directories(${CMAKE_SOURCE_DIR}/source)
   aux_source_directory(. SRC_LIST)
   aux_source_directory(./data/attribute SRC_LIST)
   aux_source_directory(./data/dictionary SRC_LIST)
   aux_source_directory(./data/dataset SRC_LIST)
   aux_source_directory(./filesystem SRC_LIST)
   aux_source_directory(./network/upperlayer SRC_LIST)
   aux_source_directory(./network/dimse SRC_LIST)
   aux_source_directory(./network SRC_LIST)
   aux_source_directory(./pixeldata SRC_LIST)
   aux_source_directory(./pixeldata/frame_extractors SRC_LIST)
   aux_source_directory(./serviceclass SRC_LIST)
   aux_source_directory(./infrastructure SRC_LIST)
   aux_source_directory(./util SRC_LIST)
   add_library(libdicompp ${SRC_LIST})
   message(${CMAKE_CURRENT_SOURCE_DIR})
   target_include_directories(libdicompp
       PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
   target_include_directories(libdicompp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} PUBLIC ${Boost_INCLUDE_DIRS})
   target_link_libraries(libdicompp ${Boost_LIBRARIES})
endif()

target_link_libraries(libdicompp ${JPEG_LIBRARIES})
target_link_libraries(libdicompp openjp2)

# Copy files necessary at runtime
configure_file(${CMAKE_SOURCE_DIR}/datadictionary.csv
    ${CMAKE_BINARY_DIR}/datadictionary.csv COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/commanddictionary.csv
    ${CMAKE_BINARY_DIR}/commanddictionary.csv COPYONLY)

