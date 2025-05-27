cmake_minimum_required(VERSION 3.10)

# Project name
project(MyProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Recursively collect all source files from src/
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")

# Print all source files (optional, for debugging)
# message(STATUS "Source files: ${SOURCES}")

# Add the executable
add_executable(main ${SOURCES})
