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

#include "LuaState.hpp"

#include <cul/log/Log>

using namespace engine;
using namespace script;

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
        LOG("Couldn't load file: " << lua_tostring(state, -1))
    }

}

/**
* Execute
*/
int LuaState::Execute()
{
  return lua_pcall(state, 0, LUA_MULTRET, 0);
}
