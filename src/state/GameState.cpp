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
    :  luaInterface(LuaInterface::Instance(luaState)), mEngine(0)
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
    RtsEnvironment::Start(engine);
    
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
        buildings.push_back(b);
      }
    }
    
    DotSceneLoader loader;
    loader.ParseFile("data/map01.scene", this->getSceneManager());
    
    //Ogre test code
    //Ogre::MaterialManager::getSingleton().load("Ogre.material", "General");
    //getSceneMng()->getRootSceneNode()->createChildSceneNode()->attachObject(getSceneMng()->createEntity("ogre", "data/ogrehead.mesh")); 
}

/**
* Shutdown GameState
*/
void GameState::Shutdown()
{

}


/**
* Update State
*/
void GameState::Update()
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
    
    //Move on X Axis
    int x = mouseState.X.abs;
    if(x < 20)
        camera->moveLeft(2);
    if(x > mouseState.width-20)
        camera->moveRight(2);
    
    //Move on Y Axis
    if(mouseState.Y.abs < 20)
        camera->moveUp(2);
    if(mouseState.Y.abs > mouseState.height -20)
        camera->moveDown(2);
}

/**
* Mouse Moved
*/
bool GameState::mouseMoved(const OIS::MouseEvent& arg)
{
    
}


