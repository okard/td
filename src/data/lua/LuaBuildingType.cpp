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

#include <common/Log.h>

//COnfiguration for Lua
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
LuaBuildingType::LuaBuildingType(lua_State* state)
{
    Log::Source()->Information("LuaBuildingType created");
    //Register itself at LuaInterface
}

LuaBuildingType::~LuaBuildingType()
{
}

int LuaBuildingType::RegisterType(lua_State* state)
{
  Log::Source()->Information("Register Type");
  //Register at Lua Interface
  LuaInterface::Instance(state)->AddBuildingType(this);
  return 1;
}
       
char* LuaBuildingType::GetName()
{
  return 0;
}

      
Building* LuaBuildingType::Create()
{
  //Create new Table
  //set metatable
  //call OnCreate();
  //return Building
  return 0;
}