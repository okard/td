/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

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

#include "LuaBuildingType.h"

//Cpp Includes
#include <cstdlib>
#include <cstring>

//Project Includes
#include <common/Log.h>


//Configuration for Lua
const char LuaBuildingType::className[] = "BuildingType";
const Luna<LuaBuildingType>::RegType LuaBuildingType::Register[] = 
  {
     // { "foo", &Foo::foo },
      { "RegisterType", &LuaBuildingType::RegisterType},
      {0}
  };


/**
* Constructor
*/
LuaBuildingType::LuaBuildingType(lua_State* state) : state(state), registered(false), name(0)
{
    Log::Source()->Information("LuaBuildingType created");
    //Register itself at LuaInterface
}

/**
* Destructor
*/
LuaBuildingType::~LuaBuildingType()
{
  delete this->name;
  
  //TODO deregister from lua interface
}

/**
* Registering the type with the given name
*/
int LuaBuildingType::RegisterType(lua_State* state)
{  
  Log::Source()->Information("Register Type");
  
  //Register if not
  if(!registered)
  {
    //Copy String from Lua
    size_t len;
    const char* str = lua_tolstring(state, -1, &len);
    this->name = static_cast<char*>(malloc(len+1));
    strncpy(this->name, str, len);
    this->name[len] = '\0';
    
    //Register at Lua Interface
    LuaInterface::Instance(state)->AddBuildingType(this);
    registered = true;
    return 0;
  }
  
  lua_pop(state, -1);
  
  return 0;
}
       
char* LuaBuildingType::GetName()
{
  return name;
}

      
Building* LuaBuildingType::Create()
{
  /*
    Lua Code:
    global type_1 = Building()
    setmetatable(type_1, type)
  */
  
  //Create new Building
  lua_getfield(state, LUA_GLOBALSINDEX, LuaBuilding::className); 
  lua_call(state, 0, 1);
  
  //set metatable
  lua_getglobal(state, this->GetName());
  if(lua_istable(state, -1))
    lua_setmetatable(state, -2);
  
  //save value
  lua_setfield(state, LUA_GLOBALSINDEX, "newBuilding_1"); 
    
  //void?
  //extract class pointer?
  //get the Building* from the new table?
  
  
  //Create new Table
  //set metatable
  //call OnCreate();
  //return Building
  return 0;
}