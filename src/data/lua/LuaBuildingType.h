/*
    Tower Defense Game
    Copyright (C) 2010  okardr>

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

#ifndef LUABUILDINGTYPE_H
#define LUABUILDINGTYPE_H

//Cpp Includes
#include <string>

//Project Includes
#include <data/BuildingType.h>
#include <data/lua/Luna.h>
#include <data/lua/LuaState.h>
#include <data/lua/LuaInterface.h>
#include <data/lua/LuaBuilding.h>

/**
* Building Type for Lua
*/
class LuaBuildingType : public BuildingType
{
  private:
      bool registered;
      lua_State* state;
      std::string name;
      
  public:
      LuaBuildingType(lua_State*, std::string);
      //LuaBuildingType();
      virtual ~LuaBuildingType();
      
      //Game Object Interface
      virtual const char* ObjectName() const;
      
      // Building Type Interface
      virtual const char* GetName();
      virtual Building* Create();
  
      //For Lua Registration
      static const char className[];
      static const LuaBind<LuaBuildingType>::RegType Register[];
};



#endif // LUABUILDINGTYPE_H
