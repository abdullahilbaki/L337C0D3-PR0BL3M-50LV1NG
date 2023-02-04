cmake_minimum_required(VERSION 3.22)

project(
  leetcode_problem_solving
  LANGUAGES CXX
  VERSION 0.0.1)

include(FetchContent)

# Fetch and configure Catch2
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

# Create a target for the catch2 library add_library(pain INTERFACE IMPORTED)

# Set C++ standard
set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20") 
# Create the executable
add_executable(leetcode)

target_link_libraries(leetcode PUBLIC Catch2::Catch2WithMain)

# Add the source files
file(GLOB_RECURSE SRC_FILES src/*.cpp)
target_sources(leetcode PRIVATE ${SRC_FILES})

# Add compiler warnings
target_compile_options(
  leetcode
  PRIVATE -std=c++20
          -Werror
          -pedantic-errors
          -Wall
          -Wextra
          -Wconversion
          -Wsign-conversion
          -Wshadow
          -Wnon-virtual-dtor
          -Wpedantic
          -Wold-style-cast
          -Wcast-align
          -Wunused
          -Wmisleading-indentation
          -Wduplicated-cond
          -Wduplicated-branches
          -Wlogical-op
          -Wnull-dereference
          -Wuseless-cast
          -Wdouble-promotion
          -Wformat=2
          -Wimplicit-fallthrough)
