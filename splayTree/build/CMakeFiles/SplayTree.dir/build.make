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
CMAKE_SOURCE_DIR = /home/nikozer/univercity_tasks/graphsAlgos/splayTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nikozer/univercity_tasks/graphsAlgos/splayTree/build

# Include any dependencies generated for this target.
include CMakeFiles/SplayTree.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SplayTree.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SplayTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SplayTree.dir/flags.make

CMakeFiles/SplayTree.dir/src/main.cpp.o: CMakeFiles/SplayTree.dir/flags.make
CMakeFiles/SplayTree.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/SplayTree.dir/src/main.cpp.o: CMakeFiles/SplayTree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nikozer/univercity_tasks/graphsAlgos/splayTree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SplayTree.dir/src/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SplayTree.dir/src/main.cpp.o -MF CMakeFiles/SplayTree.dir/src/main.cpp.o.d -o CMakeFiles/SplayTree.dir/src/main.cpp.o -c /home/nikozer/univercity_tasks/graphsAlgos/splayTree/src/main.cpp

CMakeFiles/SplayTree.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SplayTree.dir/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nikozer/univercity_tasks/graphsAlgos/splayTree/src/main.cpp > CMakeFiles/SplayTree.dir/src/main.cpp.i

CMakeFiles/SplayTree.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SplayTree.dir/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nikozer/univercity_tasks/graphsAlgos/splayTree/src/main.cpp -o CMakeFiles/SplayTree.dir/src/main.cpp.s

# Object files for target SplayTree
SplayTree_OBJECTS = \
"CMakeFiles/SplayTree.dir/src/main.cpp.o"

# External object files for target SplayTree
SplayTree_EXTERNAL_OBJECTS =

SplayTree: CMakeFiles/SplayTree.dir/src/main.cpp.o
SplayTree: CMakeFiles/SplayTree.dir/build.make
SplayTree: CMakeFiles/SplayTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nikozer/univercity_tasks/graphsAlgos/splayTree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SplayTree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SplayTree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SplayTree.dir/build: SplayTree
.PHONY : CMakeFiles/SplayTree.dir/build

CMakeFiles/SplayTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SplayTree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SplayTree.dir/clean

CMakeFiles/SplayTree.dir/depend:
	cd /home/nikozer/univercity_tasks/graphsAlgos/splayTree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nikozer/univercity_tasks/graphsAlgos/splayTree /home/nikozer/univercity_tasks/graphsAlgos/splayTree /home/nikozer/univercity_tasks/graphsAlgos/splayTree/build /home/nikozer/univercity_tasks/graphsAlgos/splayTree/build /home/nikozer/univercity_tasks/graphsAlgos/splayTree/build/CMakeFiles/SplayTree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SplayTree.dir/depend

