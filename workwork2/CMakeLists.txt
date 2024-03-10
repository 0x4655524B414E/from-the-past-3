cmake_minimum_required(VERSION 3.26)

project(workwork2)

set(CMAKE_CXX_STANDARD 20)

add_executable(RUN TestBanking.cpp Account.h Account.cpp Customer.h Customer.cpp Bank.h Bank.cpp SavingAccount.h SavingAccount.cpp CheckingAccount.h CheckingAccount.cpp)