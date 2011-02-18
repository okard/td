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

#include <cul/Singleton.hpp>

namespace engine {
namespace lua {

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
        /**
        * Creates a new LuaConext for given lua_State
        */
        LuaContext(lua_State* state);
        /**
        * Destructor
        */
        ~LuaContext();
        
        /**
        * Assign lua_State
        */
        void operator= (lua_State* state);
    
        /**
        * Assign Context to a lua_State
        */
        void assign(lua_State* state);
        
        /**
        * validate the lua stack
        */
        bool validate();
        
        /**
        * validate grow of lua lua stack
        */
        bool validate(unsigned int grow);
    
        /**
        * get stack count
        */
        int stackCount();
        

        //Push-Methods
        //* String
        //* Function
        
        
        //Get-Methods
        //* Number
        //* String
        
        //Call
        
        //Create-Methods
        //* CreateTable
        
        
        //LoadScript?
};

} //end namespace script
} //end namespace engine

#endif /* __LUACONTEXT_HPP__ */