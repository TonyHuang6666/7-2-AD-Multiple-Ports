# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = C:\Users\Wendo\.vcpkg\artifacts\vcpkg-ce-default\tools.kitware.cmake\3.25.2\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Wendo\.vcpkg\artifacts\vcpkg-ce-default\tools.kitware.cmake\3.25.2\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\OneDrive - email.szu.edu.cn\Codes\Github insiders\Examples\7-1 AD\tmp\Project\Target_1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\OneDrive - email.szu.edu.cn\Codes\Github insiders\Examples\7-1 AD\build"

# Utility rule file for database.

# Include any custom commands dependencies for this target.
include CMakeFiles/database.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/database.dir/progress.make

CMakeFiles/database:
	C:\Users\Wendo\.vcpkg\artifacts\vcpkg-ce-default\tools.kitware.cmake\3.25.2\bin\cmake.exe -E copy_if_different "D:/OneDrive - email.szu.edu.cn/Codes/Github insiders/Examples/7-1 AD/tmp/Project/Target_1/compile_commands.json" "D:/OneDrive - email.szu.edu.cn/Codes/Github insiders/Examples/7-1 AD/out/Project/Target_1"

database: CMakeFiles/database
database: CMakeFiles/database.dir/build.make
.PHONY : database

# Rule to build all files generated by this target.
CMakeFiles/database.dir/build: database
.PHONY : CMakeFiles/database.dir/build

CMakeFiles/database.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\database.dir\cmake_clean.cmake
.PHONY : CMakeFiles/database.dir/clean

CMakeFiles/database.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\OneDrive - email.szu.edu.cn\Codes\Github insiders\Examples\7-1 AD\tmp\Project\Target_1" "D:\OneDrive - email.szu.edu.cn\Codes\Github insiders\Examples\7-1 AD\tmp\Project\Target_1" "D:\OneDrive - email.szu.edu.cn\Codes\Github insiders\Examples\7-1 AD\build" "D:\OneDrive - email.szu.edu.cn\Codes\Github insiders\Examples\7-1 AD\build" "D:\OneDrive - email.szu.edu.cn\Codes\Github insiders\Examples\7-1 AD\build\CMakeFiles\database.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/database.dir/depend

