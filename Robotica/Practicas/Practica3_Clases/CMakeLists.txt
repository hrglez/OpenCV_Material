cmake_minimum_required(VERSION 2.8.3)
project(sort)

set(CMAKE_CXX_FLAGS "-std=c++11 -O3 ${CMAKE_CX_FlAGS}")

INCLUDE_DIRECTORIES(
include
)

add_executable(
class_exe
src/main.cpp
)

add_executable(
point
src/point.cpp
src/main_p.cpp
)
