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
include examples/CMakeFiles/models_mesh_picking.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/models_mesh_picking.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/models_mesh_picking.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/models_mesh_picking.dir/flags.make

examples/CMakeFiles/models_mesh_picking.dir/codegen:
.PHONY : examples/CMakeFiles/models_mesh_picking.dir/codegen

examples/CMakeFiles/models_mesh_picking.dir/models/models_mesh_picking.c.obj: examples/CMakeFiles/models_mesh_picking.dir/flags.make
examples/CMakeFiles/models_mesh_picking.dir/models/models_mesh_picking.c.obj: examples/CMakeFiles/models_mesh_picking.dir/includes_C.rsp
examples/CMakeFiles/models_mesh_picking.dir/models/models_mesh_picking.c.obj: C:/Users/Ian/Desktop/Game-Jams/Shovel_2025_Jam/raylib/examples/models/models_mesh_picking.c
examples/CMakeFiles/models_mesh_picking.dir/models/models_mesh_picking.c.obj: examples/CMakeFiles/models_mesh_picking.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/models_mesh_picking.dir/models/models_mesh_picking.c.obj"
	cd /d C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples && C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/models_mesh_picking.dir/models/models_mesh_picking.c.obj -MF CMakeFiles\models_mesh_picking.dir\models\models_mesh_picking.c.obj.d -o CMakeFiles\models_mesh_picking.dir\models\models_mesh_picking.c.obj -c C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib\examples\models\models_mesh_picking.c

examples/CMakeFiles/models_mesh_picking.dir/models/models_mesh_picking.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/models_mesh_picking.dir/models/models_mesh_picking.c.i"
	cd /d C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples && C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib\examples\models\models_mesh_picking.c > CMakeFiles\models_mesh_picking.dir\models\models_mesh_picking.c.i

examples/CMakeFiles/models_mesh_picking.dir/models/models_mesh_picking.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/models_mesh_picking.dir/models/models_mesh_picking.c.s"
	cd /d C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples && C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib\examples\models\models_mesh_picking.c -o CMakeFiles\models_mesh_picking.dir\models\models_mesh_picking.c.s

# Object files for target models_mesh_picking
models_mesh_picking_OBJECTS = \
"CMakeFiles/models_mesh_picking.dir/models/models_mesh_picking.c.obj"

# External object files for target models_mesh_picking
models_mesh_picking_EXTERNAL_OBJECTS =

examples/models_mesh_picking.exe: examples/CMakeFiles/models_mesh_picking.dir/models/models_mesh_picking.c.obj
examples/models_mesh_picking.exe: examples/CMakeFiles/models_mesh_picking.dir/build.make
examples/models_mesh_picking.exe: raylib/libraylib.a
examples/models_mesh_picking.exe: examples/CMakeFiles/models_mesh_picking.dir/linkLibs.rsp
examples/models_mesh_picking.exe: examples/CMakeFiles/models_mesh_picking.dir/objects1.rsp
examples/models_mesh_picking.exe: examples/CMakeFiles/models_mesh_picking.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable models_mesh_picking.exe"
	cd /d C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\models_mesh_picking.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/models_mesh_picking.dir/build: examples/models_mesh_picking.exe
.PHONY : examples/CMakeFiles/models_mesh_picking.dir/build

examples/CMakeFiles/models_mesh_picking.dir/clean:
	cd /d C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples && $(CMAKE_COMMAND) -P CMakeFiles\models_mesh_picking.dir\cmake_clean.cmake
.PHONY : examples/CMakeFiles/models_mesh_picking.dir/clean

examples/CMakeFiles/models_mesh_picking.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib\examples C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples\CMakeFiles\models_mesh_picking.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : examples/CMakeFiles/models_mesh_picking.dir/depend

