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
CMAKE_SOURCE_DIR = /home/hrg/Documents/OpenCV/Vision/SegmentRGB

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hrg/Documents/OpenCV/Vision/SegmentRGB/build

# Include any dependencies generated for this target.
include CMakeFiles/segmentRGB.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/segmentRGB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/segmentRGB.dir/flags.make

CMakeFiles/segmentRGB.dir/src/main.cpp.o: CMakeFiles/segmentRGB.dir/flags.make
CMakeFiles/segmentRGB.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hrg/Documents/OpenCV/Vision/SegmentRGB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/segmentRGB.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/segmentRGB.dir/src/main.cpp.o -c /home/hrg/Documents/OpenCV/Vision/SegmentRGB/src/main.cpp

CMakeFiles/segmentRGB.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/segmentRGB.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hrg/Documents/OpenCV/Vision/SegmentRGB/src/main.cpp > CMakeFiles/segmentRGB.dir/src/main.cpp.i

CMakeFiles/segmentRGB.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/segmentRGB.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hrg/Documents/OpenCV/Vision/SegmentRGB/src/main.cpp -o CMakeFiles/segmentRGB.dir/src/main.cpp.s

CMakeFiles/segmentRGB.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/segmentRGB.dir/src/main.cpp.o.requires

CMakeFiles/segmentRGB.dir/src/main.cpp.o.provides: CMakeFiles/segmentRGB.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/segmentRGB.dir/build.make CMakeFiles/segmentRGB.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/segmentRGB.dir/src/main.cpp.o.provides

CMakeFiles/segmentRGB.dir/src/main.cpp.o.provides.build: CMakeFiles/segmentRGB.dir/src/main.cpp.o


CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.o: CMakeFiles/segmentRGB.dir/flags.make
CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.o: ../src/segmentRGB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hrg/Documents/OpenCV/Vision/SegmentRGB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.o -c /home/hrg/Documents/OpenCV/Vision/SegmentRGB/src/segmentRGB.cpp

CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hrg/Documents/OpenCV/Vision/SegmentRGB/src/segmentRGB.cpp > CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.i

CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hrg/Documents/OpenCV/Vision/SegmentRGB/src/segmentRGB.cpp -o CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.s

CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.o.requires:

.PHONY : CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.o.requires

CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.o.provides: CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.o.requires
	$(MAKE) -f CMakeFiles/segmentRGB.dir/build.make CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.o.provides.build
.PHONY : CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.o.provides

CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.o.provides.build: CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.o


# Object files for target segmentRGB
segmentRGB_OBJECTS = \
"CMakeFiles/segmentRGB.dir/src/main.cpp.o" \
"CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.o"

# External object files for target segmentRGB
segmentRGB_EXTERNAL_OBJECTS =

segmentRGB: CMakeFiles/segmentRGB.dir/src/main.cpp.o
segmentRGB: CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.o
segmentRGB: CMakeFiles/segmentRGB.dir/build.make
segmentRGB: /usr/local/lib/libopencv_dnn.so.4.0.1
segmentRGB: /usr/local/lib/libopencv_gapi.so.4.0.1
segmentRGB: /usr/local/lib/libopencv_ml.so.4.0.1
segmentRGB: /usr/local/lib/libopencv_objdetect.so.4.0.1
segmentRGB: /usr/local/lib/libopencv_photo.so.4.0.1
segmentRGB: /usr/local/lib/libopencv_stitching.so.4.0.1
segmentRGB: /usr/local/lib/libopencv_video.so.4.0.1
segmentRGB: /usr/local/lib/libopencv_calib3d.so.4.0.1
segmentRGB: /usr/local/lib/libopencv_features2d.so.4.0.1
segmentRGB: /usr/local/lib/libopencv_flann.so.4.0.1
segmentRGB: /usr/local/lib/libopencv_highgui.so.4.0.1
segmentRGB: /usr/local/lib/libopencv_videoio.so.4.0.1
segmentRGB: /usr/local/lib/libopencv_imgcodecs.so.4.0.1
segmentRGB: /usr/local/lib/libopencv_imgproc.so.4.0.1
segmentRGB: /usr/local/lib/libopencv_core.so.4.0.1
segmentRGB: CMakeFiles/segmentRGB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hrg/Documents/OpenCV/Vision/SegmentRGB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable segmentRGB"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/segmentRGB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/segmentRGB.dir/build: segmentRGB

.PHONY : CMakeFiles/segmentRGB.dir/build

CMakeFiles/segmentRGB.dir/requires: CMakeFiles/segmentRGB.dir/src/main.cpp.o.requires
CMakeFiles/segmentRGB.dir/requires: CMakeFiles/segmentRGB.dir/src/segmentRGB.cpp.o.requires

.PHONY : CMakeFiles/segmentRGB.dir/requires

CMakeFiles/segmentRGB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/segmentRGB.dir/cmake_clean.cmake
.PHONY : CMakeFiles/segmentRGB.dir/clean

CMakeFiles/segmentRGB.dir/depend:
	cd /home/hrg/Documents/OpenCV/Vision/SegmentRGB/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hrg/Documents/OpenCV/Vision/SegmentRGB /home/hrg/Documents/OpenCV/Vision/SegmentRGB /home/hrg/Documents/OpenCV/Vision/SegmentRGB/build /home/hrg/Documents/OpenCV/Vision/SegmentRGB/build /home/hrg/Documents/OpenCV/Vision/SegmentRGB/build/CMakeFiles/segmentRGB.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/segmentRGB.dir/depend

