cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(boost-examples NONE)

include(${PROJECT_SOURCE_DIR}/config/core.cmake)

include_directories(${PROJECT_SOURCE_DIR})

# Boost
find_package(Boost REQUIRED)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif(Boost_FOUND)

add_subdirectory(exp_sinh)
add_subdirectory(tanh_sinh)
