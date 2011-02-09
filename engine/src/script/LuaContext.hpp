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
#ifndef __LUACONTEXT_HPP__
#define __LUACONTEXT_HPP__

//Lua Includes
extern "C" 
{
    #include <lua.h>
    #include <lauxlib.h>
    #include <lualib.h>
}

#include <cul/Singleton>

namespace engine {
namespace script {

/**
* Higher Level Access to LuaState
* Provides utility functions for lua_State
*/
class LuaContext : cul::Singleton<LuaContext>
{
    private:
        ///stack size at start
        int stacksize;
        
        ///lua state
        lua_State* luaState;
      
    public:
        LuaContext(lua_State* state);
        ~LuaContext();
    
        void assign(lua_State* state);
        bool validate();
        bool validate(unsigned int grow);
    
        
        //int getStackSize(); lua_gettop
        //LuaContext& operator= (lua_State* state);
        //make a default singleton instance
        
        //GetString
        //PushFunction
        //CreateTable
        //LoadScript?
};

} //end namespace script
} //end namespace engine

#endif /* __LUACONTEXT_HPP__ */