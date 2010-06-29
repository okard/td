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
#include <tdEngine/Log.h>
#include <lua/LuaUtils.h>

using namespace Common;


/**
* Lua Functions
*/
const LuaBind<LuaBuilding>::RegType LuaBuilding::Register[] = 
{
      { "Fire", &LuaBuilding::Fire},
      {0}
};




/**
* Constructor
*/
LuaBuilding::LuaBuilding(lua_State* state, std::string& name, LuaBuildingType* buildingType) 
    : LuaGameObject(state, name), buildingType(buildingType)
{
    //Open Table
    PushThis();
    
    //copy table for registering functions
    lua_pushvalue(state, -1);
    
    //Register Instance Functions for new Table
    //Pops one table
    LuaFunctions<LuaBuilding>::Register(state, this);
    
    
    //Call OnCreate
    if(LuaPushFunction(state, "OnCreate"))
        lua_call(state, 1, 0);
    else
        LogEvent() << "Failed to call OnCreate for: " << getObjectName() << LogEvent::End;
    
    //Sprite
    /*
    lua_getfield(state, -1, "sprite");
    sprite.SetImage(ResourceManager::GetInstance()->GetImage(getLuaString(state)));
    sprite.Resize(0.2f, 0.2f);
    lua_pop(state, 1);
    
    lua_getfield(state, -1, "icon");
    icon.SetImage(ResourceManager::GetInstance()->GetImage(getLuaString(state)));
    lua_pop(state, 1);
    */
    
    //pop table
    lua_pop(state, 1); 
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
    //save reference for this function?
    //push itself on stack
    PushThis();
    
    //push function
    if(LuaPushFunction(getLuaState(), "Update"))
    {
        //call
        lua_pushnumber(getLuaState(), time);
        lua_call(getLuaState(), 2, 0); 
    }
    
    //pop table from stack
    lua_pop(getLuaState(), 1);
}

/**
* Fire a Bullet
*/
int LuaBuilding::Fire(lua_State* state)
{
  LogEvent(LogType::Information) << "Fire Called";
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

/**
* Get Object Name
*/
const char* LuaBuilding::getObjectName() const
{
    return LuaGameObject::getObjectName();
}

/**
* get Fire Stratgy (Building Interface)
*/
Building::FireStrategy LuaBuilding::getFireStrategy() const
{
    return Building::Nearest;
}

/**
* Get Fire Type (Building Interface)
*/
Building::FireType LuaBuilding::getFireType() const
{
    return Building::CurrentPosition;
}


