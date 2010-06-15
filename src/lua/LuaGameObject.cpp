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

#include "LuaGameObject.h"

#include <sstream>

#include <common/Log.h>

/**
* Constructor
*/
LuaGameObject::LuaGameObject(lua_State* state, std::string& name): mLuaState(state), mName(name)
{
    //check if table with given name exist?
    //else throw exception
    
    Common::LogEvent() << "GameObject created: " << mName << Common::LogEvent::End;
}

/**
* Destructor
*/
LuaGameObject::~LuaGameObject()
{
    //set to nil?
}

/**
* Get Name
*/
const char* LuaGameObject::getObjectName() const
{
    return mName.c_str();
}

/**
* Create new GameObject inherited from this
*/
void LuaGameObject::Create(std::string& name)
{
    //Create Lua Table inherit from mName
    LuaCreateTable(mLuaState, mName.c_str());
    
    //Save value
    LuaGlobalBind(mLuaState, name.c_str());
}

/**
* Return Lua State
*/
lua_State* LuaGameObject::getLuaState()
{
    return mLuaState;
}


//id_index
unsigned short LuaGameObject::idIndex = 0;


/**
* ID Generator
*/
const char* LuaGameObject::id(const char* typeName)
{
  std::ostringstream stream;
  stream << typeName << '_';
  stream.width(4);
  stream.fill('0');
  stream << std::hex << idIndex++;
  return stream.str().c_str();
}
