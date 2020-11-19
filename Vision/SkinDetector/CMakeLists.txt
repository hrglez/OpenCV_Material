cmake_minimum_required(VERSION 2.8.3)
project(skinDetector)

set(CMAKE_CXX_FLAGS "-std=c++11 -O3 ${CMAKE_CX_FlAGS}")

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} include)

add_executable(
skin
src/main.cpp
src/skin.cpp
)

target_link_libraries( skin ${OpenCV_LIBS} )
