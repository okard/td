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

#include <tdEngine/Log.h>

using namespace Common;

/**
* Lua Class Name
*/
const char LuaInterface::className[] = "LuaInterface";

/**
* Functions to Bind for Lua
*/
const LuaBind<LuaInterface>::RegType LuaInterface::Register[] = 
{
    { "RegisterGameObject", &LuaInterface::RegisterGameObject},
    { "LoadScript", &LuaInterface::LoadScript },
    { "Spawn", &LuaInterface::Spawn },
    {0,0}
};

/**
* Constructor
*/
LuaInterface::LuaInterface(lua_State* state) : state(state)
{
  LogEvent(LogType::Information) << "LuaInterface created";
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
* Register a Game Object
*/
int LuaInterface::RegisterGameObject(lua_State* state)
{
    //requires two parameter table, string
    //get the type property from table
    //and register the right type with given name
    //lua_istable(state, -1);
    
    //check first param
    if(!lua_istable(state, -2))
    {
        LogEvent() << "RegisterGameObject: Require Table as first parameter" << LogEvent::End;
        lua_pop(state, 2);
        return 0;
    }
    
    //check second param
    if(!lua_isstring(state, -1))
    {
        LogEvent() << "RegisterGameObject: Require String as second parameter" << LogEvent::End;
        lua_pop(state, 2);
        return 0;
    }
    
    //get typefield from table
    lua_getfield(state, -2, "type");
    
    //error check
    if(!lua_isstring(state, -1))
    {
        LogEvent() << "RegisterGameObject: Given table needs a string type field" << LogEvent::End;
        lua_pop(state, 3); //pop table, string, and not right field value
        return 0;
    }
    
    std::string type = getLuaString(state);
    lua_pop(state, 1);
    
    //get object name to register it
    std::string objectName = getLuaString(state);
    
    //register objects for types
    if(type == "Building")
    {
        LuaBuildingType* buildingType = new LuaBuildingType(state, objectName);
        buildingTypes.insert(std::make_pair<std::string, LuaBuildingType*>(buildingType->getTypeName(), buildingType));
    }
    
    // TODO Register GameObjects with Type Bullet, Research, Creature
    
    LogEvent() << "RegisterGameObject: '" << objectName << "' with type: " << type << LogEvent::End;
    
    //pop table and string
    lua_pop(state, 2);
    
    //important to set return values
    return 0;
}

/**
* Lua Function loading script
*/
int LuaInterface::LoadScript(lua_State* state)
{
    size_t len;
    const char* str = lua_tolstring(state, -1, &len);
    std::string scriptName(str,len);// = std::string(str, len);
    lua_pop(state, 1);
    
    LogEvent(LogType::Information) << "Load Script: " << scriptName;
    //Load Script File
    int status = luaL_loadfile(state, scriptName.c_str());
    if (status) 
    {
        Log::Source().Event() << "Couldn't load file: " << lua_tostring(state, -1) << LogEvent::End;
        return 0;
    }
    return lua_pcall(state, 0, LUA_MULTRET, 0);
}

/**
* Spawn Game Objects
*/
int LuaInterface::Spawn(lua_State* state)
{
    //create anonymous objects
    
    //if it is table create a object inherited from this table
    if(lua_istable(state, -1))
    {
        
    }
    
    //use string as basis class
    if(lua_isstring(state, -1))
    {
        
    }
   
    
    //get string from state
    //get table from state?
    //create new gameobejct for this type?
    //Create GameObject?
    
    
    return 0; //failed?
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
* Returne the LuaInterface instance for this lua_state
*/
LuaInterface* LuaInterface::Instance(lua_State*  state)
{
   return LuaSingleton<LuaInterface>::Get(state);
}