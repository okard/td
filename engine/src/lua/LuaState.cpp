/*
    TD Game Engine
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

#include <engine/lua/LuaState.hpp>

#include <engine/Exception.hpp>

using engine::lua::LuaState;

/**
* Constructor
*/
LuaState::LuaState() : state(lua_open())
{
  luaL_openlibs(state); 
}

/**
* Destructor
*/
LuaState::~LuaState()
{
  //delete luastate
  lua_close(state);
  state = 0;
}

/**
* returning lua_state
*/
lua_State* LuaState::getState() const
{
  return state;
}

/**
* Cast to lua_State
*/
LuaState::operator lua_State*()
{
    return state;
}

/**
* Load lua file
*/
void LuaState::LoadFile(const char* file)
{
    int status = luaL_loadfile(state, file);
    if (status) 
    {
        throw engine::Exception("Can't load lua file");
        //LOG("Couldn't load file: " << lua_tostring(state, -1))
    }

}

/**
* Execute
*/
int LuaState::Execute()
{
  return lua_pcall(state, 0, LUA_MULTRET, 0);
}

//TODO hooking functions int lua_sethook (lua_State *L, lua_Hook f, int mask, int count);
//hook function: typedef void (*lua_Hook) (lua_State *L, lua_Debug *ar);
//lua_getinfo
//add error handling function to lua? with stacktrace?
