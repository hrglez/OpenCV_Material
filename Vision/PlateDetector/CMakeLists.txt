cmake_minimum_required(VERSION 2.8.3)
project(plate)

set(CMAKE_CXX_FLAGS "-std=c++11 -O3 ${CMAKE_CX_FlAGS}")

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} include)

add_executable(
plate
src/Main.cpp
src/DetectChars.cpp
src/DetectPlates.cpp
src/PossibleChar.cpp
src/PossiblePlate.cpp
src/Preprocess.cpp
)

target_link_libraries( plate ${OpenCV_LIBS} )
