# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/artemii/Downloads/JSON-comparison

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/artemii/Downloads/JSON-comparison/build

# Include any dependencies generated for this target.
include CMakeFiles/JSON-comparison.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/JSON-comparison.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/JSON-comparison.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/JSON-comparison.dir/flags.make

CMakeFiles/JSON-comparison.dir/main.cpp.o: CMakeFiles/JSON-comparison.dir/flags.make
CMakeFiles/JSON-comparison.dir/main.cpp.o: ../main.cpp
CMakeFiles/JSON-comparison.dir/main.cpp.o: CMakeFiles/JSON-comparison.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/artemii/Downloads/JSON-comparison/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/JSON-comparison.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/JSON-comparison.dir/main.cpp.o -MF CMakeFiles/JSON-comparison.dir/main.cpp.o.d -o CMakeFiles/JSON-comparison.dir/main.cpp.o -c /home/artemii/Downloads/JSON-comparison/main.cpp

CMakeFiles/JSON-comparison.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JSON-comparison.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/artemii/Downloads/JSON-comparison/main.cpp > CMakeFiles/JSON-comparison.dir/main.cpp.i

CMakeFiles/JSON-comparison.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JSON-comparison.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/artemii/Downloads/JSON-comparison/main.cpp -o CMakeFiles/JSON-comparison.dir/main.cpp.s

# Object files for target JSON-comparison
JSON__comparison_OBJECTS = \
"CMakeFiles/JSON-comparison.dir/main.cpp.o"

# External object files for target JSON-comparison
JSON__comparison_EXTERNAL_OBJECTS =

JSON-comparison: CMakeFiles/JSON-comparison.dir/main.cpp.o
JSON-comparison: CMakeFiles/JSON-comparison.dir/build.make
JSON-comparison: CMakeFiles/JSON-comparison.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/artemii/Downloads/JSON-comparison/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable JSON-comparison"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/JSON-comparison.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/JSON-comparison.dir/build: JSON-comparison
.PHONY : CMakeFiles/JSON-comparison.dir/build

CMakeFiles/JSON-comparison.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/JSON-comparison.dir/cmake_clean.cmake
.PHONY : CMakeFiles/JSON-comparison.dir/clean

CMakeFiles/JSON-comparison.dir/depend:
	cd /home/artemii/Downloads/JSON-comparison/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/artemii/Downloads/JSON-comparison /home/artemii/Downloads/JSON-comparison /home/artemii/Downloads/JSON-comparison/build /home/artemii/Downloads/JSON-comparison/build /home/artemii/Downloads/JSON-comparison/build/CMakeFiles/JSON-comparison.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/JSON-comparison.dir/depend

