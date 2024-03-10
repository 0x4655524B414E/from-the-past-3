cmake_minimum_required(VERSION 3.26)

project(Interval)

set(CMAKE_CXX_STANDARD 20)

add_executable(interval TestInt.cpp Interval.h Interval.cpp)