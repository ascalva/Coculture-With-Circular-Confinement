# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/coculture.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/coculture.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/coculture.dir/flags.make

CMakeFiles/coculture.dir/main.cpp.o: CMakeFiles/coculture.dir/flags.make
CMakeFiles/coculture.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/coculture.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coculture.dir/main.cpp.o -c /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/main.cpp

CMakeFiles/coculture.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coculture.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/main.cpp > CMakeFiles/coculture.dir/main.cpp.i

CMakeFiles/coculture.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coculture.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/main.cpp -o CMakeFiles/coculture.dir/main.cpp.s

CMakeFiles/coculture.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/coculture.dir/main.cpp.o.requires

CMakeFiles/coculture.dir/main.cpp.o.provides: CMakeFiles/coculture.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/coculture.dir/build.make CMakeFiles/coculture.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/coculture.dir/main.cpp.o.provides

CMakeFiles/coculture.dir/main.cpp.o.provides.build: CMakeFiles/coculture.dir/main.cpp.o


CMakeFiles/coculture.dir/Cells/Cell.cpp.o: CMakeFiles/coculture.dir/flags.make
CMakeFiles/coculture.dir/Cells/Cell.cpp.o: ../Cells/Cell.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/coculture.dir/Cells/Cell.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coculture.dir/Cells/Cell.cpp.o -c /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/Cells/Cell.cpp

CMakeFiles/coculture.dir/Cells/Cell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coculture.dir/Cells/Cell.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/Cells/Cell.cpp > CMakeFiles/coculture.dir/Cells/Cell.cpp.i

CMakeFiles/coculture.dir/Cells/Cell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coculture.dir/Cells/Cell.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/Cells/Cell.cpp -o CMakeFiles/coculture.dir/Cells/Cell.cpp.s

CMakeFiles/coculture.dir/Cells/Cell.cpp.o.requires:

.PHONY : CMakeFiles/coculture.dir/Cells/Cell.cpp.o.requires

CMakeFiles/coculture.dir/Cells/Cell.cpp.o.provides: CMakeFiles/coculture.dir/Cells/Cell.cpp.o.requires
	$(MAKE) -f CMakeFiles/coculture.dir/build.make CMakeFiles/coculture.dir/Cells/Cell.cpp.o.provides.build
.PHONY : CMakeFiles/coculture.dir/Cells/Cell.cpp.o.provides

CMakeFiles/coculture.dir/Cells/Cell.cpp.o.provides.build: CMakeFiles/coculture.dir/Cells/Cell.cpp.o


CMakeFiles/coculture.dir/Cells/Healthy.cpp.o: CMakeFiles/coculture.dir/flags.make
CMakeFiles/coculture.dir/Cells/Healthy.cpp.o: ../Cells/Healthy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/coculture.dir/Cells/Healthy.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coculture.dir/Cells/Healthy.cpp.o -c /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/Cells/Healthy.cpp

CMakeFiles/coculture.dir/Cells/Healthy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coculture.dir/Cells/Healthy.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/Cells/Healthy.cpp > CMakeFiles/coculture.dir/Cells/Healthy.cpp.i

CMakeFiles/coculture.dir/Cells/Healthy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coculture.dir/Cells/Healthy.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/Cells/Healthy.cpp -o CMakeFiles/coculture.dir/Cells/Healthy.cpp.s

CMakeFiles/coculture.dir/Cells/Healthy.cpp.o.requires:

.PHONY : CMakeFiles/coculture.dir/Cells/Healthy.cpp.o.requires

CMakeFiles/coculture.dir/Cells/Healthy.cpp.o.provides: CMakeFiles/coculture.dir/Cells/Healthy.cpp.o.requires
	$(MAKE) -f CMakeFiles/coculture.dir/build.make CMakeFiles/coculture.dir/Cells/Healthy.cpp.o.provides.build
.PHONY : CMakeFiles/coculture.dir/Cells/Healthy.cpp.o.provides

CMakeFiles/coculture.dir/Cells/Healthy.cpp.o.provides.build: CMakeFiles/coculture.dir/Cells/Healthy.cpp.o


CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.o: CMakeFiles/coculture.dir/flags.make
CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.o: ../Cells/Unhealthy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.o -c /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/Cells/Unhealthy.cpp

CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/Cells/Unhealthy.cpp > CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.i

CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/Cells/Unhealthy.cpp -o CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.s

CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.o.requires:

.PHONY : CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.o.requires

CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.o.provides: CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.o.requires
	$(MAKE) -f CMakeFiles/coculture.dir/build.make CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.o.provides.build
.PHONY : CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.o.provides

CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.o.provides.build: CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.o


CMakeFiles/coculture.dir/Simulation.cpp.o: CMakeFiles/coculture.dir/flags.make
CMakeFiles/coculture.dir/Simulation.cpp.o: ../Simulation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/coculture.dir/Simulation.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coculture.dir/Simulation.cpp.o -c /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/Simulation.cpp

CMakeFiles/coculture.dir/Simulation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coculture.dir/Simulation.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/Simulation.cpp > CMakeFiles/coculture.dir/Simulation.cpp.i

CMakeFiles/coculture.dir/Simulation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coculture.dir/Simulation.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/Simulation.cpp -o CMakeFiles/coculture.dir/Simulation.cpp.s

CMakeFiles/coculture.dir/Simulation.cpp.o.requires:

.PHONY : CMakeFiles/coculture.dir/Simulation.cpp.o.requires

CMakeFiles/coculture.dir/Simulation.cpp.o.provides: CMakeFiles/coculture.dir/Simulation.cpp.o.requires
	$(MAKE) -f CMakeFiles/coculture.dir/build.make CMakeFiles/coculture.dir/Simulation.cpp.o.provides.build
.PHONY : CMakeFiles/coculture.dir/Simulation.cpp.o.provides

CMakeFiles/coculture.dir/Simulation.cpp.o.provides.build: CMakeFiles/coculture.dir/Simulation.cpp.o


CMakeFiles/coculture.dir/Cells/randomGen.cpp.o: CMakeFiles/coculture.dir/flags.make
CMakeFiles/coculture.dir/Cells/randomGen.cpp.o: ../Cells/randomGen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/coculture.dir/Cells/randomGen.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coculture.dir/Cells/randomGen.cpp.o -c /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/Cells/randomGen.cpp

CMakeFiles/coculture.dir/Cells/randomGen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coculture.dir/Cells/randomGen.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/Cells/randomGen.cpp > CMakeFiles/coculture.dir/Cells/randomGen.cpp.i

CMakeFiles/coculture.dir/Cells/randomGen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coculture.dir/Cells/randomGen.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/Cells/randomGen.cpp -o CMakeFiles/coculture.dir/Cells/randomGen.cpp.s

CMakeFiles/coculture.dir/Cells/randomGen.cpp.o.requires:

.PHONY : CMakeFiles/coculture.dir/Cells/randomGen.cpp.o.requires

CMakeFiles/coculture.dir/Cells/randomGen.cpp.o.provides: CMakeFiles/coculture.dir/Cells/randomGen.cpp.o.requires
	$(MAKE) -f CMakeFiles/coculture.dir/build.make CMakeFiles/coculture.dir/Cells/randomGen.cpp.o.provides.build
.PHONY : CMakeFiles/coculture.dir/Cells/randomGen.cpp.o.provides

CMakeFiles/coculture.dir/Cells/randomGen.cpp.o.provides.build: CMakeFiles/coculture.dir/Cells/randomGen.cpp.o


# Object files for target coculture
coculture_OBJECTS = \
"CMakeFiles/coculture.dir/main.cpp.o" \
"CMakeFiles/coculture.dir/Cells/Cell.cpp.o" \
"CMakeFiles/coculture.dir/Cells/Healthy.cpp.o" \
"CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.o" \
"CMakeFiles/coculture.dir/Simulation.cpp.o" \
"CMakeFiles/coculture.dir/Cells/randomGen.cpp.o"

# External object files for target coculture
coculture_EXTERNAL_OBJECTS =

coculture: CMakeFiles/coculture.dir/main.cpp.o
coculture: CMakeFiles/coculture.dir/Cells/Cell.cpp.o
coculture: CMakeFiles/coculture.dir/Cells/Healthy.cpp.o
coculture: CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.o
coculture: CMakeFiles/coculture.dir/Simulation.cpp.o
coculture: CMakeFiles/coculture.dir/Cells/randomGen.cpp.o
coculture: CMakeFiles/coculture.dir/build.make
coculture: CMakeFiles/coculture.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable coculture"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/coculture.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/coculture.dir/build: coculture

.PHONY : CMakeFiles/coculture.dir/build

CMakeFiles/coculture.dir/requires: CMakeFiles/coculture.dir/main.cpp.o.requires
CMakeFiles/coculture.dir/requires: CMakeFiles/coculture.dir/Cells/Cell.cpp.o.requires
CMakeFiles/coculture.dir/requires: CMakeFiles/coculture.dir/Cells/Healthy.cpp.o.requires
CMakeFiles/coculture.dir/requires: CMakeFiles/coculture.dir/Cells/Unhealthy.cpp.o.requires
CMakeFiles/coculture.dir/requires: CMakeFiles/coculture.dir/Simulation.cpp.o.requires
CMakeFiles/coculture.dir/requires: CMakeFiles/coculture.dir/Cells/randomGen.cpp.o.requires

.PHONY : CMakeFiles/coculture.dir/requires

CMakeFiles/coculture.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/coculture.dir/cmake_clean.cmake
.PHONY : CMakeFiles/coculture.dir/clean

CMakeFiles/coculture.dir/depend:
	cd /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/cmake-build-debug /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/cmake-build-debug /Users/AlbertoSerrano/Documents/college/courses/y3summer/code/coculture/cmake-build-debug/CMakeFiles/coculture.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/coculture.dir/depend

