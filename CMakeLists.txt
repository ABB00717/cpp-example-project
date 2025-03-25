cmake_minimum_required(VERSION 3.10)
project(exampleCppProject)

# Compiler & C++ Standard
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Debugger info
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_BUILD_TYPE Debug)

# Project structure
include_directories(include)
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
file(GLOB_RECURSE TEST_FILES "tests/*.cpp")

# === Main executable ===
add_executable(exampleCppProject ${SRC_FILES})

# === Test executable ===
set(TESTABLE_SRC_FILES ${SRC_FILES})
list(FILTER TESTABLE_SRC_FILES EXCLUDE REGEX ".*/main.cpp$")

# Create unit test executable
add_executable(unit_tests ${TESTABLE_SRC_FILES} ${TEST_FILES})