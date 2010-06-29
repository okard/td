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
#include <tdEngine/Log.h>
#include <tdEngine/IDGen.h>

using namespace Common;


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
LuaBuildingType::LuaBuildingType(lua_State* state, std::string name) 
    : LuaGameObject(state, name), registered(true)
{
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
* Return Building Type Name
*/
const char* LuaBuildingType::getTypeName()
{
    //is ObjectName?
    return LuaGameObject::getObjectName();
}

/**
* Create a new Building from this type
*/
Building* LuaBuildingType::Create()
{
   //use prefix from building Type???
   std::string id = IDGen<LuaBuildingType>::get("Building");
   LuaGameObject::Create(id);
   return new LuaBuilding(getLuaState(), id, this);
}

/**
* Get Object Name
*/
const char* LuaBuildingType::getObjectName() const
{
    return LuaGameObject::getObjectName();
}
