#########################################
# CMake File for TD Game
#
#########################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(td)

#Libraries
SUBDIRS(lib/cul)
SUBDIRS(lib/glul)
SUBDIRS(lib/horde3d)

# Components Engine, Game, Editor
SUBDIRS(engine)
SUBDIRS(game)


#Platform Configuration
IF(WIN32)
	# Lua
	FIND_LIBRARY(LUA_LIB lua51 PATH ${CMAKE_SOURCE_DIR}/../luajit2/src)
	INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/../luajit2/src)
ELSE()
	# LUA Libraries
	FIND_LIBRARY(LUA_LIB luajit-5.1)
ENDIF()

