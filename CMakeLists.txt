cmake_minimum_required(VERSION 3.10)
project(exampleCppProject)
include_directories(include)

# Compiler & C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Debugger info
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_BUILD_TYPE Debug)

# Download Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
)
FetchContent_MakeAvailable(googletest)

# Project structure
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
file(GLOB_RECURSE TEST_FILES "tests/*.cpp")

# === Main executable ===
add_executable(exampleCppProject ${SRC_FILES})

# === Test executable ===
set(TESTABLE_SRC_FILES ${SRC_FILES})
list(FILTER TESTABLE_SRC_FILES EXCLUDE REGEX ".*/main.cpp$")

# Create unit test executable
add_executable(unit_tests ${TESTABLE_SRC_FILES} ${TEST_FILES})
target_link_libraries(unit_tests PRIVATE gtest_main)