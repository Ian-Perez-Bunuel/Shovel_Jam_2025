# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 4.0

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\msys64\ucrt64\bin\cmake.exe

# The command to remove a file.
RM = C:\msys64\ucrt64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build

# Include any dependencies generated for this target.
include examples/CMakeFiles/shapes_basic_shapes.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/shapes_basic_shapes.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/shapes_basic_shapes.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/shapes_basic_shapes.dir/flags.make

examples/CMakeFiles/shapes_basic_shapes.dir/codegen:
.PHONY : examples/CMakeFiles/shapes_basic_shapes.dir/codegen

examples/CMakeFiles/shapes_basic_shapes.dir/shapes/shapes_basic_shapes.c.obj: examples/CMakeFiles/shapes_basic_shapes.dir/flags.make
examples/CMakeFiles/shapes_basic_shapes.dir/shapes/shapes_basic_shapes.c.obj: examples/CMakeFiles/shapes_basic_shapes.dir/includes_C.rsp
examples/CMakeFiles/shapes_basic_shapes.dir/shapes/shapes_basic_shapes.c.obj: C:/Users/Ian/Desktop/Game-Jams/Shovel_2025_Jam/raylib/examples/shapes/shapes_basic_shapes.c
examples/CMakeFiles/shapes_basic_shapes.dir/shapes/shapes_basic_shapes.c.obj: examples/CMakeFiles/shapes_basic_shapes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/shapes_basic_shapes.dir/shapes/shapes_basic_shapes.c.obj"
	cd /d C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples && C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/shapes_basic_shapes.dir/shapes/shapes_basic_shapes.c.obj -MF CMakeFiles\shapes_basic_shapes.dir\shapes\shapes_basic_shapes.c.obj.d -o CMakeFiles\shapes_basic_shapes.dir\shapes\shapes_basic_shapes.c.obj -c C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib\examples\shapes\shapes_basic_shapes.c

examples/CMakeFiles/shapes_basic_shapes.dir/shapes/shapes_basic_shapes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/shapes_basic_shapes.dir/shapes/shapes_basic_shapes.c.i"
	cd /d C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples && C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib\examples\shapes\shapes_basic_shapes.c > CMakeFiles\shapes_basic_shapes.dir\shapes\shapes_basic_shapes.c.i

examples/CMakeFiles/shapes_basic_shapes.dir/shapes/shapes_basic_shapes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/shapes_basic_shapes.dir/shapes/shapes_basic_shapes.c.s"
	cd /d C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples && C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib\examples\shapes\shapes_basic_shapes.c -o CMakeFiles\shapes_basic_shapes.dir\shapes\shapes_basic_shapes.c.s

# Object files for target shapes_basic_shapes
shapes_basic_shapes_OBJECTS = \
"CMakeFiles/shapes_basic_shapes.dir/shapes/shapes_basic_shapes.c.obj"

# External object files for target shapes_basic_shapes
shapes_basic_shapes_EXTERNAL_OBJECTS =

examples/shapes_basic_shapes.exe: examples/CMakeFiles/shapes_basic_shapes.dir/shapes/shapes_basic_shapes.c.obj
examples/shapes_basic_shapes.exe: examples/CMakeFiles/shapes_basic_shapes.dir/build.make
examples/shapes_basic_shapes.exe: raylib/libraylib.a
examples/shapes_basic_shapes.exe: examples/CMakeFiles/shapes_basic_shapes.dir/linkLibs.rsp
examples/shapes_basic_shapes.exe: examples/CMakeFiles/shapes_basic_shapes.dir/objects1.rsp
examples/shapes_basic_shapes.exe: examples/CMakeFiles/shapes_basic_shapes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable shapes_basic_shapes.exe"
	cd /d C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\shapes_basic_shapes.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/shapes_basic_shapes.dir/build: examples/shapes_basic_shapes.exe
.PHONY : examples/CMakeFiles/shapes_basic_shapes.dir/build

examples/CMakeFiles/shapes_basic_shapes.dir/clean:
	cd /d C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples && $(CMAKE_COMMAND) -P CMakeFiles\shapes_basic_shapes.dir\cmake_clean.cmake
.PHONY : examples/CMakeFiles/shapes_basic_shapes.dir/clean

examples/CMakeFiles/shapes_basic_shapes.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib\examples C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples\CMakeFiles\shapes_basic_shapes.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : examples/CMakeFiles/shapes_basic_shapes.dir/depend

