project(CheckMasks)

cmake_minimum_required(VERSION 3.14)

find_package(OpenCV REQUIRED)
find_package(DCMTK REQUIRED)

# add_executable(checkMasks checkMasks.cpp)
add_executable(maxMasks maxMasks.cpp)

include_directories(${DCMTK_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})

# target_link_libraries(checkMasks ${DCMTK_LIBRARIES} ${OpenCV_LIBS})
target_link_libraries(maxMasks ${DCMTK_LIBRARIES} ${OpenCV_LIBS})