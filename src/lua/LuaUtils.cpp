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

#include "LuaUtils.h"


/**
* Gets a CPP String from current lua_State
*/
std::string getLuaString(lua_State* state)
{
    if(lua_isstring(state, -1))
    {
        size_t len;
        const char* str = lua_tolstring(state, -1, &len);
        return std::string(str, len);
    }
    else
        return "";
}


/**
* Creates a new Table from Basis Table
* set metatable and index property
*/
void LuaCreateTable(lua_State* state, const char* basisTable)
{
    //New table
    lua_newtable(state);
    
    //TODO better error checking
    
    //set metatable
    lua_getglobal(state, basisTable);
    if(!lua_istable(state, -1))
    {
        lua_pop(state, 1);
        return;
    }
    //required twice so push it again
    lua_pushvalue(state, -1);
    
    //set metatable 
    //new table at position 3 because of basis table laying twice on the stack
    lua_setmetatable(state, -3);
    
    //set index field
    lua_setfield(state, -1, "__index");
};

/**
* Pushs a Table Function in Lua,
* Add also table as 'self' parameter 
*/
bool LuaPushTableFunction(lua_State* state, const char* tableName, const char* functionName)
{
    //Calls Update Function from Lua Script
    lua_getfield(state, LUA_GLOBALSINDEX, tableName);
    
    if(!LuaPushFunction(state, functionName))
    {
        lua_pop(state, -1); //pop table or nil value
        return false;
    }    
    
    return true;
};

/**
* lua push function
*/
bool LuaPushFunction(lua_State* state, const char* functionName)
{
    //check top value must be a table
    if(!lua_istable(state, -1))
        return false;
    
    //get function
    lua_getfield(state, -1, functionName);
    
    //check if function is found
    if(!lua_isfunction(state, -1))
    {
        lua_pop(state, 1);
        return false;
    }
    
    //push table as self parameter
    lua_pushvalue(state, -2);
    
    return true;
}


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
    return getLuaString(state);
};

/**
* Get Table String Field
*/
std::string LuaStringTableField(lua_State* state, const char* tableName, const char* fieldName)
{
    //get table
    lua_getglobal(state, tableName);
    
    //get table field
    lua_getfield(state, -1, fieldName);
    
    return getLuaString(state);
}