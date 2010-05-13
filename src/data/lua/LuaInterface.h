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
#include <map>

//Project Includes
#include<data/Bullet.h>
#include<data/Creature.h>
#include<data/lua/LuaState.h>
#include<data/lua/LuaBuildingType.h>

class LuaBuildingType;

/**
* Lua Interface
*/
class LuaInterface
{
  private:
    lua_State* state;
    
    std::map<char*, LuaBuildingType*> buildingTypes;
    std::map<char*, Bullet*> bulletTypes;
    std::map<char*, Creature*> creatureTypes;
    
  //Lua Functions from Game
  
    LuaInterface(lua_State* state);
    static bool IsRegistered(lua_State*  state);
    
  public:
    ~LuaInterface();
    void AddBuildingType(LuaBuildingType* buildingType); 
    void AddCreatureType();
    void AddBulletType();
    

    static LuaInterface* Instance(lua_State*  state); 
};

#endif // LUAINTERFACE_H
