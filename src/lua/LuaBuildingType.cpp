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
const LuaBind<LuaBuildingType>::RegType LuaBuildingType::Register[] = 
  {
     // { "foo", &Foo::foo },
      {0}
  };

/**
* Constructor
*/ 
LuaBuildingType::LuaBuildingType(lua_State* state, std::string name) : state(state), name(name), registered(true)
{
    LogEvent(LogType::Information) << "LuaBuildingType created";
}

/*
LuaBuildingType::LuaBuildingType()
{
 throw "can not instantiate LuaBuildingType with default contructor";
}*/


/**
* Destructor
*/
LuaBuildingType::~LuaBuildingType()
{
  //delete this->name;
  
  //TODO deregister from lua interface
}

const char* LuaBuildingType::ObjectName() const
{
    return name.c_str();
}


     
const char* LuaBuildingType::GetName()
{
  return name.c_str();
}

      
Building* LuaBuildingType::Create()
{
  return new LuaBuilding(state, this);
}