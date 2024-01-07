cmake_minimum_required(VERSION 3.4)

project(C++)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCE_FILES main.cpp)
add_executable(hello ${SOURCE_FILES})