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


std::string getLuaString(lua_State* state);

void LuaCreateTable(lua_State* state, const char* basisTable);

void LuaPushTableFunction(lua_State* state, const char* tableName, const char* functionName);

void LuaGlobalBind(lua_State* state, const char* varName);

std::string LuaStringTableFunction(lua_State* state, const char* tableName, const char* functionName);

std::string LuaStringTableField(lua_State* state, const char* tableName, const char* fieldName);



#endif // LUAUTILS_H
