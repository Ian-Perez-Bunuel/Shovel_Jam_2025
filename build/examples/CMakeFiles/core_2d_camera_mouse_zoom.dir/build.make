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
include examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/flags.make

examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/codegen:
.PHONY : examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/codegen

examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/core/core_2d_camera_mouse_zoom.c.obj: examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/flags.make
examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/core/core_2d_camera_mouse_zoom.c.obj: examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/includes_C.rsp
examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/core/core_2d_camera_mouse_zoom.c.obj: C:/Users/Ian/Desktop/Game-Jams/Shovel_2025_Jam/raylib/examples/core/core_2d_camera_mouse_zoom.c
examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/core/core_2d_camera_mouse_zoom.c.obj: examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/core/core_2d_camera_mouse_zoom.c.obj"
	cd /d C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples && C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/core/core_2d_camera_mouse_zoom.c.obj -MF CMakeFiles\core_2d_camera_mouse_zoom.dir\core\core_2d_camera_mouse_zoom.c.obj.d -o CMakeFiles\core_2d_camera_mouse_zoom.dir\core\core_2d_camera_mouse_zoom.c.obj -c C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib\examples\core\core_2d_camera_mouse_zoom.c

examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/core/core_2d_camera_mouse_zoom.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/core_2d_camera_mouse_zoom.dir/core/core_2d_camera_mouse_zoom.c.i"
	cd /d C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples && C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib\examples\core\core_2d_camera_mouse_zoom.c > CMakeFiles\core_2d_camera_mouse_zoom.dir\core\core_2d_camera_mouse_zoom.c.i

examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/core/core_2d_camera_mouse_zoom.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/core_2d_camera_mouse_zoom.dir/core/core_2d_camera_mouse_zoom.c.s"
	cd /d C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples && C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib\examples\core\core_2d_camera_mouse_zoom.c -o CMakeFiles\core_2d_camera_mouse_zoom.dir\core\core_2d_camera_mouse_zoom.c.s

# Object files for target core_2d_camera_mouse_zoom
core_2d_camera_mouse_zoom_OBJECTS = \
"CMakeFiles/core_2d_camera_mouse_zoom.dir/core/core_2d_camera_mouse_zoom.c.obj"

# External object files for target core_2d_camera_mouse_zoom
core_2d_camera_mouse_zoom_EXTERNAL_OBJECTS =

examples/core_2d_camera_mouse_zoom.exe: examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/core/core_2d_camera_mouse_zoom.c.obj
examples/core_2d_camera_mouse_zoom.exe: examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/build.make
examples/core_2d_camera_mouse_zoom.exe: raylib/libraylib.a
examples/core_2d_camera_mouse_zoom.exe: examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/linkLibs.rsp
examples/core_2d_camera_mouse_zoom.exe: examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/objects1.rsp
examples/core_2d_camera_mouse_zoom.exe: examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable core_2d_camera_mouse_zoom.exe"
	cd /d C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\core_2d_camera_mouse_zoom.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/build: examples/core_2d_camera_mouse_zoom.exe
.PHONY : examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/build

examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/clean:
	cd /d C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples && $(CMAKE_COMMAND) -P CMakeFiles\core_2d_camera_mouse_zoom.dir\cmake_clean.cmake
.PHONY : examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/clean

examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib\examples C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples\CMakeFiles\core_2d_camera_mouse_zoom.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : examples/CMakeFiles/core_2d_camera_mouse_zoom.dir/depend

