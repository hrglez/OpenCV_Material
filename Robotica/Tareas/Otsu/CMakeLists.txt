cmake_minimum_required(VERSION 2.8.3)
project(Otsu)

set(CMAKE_CXX_FLAGS "-std=c++11 -O3 ${CMAKE_CX_FlAGS}")

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} include )

add_executable(
otsu
src/otsu.cpp
src/main.cpp
)

target_link_libraries( otsu ${OpenCV_LIBS} )
