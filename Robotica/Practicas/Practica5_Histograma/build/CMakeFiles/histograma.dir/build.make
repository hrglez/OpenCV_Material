# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hrg/Documents/Robotica/Practicas/Practica5_Histograma

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hrg/Documents/Robotica/Practicas/Practica5_Histograma/build

# Include any dependencies generated for this target.
include CMakeFiles/histograma.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/histograma.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/histograma.dir/flags.make

CMakeFiles/histograma.dir/src/main.cpp.o: CMakeFiles/histograma.dir/flags.make
CMakeFiles/histograma.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hrg/Documents/Robotica/Practicas/Practica5_Histograma/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/histograma.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/histograma.dir/src/main.cpp.o -c /home/hrg/Documents/Robotica/Practicas/Practica5_Histograma/src/main.cpp

CMakeFiles/histograma.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/histograma.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hrg/Documents/Robotica/Practicas/Practica5_Histograma/src/main.cpp > CMakeFiles/histograma.dir/src/main.cpp.i

CMakeFiles/histograma.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/histograma.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hrg/Documents/Robotica/Practicas/Practica5_Histograma/src/main.cpp -o CMakeFiles/histograma.dir/src/main.cpp.s

CMakeFiles/histograma.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/histograma.dir/src/main.cpp.o.requires

CMakeFiles/histograma.dir/src/main.cpp.o.provides: CMakeFiles/histograma.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/histograma.dir/build.make CMakeFiles/histograma.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/histograma.dir/src/main.cpp.o.provides

CMakeFiles/histograma.dir/src/main.cpp.o.provides.build: CMakeFiles/histograma.dir/src/main.cpp.o


# Object files for target histograma
histograma_OBJECTS = \
"CMakeFiles/histograma.dir/src/main.cpp.o"

# External object files for target histograma
histograma_EXTERNAL_OBJECTS =

histograma: CMakeFiles/histograma.dir/src/main.cpp.o
histograma: CMakeFiles/histograma.dir/build.make
histograma: /usr/local/lib/libopencv_dnn.so.4.0.1
histograma: /usr/local/lib/libopencv_gapi.so.4.0.1
histograma: /usr/local/lib/libopencv_ml.so.4.0.1
histograma: /usr/local/lib/libopencv_objdetect.so.4.0.1
histograma: /usr/local/lib/libopencv_photo.so.4.0.1
histograma: /usr/local/lib/libopencv_stitching.so.4.0.1
histograma: /usr/local/lib/libopencv_video.so.4.0.1
histograma: /usr/local/lib/libopencv_calib3d.so.4.0.1
histograma: /usr/local/lib/libopencv_features2d.so.4.0.1
histograma: /usr/local/lib/libopencv_flann.so.4.0.1
histograma: /usr/local/lib/libopencv_highgui.so.4.0.1
histograma: /usr/local/lib/libopencv_videoio.so.4.0.1
histograma: /usr/local/lib/libopencv_imgcodecs.so.4.0.1
histograma: /usr/local/lib/libopencv_imgproc.so.4.0.1
histograma: /usr/local/lib/libopencv_core.so.4.0.1
histograma: CMakeFiles/histograma.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hrg/Documents/Robotica/Practicas/Practica5_Histograma/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable histograma"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/histograma.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/histograma.dir/build: histograma

.PHONY : CMakeFiles/histograma.dir/build

CMakeFiles/histograma.dir/requires: CMakeFiles/histograma.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/histograma.dir/requires

CMakeFiles/histograma.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/histograma.dir/cmake_clean.cmake
.PHONY : CMakeFiles/histograma.dir/clean

CMakeFiles/histograma.dir/depend:
	cd /home/hrg/Documents/Robotica/Practicas/Practica5_Histograma/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hrg/Documents/Robotica/Practicas/Practica5_Histograma /home/hrg/Documents/Robotica/Practicas/Practica5_Histograma /home/hrg/Documents/Robotica/Practicas/Practica5_Histograma/build /home/hrg/Documents/Robotica/Practicas/Practica5_Histograma/build /home/hrg/Documents/Robotica/Practicas/Practica5_Histograma/build/CMakeFiles/histograma.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/histograma.dir/depend
