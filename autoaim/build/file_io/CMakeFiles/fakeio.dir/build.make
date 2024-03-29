# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/file_io

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/file_io

# Include any dependencies generated for this target.
include CMakeFiles/fakeio.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/fakeio.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/fakeio.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fakeio.dir/flags.make

CMakeFiles/fakeio.dir/src/fake_fileio.cpp.o: CMakeFiles/fakeio.dir/flags.make
CMakeFiles/fakeio.dir/src/fake_fileio.cpp.o: /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/file_io/src/fake_fileio.cpp
CMakeFiles/fakeio.dir/src/fake_fileio.cpp.o: CMakeFiles/fakeio.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/file_io/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fakeio.dir/src/fake_fileio.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/fakeio.dir/src/fake_fileio.cpp.o -MF CMakeFiles/fakeio.dir/src/fake_fileio.cpp.o.d -o CMakeFiles/fakeio.dir/src/fake_fileio.cpp.o -c /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/file_io/src/fake_fileio.cpp

CMakeFiles/fakeio.dir/src/fake_fileio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fakeio.dir/src/fake_fileio.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/file_io/src/fake_fileio.cpp > CMakeFiles/fakeio.dir/src/fake_fileio.cpp.i

CMakeFiles/fakeio.dir/src/fake_fileio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fakeio.dir/src/fake_fileio.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/file_io/src/fake_fileio.cpp -o CMakeFiles/fakeio.dir/src/fake_fileio.cpp.s

# Object files for target fakeio
fakeio_OBJECTS = \
"CMakeFiles/fakeio.dir/src/fake_fileio.cpp.o"

# External object files for target fakeio
fakeio_EXTERNAL_OBJECTS =

libfakeio.so: CMakeFiles/fakeio.dir/src/fake_fileio.cpp.o
libfakeio.so: CMakeFiles/fakeio.dir/build.make
libfakeio.so: /opt/ros/humble/lib/libcomponent_manager.so
libfakeio.so: /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/install/my_interfaces/lib/libmy_interfaces__rosidl_typesupport_fastrtps_c.so
libfakeio.so: /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/install/my_interfaces/lib/libmy_interfaces__rosidl_typesupport_fastrtps_cpp.so
libfakeio.so: /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/install/my_interfaces/lib/libmy_interfaces__rosidl_typesupport_introspection_c.so
libfakeio.so: /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/install/my_interfaces/lib/libmy_interfaces__rosidl_typesupport_introspection_cpp.so
libfakeio.so: /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/install/my_interfaces/lib/libmy_interfaces__rosidl_typesupport_cpp.so
libfakeio.so: /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/install/my_interfaces/lib/libmy_interfaces__rosidl_generator_py.so
libfakeio.so: /opt/ros/humble/lib/x86_64-linux-gnu/libimage_transport.so
libfakeio.so: /opt/ros/humble/lib/libcamera_info_manager.so
libfakeio.so: /opt/ros/humble/lib/libcv_bridge.so
libfakeio.so: minipc_comm/libminipc_comm.a
libfakeio.so: /usr/local/lib/libopencv_highgui.so.4.7.0
libfakeio.so: /usr/local/lib/libopencv_ml.so.4.7.0
libfakeio.so: /usr/local/lib/libopencv_objdetect.so.4.7.0
libfakeio.so: /usr/local/lib/libopencv_photo.so.4.7.0
libfakeio.so: /usr/local/lib/libopencv_stitching.so.4.7.0
libfakeio.so: /usr/local/lib/libopencv_video.so.4.7.0
libfakeio.so: /usr/local/lib/libopencv_videoio.so.4.7.0
libfakeio.so: /opt/ros/humble/lib/libclass_loader.so
libfakeio.so: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.1.0
libfakeio.so: /opt/ros/humble/lib/libcomposition_interfaces__rosidl_typesupport_fastrtps_c.so
libfakeio.so: /opt/ros/humble/lib/libcomposition_interfaces__rosidl_typesupport_introspection_c.so
libfakeio.so: /opt/ros/humble/lib/libcomposition_interfaces__rosidl_typesupport_fastrtps_cpp.so
libfakeio.so: /opt/ros/humble/lib/libcomposition_interfaces__rosidl_typesupport_introspection_cpp.so
libfakeio.so: /opt/ros/humble/lib/libcomposition_interfaces__rosidl_typesupport_cpp.so
libfakeio.so: /opt/ros/humble/lib/libcomposition_interfaces__rosidl_generator_py.so
libfakeio.so: /opt/ros/humble/lib/libcomposition_interfaces__rosidl_typesupport_c.so
libfakeio.so: /opt/ros/humble/lib/libcomposition_interfaces__rosidl_generator_c.so
libfakeio.so: /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/install/my_interfaces/lib/libmy_interfaces__rosidl_typesupport_c.so
libfakeio.so: /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/install/my_interfaces/lib/libmy_interfaces__rosidl_generator_c.so
libfakeio.so: /opt/ros/humble/lib/libmessage_filters.so
libfakeio.so: /opt/ros/humble/lib/librclcpp.so
libfakeio.so: /opt/ros/humble/lib/liblibstatistics_collector.so
libfakeio.so: /opt/ros/humble/lib/librcl.so
libfakeio.so: /opt/ros/humble/lib/librmw_implementation.so
libfakeio.so: /opt/ros/humble/lib/libament_index_cpp.so
libfakeio.so: /opt/ros/humble/lib/librcl_logging_spdlog.so
libfakeio.so: /opt/ros/humble/lib/librcl_logging_interface.so
libfakeio.so: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_fastrtps_c.so
libfakeio.so: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_introspection_c.so
libfakeio.so: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_fastrtps_cpp.so
libfakeio.so: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_introspection_cpp.so
libfakeio.so: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_cpp.so
libfakeio.so: /opt/ros/humble/lib/librcl_interfaces__rosidl_generator_py.so
libfakeio.so: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_c.so
libfakeio.so: /opt/ros/humble/lib/librcl_interfaces__rosidl_generator_c.so
libfakeio.so: /opt/ros/humble/lib/librcl_yaml_param_parser.so
libfakeio.so: /opt/ros/humble/lib/libyaml.so
libfakeio.so: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_fastrtps_c.so
libfakeio.so: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_fastrtps_cpp.so
libfakeio.so: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_introspection_c.so
libfakeio.so: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_introspection_cpp.so
libfakeio.so: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_cpp.so
libfakeio.so: /opt/ros/humble/lib/librosgraph_msgs__rosidl_generator_py.so
libfakeio.so: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_c.so
libfakeio.so: /opt/ros/humble/lib/librosgraph_msgs__rosidl_generator_c.so
libfakeio.so: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_fastrtps_c.so
libfakeio.so: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_fastrtps_cpp.so
libfakeio.so: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_introspection_c.so
libfakeio.so: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_introspection_cpp.so
libfakeio.so: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_cpp.so
libfakeio.so: /opt/ros/humble/lib/libstatistics_msgs__rosidl_generator_py.so
libfakeio.so: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_c.so
libfakeio.so: /opt/ros/humble/lib/libstatistics_msgs__rosidl_generator_c.so
libfakeio.so: /opt/ros/humble/lib/libtracetools.so
libfakeio.so: /opt/ros/humble/lib/libsensor_msgs__rosidl_typesupport_fastrtps_c.so
libfakeio.so: /opt/ros/humble/lib/libgeometry_msgs__rosidl_typesupport_fastrtps_c.so
libfakeio.so: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_fastrtps_c.so
libfakeio.so: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_fastrtps_c.so
libfakeio.so: /opt/ros/humble/lib/librosidl_typesupport_fastrtps_c.so
libfakeio.so: /opt/ros/humble/lib/libsensor_msgs__rosidl_typesupport_fastrtps_cpp.so
libfakeio.so: /opt/ros/humble/lib/libgeometry_msgs__rosidl_typesupport_fastrtps_cpp.so
libfakeio.so: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_fastrtps_cpp.so
libfakeio.so: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_fastrtps_cpp.so
libfakeio.so: /opt/ros/humble/lib/librosidl_typesupport_fastrtps_cpp.so
libfakeio.so: /opt/ros/humble/lib/libfastcdr.so.1.0.24
libfakeio.so: /opt/ros/humble/lib/librmw.so
libfakeio.so: /opt/ros/humble/lib/libsensor_msgs__rosidl_typesupport_introspection_c.so
libfakeio.so: /opt/ros/humble/lib/libgeometry_msgs__rosidl_typesupport_introspection_c.so
libfakeio.so: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_introspection_c.so
libfakeio.so: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_c.so
libfakeio.so: /opt/ros/humble/lib/libsensor_msgs__rosidl_typesupport_introspection_cpp.so
libfakeio.so: /opt/ros/humble/lib/libgeometry_msgs__rosidl_typesupport_introspection_cpp.so
libfakeio.so: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_introspection_cpp.so
libfakeio.so: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_cpp.so
libfakeio.so: /opt/ros/humble/lib/librosidl_typesupport_introspection_cpp.so
libfakeio.so: /opt/ros/humble/lib/librosidl_typesupport_introspection_c.so
libfakeio.so: /opt/ros/humble/lib/libsensor_msgs__rosidl_generator_py.so
libfakeio.so: /opt/ros/humble/lib/libsensor_msgs__rosidl_typesupport_c.so
libfakeio.so: /opt/ros/humble/lib/libsensor_msgs__rosidl_generator_c.so
libfakeio.so: /opt/ros/humble/lib/libgeometry_msgs__rosidl_generator_py.so
libfakeio.so: /opt/ros/humble/lib/libgeometry_msgs__rosidl_typesupport_c.so
libfakeio.so: /opt/ros/humble/lib/libgeometry_msgs__rosidl_generator_c.so
libfakeio.so: /opt/ros/humble/lib/libstd_msgs__rosidl_generator_py.so
libfakeio.so: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_generator_py.so
libfakeio.so: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_c.so
libfakeio.so: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_c.so
libfakeio.so: /opt/ros/humble/lib/libstd_msgs__rosidl_generator_c.so
libfakeio.so: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_generator_c.so
libfakeio.so: /usr/lib/x86_64-linux-gnu/libpython3.10.so
libfakeio.so: /opt/ros/humble/lib/libsensor_msgs__rosidl_typesupport_cpp.so
libfakeio.so: /opt/ros/humble/lib/libgeometry_msgs__rosidl_typesupport_cpp.so
libfakeio.so: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_cpp.so
libfakeio.so: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_cpp.so
libfakeio.so: /opt/ros/humble/lib/librosidl_typesupport_cpp.so
libfakeio.so: /opt/ros/humble/lib/librosidl_typesupport_c.so
libfakeio.so: /opt/ros/humble/lib/librosidl_runtime_c.so
libfakeio.so: /opt/ros/humble/lib/librcpputils.so
libfakeio.so: /opt/ros/humble/lib/librcutils.so
libfakeio.so: minipc_comm/utils/libutils.a
libfakeio.so: /usr/local/lib/libopencv_imgcodecs.so.4.7.0
libfakeio.so: /usr/local/lib/libopencv_calib3d.so.4.7.0
libfakeio.so: /usr/local/lib/libopencv_dnn.so.4.7.0
libfakeio.so: /usr/local/lib/libopencv_features2d.so.4.7.0
libfakeio.so: /usr/local/lib/libopencv_flann.so.4.7.0
libfakeio.so: /usr/local/lib/libopencv_imgproc.so.4.7.0
libfakeio.so: /usr/local/lib/libopencv_core.so.4.7.0
libfakeio.so: CMakeFiles/fakeio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/file_io/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libfakeio.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fakeio.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fakeio.dir/build: libfakeio.so
.PHONY : CMakeFiles/fakeio.dir/build

CMakeFiles/fakeio.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fakeio.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fakeio.dir/clean

CMakeFiles/fakeio.dir/depend:
	cd /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/file_io && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/file_io /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/file_io /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/file_io /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/file_io /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/file_io/CMakeFiles/fakeio.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fakeio.dir/depend
