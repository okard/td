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

#include "LuaInterface.h"

#include <common/Log.h>

const char LuaInterface::className[] = "LuaInterface";

/**
* Constructor
*/
LuaInterface::LuaInterface(lua_State* state) : state(state)
{
  Log::Source()->Information("LuaInterface created");
  //Register Building Type
  Luna<LuaBuildingType>::Register(state);
  Luna<LuaBuilding>::Register(state);
  
  //Chekc if already registed?
  //Registering itself as
  
  //Shared.AddBuildingType
  //Shared.AddBulletType
  //Shared.AddCreatureType
}


/**
* Destructor
*/
LuaInterface::~LuaInterface()
{
  //TODO Delete all building types, creature types and bullet types
}

/**
* Interface for registering building types
*/
void LuaInterface::AddBuildingType(LuaBuildingType* buildingType)
{
  Log::Source()->Information("Add Building Type: ");
  Log::Source()->Information(buildingType->GetName());
  
  buildingTypes[std::string(buildingType->GetName())] = buildingType;
}

/**
* Get Type
*/
BuildingType* LuaInterface::GetBuildingType(char* typeName)
{
  return buildingTypes[std::string(typeName)];
}

/**
* Interface for register bullet types
*/
void LuaInterface::AddBulletType()
{
  //table
}

/**
* Interface for register creature types
*/
void LuaInterface::AddCreatureType()
{
  //table
}

/**
* Returne the LuaInterface instance for this lua_state
*/
LuaInterface* LuaInterface::Instance(lua_State*  state)
{
   return Lun<LuaInterface>::Get(state);
}