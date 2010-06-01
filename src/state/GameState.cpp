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
    :  luaInterface(LuaInterface::Instance(luaState))
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
  //delete luaState;
}

/**
* Start GameState
*/
void GameState::Start(EngineApplication& engine)
{
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
    loader.ParseFile("data/map01.scene", engine.getSceneMng());
    
    
    
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

