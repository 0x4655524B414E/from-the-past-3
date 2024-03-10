cmake_minimum_required(VERSION 3.26)

project(Operator_Overloading)
project(Operator_Overloading2)

set(CMAKE_CXX_STANDARD 20)

add_executable(FRACTION main.cpp Fraction.h Fraction.cpp)
add_executable(FRACTION2 main2.cpp Fraction.h Fraction.cpp)