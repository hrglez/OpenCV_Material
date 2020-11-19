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
CMAKE_SOURCE_DIR = /home/hrg/Documents/OpenCV/Robotica/Tareas/Collage

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hrg/Documents/OpenCV/Robotica/Tareas/Collage/build

# Include any dependencies generated for this target.
include CMakeFiles/collage.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/collage.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/collage.dir/flags.make

CMakeFiles/collage.dir/src/collage.cpp.o: CMakeFiles/collage.dir/flags.make
CMakeFiles/collage.dir/src/collage.cpp.o: ../src/collage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hrg/Documents/OpenCV/Robotica/Tareas/Collage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/collage.dir/src/collage.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/collage.dir/src/collage.cpp.o -c /home/hrg/Documents/OpenCV/Robotica/Tareas/Collage/src/collage.cpp

CMakeFiles/collage.dir/src/collage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/collage.dir/src/collage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hrg/Documents/OpenCV/Robotica/Tareas/Collage/src/collage.cpp > CMakeFiles/collage.dir/src/collage.cpp.i

CMakeFiles/collage.dir/src/collage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/collage.dir/src/collage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hrg/Documents/OpenCV/Robotica/Tareas/Collage/src/collage.cpp -o CMakeFiles/collage.dir/src/collage.cpp.s

CMakeFiles/collage.dir/src/collage.cpp.o.requires:

.PHONY : CMakeFiles/collage.dir/src/collage.cpp.o.requires

CMakeFiles/collage.dir/src/collage.cpp.o.provides: CMakeFiles/collage.dir/src/collage.cpp.o.requires
	$(MAKE) -f CMakeFiles/collage.dir/build.make CMakeFiles/collage.dir/src/collage.cpp.o.provides.build
.PHONY : CMakeFiles/collage.dir/src/collage.cpp.o.provides

CMakeFiles/collage.dir/src/collage.cpp.o.provides.build: CMakeFiles/collage.dir/src/collage.cpp.o


CMakeFiles/collage.dir/src/main.cpp.o: CMakeFiles/collage.dir/flags.make
CMakeFiles/collage.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hrg/Documents/OpenCV/Robotica/Tareas/Collage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/collage.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/collage.dir/src/main.cpp.o -c /home/hrg/Documents/OpenCV/Robotica/Tareas/Collage/src/main.cpp

CMakeFiles/collage.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/collage.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hrg/Documents/OpenCV/Robotica/Tareas/Collage/src/main.cpp > CMakeFiles/collage.dir/src/main.cpp.i

CMakeFiles/collage.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/collage.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hrg/Documents/OpenCV/Robotica/Tareas/Collage/src/main.cpp -o CMakeFiles/collage.dir/src/main.cpp.s

CMakeFiles/collage.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/collage.dir/src/main.cpp.o.requires

CMakeFiles/collage.dir/src/main.cpp.o.provides: CMakeFiles/collage.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/collage.dir/build.make CMakeFiles/collage.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/collage.dir/src/main.cpp.o.provides

CMakeFiles/collage.dir/src/main.cpp.o.provides.build: CMakeFiles/collage.dir/src/main.cpp.o


# Object files for target collage
collage_OBJECTS = \
"CMakeFiles/collage.dir/src/collage.cpp.o" \
"CMakeFiles/collage.dir/src/main.cpp.o"

# External object files for target collage
collage_EXTERNAL_OBJECTS =

collage: CMakeFiles/collage.dir/src/collage.cpp.o
collage: CMakeFiles/collage.dir/src/main.cpp.o
collage: CMakeFiles/collage.dir/build.make
collage: /usr/local/lib/libopencv_gapi.so.4.0.1
collage: /usr/local/lib/libopencv_stitching.so.4.0.1
collage: /usr/local/lib/libopencv_aruco.so.4.0.1
collage: /usr/local/lib/libopencv_bgsegm.so.4.0.1
collage: /usr/local/lib/libopencv_bioinspired.so.4.0.1
collage: /usr/local/lib/libopencv_ccalib.so.4.0.1
collage: /usr/local/lib/libopencv_dnn_objdetect.so.4.0.1
collage: /usr/local/lib/libopencv_dnn_superres.so.4.0.1
collage: /usr/local/lib/libopencv_dpm.so.4.0.1
collage: /usr/local/lib/libopencv_face.so.4.0.1
collage: /usr/local/lib/libopencv_freetype.so.4.0.1
collage: /usr/local/lib/libopencv_fuzzy.so.4.0.1
collage: /usr/local/lib/libopencv_hdf.so.4.0.1
collage: /usr/local/lib/libopencv_hfs.so.4.0.1
collage: /usr/local/lib/libopencv_img_hash.so.4.0.1
collage: /usr/local/lib/libopencv_line_descriptor.so.4.0.1
collage: /usr/local/lib/libopencv_quality.so.4.0.1
collage: /usr/local/lib/libopencv_reg.so.4.0.1
collage: /usr/local/lib/libopencv_rgbd.so.4.0.1
collage: /usr/local/lib/libopencv_saliency.so.4.0.1
collage: /usr/local/lib/libopencv_stereo.so.4.0.1
collage: /usr/local/lib/libopencv_structured_light.so.4.0.1
collage: /usr/local/lib/libopencv_superres.so.4.0.1
collage: /usr/local/lib/libopencv_surface_matching.so.4.0.1
collage: /usr/local/lib/libopencv_tracking.so.4.0.1
collage: /usr/local/lib/libopencv_videostab.so.4.0.1
collage: /usr/local/lib/libopencv_xfeatures2d.so.4.0.1
collage: /usr/local/lib/libopencv_xobjdetect.so.4.0.1
collage: /usr/local/lib/libopencv_xphoto.so.4.0.1
collage: /usr/local/lib/libopencv_shape.so.4.0.1
collage: /usr/local/lib/libopencv_datasets.so.4.0.1
collage: /usr/local/lib/libopencv_plot.so.4.0.1
collage: /usr/local/lib/libopencv_text.so.4.0.1
collage: /usr/local/lib/libopencv_dnn.so.4.0.1
collage: /usr/local/lib/libopencv_ml.so.4.0.1
collage: /usr/local/lib/libopencv_phase_unwrapping.so.4.0.1
collage: /usr/local/lib/libopencv_optflow.so.4.0.1
collage: /usr/local/lib/libopencv_ximgproc.so.4.0.1
collage: /usr/local/lib/libopencv_video.so.4.0.1
collage: /usr/local/lib/libopencv_objdetect.so.4.0.1
collage: /usr/local/lib/libopencv_calib3d.so.4.0.1
collage: /usr/local/lib/libopencv_features2d.so.4.0.1
collage: /usr/local/lib/libopencv_flann.so.4.0.1
collage: /usr/local/lib/libopencv_highgui.so.4.0.1
collage: /usr/local/lib/libopencv_videoio.so.4.0.1
collage: /usr/local/lib/libopencv_imgcodecs.so.4.0.1
collage: /usr/local/lib/libopencv_photo.so.4.0.1
collage: /usr/local/lib/libopencv_imgproc.so.4.0.1
collage: /usr/local/lib/libopencv_core.so.4.0.1
collage: CMakeFiles/collage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hrg/Documents/OpenCV/Robotica/Tareas/Collage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable collage"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/collage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/collage.dir/build: collage

.PHONY : CMakeFiles/collage.dir/build

CMakeFiles/collage.dir/requires: CMakeFiles/collage.dir/src/collage.cpp.o.requires
CMakeFiles/collage.dir/requires: CMakeFiles/collage.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/collage.dir/requires

CMakeFiles/collage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/collage.dir/cmake_clean.cmake
.PHONY : CMakeFiles/collage.dir/clean

CMakeFiles/collage.dir/depend:
	cd /home/hrg/Documents/OpenCV/Robotica/Tareas/Collage/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hrg/Documents/OpenCV/Robotica/Tareas/Collage /home/hrg/Documents/OpenCV/Robotica/Tareas/Collage /home/hrg/Documents/OpenCV/Robotica/Tareas/Collage/build /home/hrg/Documents/OpenCV/Robotica/Tareas/Collage/build /home/hrg/Documents/OpenCV/Robotica/Tareas/Collage/build/CMakeFiles/collage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/collage.dir/depend
