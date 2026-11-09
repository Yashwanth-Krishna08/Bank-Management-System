
cmake_minimum_required(VERSION 3.16)

project(BankManagementSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(BankManagementSystem
    src/main.cpp
    src/Account.cpp
    src/Transaction.cpp
    src/Bank.cpp
)

target_include_directories(BankManagementSystem
    PRIVATE include
)
