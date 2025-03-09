# C++ Development Workflow with VSCode, LLVM, and CMake

## Required Tools
To set up your development environment with me, you must have the following tools installed:
* Code Editor: VSCode
* Compiler: LLVM (Clang)
* Build System: CMake
Optional but Recommended tools:
* Debugger: LLVM (LLDB)
* Language Server: ClangD
* Build System Alternative: Ninja (Faster than Make)

## 1. Organizing your project
A well-structed project should look like this:
```markdown
my_project/
├── CMakeLists.txt        # CMake build configuration
├── include/              # Header files
│   ├── foo.hpp
│   ├── bar.hpp
├── src/                  # Source files
│   ├── main.cpp
│   ├── foo.cpp
│   ├── bar.cpp
├── lib/                  # External libraries
│   ├── libmylib.a        # Statically linked at compile time
│   ├── libmylib.so       # Dynamically linked at runtime
└── build/                # Build directory (generate by CMake)
```

## 2. Writing your own CMakeLists.txt
Create a `CMakeLists.txt` at the root of your project:
```cmake
create_minimum_required(VERSION 3.10)
project(my_project)

# Set compiler
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Library paths
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Create the executable
add_executable(my_project ${SOURCES})

# Link static or shared libraries if needed
target_link_libraries(my_project PRIVATE my_lib)
```

## 3. Compiling and Running
Once your project is set up, follow these steps to compile and run it.
```sh
mkdir -p build && cd build
cmake -G Ninja ..             # Configure the build system
ninja                         # Build the project
./my_project                  # Run the compiled binary
```
Alternatively, if you're using `Make` instead of `Ninja`
```sh
mkdir -p build && cd build
cmake ..                      # Generating Makefiles
cmake -j$(proc)               # Build with parallel jobs
./my_project                  # Run the compiled binary
```
## 4. Debug
To debug your program using `LLDB`, follow these steps:
1. Ensure your project is compiled with debugging symbols
Modify your `CMakeLists.txt` to enable debug symbols:
```cmake
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
```
2. Start debugging with LLDB
Run LLDB manually to check if it's working:
```sh
lldb ./my_project
(lldb) breakpoin set --file main.cpp --line 8
(lldb) run
```
3. Configure VSCode for debugging
Create a `.vscode/launch.json` file. Then you might see a `Add Configuration` button at the bottom right, you should choose `Code LLDB: Launch`  Here's an example file.
```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "LLDB Debug",
      "type": "lldb",
      "request": "launch",
      "program": "${workspaceFolder}/build/my_project",
      "args": [],
      "cwd": "${workspaceFolder}",
      "stopAtEntry": false,
      "terminal": "integrated"
    }
  ]
}
```
4. Run the debugger in VSCode
* Open the `Run and Debug` tab in VSCode
* Select `LLDB Debug` and click `Start Debugging`