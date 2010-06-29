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

#=========================
# QuickGUI
SUBDIRS(lib/QuickGUI)

ADD_EXECUTABLE(td src/scene/BuildingNode.cpp src/engine/ParticleEffect.cpp src/model/Player.cpp src/lua/LuaUtils.cpp src/lua/LuaGameObject.cpp src/engine/RtsEnvironment.cpp src/engine/RtsCamera.cpp src/engine/DotSceneLoader.cpp src/engine/MouseCursor.cpp src/engine/InputManager.cpp src/engine/OgreLogListener.cpp src/Game.cpp src/engine/EngineApplication.cpp src/state/LoadingState.cpp src/lua/LuaBuilding.cpp src/lua/LuaBuildingType.cpp src/lua/LuaInterface.cpp src/lua/LuaState.cpp src/common/Log.cpp src/state/InGameMenuState.cpp src/state/GameState.cpp src/state/MenuState.cpp src/model/Map.cpp src/main.cpp)

TARGET_LINK_LIBRARIES(td ${OGRE_LIBRARY} ${OGRE_TERRAIN} ${OIS_LIB} ${LUA_LIB} TINYXML)
