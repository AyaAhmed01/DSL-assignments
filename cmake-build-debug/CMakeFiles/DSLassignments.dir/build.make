# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Go\Desktop\Third year (isa)\Algorithms\DSL assignments"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Go\Desktop\Third year (isa)\Algorithms\DSL assignments\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/DSLassignments.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DSLassignments.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DSLassignments.dir/flags.make

CMakeFiles/DSLassignments.dir/dynamic_programming/knapsack_with_repetition.cpp.obj: CMakeFiles/DSLassignments.dir/flags.make
CMakeFiles/DSLassignments.dir/dynamic_programming/knapsack_with_repetition.cpp.obj: ../dynamic\ programming/knapsack_with_repetition.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Go\Desktop\Third year (isa)\Algorithms\DSL assignments\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DSLassignments.dir/dynamic_programming/knapsack_with_repetition.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DSLassignments.dir\dynamic_programming\knapsack_with_repetition.cpp.obj -c "C:\Users\Go\Desktop\Third year (isa)\Algorithms\DSL assignments\dynamic programming\knapsack_with_repetition.cpp"

CMakeFiles/DSLassignments.dir/dynamic_programming/knapsack_with_repetition.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DSLassignments.dir/dynamic_programming/knapsack_with_repetition.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Go\Desktop\Third year (isa)\Algorithms\DSL assignments\dynamic programming\knapsack_with_repetition.cpp" > CMakeFiles\DSLassignments.dir\dynamic_programming\knapsack_with_repetition.cpp.i

CMakeFiles/DSLassignments.dir/dynamic_programming/knapsack_with_repetition.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DSLassignments.dir/dynamic_programming/knapsack_with_repetition.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Go\Desktop\Third year (isa)\Algorithms\DSL assignments\dynamic programming\knapsack_with_repetition.cpp" -o CMakeFiles\DSLassignments.dir\dynamic_programming\knapsack_with_repetition.cpp.s

# Object files for target DSLassignments
DSLassignments_OBJECTS = \
"CMakeFiles/DSLassignments.dir/dynamic_programming/knapsack_with_repetition.cpp.obj"

# External object files for target DSLassignments
DSLassignments_EXTERNAL_OBJECTS =

DSLassignments.exe: CMakeFiles/DSLassignments.dir/dynamic_programming/knapsack_with_repetition.cpp.obj
DSLassignments.exe: CMakeFiles/DSLassignments.dir/build.make
DSLassignments.exe: CMakeFiles/DSLassignments.dir/linklibs.rsp
DSLassignments.exe: CMakeFiles/DSLassignments.dir/objects1.rsp
DSLassignments.exe: CMakeFiles/DSLassignments.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Go\Desktop\Third year (isa)\Algorithms\DSL assignments\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DSLassignments.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DSLassignments.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DSLassignments.dir/build: DSLassignments.exe

.PHONY : CMakeFiles/DSLassignments.dir/build

CMakeFiles/DSLassignments.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DSLassignments.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DSLassignments.dir/clean

CMakeFiles/DSLassignments.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Go\Desktop\Third year (isa)\Algorithms\DSL assignments" "C:\Users\Go\Desktop\Third year (isa)\Algorithms\DSL assignments" "C:\Users\Go\Desktop\Third year (isa)\Algorithms\DSL assignments\cmake-build-debug" "C:\Users\Go\Desktop\Third year (isa)\Algorithms\DSL assignments\cmake-build-debug" "C:\Users\Go\Desktop\Third year (isa)\Algorithms\DSL assignments\cmake-build-debug\CMakeFiles\DSLassignments.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/DSLassignments.dir/depend

