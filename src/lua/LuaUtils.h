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

extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

/**
* Get a string from lua 
* must be at stack -1
*/
std::string getLuaString(lua_State* state);

/**
* Creates a new Table from given base table
*/
void LuaCreateTable(lua_State* state, const char* basisTable);

/**
* Pushs a Table Function on Stack
* requires Parameter and a Call
*/
bool LuaPushTableFunction(lua_State* state, const char* tableName, const char* functionName);

/**
* Pushs a Function from current Table
* return false when parent is not a table or function is not found
* requires parameter and a call when returning true
*/
bool LuaPushFunction(lua_State* state,  const char* functionName);

/**
* Bind Value on Stack to a Global Name
*/
void LuaGlobalBind(lua_State* state, const char* varName);

/**
* Calls a lua funtion returning a string
*/
std::string LuaStringTableFunction(lua_State* state, const char* tableName, const char* functionName);

/**
* Reads a lua table string field
*/
std::string LuaStringTableField(lua_State* state, const char* tableName, const char* fieldName);



#endif // LUAUTILS_H
