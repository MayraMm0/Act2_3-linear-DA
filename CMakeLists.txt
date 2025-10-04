cmake_minimum_required(VERSION 4.0)
project(Act2_3_linear_DA CXX)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Act2_3_linear_DA
        main.cpp
        IP.cpp
        LogManager.cpp
        Register.cpp
)

