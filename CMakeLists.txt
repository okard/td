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


#Platform Configuration
IF(WIN32)
	# Ogre Libraries
	#FIND_LIBRARY(OGRE_MAIN OgreMain.dll PATH ${CMAKE_SOURCE_DIR}/../ogre_sdk/lib/release)
	#FIND_LIBRARY(OIS_LIB OIS PATH ${CMAKE_SOURCE_DIR}/../ogre_sdk/lib/release)
	
	FIND_LIBRARY(OGRE_MAIN OgreMain_d.dll PATH ${CMAKE_SOURCE_DIR}/../ogre_sdk/lib/debug)
	FIND_LIBRARY(OIS_LIB OIS_d PATH ${CMAKE_SOURCE_DIR}/../ogre_sdk/lib/debug)
	INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/../ogre_sdk/include)
	INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/../ogre_sdk/boost_1_42)
	
	# Lua
	FIND_LIBRARY(LUA_LIB lua51 PATH ${CMAKE_SOURCE_DIR}/../luajit2/src)
	INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/../luajit2/src)
ELSE()
	# Ogre Libraries
	FIND_LIBRARY(OGRE_MAIN OgreMain)
	FIND_LIBRARY(OIS_LIB OIS)
	# LUA Libraries
	FIND_LIBRARY(LUA_LIB luajit-5.1)
ENDIF()


ADD_EXECUTABLE(td src/engine/RtsEnvironment.cpp src/engine/RtsCamera.cpp src/engine/DotSceneLoader.cpp src/engine/MouseCursor.cpp src/engine/InputManager.cpp src/engine/OgreLogListener.cpp src/Game.cpp src/engine/EngineApplication.cpp src/state/LoadingState.cpp src/lua/LuaBuilding.cpp src/lua/LuaBuildingType.cpp src/lua/LuaInterface.cpp src/lua/LuaState.cpp src/common/Log.cpp src/state/InGameMenuState.cpp src/state/GameState.cpp src/state/MenuState.cpp src/model/Map.cpp src/main.cpp)

TARGET_LINK_LIBRARIES(td ${OGRE_MAIN} ${OIS_LIB} ${LUA_LIB} TINYXML)
