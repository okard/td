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

#include "LuaGameObject.h"

#include <sstream>

extern "C" 
{
#include <lauxlib.h>
}

#include <tdEngine/Log.h>

using namespace Common;

/**
* Constructor
*/
LuaGameObject::LuaGameObject(lua_State* state, std::string& name): mLuaState(state), mName(name)
{
    //get table
    lua_getglobal(mLuaState, name.c_str());
    
    //check if exist
    if(!lua_istable(state, -1))
    {
        lua_pop(state, 1); //pop X from getglobal value
        throw "LuaGameObject does not exist";
    }
    
    //get lua reference (pops table)
    mLuaRef = luaL_ref(state, LUA_REGISTRYINDEX);
    
    //game object created
    Common::LogEvent() << "GameObject created: " << mName << Common::LogEvent::End;
}

/**
* Destructor
*/
LuaGameObject::~LuaGameObject()
{
    //set to nil?
    luaL_unref(mLuaState, LUA_REGISTRYINDEX, mLuaRef);
}

/**
* Get Name
*/
const char* LuaGameObject::getObjectName() const
{
    return mName.c_str();
}

/**
* Create new GameObject inherited from this
*/
void LuaGameObject::Create(std::string& name)
{
    //New table
    lua_newtable(mLuaState);
    //push itself
    PushThis();
    //required twice so push it again
    lua_pushvalue(mLuaState, -1);
    
    //set metatable 
    //new table at position 3 because of basis table laying twice on the stack
    lua_setmetatable(mLuaState, -3);
    
    //set index field
    lua_setfield(mLuaState, -1, "__index");

    //Save value
    LuaGlobalBind(mLuaState, name.c_str());
}

/**
* Return Lua State
*/
lua_State* LuaGameObject::getLuaState()
{
    return mLuaState;
}

/**
* Push this lua object on stack
*/
void LuaGameObject::PushThis()
{
    //TODO Error Checks
    
    //push reference instead of string
    lua_rawgeti(mLuaState, LUA_REGISTRYINDEX, mLuaRef);

    
    //Open Table
    //lua_getglobal(mLuaState, getObjectName());
}
