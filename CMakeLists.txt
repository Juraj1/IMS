cmake_minimum_required(VERSION 2.8)
project(drubezarna)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp chicken.cpp chicken.h factory.cpp factory.h debug.h)
add_executable(drubezarna ${SOURCE_FILES})
