# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = G:\Cmake\bin\cmake.exe

# The command to remove a file.
RM = G:\Cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Hoangi19\Desktop\MyDCMTK\checkMasks

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Hoangi19\Desktop\MyDCMTK\checkMasks\build

# Include any dependencies generated for this target.
include CMakeFiles/maxMasks.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/maxMasks.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/maxMasks.dir/flags.make

CMakeFiles/maxMasks.dir/maxMasks.cpp.obj: CMakeFiles/maxMasks.dir/flags.make
CMakeFiles/maxMasks.dir/maxMasks.cpp.obj: CMakeFiles/maxMasks.dir/includes_CXX.rsp
CMakeFiles/maxMasks.dir/maxMasks.cpp.obj: ../maxMasks.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Hoangi19\Desktop\MyDCMTK\checkMasks\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/maxMasks.dir/maxMasks.cpp.obj"
	G:\Code\MinGW64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\maxMasks.dir\maxMasks.cpp.obj -c C:\Users\Hoangi19\Desktop\MyDCMTK\checkMasks\maxMasks.cpp

CMakeFiles/maxMasks.dir/maxMasks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/maxMasks.dir/maxMasks.cpp.i"
	G:\Code\MinGW64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Hoangi19\Desktop\MyDCMTK\checkMasks\maxMasks.cpp > CMakeFiles\maxMasks.dir\maxMasks.cpp.i

CMakeFiles/maxMasks.dir/maxMasks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/maxMasks.dir/maxMasks.cpp.s"
	G:\Code\MinGW64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Hoangi19\Desktop\MyDCMTK\checkMasks\maxMasks.cpp -o CMakeFiles\maxMasks.dir\maxMasks.cpp.s

# Object files for target maxMasks
maxMasks_OBJECTS = \
"CMakeFiles/maxMasks.dir/maxMasks.cpp.obj"

# External object files for target maxMasks
maxMasks_EXTERNAL_OBJECTS =

maxMasks.exe: CMakeFiles/maxMasks.dir/maxMasks.cpp.obj
maxMasks.exe: CMakeFiles/maxMasks.dir/build.make
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libofstd.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/liboflog.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmdata.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libi2d.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmimgle.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmimage.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmjpeg.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libijg8.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libijg12.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libijg16.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmjpls.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libcharls.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmtls.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmnet.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmsr.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libcmr.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmdsig.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmwlm.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmqrdb.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmpstat.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmrt.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmiod.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmfg.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmseg.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmtract.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmpmap.a
maxMasks.exe: G:/Code/opencv-3.4.5/opencv-3.4.5/build/lib/libopencv_dnn345.dll.a
maxMasks.exe: G:/Code/opencv-3.4.5/opencv-3.4.5/build/lib/libopencv_ml345.dll.a
maxMasks.exe: G:/Code/opencv-3.4.5/opencv-3.4.5/build/lib/libopencv_objdetect345.dll.a
maxMasks.exe: G:/Code/opencv-3.4.5/opencv-3.4.5/build/lib/libopencv_shape345.dll.a
maxMasks.exe: G:/Code/opencv-3.4.5/opencv-3.4.5/build/lib/libopencv_stitching345.dll.a
maxMasks.exe: G:/Code/opencv-3.4.5/opencv-3.4.5/build/lib/libopencv_superres345.dll.a
maxMasks.exe: G:/Code/opencv-3.4.5/opencv-3.4.5/build/lib/libopencv_videostab345.dll.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmtls.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmsr.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmimage.a
maxMasks.exe: C:/Program\ Files\ (x86)/tiff/lib/libtiff.dll.a
maxMasks.exe: C:/Program\ Files\ (x86)/libpng/lib/libpng.dll.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmdsig.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmqrdb.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmnet.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmimgle.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmfg.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmiod.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libdcmdata.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/liboflog.a
maxMasks.exe: G:/Code/DCMTKPACKAGE/DCMTK/lib/libofstd.a
maxMasks.exe: C:/Program\ Files\ (x86)/zlib/lib/libzlib.dll.a
maxMasks.exe: G:/Code/opencv-3.4.5/opencv-3.4.5/build/lib/libopencv_calib3d345.dll.a
maxMasks.exe: G:/Code/opencv-3.4.5/opencv-3.4.5/build/lib/libopencv_features2d345.dll.a
maxMasks.exe: G:/Code/opencv-3.4.5/opencv-3.4.5/build/lib/libopencv_flann345.dll.a
maxMasks.exe: G:/Code/opencv-3.4.5/opencv-3.4.5/build/lib/libopencv_highgui345.dll.a
maxMasks.exe: G:/Code/opencv-3.4.5/opencv-3.4.5/build/lib/libopencv_photo345.dll.a
maxMasks.exe: G:/Code/opencv-3.4.5/opencv-3.4.5/build/lib/libopencv_video345.dll.a
maxMasks.exe: G:/Code/opencv-3.4.5/opencv-3.4.5/build/lib/libopencv_videoio345.dll.a
maxMasks.exe: G:/Code/opencv-3.4.5/opencv-3.4.5/build/lib/libopencv_imgcodecs345.dll.a
maxMasks.exe: G:/Code/opencv-3.4.5/opencv-3.4.5/build/lib/libopencv_imgproc345.dll.a
maxMasks.exe: G:/Code/opencv-3.4.5/opencv-3.4.5/build/lib/libopencv_core345.dll.a
maxMasks.exe: CMakeFiles/maxMasks.dir/linklibs.rsp
maxMasks.exe: CMakeFiles/maxMasks.dir/objects1.rsp
maxMasks.exe: CMakeFiles/maxMasks.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Hoangi19\Desktop\MyDCMTK\checkMasks\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable maxMasks.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\maxMasks.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/maxMasks.dir/build: maxMasks.exe

.PHONY : CMakeFiles/maxMasks.dir/build

CMakeFiles/maxMasks.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\maxMasks.dir\cmake_clean.cmake
.PHONY : CMakeFiles/maxMasks.dir/clean

CMakeFiles/maxMasks.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Hoangi19\Desktop\MyDCMTK\checkMasks C:\Users\Hoangi19\Desktop\MyDCMTK\checkMasks C:\Users\Hoangi19\Desktop\MyDCMTK\checkMasks\build C:\Users\Hoangi19\Desktop\MyDCMTK\checkMasks\build C:\Users\Hoangi19\Desktop\MyDCMTK\checkMasks\build\CMakeFiles\maxMasks.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/maxMasks.dir/depend

