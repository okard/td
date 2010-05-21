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

/**
* Lua Class Name
*/
const char LuaInterface::className[] = "LuaInterface";

/**
* Functions to Bind for Lua
*/
const LuaBind<LuaInterface>::RegType LuaInterface::Register[] = 
{
      { "AddBuildingType", &LuaInterface::AddBuildingTypeLua},
      {0}
};

/**
* Constructor
*/
LuaInterface::LuaInterface(lua_State* state) : state(state)
{
  Log::Source()->Information("LuaInterface created");
  buildingTypes.clear();
  //Register Building Type
  //Luna<LuaBuildingType>::Register(state);
  
  //Registering itself to "Shared" table
  LuaFunctions<LuaInterface>::RegisterTable(state, this, "Shared");
  
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
* Lua Functions
* registering a building type
*/
int LuaInterface::AddBuildingTypeLua(lua_State* state)
{
    //get string and create BuildingType Object from it
    size_t len;
    const char* str = lua_tolstring(state, -1, &len);
    std::string name(str,len);// = std::string(str, len);
    lua_pop(state, 1);
    
    Log::Source()->Information(name.c_str());
    
    LuaBuildingType* buildingType = new LuaBuildingType(state, name);
    //AddBuildingType(buildingType);
    //buildingTypes.insert(std::map<std::string, LuaBuildingType>::value_type(name, LuaBuildingType(state, name)));
    //buildingTypes[buildingType->GetName()] = 0;
    //building
    buildingTypes.insert(std::make_pair<std::string, LuaBuildingType*>(buildingType->GetName(), buildingType));
    
    
    return 0;
}

/**
* Interface for registering building types
*/
void LuaInterface::AddBuildingType(LuaBuildingType* buildingType)
{
  Log::Source()->Information("Add Building Type: ");
  //Log::Source()->Information(buildingType->GetName());
  
  //std::string name();
  //buildingTypes[buildingType->GetName()] = buildingType;
}

/**
* Get Type
*/
BuildingType* LuaInterface::GetBuildingType(char* typeName)
{
    if(buildingTypes.find(typeName) == buildingTypes.end())
        return 0;
    else
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
   return LuaSingleton<LuaInterface>::Get(state);
}