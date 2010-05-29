#########################################
# CMake File for TD Game
#
#########################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(td)

INCLUDE_DIRECTORIES(src)

#==============================
# TinyXML Library
SUBDIRS(lib/tinyxml)
INCLUDE_DIRECTORIES(lib)

#==============================
# Ogre Libraries
FIND_LIBRARY(OGRE_MAIN OgreMain)
FIND_LIBRARY(OIS_LIB OIS)

#==============================
# LUA Libraries
#find_library(LUA_LIB lua)
FIND_LIBRARY(LUA_LIB luajit-5.1)

ADD_EXECUTABLE(td src/engine/MouseCursor.cpp src/engine/InputManager.cpp src/engine/OgreLogListener.cpp src/Game.cpp src/engine/EngineApplication.cpp src/state/LoadingState.cpp src/lua/LuaBuilding.cpp src/lua/LuaBuildingType.cpp src/lua/LuaInterface.cpp src/lua/LuaState.cpp src/common/Log.cpp src/state/InGameMenuState.cpp src/state/GameState.cpp src/state/MenuState.cpp src/model/Map.cpp src/main.cpp)

TARGET_LINK_LIBRARIES(td ${OGRE_MAIN} ${OIS_LIB} ${LUA_LIB} ${TINYXML})
