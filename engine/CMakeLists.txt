#########################################
# CMake File for td engine
#########################################
cmake_minimum_required(VERSION 2.8)
project(engine)

include_directories(include)

#include directory for horde3d
include_directories(${CMAKE_SOURCE_DIR}/lib/cul/include)
include_directories(${CMAKE_SOURCE_DIR}/lib/libRocket/Include)
include_directories(${CMAKE_SOURCE_DIR}/lib/csoh/include)

#source files for engine
set( ENGINE_SRC
    src/EngineCore.cpp
    src/lua/LuaState.cpp
    src/lua/LuaContext.cpp
    src/ui/RenderInterfaceOpenGL.cpp
    src/ui/SystemInterface.cpp
)

#library
add_library(engine ${ENGINE_SRC})
target_link_libraries(engine csoh Rocket ${LUA_LIB})