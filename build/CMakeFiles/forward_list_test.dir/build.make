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
CMAKE_SOURCE_DIR = /home/cowant/repo/data_structure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cowant/repo/data_structure/build

# Include any dependencies generated for this target.
include CMakeFiles/forward_list_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/forward_list_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/forward_list_test.dir/flags.make

CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.o: CMakeFiles/forward_list_test.dir/flags.make
CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.o: ../forward_list/forward_list_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cowant/repo/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.o -c /home/cowant/repo/data_structure/forward_list/forward_list_test.cc

CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cowant/repo/data_structure/forward_list/forward_list_test.cc > CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.i

CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cowant/repo/data_structure/forward_list/forward_list_test.cc -o CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.s

CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.o.requires:

.PHONY : CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.o.requires

CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.o.provides: CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.o.requires
	$(MAKE) -f CMakeFiles/forward_list_test.dir/build.make CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.o.provides.build
.PHONY : CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.o.provides

CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.o.provides.build: CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.o


# Object files for target forward_list_test
forward_list_test_OBJECTS = \
"CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.o"

# External object files for target forward_list_test
forward_list_test_EXTERNAL_OBJECTS =

forward_list_test: CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.o
forward_list_test: CMakeFiles/forward_list_test.dir/build.make
forward_list_test: libds.a
forward_list_test: lib/libgmock.a
forward_list_test: lib/libgtest.a
forward_list_test: CMakeFiles/forward_list_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cowant/repo/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable forward_list_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/forward_list_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/forward_list_test.dir/build: forward_list_test

.PHONY : CMakeFiles/forward_list_test.dir/build

CMakeFiles/forward_list_test.dir/requires: CMakeFiles/forward_list_test.dir/forward_list/forward_list_test.cc.o.requires

.PHONY : CMakeFiles/forward_list_test.dir/requires

CMakeFiles/forward_list_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/forward_list_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/forward_list_test.dir/clean

CMakeFiles/forward_list_test.dir/depend:
	cd /home/cowant/repo/data_structure/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cowant/repo/data_structure /home/cowant/repo/data_structure /home/cowant/repo/data_structure/build /home/cowant/repo/data_structure/build /home/cowant/repo/data_structure/build/CMakeFiles/forward_list_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/forward_list_test.dir/depend

