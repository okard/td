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
#include <tdEngine/Log.h>

#include <tdEngine/IEngineState.h>
#include <tdEngine/EngineApplication.h>
#include <tdEngine/RtsCamera.h>
#include <tdEngine/RtsEnvironment.h>

#include <lua/LuaState.h>
#include <lua/LuaInterface.h>
#include <lua/LuaBuildingType.h>
#include <model/Building.h>
#include <model/Player.h>
#include <model/Map.h>


typedef std::list<Building*> BuildingList;

/**
* The Game State
*/
class GameState : public IEngineState, public RtsEnvironment, public OIS::MouseListener
{
    private:
        /// Lua VM
        LuaState luaState;
        
        /// Lua Game Interface
        LuaInterface* luaInterface;
        
        /// Engine Application
        EngineApplication* mEngine;
        
        /// Map
        Map* mMap;
        
        /// Local Player
        Player mLocalPlayer;
        
        //List of game objects here?
    
        //TODO Available Buildings
        //TODO Available Researches
        
        //TODO Current Map
        //TODO Current Buildings
        BuildingList mBuildings;
        //TODO Current Stage
        //TODO 
        
        /// update time count for game objects (ms)
        unsigned int mUpdateTimeGO;
        
        //BuildingEntity <- LuaBuilding <- Building?
    public:
        /**
        * Constructor
        */
        GameState();
        
        /**
        * Destructor
        */
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
    
    
    private:
        /**
        * Handle Input
        */
        void HandleInput();
        
        /**
        * Update Game Objects
        */
        void UpdateGameObjects();
};

#endif // GAMESTATE_H
