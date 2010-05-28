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

class LuaBuildingType;

class LuaBuilding : public Building
{
  private:
    BuildingType* buildingType;
    std::string name;
    lua_State* state;
    
    //Sprite sprite;
    //Sprite icon;
    
    //id function generator
    static unsigned short idIndex;
    
  public:
    LuaBuilding(lua_State* state, LuaBuildingType* type);
    virtual ~LuaBuilding();
    
    //Game Object Interface
    virtual const char* ObjectName() const;
    
    //Building Interface
    virtual BuildingType* GetType();
    virtual void Update(int time);
    
    //Lua Interface
    int Fire(lua_State* state);
    
    //For Lua Registration
    static const char className[];
    static const LuaBind<LuaBuilding>::RegType Register[];
    
    static const char* id(const char* typeName);
};

#endif // LUABUILDING_H
