cmake_minimum_required(VERSION 3.10)
project(PiController C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Wextra")

include_directories(${CMAKE_SOURCE_DIR})

add_library(PiController 
    PiController.c)