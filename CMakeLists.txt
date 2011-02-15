#########################################
# CMake File for TD Game
#
#########################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(td)


#Platform Configuration
IF(WIN32)
    # Lua
    FIND_LIBRARY(LUA_LIB lua51 PATH ${CMAKE_SOURCE_DIR}/../luajit2/src)
    INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/../luajit2/src)
ELSE()
    # LUA Libraries
    FIND_LIBRARY(LUA_LIB luajit-5.1)
ENDIF()



#Libraries
ADD_SUBDIRECTORY(lib/cul)
ADD_SUBDIRECTORY(lib/glul)
ADD_SUBDIRECTORY(lib/aul)
ADD_SUBDIRECTORY(lib/csoh)
ADD_SUBDIRECTORY(lib/horde3d)
ADD_SUBDIRECTORY(lib/libRocket)

# Components Engine, Game, Editor
ADD_SUBDIRECTORY(engine)
ADD_SUBDIRECTORY(game)
ADD_SUBDIRECTORY(editor)


