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

#ifndef GAMESTATE_H
#define GAMESTATE_H

//STL Includes
#include <list>

// OIS & Ogre Includes
#include <OIS/OISMouse.h>

//Project Includes
#include <common/Log.h>

#include <engine/EngineState.h>
#include <engine/EngineApplication.h>
#include <engine/RtsCamera.h>

#include <lua/LuaState.h>
#include <lua/LuaInterface.h>
#include <lua/LuaBuildingType.h>
#include <model/Building.h>


/**
* The Game State
*/
class GameState : public EngineState, public OIS::MouseListener
{
  private:
    LuaState luaState;
    LuaInterface* luaInterface;
    
    RtsCamera* mCamera;
    
    EngineApplication* mEngine;
   
    //TODO Available Buildings
    //TODO Available Researches
    
    //TODO Current Map
    //TODO Current Buildings
    std::list<Building*> buildings;
    //TODO Current Stage
    //TODO 
    
    //BuildingEntity <- LuaBuilding <- Building?
  public:
    GameState();
    virtual ~GameState();
    
    /**
    * Start GameState
    */
    virtual void Start(EngineApplication* engine);
    
    /**
    * Shutdown GameState
    */
    virtual void Shutdown();
    
    /**
    * Update State
    */
    virtual void Update();
    
    /**
    * Mouse Moved
    */
    virtual bool mouseMoved( const OIS::MouseEvent &arg );
    
    /**
    * Mouse Button Pressed
    */
    virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id ){};
    
    /**
    * Mouse Released
    */
    virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id ){};

};

#endif // GAMESTATE_H
