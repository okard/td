/*
    Tower Defense Game
    Copyright (C) 2010  okard

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

#include "GameState.h"

#include <list>
#include <engine/DotSceneLoader.h>

/**
* Constructor
*/
GameState::GameState() 
    :  luaInterface(LuaInterface::Instance(luaState)), mEngine(0), mUpdateTimeGO(0), mMap(0)
{
    //Load Lua Game File
    luaState.LoadFile("data/game.lua");
    luaState.Execute();
}

/**
* Destrcutor
*/
GameState::~GameState()
{
  //call shutdown?
  Shutdown();
  //delete luaState;
}

/**
* Start GameState
*/
void GameState::Start(EngineApplication* engine)
{
    // Start up enviroment
    RtsEnvironment::Initialize(engine);
    //Create Map
    mMap = new Map(this);
    
    mEngine = engine;
    Common::LogEvent() << "GameState started" << Common::LogEvent::End;
    
    //test lua building
    BuildingType* type = luaInterface->GetBuildingType("CanonTower");
    if(type == 0)
    {
      Common::LogEvent() << "No Canon Tower";
    }
    else
    {
      for(int i=0;i < 1;i++)
      {
        Building* b = type->Create();
        b->Update(500);
        mBuildings.push_back(b);
      }
    }
    
    //DotSceneLoader loader;
    //loader.ParseFile("map/map01.scene", this->getSceneManager());
    mMap->Load("map/map01.cfg");
    
    //Ogre test code
    //Ogre::MaterialManager::getSingleton().load("Ogre.material", "General");
    //getSceneMng()->getRootSceneNode()->createChildSceneNode()->attachObject(getSceneMng()->createEntity("ogre", "data/ogrehead.mesh")); 
}

/**
* Shutdown GameState
*/
void GameState::Shutdown()
{
    delete mMap;
    mMap = 0;
}


/**
* Update State
*/
void GameState::Update()
{
    //mEngine->getRoot()->get
    // Update Game Objects
    UpdateGameObjects();
    
    // Handle Input
    HandleInput();
}

/**
* Mouse Moved
*/
bool GameState::mouseMoved(const OIS::MouseEvent& arg)
{
    
}

/**
* Handle Input
*/
void GameState::HandleInput()
{
    const InputManager& input = mEngine->getInputManager();
    RtsCamera* camera = getRtsCamera();
    
    if(input.Keyboard()->isKeyDown(OIS::KC_W))
        camera->moveUp(1);
    if(input.Keyboard()->isKeyDown(OIS::KC_S))
        camera->moveDown(1);
    if(input.Keyboard()->isKeyDown(OIS::KC_A))
        camera->moveLeft(1);
    if(input.Keyboard()->isKeyDown(OIS::KC_D))
        camera->moveRight(1);
    
    if(input.Keyboard()->isKeyDown(OIS::KC_PERIOD))
        camera->zoomIn(1);
     
    if(input.Keyboard()->isKeyDown(OIS::KC_MINUS))
        camera->zoomOut(1);
    
    //Mouse State
    const OIS::MouseState& mouseState = input.Mouse()->getMouseState();
    
    //zoom using mouse wheel
    int z = (mouseState.Z.rel);
    if(z < 0)
        camera->zoomIn(-z/12);
    if(z > 0)
        camera->zoomOut(z/12);
    
    const int movSecSize = 40;
    
    //Move on X Axis
    int x = mouseState.X.abs;
    if(x < movSecSize)
        camera->moveLeft(2);
    if(x > mouseState.width-movSecSize)
        camera->moveRight(2);
    
    //Move on Y Axis
    if(mouseState.Y.abs < movSecSize)
        camera->moveUp(2);
    if(mouseState.Y.abs > mouseState.height -movSecSize)
        camera->moveDown(2);
}

/**
* Update all Game Objects
*/
void GameState::UpdateGameObjects()
{
    //its not required each frame so limit time? all 200ms ?
    // 20 ms = max ~50 per second
    mUpdateTimeGO += mEngine->getElapsedTime();
    if(mUpdateTimeGO < 20)
        return;
    
    
    //loop through all game objects and call update
     for(BuildingList::iterator it = mBuildings.begin(); it != mBuildings.end(); it++)
         (*it)->Update(mUpdateTimeGO);
     
     //TODO Creatures, Bullets?
     //TODO Different Update Rate for each?
     
     mUpdateTimeGO = 0;
}

