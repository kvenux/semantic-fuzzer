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
CMAKE_SOURCE_DIR = /home/keven/Projects/Fuzzing/Superion/new_tree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/keven/Projects/Fuzzing/Superion/new_tree/build

# Include any dependencies generated for this target.
include demo/CMakeFiles/antlr4-demo.dir/depend.make

# Include the progress variables for this target.
include demo/CMakeFiles/antlr4-demo.dir/progress.make

# Include the compile flags for this target's objects.
include demo/CMakeFiles/antlr4-demo.dir/flags.make

../demo/generated/TLexer.cpp: ../demo/TLexer.g4
../demo/generated/TLexer.cpp: ../demo/TParser.g4
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/keven/Projects/Fuzzing/Superion/new_tree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ../../demo/generated/TLexer.cpp, ../../demo/generated/TParser.cpp, ../../demo/generated/TParserBaseListener.cpp, ../../demo/generated/TParserBaseVisitor.cpp, ../../demo/generated/TParserListener.cpp, ../../demo/generated/TParserVisitor.cpp"
	/usr/bin/cmake -E make_directory /home/keven/Projects/Fuzzing/Superion/new_tree/demo/generated/
	/usr/bin/java -jar /usr/local/lib/antlr-4.7.2-complete.jar -Werror -Dlanguage=Cpp -listener -visitor -o /home/keven/Projects/Fuzzing/Superion/new_tree/demo/generated/ -package antlrcpptest /home/keven/Projects/Fuzzing/Superion/new_tree/demo/TLexer.g4 /home/keven/Projects/Fuzzing/Superion/new_tree/demo/TParser.g4

../demo/generated/TParser.cpp: ../demo/generated/TLexer.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate ../demo/generated/TParser.cpp

../demo/generated/TParserBaseListener.cpp: ../demo/generated/TLexer.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate ../demo/generated/TParserBaseListener.cpp

../demo/generated/TParserBaseVisitor.cpp: ../demo/generated/TLexer.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate ../demo/generated/TParserBaseVisitor.cpp

../demo/generated/TParserListener.cpp: ../demo/generated/TLexer.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate ../demo/generated/TParserListener.cpp

../demo/generated/TParserVisitor.cpp: ../demo/generated/TLexer.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate ../demo/generated/TParserVisitor.cpp

demo/CMakeFiles/antlr4-demo.dir/Linux/main.cpp.o: demo/CMakeFiles/antlr4-demo.dir/flags.make
demo/CMakeFiles/antlr4-demo.dir/Linux/main.cpp.o: ../demo/Linux/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keven/Projects/Fuzzing/Superion/new_tree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object demo/CMakeFiles/antlr4-demo.dir/Linux/main.cpp.o"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -o CMakeFiles/antlr4-demo.dir/Linux/main.cpp.o -c /home/keven/Projects/Fuzzing/Superion/new_tree/demo/Linux/main.cpp

demo/CMakeFiles/antlr4-demo.dir/Linux/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antlr4-demo.dir/Linux/main.cpp.i"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -E /home/keven/Projects/Fuzzing/Superion/new_tree/demo/Linux/main.cpp > CMakeFiles/antlr4-demo.dir/Linux/main.cpp.i

demo/CMakeFiles/antlr4-demo.dir/Linux/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antlr4-demo.dir/Linux/main.cpp.s"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -S /home/keven/Projects/Fuzzing/Superion/new_tree/demo/Linux/main.cpp -o CMakeFiles/antlr4-demo.dir/Linux/main.cpp.s

demo/CMakeFiles/antlr4-demo.dir/Linux/main.cpp.o.requires:

.PHONY : demo/CMakeFiles/antlr4-demo.dir/Linux/main.cpp.o.requires

demo/CMakeFiles/antlr4-demo.dir/Linux/main.cpp.o.provides: demo/CMakeFiles/antlr4-demo.dir/Linux/main.cpp.o.requires
	$(MAKE) -f demo/CMakeFiles/antlr4-demo.dir/build.make demo/CMakeFiles/antlr4-demo.dir/Linux/main.cpp.o.provides.build
.PHONY : demo/CMakeFiles/antlr4-demo.dir/Linux/main.cpp.o.provides

demo/CMakeFiles/antlr4-demo.dir/Linux/main.cpp.o.provides.build: demo/CMakeFiles/antlr4-demo.dir/Linux/main.cpp.o


demo/CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.o: demo/CMakeFiles/antlr4-demo.dir/flags.make
demo/CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.o: ../demo/generated/TLexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keven/Projects/Fuzzing/Superion/new_tree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object demo/CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.o"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -o CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.o -c /home/keven/Projects/Fuzzing/Superion/new_tree/demo/generated/TLexer.cpp

demo/CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.i"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -E /home/keven/Projects/Fuzzing/Superion/new_tree/demo/generated/TLexer.cpp > CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.i

demo/CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.s"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -S /home/keven/Projects/Fuzzing/Superion/new_tree/demo/generated/TLexer.cpp -o CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.s

demo/CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.o.requires:

.PHONY : demo/CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.o.requires

demo/CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.o.provides: demo/CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.o.requires
	$(MAKE) -f demo/CMakeFiles/antlr4-demo.dir/build.make demo/CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.o.provides.build
.PHONY : demo/CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.o.provides

demo/CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.o.provides.build: demo/CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.o


demo/CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.o: demo/CMakeFiles/antlr4-demo.dir/flags.make
demo/CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.o: ../demo/generated/TParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keven/Projects/Fuzzing/Superion/new_tree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object demo/CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.o"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -o CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.o -c /home/keven/Projects/Fuzzing/Superion/new_tree/demo/generated/TParser.cpp

demo/CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.i"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -E /home/keven/Projects/Fuzzing/Superion/new_tree/demo/generated/TParser.cpp > CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.i

demo/CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.s"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -S /home/keven/Projects/Fuzzing/Superion/new_tree/demo/generated/TParser.cpp -o CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.s

demo/CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.o.requires:

.PHONY : demo/CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.o.requires

demo/CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.o.provides: demo/CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.o.requires
	$(MAKE) -f demo/CMakeFiles/antlr4-demo.dir/build.make demo/CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.o.provides.build
.PHONY : demo/CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.o.provides

demo/CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.o.provides.build: demo/CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.o


demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.o: demo/CMakeFiles/antlr4-demo.dir/flags.make
demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.o: ../demo/generated/TParserBaseListener.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keven/Projects/Fuzzing/Superion/new_tree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.o"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -o CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.o -c /home/keven/Projects/Fuzzing/Superion/new_tree/demo/generated/TParserBaseListener.cpp

demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.i"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -E /home/keven/Projects/Fuzzing/Superion/new_tree/demo/generated/TParserBaseListener.cpp > CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.i

demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.s"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -S /home/keven/Projects/Fuzzing/Superion/new_tree/demo/generated/TParserBaseListener.cpp -o CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.s

demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.o.requires:

.PHONY : demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.o.requires

demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.o.provides: demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.o.requires
	$(MAKE) -f demo/CMakeFiles/antlr4-demo.dir/build.make demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.o.provides.build
.PHONY : demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.o.provides

demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.o.provides.build: demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.o


demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.o: demo/CMakeFiles/antlr4-demo.dir/flags.make
demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.o: ../demo/generated/TParserBaseVisitor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keven/Projects/Fuzzing/Superion/new_tree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.o"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -o CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.o -c /home/keven/Projects/Fuzzing/Superion/new_tree/demo/generated/TParserBaseVisitor.cpp

demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.i"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -E /home/keven/Projects/Fuzzing/Superion/new_tree/demo/generated/TParserBaseVisitor.cpp > CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.i

demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.s"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -S /home/keven/Projects/Fuzzing/Superion/new_tree/demo/generated/TParserBaseVisitor.cpp -o CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.s

demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.o.requires:

.PHONY : demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.o.requires

demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.o.provides: demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.o.requires
	$(MAKE) -f demo/CMakeFiles/antlr4-demo.dir/build.make demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.o.provides.build
.PHONY : demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.o.provides

demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.o.provides.build: demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.o


demo/CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.o: demo/CMakeFiles/antlr4-demo.dir/flags.make
demo/CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.o: ../demo/generated/TParserListener.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keven/Projects/Fuzzing/Superion/new_tree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object demo/CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.o"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -o CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.o -c /home/keven/Projects/Fuzzing/Superion/new_tree/demo/generated/TParserListener.cpp

demo/CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.i"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -E /home/keven/Projects/Fuzzing/Superion/new_tree/demo/generated/TParserListener.cpp > CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.i

demo/CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.s"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -S /home/keven/Projects/Fuzzing/Superion/new_tree/demo/generated/TParserListener.cpp -o CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.s

demo/CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.o.requires:

.PHONY : demo/CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.o.requires

demo/CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.o.provides: demo/CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.o.requires
	$(MAKE) -f demo/CMakeFiles/antlr4-demo.dir/build.make demo/CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.o.provides.build
.PHONY : demo/CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.o.provides

demo/CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.o.provides.build: demo/CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.o


demo/CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.o: demo/CMakeFiles/antlr4-demo.dir/flags.make
demo/CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.o: ../demo/generated/TParserVisitor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keven/Projects/Fuzzing/Superion/new_tree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object demo/CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.o"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -o CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.o -c /home/keven/Projects/Fuzzing/Superion/new_tree/demo/generated/TParserVisitor.cpp

demo/CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.i"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -E /home/keven/Projects/Fuzzing/Superion/new_tree/demo/generated/TParserVisitor.cpp > CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.i

demo/CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.s"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -S /home/keven/Projects/Fuzzing/Superion/new_tree/demo/generated/TParserVisitor.cpp -o CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.s

demo/CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.o.requires:

.PHONY : demo/CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.o.requires

demo/CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.o.provides: demo/CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.o.requires
	$(MAKE) -f demo/CMakeFiles/antlr4-demo.dir/build.make demo/CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.o.provides.build
.PHONY : demo/CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.o.provides

demo/CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.o.provides.build: demo/CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.o


# Object files for target antlr4-demo
antlr4__demo_OBJECTS = \
"CMakeFiles/antlr4-demo.dir/Linux/main.cpp.o" \
"CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.o" \
"CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.o" \
"CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.o" \
"CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.o" \
"CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.o" \
"CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.o"

# External object files for target antlr4-demo
antlr4__demo_EXTERNAL_OBJECTS =

demo/antlr4-demo: demo/CMakeFiles/antlr4-demo.dir/Linux/main.cpp.o
demo/antlr4-demo: demo/CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.o
demo/antlr4-demo: demo/CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.o
demo/antlr4-demo: demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.o
demo/antlr4-demo: demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.o
demo/antlr4-demo: demo/CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.o
demo/antlr4-demo: demo/CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.o
demo/antlr4-demo: demo/CMakeFiles/antlr4-demo.dir/build.make
demo/antlr4-demo: ../dist/libantlr4-runtime.a
demo/antlr4-demo: demo/CMakeFiles/antlr4-demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/keven/Projects/Fuzzing/Superion/new_tree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable antlr4-demo"
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/antlr4-demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
demo/CMakeFiles/antlr4-demo.dir/build: demo/antlr4-demo

.PHONY : demo/CMakeFiles/antlr4-demo.dir/build

demo/CMakeFiles/antlr4-demo.dir/requires: demo/CMakeFiles/antlr4-demo.dir/Linux/main.cpp.o.requires
demo/CMakeFiles/antlr4-demo.dir/requires: demo/CMakeFiles/antlr4-demo.dir/generated/TLexer.cpp.o.requires
demo/CMakeFiles/antlr4-demo.dir/requires: demo/CMakeFiles/antlr4-demo.dir/generated/TParser.cpp.o.requires
demo/CMakeFiles/antlr4-demo.dir/requires: demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseListener.cpp.o.requires
demo/CMakeFiles/antlr4-demo.dir/requires: demo/CMakeFiles/antlr4-demo.dir/generated/TParserBaseVisitor.cpp.o.requires
demo/CMakeFiles/antlr4-demo.dir/requires: demo/CMakeFiles/antlr4-demo.dir/generated/TParserListener.cpp.o.requires
demo/CMakeFiles/antlr4-demo.dir/requires: demo/CMakeFiles/antlr4-demo.dir/generated/TParserVisitor.cpp.o.requires

.PHONY : demo/CMakeFiles/antlr4-demo.dir/requires

demo/CMakeFiles/antlr4-demo.dir/clean:
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo && $(CMAKE_COMMAND) -P CMakeFiles/antlr4-demo.dir/cmake_clean.cmake
.PHONY : demo/CMakeFiles/antlr4-demo.dir/clean

demo/CMakeFiles/antlr4-demo.dir/depend: ../demo/generated/TLexer.cpp
demo/CMakeFiles/antlr4-demo.dir/depend: ../demo/generated/TParser.cpp
demo/CMakeFiles/antlr4-demo.dir/depend: ../demo/generated/TParserBaseListener.cpp
demo/CMakeFiles/antlr4-demo.dir/depend: ../demo/generated/TParserBaseVisitor.cpp
demo/CMakeFiles/antlr4-demo.dir/depend: ../demo/generated/TParserListener.cpp
demo/CMakeFiles/antlr4-demo.dir/depend: ../demo/generated/TParserVisitor.cpp
	cd /home/keven/Projects/Fuzzing/Superion/new_tree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/keven/Projects/Fuzzing/Superion/new_tree /home/keven/Projects/Fuzzing/Superion/new_tree/demo /home/keven/Projects/Fuzzing/Superion/new_tree/build /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo /home/keven/Projects/Fuzzing/Superion/new_tree/build/demo/CMakeFiles/antlr4-demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : demo/CMakeFiles/antlr4-demo.dir/depend

