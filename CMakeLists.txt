cmake_minimum_required(VERSION 3.0.0)
project(graph_exercises VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -O2 -Wpedantic")

file(GLOB_RECURSE graph_exercises_SRC CONFIGURE_DEPENDS "./src/*.cpp")
file(GLOB_RECURSE graph_exercises_HDR CONFIGURE_DEPENDS "./src/*.h")

set(graph_exercises_INC "")
foreach(_headerFile ${graph_exercises_HDR})
    get_filename_component(_dir ${_headerFile} PATH)
    list(APPEND graph_exercises_INC ${_dir})
endforeach()
list(REMOVE_DUPLICATES graph_exercises_INC)


include(CTest)
enable_testing()

add_executable(graph_exercises ${graph_exercises_SRC})
target_include_directories(graph_exercises PRIVATE ${graph_exercises_INC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
