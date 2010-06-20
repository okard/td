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

#ifndef LUABUILDING_H
#define LUABUILDING_H

//Cpp Includes
#include <string>

//Project Includes
#include <model/Building.h>
#include <lua/Luna.h>
#include <lua/LuaBuildingType.h>

//Forward Declarations
class LuaBuildingType;

/**
* Represents a Building defined through lua script
*/
class LuaBuilding : public Building, public LuaGameObject
{
  private:
    /// The Building Type
    BuildingType* buildingType;
 
  public:
    /**
    * Constructor
    */
    LuaBuilding(lua_State* state, std::string& name, LuaBuildingType* type);
    /**
    * Destructor
    */
    virtual ~LuaBuilding();
    
    ///////////////////////////////////////////////////////////////////////////
    // Game Object Interface
    /**
    * Get Object Name
    */
    virtual const char* getObjectName() const;
    
    ///////////////////////////////////////////////////////////////////////////
    // Building Interface
    /**
    * Get Building Type
    */
    virtual BuildingType* GetType();
    
    /**
    * Update Game Object
    */
    virtual void Update(int time);
    
    /**
    * Get Fire Strategy
    */
    virtual FireStrategy getFireStrategy() const;
    
    /**
    * Get FireType
    */
    virtual FireType     getFireType() const;
    
    ///////////////////////////////////////////////////////////////////////////
    // Lua Interface
    /**
    * Fire Bullet (deprecated)
    */
    int Fire(lua_State* state);
    
    //For Lua Registration
    /// List with Functions to bind
    static const LuaBind<LuaBuilding>::RegType Register[];
    
    
};

#endif // LUABUILDING_H
