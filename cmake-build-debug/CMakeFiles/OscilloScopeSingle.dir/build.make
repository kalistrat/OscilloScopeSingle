# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\GitProjects\OscilloScopeSingle

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\GitProjects\OscilloScopeSingle\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OscilloScopeSingle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OscilloScopeSingle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OscilloScopeSingle.dir/flags.make

CMakeFiles/OscilloScopeSingle.dir/main.cpp.obj: CMakeFiles/OscilloScopeSingle.dir/flags.make
CMakeFiles/OscilloScopeSingle.dir/main.cpp.obj: CMakeFiles/OscilloScopeSingle.dir/includes_CXX.rsp
CMakeFiles/OscilloScopeSingle.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitProjects\OscilloScopeSingle\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OscilloScopeSingle.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OscilloScopeSingle.dir\main.cpp.obj -c D:\GitProjects\OscilloScopeSingle\main.cpp

CMakeFiles/OscilloScopeSingle.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OscilloScopeSingle.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\GitProjects\OscilloScopeSingle\main.cpp > CMakeFiles\OscilloScopeSingle.dir\main.cpp.i

CMakeFiles/OscilloScopeSingle.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OscilloScopeSingle.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\GitProjects\OscilloScopeSingle\main.cpp -o CMakeFiles\OscilloScopeSingle.dir\main.cpp.s

CMakeFiles/OscilloScopeSingle.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/OscilloScopeSingle.dir/main.cpp.obj.requires

CMakeFiles/OscilloScopeSingle.dir/main.cpp.obj.provides: CMakeFiles/OscilloScopeSingle.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OscilloScopeSingle.dir\build.make CMakeFiles/OscilloScopeSingle.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/OscilloScopeSingle.dir/main.cpp.obj.provides

CMakeFiles/OscilloScopeSingle.dir/main.cpp.obj.provides.build: CMakeFiles/OscilloScopeSingle.dir/main.cpp.obj


CMakeFiles/OscilloScopeSingle.dir/mainwindow.cpp.obj: CMakeFiles/OscilloScopeSingle.dir/flags.make
CMakeFiles/OscilloScopeSingle.dir/mainwindow.cpp.obj: CMakeFiles/OscilloScopeSingle.dir/includes_CXX.rsp
CMakeFiles/OscilloScopeSingle.dir/mainwindow.cpp.obj: ../mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitProjects\OscilloScopeSingle\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OscilloScopeSingle.dir/mainwindow.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OscilloScopeSingle.dir\mainwindow.cpp.obj -c D:\GitProjects\OscilloScopeSingle\mainwindow.cpp

CMakeFiles/OscilloScopeSingle.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OscilloScopeSingle.dir/mainwindow.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\GitProjects\OscilloScopeSingle\mainwindow.cpp > CMakeFiles\OscilloScopeSingle.dir\mainwindow.cpp.i

CMakeFiles/OscilloScopeSingle.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OscilloScopeSingle.dir/mainwindow.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\GitProjects\OscilloScopeSingle\mainwindow.cpp -o CMakeFiles\OscilloScopeSingle.dir\mainwindow.cpp.s

CMakeFiles/OscilloScopeSingle.dir/mainwindow.cpp.obj.requires:

.PHONY : CMakeFiles/OscilloScopeSingle.dir/mainwindow.cpp.obj.requires

CMakeFiles/OscilloScopeSingle.dir/mainwindow.cpp.obj.provides: CMakeFiles/OscilloScopeSingle.dir/mainwindow.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OscilloScopeSingle.dir\build.make CMakeFiles/OscilloScopeSingle.dir/mainwindow.cpp.obj.provides.build
.PHONY : CMakeFiles/OscilloScopeSingle.dir/mainwindow.cpp.obj.provides

CMakeFiles/OscilloScopeSingle.dir/mainwindow.cpp.obj.provides.build: CMakeFiles/OscilloScopeSingle.dir/mainwindow.cpp.obj


CMakeFiles/OscilloScopeSingle.dir/crc16_ccitt.cpp.obj: CMakeFiles/OscilloScopeSingle.dir/flags.make
CMakeFiles/OscilloScopeSingle.dir/crc16_ccitt.cpp.obj: CMakeFiles/OscilloScopeSingle.dir/includes_CXX.rsp
CMakeFiles/OscilloScopeSingle.dir/crc16_ccitt.cpp.obj: ../crc16_ccitt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitProjects\OscilloScopeSingle\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OscilloScopeSingle.dir/crc16_ccitt.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OscilloScopeSingle.dir\crc16_ccitt.cpp.obj -c D:\GitProjects\OscilloScopeSingle\crc16_ccitt.cpp

CMakeFiles/OscilloScopeSingle.dir/crc16_ccitt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OscilloScopeSingle.dir/crc16_ccitt.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\GitProjects\OscilloScopeSingle\crc16_ccitt.cpp > CMakeFiles\OscilloScopeSingle.dir\crc16_ccitt.cpp.i

CMakeFiles/OscilloScopeSingle.dir/crc16_ccitt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OscilloScopeSingle.dir/crc16_ccitt.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\GitProjects\OscilloScopeSingle\crc16_ccitt.cpp -o CMakeFiles\OscilloScopeSingle.dir\crc16_ccitt.cpp.s

CMakeFiles/OscilloScopeSingle.dir/crc16_ccitt.cpp.obj.requires:

.PHONY : CMakeFiles/OscilloScopeSingle.dir/crc16_ccitt.cpp.obj.requires

CMakeFiles/OscilloScopeSingle.dir/crc16_ccitt.cpp.obj.provides: CMakeFiles/OscilloScopeSingle.dir/crc16_ccitt.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OscilloScopeSingle.dir\build.make CMakeFiles/OscilloScopeSingle.dir/crc16_ccitt.cpp.obj.provides.build
.PHONY : CMakeFiles/OscilloScopeSingle.dir/crc16_ccitt.cpp.obj.provides

CMakeFiles/OscilloScopeSingle.dir/crc16_ccitt.cpp.obj.provides.build: CMakeFiles/OscilloScopeSingle.dir/crc16_ccitt.cpp.obj


CMakeFiles/OscilloScopeSingle.dir/devcmd.cpp.obj: CMakeFiles/OscilloScopeSingle.dir/flags.make
CMakeFiles/OscilloScopeSingle.dir/devcmd.cpp.obj: CMakeFiles/OscilloScopeSingle.dir/includes_CXX.rsp
CMakeFiles/OscilloScopeSingle.dir/devcmd.cpp.obj: ../devcmd.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitProjects\OscilloScopeSingle\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/OscilloScopeSingle.dir/devcmd.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OscilloScopeSingle.dir\devcmd.cpp.obj -c D:\GitProjects\OscilloScopeSingle\devcmd.cpp

CMakeFiles/OscilloScopeSingle.dir/devcmd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OscilloScopeSingle.dir/devcmd.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\GitProjects\OscilloScopeSingle\devcmd.cpp > CMakeFiles\OscilloScopeSingle.dir\devcmd.cpp.i

CMakeFiles/OscilloScopeSingle.dir/devcmd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OscilloScopeSingle.dir/devcmd.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\GitProjects\OscilloScopeSingle\devcmd.cpp -o CMakeFiles\OscilloScopeSingle.dir\devcmd.cpp.s

CMakeFiles/OscilloScopeSingle.dir/devcmd.cpp.obj.requires:

.PHONY : CMakeFiles/OscilloScopeSingle.dir/devcmd.cpp.obj.requires

CMakeFiles/OscilloScopeSingle.dir/devcmd.cpp.obj.provides: CMakeFiles/OscilloScopeSingle.dir/devcmd.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OscilloScopeSingle.dir\build.make CMakeFiles/OscilloScopeSingle.dir/devcmd.cpp.obj.provides.build
.PHONY : CMakeFiles/OscilloScopeSingle.dir/devcmd.cpp.obj.provides

CMakeFiles/OscilloScopeSingle.dir/devcmd.cpp.obj.provides.build: CMakeFiles/OscilloScopeSingle.dir/devcmd.cpp.obj


CMakeFiles/OscilloScopeSingle.dir/hdlc.cpp.obj: CMakeFiles/OscilloScopeSingle.dir/flags.make
CMakeFiles/OscilloScopeSingle.dir/hdlc.cpp.obj: CMakeFiles/OscilloScopeSingle.dir/includes_CXX.rsp
CMakeFiles/OscilloScopeSingle.dir/hdlc.cpp.obj: ../hdlc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitProjects\OscilloScopeSingle\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/OscilloScopeSingle.dir/hdlc.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OscilloScopeSingle.dir\hdlc.cpp.obj -c D:\GitProjects\OscilloScopeSingle\hdlc.cpp

CMakeFiles/OscilloScopeSingle.dir/hdlc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OscilloScopeSingle.dir/hdlc.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\GitProjects\OscilloScopeSingle\hdlc.cpp > CMakeFiles\OscilloScopeSingle.dir\hdlc.cpp.i

CMakeFiles/OscilloScopeSingle.dir/hdlc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OscilloScopeSingle.dir/hdlc.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\GitProjects\OscilloScopeSingle\hdlc.cpp -o CMakeFiles\OscilloScopeSingle.dir\hdlc.cpp.s

CMakeFiles/OscilloScopeSingle.dir/hdlc.cpp.obj.requires:

.PHONY : CMakeFiles/OscilloScopeSingle.dir/hdlc.cpp.obj.requires

CMakeFiles/OscilloScopeSingle.dir/hdlc.cpp.obj.provides: CMakeFiles/OscilloScopeSingle.dir/hdlc.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OscilloScopeSingle.dir\build.make CMakeFiles/OscilloScopeSingle.dir/hdlc.cpp.obj.provides.build
.PHONY : CMakeFiles/OscilloScopeSingle.dir/hdlc.cpp.obj.provides

CMakeFiles/OscilloScopeSingle.dir/hdlc.cpp.obj.provides.build: CMakeFiles/OscilloScopeSingle.dir/hdlc.cpp.obj


CMakeFiles/OscilloScopeSingle.dir/OscilloScopeSingle_autogen/moc_compilation.cpp.obj: CMakeFiles/OscilloScopeSingle.dir/flags.make
CMakeFiles/OscilloScopeSingle.dir/OscilloScopeSingle_autogen/moc_compilation.cpp.obj: CMakeFiles/OscilloScopeSingle.dir/includes_CXX.rsp
CMakeFiles/OscilloScopeSingle.dir/OscilloScopeSingle_autogen/moc_compilation.cpp.obj: OscilloScopeSingle_autogen/moc_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitProjects\OscilloScopeSingle\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/OscilloScopeSingle.dir/OscilloScopeSingle_autogen/moc_compilation.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OscilloScopeSingle.dir\OscilloScopeSingle_autogen\moc_compilation.cpp.obj -c D:\GitProjects\OscilloScopeSingle\cmake-build-debug\OscilloScopeSingle_autogen\moc_compilation.cpp

CMakeFiles/OscilloScopeSingle.dir/OscilloScopeSingle_autogen/moc_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OscilloScopeSingle.dir/OscilloScopeSingle_autogen/moc_compilation.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\GitProjects\OscilloScopeSingle\cmake-build-debug\OscilloScopeSingle_autogen\moc_compilation.cpp > CMakeFiles\OscilloScopeSingle.dir\OscilloScopeSingle_autogen\moc_compilation.cpp.i

CMakeFiles/OscilloScopeSingle.dir/OscilloScopeSingle_autogen/moc_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OscilloScopeSingle.dir/OscilloScopeSingle_autogen/moc_compilation.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\GitProjects\OscilloScopeSingle\cmake-build-debug\OscilloScopeSingle_autogen\moc_compilation.cpp -o CMakeFiles\OscilloScopeSingle.dir\OscilloScopeSingle_autogen\moc_compilation.cpp.s

CMakeFiles/OscilloScopeSingle.dir/OscilloScopeSingle_autogen/moc_compilation.cpp.obj.requires:

.PHONY : CMakeFiles/OscilloScopeSingle.dir/OscilloScopeSingle_autogen/moc_compilation.cpp.obj.requires

CMakeFiles/OscilloScopeSingle.dir/OscilloScopeSingle_autogen/moc_compilation.cpp.obj.provides: CMakeFiles/OscilloScopeSingle.dir/OscilloScopeSingle_autogen/moc_compilation.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OscilloScopeSingle.dir\build.make CMakeFiles/OscilloScopeSingle.dir/OscilloScopeSingle_autogen/moc_compilation.cpp.obj.provides.build
.PHONY : CMakeFiles/OscilloScopeSingle.dir/OscilloScopeSingle_autogen/moc_compilation.cpp.obj.provides

CMakeFiles/OscilloScopeSingle.dir/OscilloScopeSingle_autogen/moc_compilation.cpp.obj.provides.build: CMakeFiles/OscilloScopeSingle.dir/OscilloScopeSingle_autogen/moc_compilation.cpp.obj


# Object files for target OscilloScopeSingle
OscilloScopeSingle_OBJECTS = \
"CMakeFiles/OscilloScopeSingle.dir/main.cpp.obj" \
"CMakeFiles/OscilloScopeSingle.dir/mainwindow.cpp.obj" \
"CMakeFiles/OscilloScopeSingle.dir/crc16_ccitt.cpp.obj" \
"CMakeFiles/OscilloScopeSingle.dir/devcmd.cpp.obj" \
"CMakeFiles/OscilloScopeSingle.dir/hdlc.cpp.obj" \
"CMakeFiles/OscilloScopeSingle.dir/OscilloScopeSingle_autogen/moc_compilation.cpp.obj"

# External object files for target OscilloScopeSingle
OscilloScopeSingle_EXTERNAL_OBJECTS =

OscilloScopeSingle.exe: CMakeFiles/OscilloScopeSingle.dir/main.cpp.obj
OscilloScopeSingle.exe: CMakeFiles/OscilloScopeSingle.dir/mainwindow.cpp.obj
OscilloScopeSingle.exe: CMakeFiles/OscilloScopeSingle.dir/crc16_ccitt.cpp.obj
OscilloScopeSingle.exe: CMakeFiles/OscilloScopeSingle.dir/devcmd.cpp.obj
OscilloScopeSingle.exe: CMakeFiles/OscilloScopeSingle.dir/hdlc.cpp.obj
OscilloScopeSingle.exe: CMakeFiles/OscilloScopeSingle.dir/OscilloScopeSingle_autogen/moc_compilation.cpp.obj
OscilloScopeSingle.exe: CMakeFiles/OscilloScopeSingle.dir/build.make
OscilloScopeSingle.exe: C:/Qt/Qt5.8.0/5.8/mingw53_32/lib/libQt5Widgetsd.a
OscilloScopeSingle.exe: C:/Qt/Qt5.8.0/5.8/mingw53_32/lib/libQt5Guid.a
OscilloScopeSingle.exe: C:/Qt/Qt5.8.0/5.8/mingw53_32/lib/libQt5SerialPortd.a
OscilloScopeSingle.exe: C:/Qt/Qt5.8.0/5.8/mingw53_32/lib/libQt5Cored.a
OscilloScopeSingle.exe: CMakeFiles/OscilloScopeSingle.dir/linklibs.rsp
OscilloScopeSingle.exe: CMakeFiles/OscilloScopeSingle.dir/objects1.rsp
OscilloScopeSingle.exe: CMakeFiles/OscilloScopeSingle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\GitProjects\OscilloScopeSingle\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable OscilloScopeSingle.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\OscilloScopeSingle.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OscilloScopeSingle.dir/build: OscilloScopeSingle.exe

.PHONY : CMakeFiles/OscilloScopeSingle.dir/build

CMakeFiles/OscilloScopeSingle.dir/requires: CMakeFiles/OscilloScopeSingle.dir/main.cpp.obj.requires
CMakeFiles/OscilloScopeSingle.dir/requires: CMakeFiles/OscilloScopeSingle.dir/mainwindow.cpp.obj.requires
CMakeFiles/OscilloScopeSingle.dir/requires: CMakeFiles/OscilloScopeSingle.dir/crc16_ccitt.cpp.obj.requires
CMakeFiles/OscilloScopeSingle.dir/requires: CMakeFiles/OscilloScopeSingle.dir/devcmd.cpp.obj.requires
CMakeFiles/OscilloScopeSingle.dir/requires: CMakeFiles/OscilloScopeSingle.dir/hdlc.cpp.obj.requires
CMakeFiles/OscilloScopeSingle.dir/requires: CMakeFiles/OscilloScopeSingle.dir/OscilloScopeSingle_autogen/moc_compilation.cpp.obj.requires

.PHONY : CMakeFiles/OscilloScopeSingle.dir/requires

CMakeFiles/OscilloScopeSingle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\OscilloScopeSingle.dir\cmake_clean.cmake
.PHONY : CMakeFiles/OscilloScopeSingle.dir/clean

CMakeFiles/OscilloScopeSingle.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\GitProjects\OscilloScopeSingle D:\GitProjects\OscilloScopeSingle D:\GitProjects\OscilloScopeSingle\cmake-build-debug D:\GitProjects\OscilloScopeSingle\cmake-build-debug D:\GitProjects\OscilloScopeSingle\cmake-build-debug\CMakeFiles\OscilloScopeSingle.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OscilloScopeSingle.dir/depend

