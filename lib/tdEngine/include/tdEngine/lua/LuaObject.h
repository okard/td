/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

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

#ifndef LUAOBJECT_H
#define LUAOBJECT_H
    
extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

namespace tdEngine {
namespace lua {

//TODO Seperate LuaObject for Tables, Functions, Numbers?
    
/**
* Represents a LuaTable
*/    
class LuaObject
{
    private:
        /// Lua Reference
        int mLuaRef;
        
    public:
        /**
        * Creates a new LuaObject from table lying on Stack
        */
        LuaObject(lua_State* state);
        
        /**
        * Destructor
        */
        ~LuaObject();
        
        
        //Push (return LuaObject)
        //Pop
        
        //chaining
        //object.Push().PushFunc("abc").Push(5).Call(2).Pop()
};


//LuaNumber, LuaTable, LuaBool, LuaFunction, ...

} //namespace lua
} //namespace tdEngine

#endif // LUAOBJECT_H
