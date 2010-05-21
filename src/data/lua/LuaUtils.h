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

#ifndef LUAUTILS_H
#define LUAUTILS_H

#include <cstdarg>
#include <string>

extern "C" 
{
#include <lua.h>
}

/**
* Creates a new Table from Basis Table
* set metatable and index property
*/
void LuaCreateTable(lua_State* state, const char* basisTable)
{
    //New table
    lua_newtable(state);
    
    //set metatable
    lua_getglobal(state, basisTable);
    if(lua_istable(state, -1))
      lua_setmetatable(state, -2);
    
    //set index field
    lua_getglobal(state, basisTable);
    lua_setfield(state, -1, "__index");
};

/**
* Pushs a Table Function in Lua
* Add also table as 'self' parameter 
*/
void LuaPushTableFunction(lua_State* state, const char* tableName, const char* functionName)
{
    //Calls Update Function from Lua Script
    lua_getfield(state, LUA_GLOBALSINDEX, tableName);
    //lua_getmetatable(state, -1);
    lua_getfield(state, -1, functionName);
    //the table is the first argument 'self'
    lua_getfield(state, LUA_GLOBALSINDEX, tableName);
};


/**
* Bind Current Value to a name
*/
void LuaGlobalBind(lua_State* state, const char* varName)
{
    lua_setfield(state, LUA_GLOBALSINDEX, varName); 
};

/**
* Get a String from Table Function
*/
std::string LuaStringTableFunction(lua_State* state, const char* tableName, const char* functionName)
{
    LuaPushTableFunction(state, tableName, functionName);
    lua_call(state, 1, 1);
    size_t len;
    const char* str = lua_tolstring(state, -1, &len);
    return std::string(str, len);
};


#endif // LUAUTILS_H
