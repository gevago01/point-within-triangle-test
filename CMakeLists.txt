cmake_minimum_required(VERSION 3.6)
project(PointInTriangle)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -Wextra   ")

set(SOURCE_FILES main.cpp TriangleIntersections.cpp TriangleIntersections.h  DataReader.cpp DataReader.h)

# find OpenCV
find_package(OpenCV REQUIRED)

if(OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})

    message(STATUS "OpenCV library was successfully found.")
endif()


add_executable(PointInTriangle ${SOURCE_FILES})
target_link_libraries(PointInTriangle ${OpenCV_LIBS})
