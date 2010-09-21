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
#ifndef __LUASTATE_HPP__
#define __LUASTATE_HPP__

//Lua Includes
extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}


namespace engine {
namespace script {

//TODO Add Script.Load to vm at creation

/**
* Lua State
*/
class LuaState
{
  private:
    /// the lua state
    lua_State *state;
    
  public:
    /**
    * Creates a new LuaState
    */
    LuaState();
    
    /**
    * Destructor
    */
    ~LuaState();
    
    /**
    * Load a file
    */
    void LoadFile(const char* file);
    
    /**
    * Execute Lua Scripts
    */
    int Execute();
    
    /**
    * Cast Operator for lua_State*
    */
    operator lua_State* ();
    
    /**
    * Get the lua state manually
    */
    lua_State* getState() const;  
};

} //namespace script
} //namespace engine

#endif /* __LUASTATE_HPP__ */
