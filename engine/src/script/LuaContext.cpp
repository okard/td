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
#include <engine/script/LuaContext.hpp>


using engine::script::LuaContext;

/**
* Creates a new LuaConext for given lua_State
*/
LuaContext::LuaContext(lua_State* state)
    : luaState(state), stacksize(lua_gettop (luaState))
{
}

/**
* Destructor
*/
LuaContext::~LuaContext()
{
}

/**
* Assign lua_State
*/
void LuaContext::operator=(lua_State* state)
{
    assign(state);
}


/**
* Assign Context to a lua_State
*/
void LuaContext::assign(lua_State* state)
{
    luaState = state;
    stacksize = lua_gettop (luaState);
}

/**
* validate the lua stack
*/
bool LuaContext::validate()
{
    return (stacksize == lua_gettop (luaState));
}

/**
* validate grow of lua lua stack
*/
bool LuaContext::validate(unsigned int grow)
{
    return (stacksize + grow == lua_gettop (luaState));
}

/**
* get stack count
*/
int LuaContext::stackCount()
{
    return lua_gettop (luaState);
}