# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.25
cmake_policy(SET CMP0009 NEW)

# graph_exercises_SRC at CMakeLists.txt:7 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/home/theam/development/projects/cpp/graphs/./src/*.cpp")
set(OLD_GLOB
  "/home/theam/development/projects/cpp/graphs/./src/main.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/theam/development/projects/cpp/graphs/build/CMakeFiles/cmake.verify_globs")
endif()

# graph_exercises_HDR at CMakeLists.txt:8 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/home/theam/development/projects/cpp/graphs/./src/*.h")
set(OLD_GLOB
  "/home/theam/development/projects/cpp/graphs/./src/SimpleGraph.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/theam/development/projects/cpp/graphs/build/CMakeFiles/cmake.verify_globs")
endif()
