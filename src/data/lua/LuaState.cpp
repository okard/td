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

#include "LuaState.h"


/**
* Constructor
*/
LuaState::LuaState()
{
  state = luaL_newstate();
}

/**
* Destructor
*/
LuaState::~LuaState()
{
  //delete luastate
  lua_close(state);
}

/**
* Load lua file
*/
void LuaState::LoadFile(const char* file)
{
    int status = luaL_loadfile(state, file);
    if (status) 
    {
        fprintf(stderr, "Couldn't load file: %s\n", lua_tostring(state, -1));
    }

}