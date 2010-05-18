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
LuaBuildingType::LuaBuildingType(lua_State* state) : state(state), registered(false)
{
    Log::Source()->Information("LuaBuildingType created");
    //Register itself at LuaInterface
}

/**
* Destructor
*/
LuaBuildingType::~LuaBuildingType()
{
  //delete this->name;
  
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
    /*size_t len;
    const char* str = lua_tolstring(state, -1, &len);
    this->name = static_cast<char*>(malloc(len+1));
    strncpy(this->name, str, len);
    this->name[len] = '\0';
    */
    size_t len;
    const char* str = lua_tolstring(state, -1, &len);
    name = std::string(str, len);
    
    
    //Register at Lua Interface
    LuaInterface::Instance(state)->AddBuildingType(this);
    registered = true;
    return 0;
  }
  
  lua_pop(state, -1);
  
  return 0;
}
       
const char* LuaBuildingType::GetName() const
{
  return name.c_str();
}

      
Building* LuaBuildingType::Create()
{
  return new LuaBuilding(state, this);
}