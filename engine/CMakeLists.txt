#########################################
# CMake File for td engine
#########################################
cmake_minimum_required(VERSION 2.8)
project(engine)

#include directory for horde3d
include_directories(${CMAKE_SOURCE_DIR}/lib/horde3d/shared)
include_directories(${CMAKE_SOURCE_DIR}/lib/horde3d/source)

#source files for engine
set( ENGINE_SRC
    src/Engine.cpp
)

#library
add_library(engine ${ENGINE_SRC})
target_link_libraries(engine horde3d)