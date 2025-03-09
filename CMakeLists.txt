cmake_minimum_required(VERSION 3.10)
project(exampleCppProject)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 17)

# Include Paths
include_directories(include)

# Source Files
file(GLOB SOURCES "src/*.cpp")
add_executable(exampleCppProject ${SOURCES})