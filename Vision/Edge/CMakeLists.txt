cmake_minimum_required(VERSION 2.8.3)
project(Edge)

set(CMAKE_CXX_FLAGS "-std=c++11 -O3 ${CMAKE_CX_FlAGS}")

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} include)

add_executable(
edge
src/main.cpp
src/edge.cpp
)

target_link_libraries( edge ${OpenCV_LIBS} )
