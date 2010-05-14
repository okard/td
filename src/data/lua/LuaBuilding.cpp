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

#include "LuaBuilding.h"

//Project Includes
#include <common/Log.h>


//Configuration for Lua
const char LuaBuilding::className[] = "Building";
const Luna<LuaBuilding>::RegType LuaBuilding::Register[] = 
  {
     // { "foo", &Foo::foo },
      { "Fire", &LuaBuilding::Fire},
      {0}
  };

/**
* Constructor
*/
LuaBuilding::LuaBuilding(lua_State* state)
{
  Log::Source()->Information("LuaBuilding created");
  //register own functions for this type
  
  //TODO Fire
}

/**
* Destructor
*/
LuaBuilding::~LuaBuilding()
{

}


/**
* Fire a Bullet
*/
int LuaBuilding::Fire(lua_State* state)
{

  return 0;
}


/**
* Return Building Type
*/
BuildingType* LuaBuilding::GetType()
{
  //get from meta table the class pointer?
  return 0;
}

