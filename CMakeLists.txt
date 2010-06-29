#########################################
# CMake File for TD Game
#
#########################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(td)

INCLUDE_DIRECTORIES(src)

#Platform Configuration
IF(WIN32)
	# Ogre Libraries
	#FIND_LIBRARY(OGRE_LIBRARY OgreMain.dll PATH ${CMAKE_SOURCE_DIR}/../ogre_sdk/lib/release)
	#FIND_LIBRARY(OIS_LIB OIS PATH ${CMAKE_SOURCE_DIR}/../ogre_sdk/lib/release)
	
	FIND_LIBRARY(OGRE_LIBRARY OgreMain_d.dll PATH ${CMAKE_SOURCE_DIR}/../ogre_sdk/lib/debug)
	FIND_LIBRARY(OIS_LIB OIS_d PATH ${CMAKE_SOURCE_DIR}/../ogre_sdk/lib/debug)
        FIND_LIBRARY(OGRE_TERRAIN OgreTerrain_d.dll PATH ${CMAKE_SOURCE_DIR}/../ogre_sdk/lib/debug)
	INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/../ogre_sdk/include)
        # For using Plugins and Components directly required for include OgrePrerequisites.h
        INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/../ogre_sdk/include/OGRE)
	INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/../ogre_sdk/boost_1_42)
	
	# Lua
	FIND_LIBRARY(LUA_LIB lua51 PATH ${CMAKE_SOURCE_DIR}/../luajit2/src)
	INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/../luajit2/src)
ELSE()
	# Ogre Libraries
	FIND_LIBRARY(OGRE_LIBRARY OgreMain)
	FIND_LIBRARY(OIS_LIB OIS)
        FIND_LIBRARY(OGRE_TERRAIN OgreTerrain)
	# LUA Libraries
	FIND_LIBRARY(LUA_LIB luajit-5.1)

        # For using Plugins and Components directly required for include OgrePrerequisites.h
        INCLUDE_DIRECTORIES(/usr/include/OGRE)
ENDIF()

#==============================
# TinyXML Library
SUBDIRS(lib/tinyxml)
INCLUDE_DIRECTORIES(lib)

#==============================
# QuickGUI
SUBDIRS(lib/QuickGUI)

#==============================
SUBDIRS(lib/tdEngine)
INCLUDE_DIRECTORIES(lib/tdEngine/include)

ADD_EXECUTABLE(td src/scene/BuildingNode.cpp src/model/Player.cpp src/lua/LuaUtils.cpp src/lua/LuaGameObject.cpp src/Game.cpp src/state/LoadingState.cpp src/lua/LuaBuilding.cpp src/lua/LuaBuildingType.cpp src/lua/LuaInterface.cpp src/lua/LuaState.cpp src/state/InGameMenuState.cpp src/state/GameState.cpp src/state/MenuState.cpp src/model/Map.cpp src/main.cpp)

TARGET_LINK_LIBRARIES(td tdEngine ${OGRE_LIBRARY} ${OGRE_TERRAIN} ${OIS_LIB} ${LUA_LIB} TINYXML)
