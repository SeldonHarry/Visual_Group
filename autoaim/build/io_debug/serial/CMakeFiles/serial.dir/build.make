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
CMAKE_SOURCE_DIR = /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/io_debug

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug

# Include any dependencies generated for this target.
include serial/CMakeFiles/serial.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include serial/CMakeFiles/serial.dir/compiler_depend.make

# Include the progress variables for this target.
include serial/CMakeFiles/serial.dir/progress.make

# Include the compile flags for this target's objects.
include serial/CMakeFiles/serial.dir/flags.make

serial/CMakeFiles/serial.dir/src/serial.cc.o: serial/CMakeFiles/serial.dir/flags.make
serial/CMakeFiles/serial.dir/src/serial.cc.o: /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/io_debug/serial/src/serial.cc
serial/CMakeFiles/serial.dir/src/serial.cc.o: serial/CMakeFiles/serial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object serial/CMakeFiles/serial.dir/src/serial.cc.o"
	cd /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug/serial && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT serial/CMakeFiles/serial.dir/src/serial.cc.o -MF CMakeFiles/serial.dir/src/serial.cc.o.d -o CMakeFiles/serial.dir/src/serial.cc.o -c /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/io_debug/serial/src/serial.cc

serial/CMakeFiles/serial.dir/src/serial.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serial.dir/src/serial.cc.i"
	cd /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug/serial && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/io_debug/serial/src/serial.cc > CMakeFiles/serial.dir/src/serial.cc.i

serial/CMakeFiles/serial.dir/src/serial.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serial.dir/src/serial.cc.s"
	cd /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug/serial && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/io_debug/serial/src/serial.cc -o CMakeFiles/serial.dir/src/serial.cc.s

serial/CMakeFiles/serial.dir/src/impl/unix.cc.o: serial/CMakeFiles/serial.dir/flags.make
serial/CMakeFiles/serial.dir/src/impl/unix.cc.o: /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/io_debug/serial/src/impl/unix.cc
serial/CMakeFiles/serial.dir/src/impl/unix.cc.o: serial/CMakeFiles/serial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object serial/CMakeFiles/serial.dir/src/impl/unix.cc.o"
	cd /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug/serial && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT serial/CMakeFiles/serial.dir/src/impl/unix.cc.o -MF CMakeFiles/serial.dir/src/impl/unix.cc.o.d -o CMakeFiles/serial.dir/src/impl/unix.cc.o -c /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/io_debug/serial/src/impl/unix.cc

serial/CMakeFiles/serial.dir/src/impl/unix.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serial.dir/src/impl/unix.cc.i"
	cd /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug/serial && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/io_debug/serial/src/impl/unix.cc > CMakeFiles/serial.dir/src/impl/unix.cc.i

serial/CMakeFiles/serial.dir/src/impl/unix.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serial.dir/src/impl/unix.cc.s"
	cd /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug/serial && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/io_debug/serial/src/impl/unix.cc -o CMakeFiles/serial.dir/src/impl/unix.cc.s

serial/CMakeFiles/serial.dir/src/impl/list_ports/list_ports_linux.cc.o: serial/CMakeFiles/serial.dir/flags.make
serial/CMakeFiles/serial.dir/src/impl/list_ports/list_ports_linux.cc.o: /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/io_debug/serial/src/impl/list_ports/list_ports_linux.cc
serial/CMakeFiles/serial.dir/src/impl/list_ports/list_ports_linux.cc.o: serial/CMakeFiles/serial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object serial/CMakeFiles/serial.dir/src/impl/list_ports/list_ports_linux.cc.o"
	cd /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug/serial && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT serial/CMakeFiles/serial.dir/src/impl/list_ports/list_ports_linux.cc.o -MF CMakeFiles/serial.dir/src/impl/list_ports/list_ports_linux.cc.o.d -o CMakeFiles/serial.dir/src/impl/list_ports/list_ports_linux.cc.o -c /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/io_debug/serial/src/impl/list_ports/list_ports_linux.cc

serial/CMakeFiles/serial.dir/src/impl/list_ports/list_ports_linux.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serial.dir/src/impl/list_ports/list_ports_linux.cc.i"
	cd /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug/serial && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/io_debug/serial/src/impl/list_ports/list_ports_linux.cc > CMakeFiles/serial.dir/src/impl/list_ports/list_ports_linux.cc.i

serial/CMakeFiles/serial.dir/src/impl/list_ports/list_ports_linux.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serial.dir/src/impl/list_ports/list_ports_linux.cc.s"
	cd /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug/serial && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/io_debug/serial/src/impl/list_ports/list_ports_linux.cc -o CMakeFiles/serial.dir/src/impl/list_ports/list_ports_linux.cc.s

# Object files for target serial
serial_OBJECTS = \
"CMakeFiles/serial.dir/src/serial.cc.o" \
"CMakeFiles/serial.dir/src/impl/unix.cc.o" \
"CMakeFiles/serial.dir/src/impl/list_ports/list_ports_linux.cc.o"

# External object files for target serial
serial_EXTERNAL_OBJECTS =

serial/libserial.a: serial/CMakeFiles/serial.dir/src/serial.cc.o
serial/libserial.a: serial/CMakeFiles/serial.dir/src/impl/unix.cc.o
serial/libserial.a: serial/CMakeFiles/serial.dir/src/impl/list_ports/list_ports_linux.cc.o
serial/libserial.a: serial/CMakeFiles/serial.dir/build.make
serial/libserial.a: serial/CMakeFiles/serial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libserial.a"
	cd /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug/serial && $(CMAKE_COMMAND) -P CMakeFiles/serial.dir/cmake_clean_target.cmake
	cd /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug/serial && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
serial/CMakeFiles/serial.dir/build: serial/libserial.a
.PHONY : serial/CMakeFiles/serial.dir/build

serial/CMakeFiles/serial.dir/clean:
	cd /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug/serial && $(CMAKE_COMMAND) -P CMakeFiles/serial.dir/cmake_clean.cmake
.PHONY : serial/CMakeFiles/serial.dir/clean

serial/CMakeFiles/serial.dir/depend:
	cd /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/io_debug /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/src/io_debug/serial /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug/serial /home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/build/io_debug/serial/CMakeFiles/serial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : serial/CMakeFiles/serial.dir/depend

