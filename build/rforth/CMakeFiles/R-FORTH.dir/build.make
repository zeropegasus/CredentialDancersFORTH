# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sophiahoman/Desktop/CredentialDancersFORTH

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sophiahoman/Desktop/CredentialDancersFORTH/build

# Include any dependencies generated for this target.
include rforth/CMakeFiles/R-FORTH.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include rforth/CMakeFiles/R-FORTH.dir/compiler_depend.make

# Include the progress variables for this target.
include rforth/CMakeFiles/R-FORTH.dir/progress.make

# Include the compile flags for this target's objects.
include rforth/CMakeFiles/R-FORTH.dir/flags.make

rforth/CMakeFiles/R-FORTH.dir/main.c.o: rforth/CMakeFiles/R-FORTH.dir/flags.make
rforth/CMakeFiles/R-FORTH.dir/main.c.o: /Users/sophiahoman/Desktop/CredentialDancersFORTH/rforth/main.c
rforth/CMakeFiles/R-FORTH.dir/main.c.o: rforth/CMakeFiles/R-FORTH.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/sophiahoman/Desktop/CredentialDancersFORTH/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object rforth/CMakeFiles/R-FORTH.dir/main.c.o"
	cd /Users/sophiahoman/Desktop/CredentialDancersFORTH/build/rforth && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT rforth/CMakeFiles/R-FORTH.dir/main.c.o -MF CMakeFiles/R-FORTH.dir/main.c.o.d -o CMakeFiles/R-FORTH.dir/main.c.o -c /Users/sophiahoman/Desktop/CredentialDancersFORTH/rforth/main.c

rforth/CMakeFiles/R-FORTH.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/R-FORTH.dir/main.c.i"
	cd /Users/sophiahoman/Desktop/CredentialDancersFORTH/build/rforth && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sophiahoman/Desktop/CredentialDancersFORTH/rforth/main.c > CMakeFiles/R-FORTH.dir/main.c.i

rforth/CMakeFiles/R-FORTH.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/R-FORTH.dir/main.c.s"
	cd /Users/sophiahoman/Desktop/CredentialDancersFORTH/build/rforth && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sophiahoman/Desktop/CredentialDancersFORTH/rforth/main.c -o CMakeFiles/R-FORTH.dir/main.c.s

rforth/CMakeFiles/R-FORTH.dir/token.c.o: rforth/CMakeFiles/R-FORTH.dir/flags.make
rforth/CMakeFiles/R-FORTH.dir/token.c.o: /Users/sophiahoman/Desktop/CredentialDancersFORTH/rforth/token.c
rforth/CMakeFiles/R-FORTH.dir/token.c.o: rforth/CMakeFiles/R-FORTH.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/sophiahoman/Desktop/CredentialDancersFORTH/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object rforth/CMakeFiles/R-FORTH.dir/token.c.o"
	cd /Users/sophiahoman/Desktop/CredentialDancersFORTH/build/rforth && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT rforth/CMakeFiles/R-FORTH.dir/token.c.o -MF CMakeFiles/R-FORTH.dir/token.c.o.d -o CMakeFiles/R-FORTH.dir/token.c.o -c /Users/sophiahoman/Desktop/CredentialDancersFORTH/rforth/token.c

rforth/CMakeFiles/R-FORTH.dir/token.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/R-FORTH.dir/token.c.i"
	cd /Users/sophiahoman/Desktop/CredentialDancersFORTH/build/rforth && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sophiahoman/Desktop/CredentialDancersFORTH/rforth/token.c > CMakeFiles/R-FORTH.dir/token.c.i

rforth/CMakeFiles/R-FORTH.dir/token.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/R-FORTH.dir/token.c.s"
	cd /Users/sophiahoman/Desktop/CredentialDancersFORTH/build/rforth && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sophiahoman/Desktop/CredentialDancersFORTH/rforth/token.c -o CMakeFiles/R-FORTH.dir/token.c.s

rforth/CMakeFiles/R-FORTH.dir/int_stack.c.o: rforth/CMakeFiles/R-FORTH.dir/flags.make
rforth/CMakeFiles/R-FORTH.dir/int_stack.c.o: /Users/sophiahoman/Desktop/CredentialDancersFORTH/rforth/int_stack.c
rforth/CMakeFiles/R-FORTH.dir/int_stack.c.o: rforth/CMakeFiles/R-FORTH.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/sophiahoman/Desktop/CredentialDancersFORTH/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object rforth/CMakeFiles/R-FORTH.dir/int_stack.c.o"
	cd /Users/sophiahoman/Desktop/CredentialDancersFORTH/build/rforth && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT rforth/CMakeFiles/R-FORTH.dir/int_stack.c.o -MF CMakeFiles/R-FORTH.dir/int_stack.c.o.d -o CMakeFiles/R-FORTH.dir/int_stack.c.o -c /Users/sophiahoman/Desktop/CredentialDancersFORTH/rforth/int_stack.c

rforth/CMakeFiles/R-FORTH.dir/int_stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/R-FORTH.dir/int_stack.c.i"
	cd /Users/sophiahoman/Desktop/CredentialDancersFORTH/build/rforth && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sophiahoman/Desktop/CredentialDancersFORTH/rforth/int_stack.c > CMakeFiles/R-FORTH.dir/int_stack.c.i

rforth/CMakeFiles/R-FORTH.dir/int_stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/R-FORTH.dir/int_stack.c.s"
	cd /Users/sophiahoman/Desktop/CredentialDancersFORTH/build/rforth && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sophiahoman/Desktop/CredentialDancersFORTH/rforth/int_stack.c -o CMakeFiles/R-FORTH.dir/int_stack.c.s

# Object files for target R-FORTH
R__FORTH_OBJECTS = \
"CMakeFiles/R-FORTH.dir/main.c.o" \
"CMakeFiles/R-FORTH.dir/token.c.o" \
"CMakeFiles/R-FORTH.dir/int_stack.c.o"

# External object files for target R-FORTH
R__FORTH_EXTERNAL_OBJECTS =

bin/R-FORTH: rforth/CMakeFiles/R-FORTH.dir/main.c.o
bin/R-FORTH: rforth/CMakeFiles/R-FORTH.dir/token.c.o
bin/R-FORTH: rforth/CMakeFiles/R-FORTH.dir/int_stack.c.o
bin/R-FORTH: rforth/CMakeFiles/R-FORTH.dir/build.make
bin/R-FORTH: rforth/CMakeFiles/R-FORTH.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/sophiahoman/Desktop/CredentialDancersFORTH/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable ../bin/R-FORTH"
	cd /Users/sophiahoman/Desktop/CredentialDancersFORTH/build/rforth && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/R-FORTH.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
rforth/CMakeFiles/R-FORTH.dir/build: bin/R-FORTH
.PHONY : rforth/CMakeFiles/R-FORTH.dir/build

rforth/CMakeFiles/R-FORTH.dir/clean:
	cd /Users/sophiahoman/Desktop/CredentialDancersFORTH/build/rforth && $(CMAKE_COMMAND) -P CMakeFiles/R-FORTH.dir/cmake_clean.cmake
.PHONY : rforth/CMakeFiles/R-FORTH.dir/clean

rforth/CMakeFiles/R-FORTH.dir/depend:
	cd /Users/sophiahoman/Desktop/CredentialDancersFORTH/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sophiahoman/Desktop/CredentialDancersFORTH /Users/sophiahoman/Desktop/CredentialDancersFORTH/rforth /Users/sophiahoman/Desktop/CredentialDancersFORTH/build /Users/sophiahoman/Desktop/CredentialDancersFORTH/build/rforth /Users/sophiahoman/Desktop/CredentialDancersFORTH/build/rforth/CMakeFiles/R-FORTH.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : rforth/CMakeFiles/R-FORTH.dir/depend

