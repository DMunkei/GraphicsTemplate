# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Programming-Projects\GraphicsTemplate

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Programming-Projects\GraphicsTemplate\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\GraphicsTemplate.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\GraphicsTemplate.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\GraphicsTemplate.dir\flags.make

CMakeFiles\GraphicsTemplate.dir\src\main.cpp.obj: CMakeFiles\GraphicsTemplate.dir\flags.make
CMakeFiles\GraphicsTemplate.dir\src\main.cpp.obj: ..\src\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Programming-Projects\GraphicsTemplate\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GraphicsTemplate.dir/src/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\GraphicsTemplate.dir\src\main.cpp.obj /FdCMakeFiles\GraphicsTemplate.dir\ /FS -c D:\Programming-Projects\GraphicsTemplate\src\main.cpp
<<

CMakeFiles\GraphicsTemplate.dir\src\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GraphicsTemplate.dir/src/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\GraphicsTemplate.dir\src\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Programming-Projects\GraphicsTemplate\src\main.cpp
<<

CMakeFiles\GraphicsTemplate.dir\src\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GraphicsTemplate.dir/src/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\GraphicsTemplate.dir\src\main.cpp.s /c D:\Programming-Projects\GraphicsTemplate\src\main.cpp
<<

# Object files for target GraphicsTemplate
GraphicsTemplate_OBJECTS = \
"CMakeFiles\GraphicsTemplate.dir\src\main.cpp.obj"

# External object files for target GraphicsTemplate
GraphicsTemplate_EXTERNAL_OBJECTS =

GraphicsTemplate.exe: CMakeFiles\GraphicsTemplate.dir\src\main.cpp.obj
GraphicsTemplate.exe: CMakeFiles\GraphicsTemplate.dir\build.make
GraphicsTemplate.exe: libs\glfw\src\glfw3.lib
GraphicsTemplate.exe: GLAD.lib
GraphicsTemplate.exe: STB_IMAGE.lib
GraphicsTemplate.exe: CMakeFiles\GraphicsTemplate.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Programming-Projects\GraphicsTemplate\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GraphicsTemplate.exe"
	"C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\GraphicsTemplate.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\GraphicsTemplate.dir\objects1.rsp @<<
 /out:GraphicsTemplate.exe /implib:GraphicsTemplate.lib /pdb:D:\Programming-Projects\GraphicsTemplate\cmake-build-debug\GraphicsTemplate.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  opengl32.lib libs\glfw\src\glfw3.lib GLAD.lib STB_IMAGE.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\GraphicsTemplate.dir\build: GraphicsTemplate.exe

.PHONY : CMakeFiles\GraphicsTemplate.dir\build

CMakeFiles\GraphicsTemplate.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GraphicsTemplate.dir\cmake_clean.cmake
.PHONY : CMakeFiles\GraphicsTemplate.dir\clean

CMakeFiles\GraphicsTemplate.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\Programming-Projects\GraphicsTemplate D:\Programming-Projects\GraphicsTemplate D:\Programming-Projects\GraphicsTemplate\cmake-build-debug D:\Programming-Projects\GraphicsTemplate\cmake-build-debug D:\Programming-Projects\GraphicsTemplate\cmake-build-debug\CMakeFiles\GraphicsTemplate.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\GraphicsTemplate.dir\depend
