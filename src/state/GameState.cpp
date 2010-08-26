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

/**
* Constructor
*/
GameState::GameState() 
    :  luaInterface(LuaInterface::Instance(luaState)), mEngine(0), mUpdateTimeGO(0), mMap(0)
{
    //Load Lua Game File
    luaState.LoadFile("data/main.lua");
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
    LOG("GameState started")
    
    //test lua building
    BuildingType* type = luaInterface->GetBuildingType("CanonTower");
    if(type == 0)
    {
      Common::LogEvent() << "No Canon Tower";
    }
    else
    {
      for(int i=0;i < 50;i++)
      {
        Building* b = type->Create();
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
    float avFps = mEngine->getRenderWindow()->getAverageFPS();
    Common::LogEvent() << "fps: " << avFps << Common::LogEvent::End;
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
   
    unsigned int move = (0.5 * mEngine->getElapsedTime());
    
    
    if(input.Keyboard()->isKeyDown(OIS::KC_W))
        camera->moveUp(move);
    if(input.Keyboard()->isKeyDown(OIS::KC_S))
        camera->moveDown(move);
    if(input.Keyboard()->isKeyDown(OIS::KC_A))
        camera->moveLeft(move);
    if(input.Keyboard()->isKeyDown(OIS::KC_D))
        camera->moveRight(move);
    
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
        camera->moveLeft(move);
    if(x > mouseState.width-movSecSize)
        camera->moveRight(move);
    
    //Move on Y Axis
    if(mouseState.Y.abs < movSecSize)
        camera->moveUp(move);
    if(mouseState.Y.abs > mouseState.height -movSecSize)
        camera->moveDown(move);
}

/**
* Update all Game Objects
*/
void GameState::UpdateGameObjects()
{
    //its not required each frame so limit time? all 200ms ?
    // 20 ms = max ~50 per second
    mUpdateTimeGO += mEngine->getElapsedTime();
    if(mUpdateTimeGO < 200)
        return;
    
    //access per string is slow, maybe a table where objects can be added an loop trough
    
    //loop through all game objects and call update
     for(BuildingList::iterator it = mBuildings.begin(); it != mBuildings.end(); it++)
         (*it)->Update(mUpdateTimeGO);
     
     //TODO Creatures, Bullets?
     //TODO Different Update Rate for each?
     
     //TODO each objects per frame for better balancing of lua calls?
     //TODO a general update list objects can register iteself?
     
     //Buildings and Researches needs lesser update rate
     
     //bullets and creatures need higher update rate because of movement?
        //store movement command in c++ and move to point with given speed then call script again?
     
     mUpdateTimeGO = 0;
}

