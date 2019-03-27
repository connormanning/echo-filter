cmake_minimum_required(VERSION 2.8.8)

project(SamplePlugin)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR
    ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    add_definitions(${CMAKE_CXX_FLAGS} "-std=c++11")
    add_definitions(${CMAKE_CXX_FLAGS} "-Wno-deprecated-declarations")
    add_definitions(${CMAKE_CXX_FLAGS} "-Wall")
    add_definitions(${CMAKE_CXX_FLAGS} "-pedantic")
    add_definitions(${CMAKE_CXX_FLAGS} "-fexceptions")
    add_definitions(${CMAKE_CXX_FLAGS} "-fPIC")
endif()

find_package(PDAL 1.8 REQUIRED CONFIG)

add_library(pdal_plugin_filter_echo SHARED EchoFilter.cpp)
target_link_libraries(pdal_plugin_filter_echo PRIVATE ${PDAL_LIBRARIES})
target_include_directories(pdal_plugin_filter_echo PRIVATE ${PDAL_INCLUDE_DIRS})
install(TARGETS pdal_plugin_filter_echo DESTINATION lib)

