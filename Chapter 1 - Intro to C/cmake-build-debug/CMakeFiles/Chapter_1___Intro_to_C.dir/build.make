# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "N:\alevel-programming\Chapter 1 - Intro to C"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "N:\alevel-programming\Chapter 1 - Intro to C\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\Chapter_1___Intro_to_C.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Chapter_1___Intro_to_C.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Chapter_1___Intro_to_C.dir\flags.make

CMakeFiles\Chapter_1___Intro_to_C.dir\main.c.obj: CMakeFiles\Chapter_1___Intro_to_C.dir\flags.make
CMakeFiles\Chapter_1___Intro_to_C.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="N:\alevel-programming\Chapter 1 - Intro to C\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Chapter_1___Intro_to_C.dir/main.c.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Chapter_1___Intro_to_C.dir\main.c.obj /FdCMakeFiles\Chapter_1___Intro_to_C.dir\ /FS -c "N:\alevel-programming\Chapter 1 - Intro to C\main.c"
<<

CMakeFiles\Chapter_1___Intro_to_C.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Chapter_1___Intro_to_C.dir/main.c.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\Chapter_1___Intro_to_C.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "N:\alevel-programming\Chapter 1 - Intro to C\main.c"
<<

CMakeFiles\Chapter_1___Intro_to_C.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Chapter_1___Intro_to_C.dir/main.c.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Chapter_1___Intro_to_C.dir\main.c.s /c "N:\alevel-programming\Chapter 1 - Intro to C\main.c"
<<

# Object files for target Chapter_1___Intro_to_C
Chapter_1___Intro_to_C_OBJECTS = \
"CMakeFiles\Chapter_1___Intro_to_C.dir\main.c.obj"

# External object files for target Chapter_1___Intro_to_C
Chapter_1___Intro_to_C_EXTERNAL_OBJECTS =

Chapter_1___Intro_to_C.exe: CMakeFiles\Chapter_1___Intro_to_C.dir\main.c.obj
Chapter_1___Intro_to_C.exe: CMakeFiles\Chapter_1___Intro_to_C.dir\build.make
Chapter_1___Intro_to_C.exe: CMakeFiles\Chapter_1___Intro_to_C.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="N:\alevel-programming\Chapter 1 - Intro to C\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Chapter_1___Intro_to_C.exe"
	"C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Chapter_1___Intro_to_C.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Chapter_1___Intro_to_C.dir\objects1.rsp @<<
 /out:Chapter_1___Intro_to_C.exe /implib:Chapter_1___Intro_to_C.lib /pdb:"N:\alevel-programming\Chapter 1 - Intro to C\cmake-build-debug\Chapter_1___Intro_to_C.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Chapter_1___Intro_to_C.dir\build: Chapter_1___Intro_to_C.exe

.PHONY : CMakeFiles\Chapter_1___Intro_to_C.dir\build

CMakeFiles\Chapter_1___Intro_to_C.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Chapter_1___Intro_to_C.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Chapter_1___Intro_to_C.dir\clean

CMakeFiles\Chapter_1___Intro_to_C.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "N:\alevel-programming\Chapter 1 - Intro to C" "N:\alevel-programming\Chapter 1 - Intro to C" "N:\alevel-programming\Chapter 1 - Intro to C\cmake-build-debug" "N:\alevel-programming\Chapter 1 - Intro to C\cmake-build-debug" "N:\alevel-programming\Chapter 1 - Intro to C\cmake-build-debug\CMakeFiles\Chapter_1___Intro_to_C.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Chapter_1___Intro_to_C.dir\depend
