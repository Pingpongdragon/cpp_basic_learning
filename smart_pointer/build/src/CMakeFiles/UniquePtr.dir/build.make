# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /media/ljy/data/cpplearning/cpp_basic_learning/smart_pointer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/ljy/data/cpplearning/cpp_basic_learning/smart_pointer/build

# Include any dependencies generated for this target.
include src/CMakeFiles/UniquePtr.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/UniquePtr.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/UniquePtr.dir/flags.make

src/CMakeFiles/UniquePtr.dir/UniquePtr.cpp.o: src/CMakeFiles/UniquePtr.dir/flags.make
src/CMakeFiles/UniquePtr.dir/UniquePtr.cpp.o: ../src/UniquePtr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/ljy/data/cpplearning/cpp_basic_learning/smart_pointer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/UniquePtr.dir/UniquePtr.cpp.o"
	cd /media/ljy/data/cpplearning/cpp_basic_learning/smart_pointer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UniquePtr.dir/UniquePtr.cpp.o -c /media/ljy/data/cpplearning/cpp_basic_learning/smart_pointer/src/UniquePtr.cpp

src/CMakeFiles/UniquePtr.dir/UniquePtr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UniquePtr.dir/UniquePtr.cpp.i"
	cd /media/ljy/data/cpplearning/cpp_basic_learning/smart_pointer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/ljy/data/cpplearning/cpp_basic_learning/smart_pointer/src/UniquePtr.cpp > CMakeFiles/UniquePtr.dir/UniquePtr.cpp.i

src/CMakeFiles/UniquePtr.dir/UniquePtr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UniquePtr.dir/UniquePtr.cpp.s"
	cd /media/ljy/data/cpplearning/cpp_basic_learning/smart_pointer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/ljy/data/cpplearning/cpp_basic_learning/smart_pointer/src/UniquePtr.cpp -o CMakeFiles/UniquePtr.dir/UniquePtr.cpp.s

# Object files for target UniquePtr
UniquePtr_OBJECTS = \
"CMakeFiles/UniquePtr.dir/UniquePtr.cpp.o"

# External object files for target UniquePtr
UniquePtr_EXTERNAL_OBJECTS =

src/libUniquePtr.a: src/CMakeFiles/UniquePtr.dir/UniquePtr.cpp.o
src/libUniquePtr.a: src/CMakeFiles/UniquePtr.dir/build.make
src/libUniquePtr.a: src/CMakeFiles/UniquePtr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/ljy/data/cpplearning/cpp_basic_learning/smart_pointer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libUniquePtr.a"
	cd /media/ljy/data/cpplearning/cpp_basic_learning/smart_pointer/build/src && $(CMAKE_COMMAND) -P CMakeFiles/UniquePtr.dir/cmake_clean_target.cmake
	cd /media/ljy/data/cpplearning/cpp_basic_learning/smart_pointer/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UniquePtr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/UniquePtr.dir/build: src/libUniquePtr.a

.PHONY : src/CMakeFiles/UniquePtr.dir/build

src/CMakeFiles/UniquePtr.dir/clean:
	cd /media/ljy/data/cpplearning/cpp_basic_learning/smart_pointer/build/src && $(CMAKE_COMMAND) -P CMakeFiles/UniquePtr.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/UniquePtr.dir/clean

src/CMakeFiles/UniquePtr.dir/depend:
	cd /media/ljy/data/cpplearning/cpp_basic_learning/smart_pointer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/ljy/data/cpplearning/cpp_basic_learning/smart_pointer /media/ljy/data/cpplearning/cpp_basic_learning/smart_pointer/src /media/ljy/data/cpplearning/cpp_basic_learning/smart_pointer/build /media/ljy/data/cpplearning/cpp_basic_learning/smart_pointer/build/src /media/ljy/data/cpplearning/cpp_basic_learning/smart_pointer/build/src/CMakeFiles/UniquePtr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/UniquePtr.dir/depend

