# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Users/cfahey/Desktop/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Users/cfahey/Desktop/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/cfahey/Desktop/112

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/cfahey/Desktop/112/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RTv1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RTv1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RTv1.dir/flags.make

CMakeFiles/RTv1.dir/rtv1.c.o: CMakeFiles/RTv1.dir/flags.make
CMakeFiles/RTv1.dir/rtv1.c.o: ../rtv1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cfahey/Desktop/112/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/RTv1.dir/rtv1.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RTv1.dir/rtv1.c.o   -c /Users/cfahey/Desktop/112/rtv1.c

CMakeFiles/RTv1.dir/rtv1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RTv1.dir/rtv1.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cfahey/Desktop/112/rtv1.c > CMakeFiles/RTv1.dir/rtv1.c.i

CMakeFiles/RTv1.dir/rtv1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RTv1.dir/rtv1.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cfahey/Desktop/112/rtv1.c -o CMakeFiles/RTv1.dir/rtv1.c.s

CMakeFiles/RTv1.dir/vector_utils.c.o: CMakeFiles/RTv1.dir/flags.make
CMakeFiles/RTv1.dir/vector_utils.c.o: ../vector_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cfahey/Desktop/112/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/RTv1.dir/vector_utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RTv1.dir/vector_utils.c.o   -c /Users/cfahey/Desktop/112/vector_utils.c

CMakeFiles/RTv1.dir/vector_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RTv1.dir/vector_utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cfahey/Desktop/112/vector_utils.c > CMakeFiles/RTv1.dir/vector_utils.c.i

CMakeFiles/RTv1.dir/vector_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RTv1.dir/vector_utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cfahey/Desktop/112/vector_utils.c -o CMakeFiles/RTv1.dir/vector_utils.c.s

CMakeFiles/RTv1.dir/vector_scal.c.o: CMakeFiles/RTv1.dir/flags.make
CMakeFiles/RTv1.dir/vector_scal.c.o: ../vector_scal.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cfahey/Desktop/112/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/RTv1.dir/vector_scal.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RTv1.dir/vector_scal.c.o   -c /Users/cfahey/Desktop/112/vector_scal.c

CMakeFiles/RTv1.dir/vector_scal.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RTv1.dir/vector_scal.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cfahey/Desktop/112/vector_scal.c > CMakeFiles/RTv1.dir/vector_scal.c.i

CMakeFiles/RTv1.dir/vector_scal.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RTv1.dir/vector_scal.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cfahey/Desktop/112/vector_scal.c -o CMakeFiles/RTv1.dir/vector_scal.c.s

# Object files for target RTv1
RTv1_OBJECTS = \
"CMakeFiles/RTv1.dir/rtv1.c.o" \
"CMakeFiles/RTv1.dir/vector_utils.c.o" \
"CMakeFiles/RTv1.dir/vector_scal.c.o"

# External object files for target RTv1
RTv1_EXTERNAL_OBJECTS =

RTv1: CMakeFiles/RTv1.dir/rtv1.c.o
RTv1: CMakeFiles/RTv1.dir/vector_utils.c.o
RTv1: CMakeFiles/RTv1.dir/vector_scal.c.o
RTv1: CMakeFiles/RTv1.dir/build.make
RTv1: CMakeFiles/RTv1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/cfahey/Desktop/112/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable RTv1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RTv1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RTv1.dir/build: RTv1

.PHONY : CMakeFiles/RTv1.dir/build

CMakeFiles/RTv1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RTv1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RTv1.dir/clean

CMakeFiles/RTv1.dir/depend:
	cd /Users/cfahey/Desktop/112/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/cfahey/Desktop/112 /Users/cfahey/Desktop/112 /Users/cfahey/Desktop/112/cmake-build-debug /Users/cfahey/Desktop/112/cmake-build-debug /Users/cfahey/Desktop/112/cmake-build-debug/CMakeFiles/RTv1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RTv1.dir/depend

