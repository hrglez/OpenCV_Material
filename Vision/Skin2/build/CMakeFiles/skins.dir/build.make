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
CMAKE_SOURCE_DIR = /home/hrg/Documents/OpenCV/Vision/Skin2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hrg/Documents/OpenCV/Vision/Skin2/build

# Include any dependencies generated for this target.
include CMakeFiles/skins.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/skins.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/skins.dir/flags.make

CMakeFiles/skins.dir/src/main.cpp.o: CMakeFiles/skins.dir/flags.make
CMakeFiles/skins.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hrg/Documents/OpenCV/Vision/Skin2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/skins.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/skins.dir/src/main.cpp.o -c /home/hrg/Documents/OpenCV/Vision/Skin2/src/main.cpp

CMakeFiles/skins.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/skins.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hrg/Documents/OpenCV/Vision/Skin2/src/main.cpp > CMakeFiles/skins.dir/src/main.cpp.i

CMakeFiles/skins.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/skins.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hrg/Documents/OpenCV/Vision/Skin2/src/main.cpp -o CMakeFiles/skins.dir/src/main.cpp.s

CMakeFiles/skins.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/skins.dir/src/main.cpp.o.requires

CMakeFiles/skins.dir/src/main.cpp.o.provides: CMakeFiles/skins.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/skins.dir/build.make CMakeFiles/skins.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/skins.dir/src/main.cpp.o.provides

CMakeFiles/skins.dir/src/main.cpp.o.provides.build: CMakeFiles/skins.dir/src/main.cpp.o


# Object files for target skins
skins_OBJECTS = \
"CMakeFiles/skins.dir/src/main.cpp.o"

# External object files for target skins
skins_EXTERNAL_OBJECTS =

skins: CMakeFiles/skins.dir/src/main.cpp.o
skins: CMakeFiles/skins.dir/build.make
skins: /usr/local/lib/libopencv_dnn.so.4.0.1
skins: /usr/local/lib/libopencv_gapi.so.4.0.1
skins: /usr/local/lib/libopencv_ml.so.4.0.1
skins: /usr/local/lib/libopencv_objdetect.so.4.0.1
skins: /usr/local/lib/libopencv_photo.so.4.0.1
skins: /usr/local/lib/libopencv_stitching.so.4.0.1
skins: /usr/local/lib/libopencv_video.so.4.0.1
skins: /usr/local/lib/libopencv_calib3d.so.4.0.1
skins: /usr/local/lib/libopencv_features2d.so.4.0.1
skins: /usr/local/lib/libopencv_flann.so.4.0.1
skins: /usr/local/lib/libopencv_highgui.so.4.0.1
skins: /usr/local/lib/libopencv_videoio.so.4.0.1
skins: /usr/local/lib/libopencv_imgcodecs.so.4.0.1
skins: /usr/local/lib/libopencv_imgproc.so.4.0.1
skins: /usr/local/lib/libopencv_core.so.4.0.1
skins: CMakeFiles/skins.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hrg/Documents/OpenCV/Vision/Skin2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable skins"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/skins.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/skins.dir/build: skins

.PHONY : CMakeFiles/skins.dir/build

CMakeFiles/skins.dir/requires: CMakeFiles/skins.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/skins.dir/requires

CMakeFiles/skins.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/skins.dir/cmake_clean.cmake
.PHONY : CMakeFiles/skins.dir/clean

CMakeFiles/skins.dir/depend:
	cd /home/hrg/Documents/OpenCV/Vision/Skin2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hrg/Documents/OpenCV/Vision/Skin2 /home/hrg/Documents/OpenCV/Vision/Skin2 /home/hrg/Documents/OpenCV/Vision/Skin2/build /home/hrg/Documents/OpenCV/Vision/Skin2/build /home/hrg/Documents/OpenCV/Vision/Skin2/build/CMakeFiles/skins.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/skins.dir/depend

