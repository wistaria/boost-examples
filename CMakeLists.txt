cmake_minimum_required(VERSION 3.18)
include(cmake/prefix.cmake)
project(boost-examples CXX)
include(cmake/postfix.cmake)

include_directories(${PROJECT_SOURCE_DIR})

find_package(Boost COMPONENTS date_time program_options REQUIRED NO_MODULE)
if(Boost_FOUND)
  message(STATUS "Found Boost: ${Boost_VERSION_STRING}")
endif(Boost_FOUND)

add_subdirectory(date_time)
add_subdirectory(exp_sinh)
add_subdirectory(program_options)
add_subdirectory(tanh_sinh)
