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
include examples/CMakeFiles/models_loading.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/models_loading.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/models_loading.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/models_loading.dir/flags.make

examples/CMakeFiles/models_loading.dir/codegen:
.PHONY : examples/CMakeFiles/models_loading.dir/codegen

examples/CMakeFiles/models_loading.dir/models/models_loading.c.obj: examples/CMakeFiles/models_loading.dir/flags.make
examples/CMakeFiles/models_loading.dir/models/models_loading.c.obj: examples/CMakeFiles/models_loading.dir/includes_C.rsp
examples/CMakeFiles/models_loading.dir/models/models_loading.c.obj: C:/Users/Ian/Desktop/Game-Jams/Shovel_2025_Jam/raylib/examples/models/models_loading.c
examples/CMakeFiles/models_loading.dir/models/models_loading.c.obj: examples/CMakeFiles/models_loading.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/models_loading.dir/models/models_loading.c.obj"
	cd /d C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples && C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/models_loading.dir/models/models_loading.c.obj -MF CMakeFiles\models_loading.dir\models\models_loading.c.obj.d -o CMakeFiles\models_loading.dir\models\models_loading.c.obj -c C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib\examples\models\models_loading.c

examples/CMakeFiles/models_loading.dir/models/models_loading.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/models_loading.dir/models/models_loading.c.i"
	cd /d C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples && C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib\examples\models\models_loading.c > CMakeFiles\models_loading.dir\models\models_loading.c.i

examples/CMakeFiles/models_loading.dir/models/models_loading.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/models_loading.dir/models/models_loading.c.s"
	cd /d C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples && C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib\examples\models\models_loading.c -o CMakeFiles\models_loading.dir\models\models_loading.c.s

# Object files for target models_loading
models_loading_OBJECTS = \
"CMakeFiles/models_loading.dir/models/models_loading.c.obj"

# External object files for target models_loading
models_loading_EXTERNAL_OBJECTS =

examples/models_loading.exe: examples/CMakeFiles/models_loading.dir/models/models_loading.c.obj
examples/models_loading.exe: examples/CMakeFiles/models_loading.dir/build.make
examples/models_loading.exe: raylib/libraylib.a
examples/models_loading.exe: examples/CMakeFiles/models_loading.dir/linkLibs.rsp
examples/models_loading.exe: examples/CMakeFiles/models_loading.dir/objects1.rsp
examples/models_loading.exe: examples/CMakeFiles/models_loading.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable models_loading.exe"
	cd /d C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\models_loading.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/models_loading.dir/build: examples/models_loading.exe
.PHONY : examples/CMakeFiles/models_loading.dir/build

examples/CMakeFiles/models_loading.dir/clean:
	cd /d C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples && $(CMAKE_COMMAND) -P CMakeFiles\models_loading.dir\cmake_clean.cmake
.PHONY : examples/CMakeFiles/models_loading.dir/clean

examples/CMakeFiles/models_loading.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\raylib\examples C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples C:\Users\Ian\Desktop\Game-Jams\Shovel_2025_Jam\build\examples\CMakeFiles\models_loading.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : examples/CMakeFiles/models_loading.dir/depend

