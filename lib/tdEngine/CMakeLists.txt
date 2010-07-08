CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(tdEngine)

INCLUDE_DIRECTORIES(include)


ADD_LIBRARY(tdEngine STATIC
                src/lua/LuaState.cpp
                src/lua/LuaObject.cpp
                src/EffectManager.cpp 
                src/Log.cpp
                src/DotSceneLoader.cpp     
                src/InputManager.cpp  
                src/OgreLogListener.cpp  
                src/RtsCamera.cpp                                           
                src/EngineApplication.cpp  
                src/MouseCursor.cpp   
                src/ParticleEffect.cpp   
                src/RtsEnvironment.cpp )
TARGET_LINK_LIBRARIES(tdEngine QuickGUI ${OGRE_LIBRARY} ${LUA_LIB})

