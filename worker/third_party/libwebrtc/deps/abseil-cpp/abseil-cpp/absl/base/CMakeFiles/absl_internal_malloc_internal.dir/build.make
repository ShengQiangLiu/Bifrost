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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/admin/go/src/github.com/Bifrost/worker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/admin/go/src/github.com/Bifrost/worker

# Include any dependencies generated for this target.
include third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/compiler_depend.make

# Include the progress variables for this target.
include third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/progress.make

# Include the compile flags for this target's objects.
include third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/flags.make

third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/internal/low_level_alloc.cc.o: third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/flags.make
third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/internal/low_level_alloc.cc.o: third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/internal/low_level_alloc.cc
third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/internal/low_level_alloc.cc.o: third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/admin/go/src/github.com/Bifrost/worker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/internal/low_level_alloc.cc.o"
	cd /Users/admin/go/src/github.com/Bifrost/worker/third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/internal/low_level_alloc.cc.o -MF CMakeFiles/absl_internal_malloc_internal.dir/internal/low_level_alloc.cc.o.d -o CMakeFiles/absl_internal_malloc_internal.dir/internal/low_level_alloc.cc.o -c /Users/admin/go/src/github.com/Bifrost/worker/third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/internal/low_level_alloc.cc

third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/internal/low_level_alloc.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/absl_internal_malloc_internal.dir/internal/low_level_alloc.cc.i"
	cd /Users/admin/go/src/github.com/Bifrost/worker/third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/admin/go/src/github.com/Bifrost/worker/third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/internal/low_level_alloc.cc > CMakeFiles/absl_internal_malloc_internal.dir/internal/low_level_alloc.cc.i

third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/internal/low_level_alloc.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/absl_internal_malloc_internal.dir/internal/low_level_alloc.cc.s"
	cd /Users/admin/go/src/github.com/Bifrost/worker/third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/admin/go/src/github.com/Bifrost/worker/third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/internal/low_level_alloc.cc -o CMakeFiles/absl_internal_malloc_internal.dir/internal/low_level_alloc.cc.s

# Object files for target absl_internal_malloc_internal
absl_internal_malloc_internal_OBJECTS = \
"CMakeFiles/absl_internal_malloc_internal.dir/internal/low_level_alloc.cc.o"

# External object files for target absl_internal_malloc_internal
absl_internal_malloc_internal_EXTERNAL_OBJECTS =

third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/libabsl_internal_malloc_internal.a: third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/internal/low_level_alloc.cc.o
third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/libabsl_internal_malloc_internal.a: third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/build.make
third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/libabsl_internal_malloc_internal.a: third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/admin/go/src/github.com/Bifrost/worker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libabsl_internal_malloc_internal.a"
	cd /Users/admin/go/src/github.com/Bifrost/worker/third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base && $(CMAKE_COMMAND) -P CMakeFiles/absl_internal_malloc_internal.dir/cmake_clean_target.cmake
	cd /Users/admin/go/src/github.com/Bifrost/worker/third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/absl_internal_malloc_internal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/build: third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/libabsl_internal_malloc_internal.a
.PHONY : third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/build

third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/clean:
	cd /Users/admin/go/src/github.com/Bifrost/worker/third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base && $(CMAKE_COMMAND) -P CMakeFiles/absl_internal_malloc_internal.dir/cmake_clean.cmake
.PHONY : third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/clean

third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/depend:
	cd /Users/admin/go/src/github.com/Bifrost/worker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/admin/go/src/github.com/Bifrost/worker /Users/admin/go/src/github.com/Bifrost/worker/third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base /Users/admin/go/src/github.com/Bifrost/worker /Users/admin/go/src/github.com/Bifrost/worker/third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base /Users/admin/go/src/github.com/Bifrost/worker/third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : third_party/libwebrtc/deps/abseil-cpp/abseil-cpp/absl/base/CMakeFiles/absl_internal_malloc_internal.dir/depend

