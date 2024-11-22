cmake_minimum_required(VERSION 3.10)

# Set the project name
project(PimplInnerWorker)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Include directories
include_directories(src)

# Add executable
add_executable(PimplTests
    src/main.cpp
    src/MyClass.cpp
    src/MyClass.h
)
