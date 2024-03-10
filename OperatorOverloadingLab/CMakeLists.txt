cmake_minimum_required(VERSION 3.26)

project(OperatorOverloadingLab)
project(OperatorOver)

set(CMAKE_CXX_STANDARD 20)

add_executable(BANK TestBanking.cpp Bank.h Bank.cpp Customer.h Customer.cpp Account.h Account.cpp)
add_executable(OperatorOver TestCustomer.cpp Bank.h Bank.cpp Customer.h Customer.cpp Account.h Account.cpp)