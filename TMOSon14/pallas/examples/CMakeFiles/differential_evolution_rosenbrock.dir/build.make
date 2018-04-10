# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/pavel/Dokumenty/pallas-solver-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pavel/Dokumenty/pallas-solver-master

# Include any dependencies generated for this target.
include examples/CMakeFiles/differential_evolution_rosenbrock.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/differential_evolution_rosenbrock.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/differential_evolution_rosenbrock.dir/flags.make

examples/CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.o: examples/CMakeFiles/differential_evolution_rosenbrock.dir/flags.make
examples/CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.o: examples/differential_evolution_rosenbrock.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pavel/Dokumenty/pallas-solver-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.o"
	cd /home/pavel/Dokumenty/pallas-solver-master/examples && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.o -c /home/pavel/Dokumenty/pallas-solver-master/examples/differential_evolution_rosenbrock.cc

examples/CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.i"
	cd /home/pavel/Dokumenty/pallas-solver-master/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pavel/Dokumenty/pallas-solver-master/examples/differential_evolution_rosenbrock.cc > CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.i

examples/CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.s"
	cd /home/pavel/Dokumenty/pallas-solver-master/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pavel/Dokumenty/pallas-solver-master/examples/differential_evolution_rosenbrock.cc -o CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.s

examples/CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.o.requires:

.PHONY : examples/CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.o.requires

examples/CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.o.provides: examples/CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.o.requires
	$(MAKE) -f examples/CMakeFiles/differential_evolution_rosenbrock.dir/build.make examples/CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.o.provides.build
.PHONY : examples/CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.o.provides

examples/CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.o.provides.build: examples/CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.o


# Object files for target differential_evolution_rosenbrock
differential_evolution_rosenbrock_OBJECTS = \
"CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.o"

# External object files for target differential_evolution_rosenbrock
differential_evolution_rosenbrock_EXTERNAL_OBJECTS =

bin/differential_evolution_rosenbrock: examples/CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.o
bin/differential_evolution_rosenbrock: examples/CMakeFiles/differential_evolution_rosenbrock.dir/build.make
bin/differential_evolution_rosenbrock: lib/libpallas.a
bin/differential_evolution_rosenbrock: /usr/local/lib/libceres.a
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libgflags.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libspqr.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libtbbmalloc.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libtbb.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libcholmod.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libccolamd.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libcamd.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libcolamd.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libamd.so
bin/differential_evolution_rosenbrock: /usr/lib/liblapack.so
bin/differential_evolution_rosenbrock: /usr/lib/libf77blas.so
bin/differential_evolution_rosenbrock: /usr/lib/libatlas.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libsuitesparseconfig.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/librt.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libcxsparse.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libspqr.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libtbbmalloc.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libtbb.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libcholmod.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libccolamd.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libcamd.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libcolamd.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libamd.so
bin/differential_evolution_rosenbrock: /usr/lib/liblapack.so
bin/differential_evolution_rosenbrock: /usr/lib/libf77blas.so
bin/differential_evolution_rosenbrock: /usr/lib/libatlas.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libsuitesparseconfig.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/librt.so
bin/differential_evolution_rosenbrock: /usr/lib/x86_64-linux-gnu/libcxsparse.so
bin/differential_evolution_rosenbrock: /usr/local/lib/libglog.so
bin/differential_evolution_rosenbrock: examples/CMakeFiles/differential_evolution_rosenbrock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pavel/Dokumenty/pallas-solver-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/differential_evolution_rosenbrock"
	cd /home/pavel/Dokumenty/pallas-solver-master/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/differential_evolution_rosenbrock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/differential_evolution_rosenbrock.dir/build: bin/differential_evolution_rosenbrock

.PHONY : examples/CMakeFiles/differential_evolution_rosenbrock.dir/build

examples/CMakeFiles/differential_evolution_rosenbrock.dir/requires: examples/CMakeFiles/differential_evolution_rosenbrock.dir/differential_evolution_rosenbrock.cc.o.requires

.PHONY : examples/CMakeFiles/differential_evolution_rosenbrock.dir/requires

examples/CMakeFiles/differential_evolution_rosenbrock.dir/clean:
	cd /home/pavel/Dokumenty/pallas-solver-master/examples && $(CMAKE_COMMAND) -P CMakeFiles/differential_evolution_rosenbrock.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/differential_evolution_rosenbrock.dir/clean

examples/CMakeFiles/differential_evolution_rosenbrock.dir/depend:
	cd /home/pavel/Dokumenty/pallas-solver-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pavel/Dokumenty/pallas-solver-master /home/pavel/Dokumenty/pallas-solver-master/examples /home/pavel/Dokumenty/pallas-solver-master /home/pavel/Dokumenty/pallas-solver-master/examples /home/pavel/Dokumenty/pallas-solver-master/examples/CMakeFiles/differential_evolution_rosenbrock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/differential_evolution_rosenbrock.dir/depend

