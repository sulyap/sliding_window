cmake_minimum_required(VERSION 2.8)
project(sliding_window)
find_package(OpenCV REQUIRED)

set(CMAKE_BUILD_TYPE Debug)

add_executable(sliding_window main.cpp)
target_link_libraries(sliding_window ${OpenCV_LIBS})
