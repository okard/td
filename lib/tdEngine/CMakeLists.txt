CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(tdEngine)

INCLUDE_DIRECTORIES(include)


ADD_LIBRARY(tdEngine STATIC
                src/Log.cpp
                src/DotSceneLoader.cpp     
                src/InputManager.cpp  
                src/OgreLogListener.cpp  
                src/RtsCamera.cpp                                           
                src/EngineApplication.cpp  
                src/MouseCursor.cpp   
                src/ParticleEffect.cpp   
                src/RtsEnvironment.cpp)
TARGET_LINK_LIBRARIES(tdEngine ${OGRE_LIBRARY})

