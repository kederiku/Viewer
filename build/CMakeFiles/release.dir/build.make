# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /afs/.gpp.isartdigital.com/user/all/delagr_c/rendu/Viewer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /afs/.gpp.isartdigital.com/user/all/delagr_c/rendu/Viewer/build

# Utility rule file for release.

# Include the progress variables for this target.
include CMakeFiles/release.dir/progress.make

CMakeFiles/release:
	$(CMAKE_COMMAND) -E cmake_progress_report /afs/.gpp.isartdigital.com/user/all/delagr_c/rendu/Viewer/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Releasing lib2D"

release: CMakeFiles/release
release: CMakeFiles/release.dir/build.make
	cmake . -DCMAKE_BUILD_TYPE:STRING=Release
	make distclean
	make
.PHONY : release

# Rule to build all files generated by this target.
CMakeFiles/release.dir/build: release
.PHONY : CMakeFiles/release.dir/build

CMakeFiles/release.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/release.dir/cmake_clean.cmake
.PHONY : CMakeFiles/release.dir/clean

CMakeFiles/release.dir/depend:
	cd /afs/.gpp.isartdigital.com/user/all/delagr_c/rendu/Viewer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /afs/.gpp.isartdigital.com/user/all/delagr_c/rendu/Viewer /afs/.gpp.isartdigital.com/user/all/delagr_c/rendu/Viewer /afs/.gpp.isartdigital.com/user/all/delagr_c/rendu/Viewer/build /afs/.gpp.isartdigital.com/user/all/delagr_c/rendu/Viewer/build /afs/.gpp.isartdigital.com/user/all/delagr_c/rendu/Viewer/build/CMakeFiles/release.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/release.dir/depend

