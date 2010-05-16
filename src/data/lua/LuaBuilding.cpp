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

#include "LuaBuilding.h"

//Cpp Includes
#include <string>
#include <sstream>

//Project Includes
#include <common/Log.h>


/**
* Lua Class Name
*/
const char LuaBuilding::className[] = "Building";
/**
* Lua Functions
*/
const Luna<LuaBuilding>::RegType LuaBuilding::Register[] = 
{
      { "Fire", &LuaBuilding::Fire},
      {0}
};

//id_index
unsigned short LuaBuilding::idIndex = 0;

/**
* ID Generator
*/
char* LuaBuilding::id(char* typeName)
{
  std::ostringstream stream;
  stream << typeName << "_" << idIndex++;
  return const_cast<char*>(stream.str().c_str());
}

/**
* Constructor
*/
LuaBuilding::LuaBuilding(lua_State* state, LuaBuildingType* buildingType) : buildingType(buildingType), state(state)
{
    Log::Source()->Information("LuaBuilding created");
    //register own functions for this type
  
    //New table
    lua_newtable(state);
    
    //set metatable
    lua_getglobal(state, buildingType->GetName());
    if(lua_istable(state, -1))
      lua_setmetatable(state, -2);
    
    //set index field
    lua_getglobal(state, buildingType->GetName());
    lua_setfield(state, -1, "__index");
  
    //Register Functions for new Table
    WrapClassFunction<LuaBuilding>::Register(state, this);
   
    //save new building in lua with following name
    this->name = id(buildingType->GetName());
    //save value
    lua_setfield(state, LUA_GLOBALSINDEX, this->name); 
}

/**
* Destructor
*/
LuaBuilding::~LuaBuilding()
{
    //Delete Object from global lua table
}

/**
* Inform Lua Building about the elapsed time
*/
void LuaBuilding::Update(int time)
{
    Log::Source()->Information(this->name);
    //Calls Update Function from Lua Script
    lua_getfield(state, LUA_GLOBALSINDEX, this->name);
    lua_getmetatable(state, -1);
    lua_getfield(state, -1, "Update");
    //the table is the first argument 'self'
    lua_getfield(state, LUA_GLOBALSINDEX, this->name);
    lua_pushnumber(state, time);
    lua_call(state, 2, 0);
}

/**
* Fire a Bullet
*/
int LuaBuilding::Fire(lua_State* state)
{
  Log::Source()->Information("Fire Called");
  //Get Property BulletType
  //create a new Bullet with that type
  //set target for bullet for strategy

  return 0;
}


/**
* Return Building Type
*/
BuildingType* LuaBuilding::GetType()
{
  return this->buildingType;
}

