cmake_minimum_required(VERSION 3.26)

project(mockup2)

set(CMAKE_CXX_STANDARD 20)

add_executable(RUN TestInt.cpp Interval.h Interval.cpp)