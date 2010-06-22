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

#ifndef LUAINTERFACE_H
#define LUAINTERFACE_H

//STL Includes
#include <string>
#include <map>
#include <list>

//Project Includes
#include <model/Bullet.h>
#include <model/Creature.h>

#include <lua/LuaState.h>
#include <lua/LuaGameObject.h>
#include <lua/LuaBuildingType.h>

class LuaBuildingType;

typedef std::list<LuaGameObject*> GameObjectList;

typedef std::map<std::string, LuaBuildingType*> BuildingTypeList;



/**
* Lua Interface
*/
class LuaInterface
{
    ///friend class for LuaSingleton implementation
    friend class LuaSingleton<LuaInterface>;
  
  private:
    /// the Lua State
    lua_State* state;
    
    /// All Game Objects
    ///GameObjectList gameObjects;
    
    /// list with available building types
    BuildingTypeList buildingTypes;
    
    
    std::map<std::string, Bullet*> bulletTypes;
    std::map<std::string, Creature*> creatureTypes;
    
  
    /**
    * Constructor
    */
    LuaInterface(lua_State* state);
  public:
    /**
    * Destructor
    */
    ~LuaInterface();
    
    ///////////////////////////////////////////////////////////////////////////
    // Lua Interface
    /**
    * Register a general game object
    */
    int RegisterGameObject(lua_State* state);
    
    /**
    * Loads a Script
    */
    int LoadScript(lua_State* state);
    
    /**
    * Spawn Game Objects?
    */
    int Spawn(lua_State* state);
    
    ///////////////////////////////////////////////////////////////////////////
    // Normal Methods
    
    /**
    * Get a Specific Building Type
    */
    BuildingType* GetBuildingType(char*);
    
    
    /**
    * Return the LuaInterface instance for this lua state
    */
    static LuaInterface* Instance(lua_State*  state); 
           
    //Lua Binding Stuff
    /// Lua Class Name
    static const char className[];
    /// Function List to Register
    static const LuaBind<LuaInterface>::RegType Register[];
};

#endif // LUAINTERFACE_H
