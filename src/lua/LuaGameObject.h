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

#ifndef LUAGAMEOBJECT_H
#define LUAGAMEOBJECT_H

//Cpp Includes
#include <string>

//Project Includes
#include "LuaUtils.h"
#include <model/GameObject.h>


/**
* Represents Lua Game Object
*/
class LuaGameObject : public GameObject
{
    private:
        /// Object Name
        std::string mName;
        
        /// Lua State
        lua_State* mLuaState;
        
    public:
        /**
        * Constructor
        */
        LuaGameObject(lua_State* state, std::string& name);
        
        /**
        * Destructor
        */
        ~LuaGameObject();
        
        /**
        * get Object Name
        */
        virtual const char* getObjectName() const;
        
        /**
        * return lua state
        */
        lua_State* getLuaState();
        
        /**
        * Create a new LuaGameObject inherited from current one
        */
        virtual void Create(std::string& name);
        
        
        //get property?
        //getStringProperty()
        //getIntProperty()
        
        //general: LuaTable?
        //get type? Building, Bullet, Research, Creatures
        
    private:
        /// id count for id generator
        static unsigned short idIndex;
    protected:
        /// id generator function
        static const char* id(const char* typeName);
};

#endif // LUAGAMEOBJECT_H
