# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /Users/kkuvalis/Desktop/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Users/kkuvalis/Desktop/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kkuvalis/Desktop/aaa

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kkuvalis/Desktop/aaa

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Users/kkuvalis/Desktop/CLion.app/Contents/bin/cmake/mac/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/Users/kkuvalis/Desktop/CLion.app/Contents/bin/cmake/mac/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/kkuvalis/Desktop/aaa/CMakeFiles /Users/kkuvalis/Desktop/aaa/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/kkuvalis/Desktop/aaa/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named RTv1

# Build rule for target.
RTv1: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 RTv1
.PHONY : RTv1

# fast build rule for target.
RTv1/fast:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/build
.PHONY : RTv1/fast

atof.o: atof.c.o

.PHONY : atof.o

# target to build an object file
atof.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/atof.c.o
.PHONY : atof.c.o

atof.i: atof.c.i

.PHONY : atof.i

# target to preprocess a source file
atof.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/atof.c.i
.PHONY : atof.c.i

atof.s: atof.c.s

.PHONY : atof.s

# target to generate assembly for a file
atof.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/atof.c.s
.PHONY : atof.c.s

check_intersect.o: check_intersect.c.o

.PHONY : check_intersect.o

# target to build an object file
check_intersect.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/check_intersect.c.o
.PHONY : check_intersect.c.o

check_intersect.i: check_intersect.c.i

.PHONY : check_intersect.i

# target to preprocess a source file
check_intersect.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/check_intersect.c.i
.PHONY : check_intersect.c.i

check_intersect.s: check_intersect.c.s

.PHONY : check_intersect.s

# target to generate assembly for a file
check_intersect.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/check_intersect.c.s
.PHONY : check_intersect.c.s

gnl/get_next_line.o: gnl/get_next_line.c.o

.PHONY : gnl/get_next_line.o

# target to build an object file
gnl/get_next_line.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/get_next_line.c.o
.PHONY : gnl/get_next_line.c.o

gnl/get_next_line.i: gnl/get_next_line.c.i

.PHONY : gnl/get_next_line.i

# target to preprocess a source file
gnl/get_next_line.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/get_next_line.c.i
.PHONY : gnl/get_next_line.c.i

gnl/get_next_line.s: gnl/get_next_line.c.s

.PHONY : gnl/get_next_line.s

# target to generate assembly for a file
gnl/get_next_line.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/get_next_line.c.s
.PHONY : gnl/get_next_line.c.s

gnl/libft/ft_atoi.o: gnl/libft/ft_atoi.c.o

.PHONY : gnl/libft/ft_atoi.o

# target to build an object file
gnl/libft/ft_atoi.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_atoi.c.o
.PHONY : gnl/libft/ft_atoi.c.o

gnl/libft/ft_atoi.i: gnl/libft/ft_atoi.c.i

.PHONY : gnl/libft/ft_atoi.i

# target to preprocess a source file
gnl/libft/ft_atoi.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_atoi.c.i
.PHONY : gnl/libft/ft_atoi.c.i

gnl/libft/ft_atoi.s: gnl/libft/ft_atoi.c.s

.PHONY : gnl/libft/ft_atoi.s

# target to generate assembly for a file
gnl/libft/ft_atoi.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_atoi.c.s
.PHONY : gnl/libft/ft_atoi.c.s

gnl/libft/ft_isdigit.o: gnl/libft/ft_isdigit.c.o

.PHONY : gnl/libft/ft_isdigit.o

# target to build an object file
gnl/libft/ft_isdigit.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_isdigit.c.o
.PHONY : gnl/libft/ft_isdigit.c.o

gnl/libft/ft_isdigit.i: gnl/libft/ft_isdigit.c.i

.PHONY : gnl/libft/ft_isdigit.i

# target to preprocess a source file
gnl/libft/ft_isdigit.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_isdigit.c.i
.PHONY : gnl/libft/ft_isdigit.c.i

gnl/libft/ft_isdigit.s: gnl/libft/ft_isdigit.c.s

.PHONY : gnl/libft/ft_isdigit.s

# target to generate assembly for a file
gnl/libft/ft_isdigit.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_isdigit.c.s
.PHONY : gnl/libft/ft_isdigit.c.s

gnl/libft/ft_joincatfree.o: gnl/libft/ft_joincatfree.c.o

.PHONY : gnl/libft/ft_joincatfree.o

# target to build an object file
gnl/libft/ft_joincatfree.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_joincatfree.c.o
.PHONY : gnl/libft/ft_joincatfree.c.o

gnl/libft/ft_joincatfree.i: gnl/libft/ft_joincatfree.c.i

.PHONY : gnl/libft/ft_joincatfree.i

# target to preprocess a source file
gnl/libft/ft_joincatfree.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_joincatfree.c.i
.PHONY : gnl/libft/ft_joincatfree.c.i

gnl/libft/ft_joincatfree.s: gnl/libft/ft_joincatfree.c.s

.PHONY : gnl/libft/ft_joincatfree.s

# target to generate assembly for a file
gnl/libft/ft_joincatfree.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_joincatfree.c.s
.PHONY : gnl/libft/ft_joincatfree.c.s

gnl/libft/ft_lstadd.o: gnl/libft/ft_lstadd.c.o

.PHONY : gnl/libft/ft_lstadd.o

# target to build an object file
gnl/libft/ft_lstadd.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_lstadd.c.o
.PHONY : gnl/libft/ft_lstadd.c.o

gnl/libft/ft_lstadd.i: gnl/libft/ft_lstadd.c.i

.PHONY : gnl/libft/ft_lstadd.i

# target to preprocess a source file
gnl/libft/ft_lstadd.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_lstadd.c.i
.PHONY : gnl/libft/ft_lstadd.c.i

gnl/libft/ft_lstadd.s: gnl/libft/ft_lstadd.c.s

.PHONY : gnl/libft/ft_lstadd.s

# target to generate assembly for a file
gnl/libft/ft_lstadd.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_lstadd.c.s
.PHONY : gnl/libft/ft_lstadd.c.s

gnl/libft/ft_lstnew.o: gnl/libft/ft_lstnew.c.o

.PHONY : gnl/libft/ft_lstnew.o

# target to build an object file
gnl/libft/ft_lstnew.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_lstnew.c.o
.PHONY : gnl/libft/ft_lstnew.c.o

gnl/libft/ft_lstnew.i: gnl/libft/ft_lstnew.c.i

.PHONY : gnl/libft/ft_lstnew.i

# target to preprocess a source file
gnl/libft/ft_lstnew.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_lstnew.c.i
.PHONY : gnl/libft/ft_lstnew.c.i

gnl/libft/ft_lstnew.s: gnl/libft/ft_lstnew.c.s

.PHONY : gnl/libft/ft_lstnew.s

# target to generate assembly for a file
gnl/libft/ft_lstnew.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_lstnew.c.s
.PHONY : gnl/libft/ft_lstnew.c.s

gnl/libft/ft_memcpy.o: gnl/libft/ft_memcpy.c.o

.PHONY : gnl/libft/ft_memcpy.o

# target to build an object file
gnl/libft/ft_memcpy.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_memcpy.c.o
.PHONY : gnl/libft/ft_memcpy.c.o

gnl/libft/ft_memcpy.i: gnl/libft/ft_memcpy.c.i

.PHONY : gnl/libft/ft_memcpy.i

# target to preprocess a source file
gnl/libft/ft_memcpy.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_memcpy.c.i
.PHONY : gnl/libft/ft_memcpy.c.i

gnl/libft/ft_memcpy.s: gnl/libft/ft_memcpy.c.s

.PHONY : gnl/libft/ft_memcpy.s

# target to generate assembly for a file
gnl/libft/ft_memcpy.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_memcpy.c.s
.PHONY : gnl/libft/ft_memcpy.c.s

gnl/libft/ft_putchar.o: gnl/libft/ft_putchar.c.o

.PHONY : gnl/libft/ft_putchar.o

# target to build an object file
gnl/libft/ft_putchar.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_putchar.c.o
.PHONY : gnl/libft/ft_putchar.c.o

gnl/libft/ft_putchar.i: gnl/libft/ft_putchar.c.i

.PHONY : gnl/libft/ft_putchar.i

# target to preprocess a source file
gnl/libft/ft_putchar.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_putchar.c.i
.PHONY : gnl/libft/ft_putchar.c.i

gnl/libft/ft_putchar.s: gnl/libft/ft_putchar.c.s

.PHONY : gnl/libft/ft_putchar.s

# target to generate assembly for a file
gnl/libft/ft_putchar.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_putchar.c.s
.PHONY : gnl/libft/ft_putchar.c.s

gnl/libft/ft_putendl.o: gnl/libft/ft_putendl.c.o

.PHONY : gnl/libft/ft_putendl.o

# target to build an object file
gnl/libft/ft_putendl.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_putendl.c.o
.PHONY : gnl/libft/ft_putendl.c.o

gnl/libft/ft_putendl.i: gnl/libft/ft_putendl.c.i

.PHONY : gnl/libft/ft_putendl.i

# target to preprocess a source file
gnl/libft/ft_putendl.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_putendl.c.i
.PHONY : gnl/libft/ft_putendl.c.i

gnl/libft/ft_putendl.s: gnl/libft/ft_putendl.c.s

.PHONY : gnl/libft/ft_putendl.s

# target to generate assembly for a file
gnl/libft/ft_putendl.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_putendl.c.s
.PHONY : gnl/libft/ft_putendl.c.s

gnl/libft/ft_putstr.o: gnl/libft/ft_putstr.c.o

.PHONY : gnl/libft/ft_putstr.o

# target to build an object file
gnl/libft/ft_putstr.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_putstr.c.o
.PHONY : gnl/libft/ft_putstr.c.o

gnl/libft/ft_putstr.i: gnl/libft/ft_putstr.c.i

.PHONY : gnl/libft/ft_putstr.i

# target to preprocess a source file
gnl/libft/ft_putstr.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_putstr.c.i
.PHONY : gnl/libft/ft_putstr.c.i

gnl/libft/ft_putstr.s: gnl/libft/ft_putstr.c.s

.PHONY : gnl/libft/ft_putstr.s

# target to generate assembly for a file
gnl/libft/ft_putstr.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_putstr.c.s
.PHONY : gnl/libft/ft_putstr.c.s

gnl/libft/ft_strcat.o: gnl/libft/ft_strcat.c.o

.PHONY : gnl/libft/ft_strcat.o

# target to build an object file
gnl/libft/ft_strcat.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strcat.c.o
.PHONY : gnl/libft/ft_strcat.c.o

gnl/libft/ft_strcat.i: gnl/libft/ft_strcat.c.i

.PHONY : gnl/libft/ft_strcat.i

# target to preprocess a source file
gnl/libft/ft_strcat.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strcat.c.i
.PHONY : gnl/libft/ft_strcat.c.i

gnl/libft/ft_strcat.s: gnl/libft/ft_strcat.c.s

.PHONY : gnl/libft/ft_strcat.s

# target to generate assembly for a file
gnl/libft/ft_strcat.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strcat.c.s
.PHONY : gnl/libft/ft_strcat.c.s

gnl/libft/ft_strchr.o: gnl/libft/ft_strchr.c.o

.PHONY : gnl/libft/ft_strchr.o

# target to build an object file
gnl/libft/ft_strchr.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strchr.c.o
.PHONY : gnl/libft/ft_strchr.c.o

gnl/libft/ft_strchr.i: gnl/libft/ft_strchr.c.i

.PHONY : gnl/libft/ft_strchr.i

# target to preprocess a source file
gnl/libft/ft_strchr.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strchr.c.i
.PHONY : gnl/libft/ft_strchr.c.i

gnl/libft/ft_strchr.s: gnl/libft/ft_strchr.c.s

.PHONY : gnl/libft/ft_strchr.s

# target to generate assembly for a file
gnl/libft/ft_strchr.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strchr.c.s
.PHONY : gnl/libft/ft_strchr.c.s

gnl/libft/ft_strcmp.o: gnl/libft/ft_strcmp.c.o

.PHONY : gnl/libft/ft_strcmp.o

# target to build an object file
gnl/libft/ft_strcmp.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strcmp.c.o
.PHONY : gnl/libft/ft_strcmp.c.o

gnl/libft/ft_strcmp.i: gnl/libft/ft_strcmp.c.i

.PHONY : gnl/libft/ft_strcmp.i

# target to preprocess a source file
gnl/libft/ft_strcmp.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strcmp.c.i
.PHONY : gnl/libft/ft_strcmp.c.i

gnl/libft/ft_strcmp.s: gnl/libft/ft_strcmp.c.s

.PHONY : gnl/libft/ft_strcmp.s

# target to generate assembly for a file
gnl/libft/ft_strcmp.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strcmp.c.s
.PHONY : gnl/libft/ft_strcmp.c.s

gnl/libft/ft_strcpy.o: gnl/libft/ft_strcpy.c.o

.PHONY : gnl/libft/ft_strcpy.o

# target to build an object file
gnl/libft/ft_strcpy.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strcpy.c.o
.PHONY : gnl/libft/ft_strcpy.c.o

gnl/libft/ft_strcpy.i: gnl/libft/ft_strcpy.c.i

.PHONY : gnl/libft/ft_strcpy.i

# target to preprocess a source file
gnl/libft/ft_strcpy.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strcpy.c.i
.PHONY : gnl/libft/ft_strcpy.c.i

gnl/libft/ft_strcpy.s: gnl/libft/ft_strcpy.c.s

.PHONY : gnl/libft/ft_strcpy.s

# target to generate assembly for a file
gnl/libft/ft_strcpy.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strcpy.c.s
.PHONY : gnl/libft/ft_strcpy.c.s

gnl/libft/ft_strdel.o: gnl/libft/ft_strdel.c.o

.PHONY : gnl/libft/ft_strdel.o

# target to build an object file
gnl/libft/ft_strdel.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strdel.c.o
.PHONY : gnl/libft/ft_strdel.c.o

gnl/libft/ft_strdel.i: gnl/libft/ft_strdel.c.i

.PHONY : gnl/libft/ft_strdel.i

# target to preprocess a source file
gnl/libft/ft_strdel.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strdel.c.i
.PHONY : gnl/libft/ft_strdel.c.i

gnl/libft/ft_strdel.s: gnl/libft/ft_strdel.c.s

.PHONY : gnl/libft/ft_strdel.s

# target to generate assembly for a file
gnl/libft/ft_strdel.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strdel.c.s
.PHONY : gnl/libft/ft_strdel.c.s

gnl/libft/ft_strdup.o: gnl/libft/ft_strdup.c.o

.PHONY : gnl/libft/ft_strdup.o

# target to build an object file
gnl/libft/ft_strdup.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strdup.c.o
.PHONY : gnl/libft/ft_strdup.c.o

gnl/libft/ft_strdup.i: gnl/libft/ft_strdup.c.i

.PHONY : gnl/libft/ft_strdup.i

# target to preprocess a source file
gnl/libft/ft_strdup.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strdup.c.i
.PHONY : gnl/libft/ft_strdup.c.i

gnl/libft/ft_strdup.s: gnl/libft/ft_strdup.c.s

.PHONY : gnl/libft/ft_strdup.s

# target to generate assembly for a file
gnl/libft/ft_strdup.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strdup.c.s
.PHONY : gnl/libft/ft_strdup.c.s

gnl/libft/ft_strlen.o: gnl/libft/ft_strlen.c.o

.PHONY : gnl/libft/ft_strlen.o

# target to build an object file
gnl/libft/ft_strlen.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strlen.c.o
.PHONY : gnl/libft/ft_strlen.c.o

gnl/libft/ft_strlen.i: gnl/libft/ft_strlen.c.i

.PHONY : gnl/libft/ft_strlen.i

# target to preprocess a source file
gnl/libft/ft_strlen.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strlen.c.i
.PHONY : gnl/libft/ft_strlen.c.i

gnl/libft/ft_strlen.s: gnl/libft/ft_strlen.c.s

.PHONY : gnl/libft/ft_strlen.s

# target to generate assembly for a file
gnl/libft/ft_strlen.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strlen.c.s
.PHONY : gnl/libft/ft_strlen.c.s

gnl/libft/ft_strncpy.o: gnl/libft/ft_strncpy.c.o

.PHONY : gnl/libft/ft_strncpy.o

# target to build an object file
gnl/libft/ft_strncpy.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strncpy.c.o
.PHONY : gnl/libft/ft_strncpy.c.o

gnl/libft/ft_strncpy.i: gnl/libft/ft_strncpy.c.i

.PHONY : gnl/libft/ft_strncpy.i

# target to preprocess a source file
gnl/libft/ft_strncpy.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strncpy.c.i
.PHONY : gnl/libft/ft_strncpy.c.i

gnl/libft/ft_strncpy.s: gnl/libft/ft_strncpy.c.s

.PHONY : gnl/libft/ft_strncpy.s

# target to generate assembly for a file
gnl/libft/ft_strncpy.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strncpy.c.s
.PHONY : gnl/libft/ft_strncpy.c.s

gnl/libft/ft_strnew.o: gnl/libft/ft_strnew.c.o

.PHONY : gnl/libft/ft_strnew.o

# target to build an object file
gnl/libft/ft_strnew.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strnew.c.o
.PHONY : gnl/libft/ft_strnew.c.o

gnl/libft/ft_strnew.i: gnl/libft/ft_strnew.c.i

.PHONY : gnl/libft/ft_strnew.i

# target to preprocess a source file
gnl/libft/ft_strnew.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strnew.c.i
.PHONY : gnl/libft/ft_strnew.c.i

gnl/libft/ft_strnew.s: gnl/libft/ft_strnew.c.s

.PHONY : gnl/libft/ft_strnew.s

# target to generate assembly for a file
gnl/libft/ft_strnew.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strnew.c.s
.PHONY : gnl/libft/ft_strnew.c.s

gnl/libft/ft_strstr.o: gnl/libft/ft_strstr.c.o

.PHONY : gnl/libft/ft_strstr.o

# target to build an object file
gnl/libft/ft_strstr.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strstr.c.o
.PHONY : gnl/libft/ft_strstr.c.o

gnl/libft/ft_strstr.i: gnl/libft/ft_strstr.c.i

.PHONY : gnl/libft/ft_strstr.i

# target to preprocess a source file
gnl/libft/ft_strstr.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strstr.c.i
.PHONY : gnl/libft/ft_strstr.c.i

gnl/libft/ft_strstr.s: gnl/libft/ft_strstr.c.s

.PHONY : gnl/libft/ft_strstr.s

# target to generate assembly for a file
gnl/libft/ft_strstr.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/gnl/libft/ft_strstr.c.s
.PHONY : gnl/libft/ft_strstr.c.s

help_computelight.o: help_computelight.c.o

.PHONY : help_computelight.o

# target to build an object file
help_computelight.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/help_computelight.c.o
.PHONY : help_computelight.c.o

help_computelight.i: help_computelight.c.i

.PHONY : help_computelight.i

# target to preprocess a source file
help_computelight.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/help_computelight.c.i
.PHONY : help_computelight.c.i

help_computelight.s: help_computelight.c.s

.PHONY : help_computelight.s

# target to generate assembly for a file
help_computelight.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/help_computelight.c.s
.PHONY : help_computelight.c.s

help_utils.o: help_utils.c.o

.PHONY : help_utils.o

# target to build an object file
help_utils.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/help_utils.c.o
.PHONY : help_utils.c.o

help_utils.i: help_utils.c.i

.PHONY : help_utils.i

# target to preprocess a source file
help_utils.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/help_utils.c.i
.PHONY : help_utils.c.i

help_utils.s: help_utils.c.s

.PHONY : help_utils.s

# target to generate assembly for a file
help_utils.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/help_utils.c.s
.PHONY : help_utils.c.s

init.o: init.c.o

.PHONY : init.o

# target to build an object file
init.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/init.c.o
.PHONY : init.c.o

init.i: init.c.i

.PHONY : init.i

# target to preprocess a source file
init.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/init.c.i
.PHONY : init.c.i

init.s: init.c.s

.PHONY : init.s

# target to generate assembly for a file
init.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/init.c.s
.PHONY : init.c.s

intesect.o: intesect.c.o

.PHONY : intesect.o

# target to build an object file
intesect.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/intesect.c.o
.PHONY : intesect.c.o

intesect.i: intesect.c.i

.PHONY : intesect.i

# target to preprocess a source file
intesect.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/intesect.c.i
.PHONY : intesect.c.i

intesect.s: intesect.c.s

.PHONY : intesect.s

# target to generate assembly for a file
intesect.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/intesect.c.s
.PHONY : intesect.c.s

ray.o: ray.c.o

.PHONY : ray.o

# target to build an object file
ray.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/ray.c.o
.PHONY : ray.c.o

ray.i: ray.c.i

.PHONY : ray.i

# target to preprocess a source file
ray.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/ray.c.i
.PHONY : ray.c.i

ray.s: ray.c.s

.PHONY : ray.s

# target to generate assembly for a file
ray.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/ray.c.s
.PHONY : ray.c.s

read_scene1.o: read_scene1.c.o

.PHONY : read_scene1.o

# target to build an object file
read_scene1.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/read_scene1.c.o
.PHONY : read_scene1.c.o

read_scene1.i: read_scene1.c.i

.PHONY : read_scene1.i

# target to preprocess a source file
read_scene1.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/read_scene1.c.i
.PHONY : read_scene1.c.i

read_scene1.s: read_scene1.c.s

.PHONY : read_scene1.s

# target to generate assembly for a file
read_scene1.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/read_scene1.c.s
.PHONY : read_scene1.c.s

read_scene2.o: read_scene2.c.o

.PHONY : read_scene2.o

# target to build an object file
read_scene2.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/read_scene2.c.o
.PHONY : read_scene2.c.o

read_scene2.i: read_scene2.c.i

.PHONY : read_scene2.i

# target to preprocess a source file
read_scene2.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/read_scene2.c.i
.PHONY : read_scene2.c.i

read_scene2.s: read_scene2.c.s

.PHONY : read_scene2.s

# target to generate assembly for a file
read_scene2.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/read_scene2.c.s
.PHONY : read_scene2.c.s

rtv1.o: rtv1.c.o

.PHONY : rtv1.o

# target to build an object file
rtv1.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/rtv1.c.o
.PHONY : rtv1.c.o

rtv1.i: rtv1.c.i

.PHONY : rtv1.i

# target to preprocess a source file
rtv1.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/rtv1.c.i
.PHONY : rtv1.c.i

rtv1.s: rtv1.c.s

.PHONY : rtv1.s

# target to generate assembly for a file
rtv1.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/rtv1.c.s
.PHONY : rtv1.c.s

sdl_utils.o: sdl_utils.c.o

.PHONY : sdl_utils.o

# target to build an object file
sdl_utils.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/sdl_utils.c.o
.PHONY : sdl_utils.c.o

sdl_utils.i: sdl_utils.c.i

.PHONY : sdl_utils.i

# target to preprocess a source file
sdl_utils.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/sdl_utils.c.i
.PHONY : sdl_utils.c.i

sdl_utils.s: sdl_utils.c.s

.PHONY : sdl_utils.s

# target to generate assembly for a file
sdl_utils.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/sdl_utils.c.s
.PHONY : sdl_utils.c.s

source.o: source.c.o

.PHONY : source.o

# target to build an object file
source.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/source.c.o
.PHONY : source.c.o

source.i: source.c.i

.PHONY : source.i

# target to preprocess a source file
source.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/source.c.i
.PHONY : source.c.i

source.s: source.c.s

.PHONY : source.s

# target to generate assembly for a file
source.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/source.c.s
.PHONY : source.c.s

vector_scal.o: vector_scal.c.o

.PHONY : vector_scal.o

# target to build an object file
vector_scal.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/vector_scal.c.o
.PHONY : vector_scal.c.o

vector_scal.i: vector_scal.c.i

.PHONY : vector_scal.i

# target to preprocess a source file
vector_scal.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/vector_scal.c.i
.PHONY : vector_scal.c.i

vector_scal.s: vector_scal.c.s

.PHONY : vector_scal.s

# target to generate assembly for a file
vector_scal.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/vector_scal.c.s
.PHONY : vector_scal.c.s

vector_utils.o: vector_utils.c.o

.PHONY : vector_utils.o

# target to build an object file
vector_utils.c.o:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/vector_utils.c.o
.PHONY : vector_utils.c.o

vector_utils.i: vector_utils.c.i

.PHONY : vector_utils.i

# target to preprocess a source file
vector_utils.c.i:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/vector_utils.c.i
.PHONY : vector_utils.c.i

vector_utils.s: vector_utils.c.s

.PHONY : vector_utils.s

# target to generate assembly for a file
vector_utils.c.s:
	$(MAKE) -f CMakeFiles/RTv1.dir/build.make CMakeFiles/RTv1.dir/vector_utils.c.s
.PHONY : vector_utils.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... RTv1"
	@echo "... atof.o"
	@echo "... atof.i"
	@echo "... atof.s"
	@echo "... check_intersect.o"
	@echo "... check_intersect.i"
	@echo "... check_intersect.s"
	@echo "... gnl/get_next_line.o"
	@echo "... gnl/get_next_line.i"
	@echo "... gnl/get_next_line.s"
	@echo "... gnl/libft/ft_atoi.o"
	@echo "... gnl/libft/ft_atoi.i"
	@echo "... gnl/libft/ft_atoi.s"
	@echo "... gnl/libft/ft_isdigit.o"
	@echo "... gnl/libft/ft_isdigit.i"
	@echo "... gnl/libft/ft_isdigit.s"
	@echo "... gnl/libft/ft_joincatfree.o"
	@echo "... gnl/libft/ft_joincatfree.i"
	@echo "... gnl/libft/ft_joincatfree.s"
	@echo "... gnl/libft/ft_lstadd.o"
	@echo "... gnl/libft/ft_lstadd.i"
	@echo "... gnl/libft/ft_lstadd.s"
	@echo "... gnl/libft/ft_lstnew.o"
	@echo "... gnl/libft/ft_lstnew.i"
	@echo "... gnl/libft/ft_lstnew.s"
	@echo "... gnl/libft/ft_memcpy.o"
	@echo "... gnl/libft/ft_memcpy.i"
	@echo "... gnl/libft/ft_memcpy.s"
	@echo "... gnl/libft/ft_putchar.o"
	@echo "... gnl/libft/ft_putchar.i"
	@echo "... gnl/libft/ft_putchar.s"
	@echo "... gnl/libft/ft_putendl.o"
	@echo "... gnl/libft/ft_putendl.i"
	@echo "... gnl/libft/ft_putendl.s"
	@echo "... gnl/libft/ft_putstr.o"
	@echo "... gnl/libft/ft_putstr.i"
	@echo "... gnl/libft/ft_putstr.s"
	@echo "... gnl/libft/ft_strcat.o"
	@echo "... gnl/libft/ft_strcat.i"
	@echo "... gnl/libft/ft_strcat.s"
	@echo "... gnl/libft/ft_strchr.o"
	@echo "... gnl/libft/ft_strchr.i"
	@echo "... gnl/libft/ft_strchr.s"
	@echo "... gnl/libft/ft_strcmp.o"
	@echo "... gnl/libft/ft_strcmp.i"
	@echo "... gnl/libft/ft_strcmp.s"
	@echo "... gnl/libft/ft_strcpy.o"
	@echo "... gnl/libft/ft_strcpy.i"
	@echo "... gnl/libft/ft_strcpy.s"
	@echo "... gnl/libft/ft_strdel.o"
	@echo "... gnl/libft/ft_strdel.i"
	@echo "... gnl/libft/ft_strdel.s"
	@echo "... gnl/libft/ft_strdup.o"
	@echo "... gnl/libft/ft_strdup.i"
	@echo "... gnl/libft/ft_strdup.s"
	@echo "... gnl/libft/ft_strlen.o"
	@echo "... gnl/libft/ft_strlen.i"
	@echo "... gnl/libft/ft_strlen.s"
	@echo "... gnl/libft/ft_strncpy.o"
	@echo "... gnl/libft/ft_strncpy.i"
	@echo "... gnl/libft/ft_strncpy.s"
	@echo "... gnl/libft/ft_strnew.o"
	@echo "... gnl/libft/ft_strnew.i"
	@echo "... gnl/libft/ft_strnew.s"
	@echo "... gnl/libft/ft_strstr.o"
	@echo "... gnl/libft/ft_strstr.i"
	@echo "... gnl/libft/ft_strstr.s"
	@echo "... help_computelight.o"
	@echo "... help_computelight.i"
	@echo "... help_computelight.s"
	@echo "... help_utils.o"
	@echo "... help_utils.i"
	@echo "... help_utils.s"
	@echo "... init.o"
	@echo "... init.i"
	@echo "... init.s"
	@echo "... intesect.o"
	@echo "... intesect.i"
	@echo "... intesect.s"
	@echo "... ray.o"
	@echo "... ray.i"
	@echo "... ray.s"
	@echo "... read_scene1.o"
	@echo "... read_scene1.i"
	@echo "... read_scene1.s"
	@echo "... read_scene2.o"
	@echo "... read_scene2.i"
	@echo "... read_scene2.s"
	@echo "... rtv1.o"
	@echo "... rtv1.i"
	@echo "... rtv1.s"
	@echo "... sdl_utils.o"
	@echo "... sdl_utils.i"
	@echo "... sdl_utils.s"
	@echo "... source.o"
	@echo "... source.i"
	@echo "... source.s"
	@echo "... vector_scal.o"
	@echo "... vector_scal.i"
	@echo "... vector_scal.s"
	@echo "... vector_utils.o"
	@echo "... vector_utils.i"
	@echo "... vector_utils.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

