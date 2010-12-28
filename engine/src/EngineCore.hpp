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
#ifndef __ENGINECORE_HPP__
#define __ENGINECORE_HPP__

#include "script/LuaState.hpp"

//forward declaration
namespace Horde3D {
    class Renderer;
}

//engine namespace
namespace engine {

/**
* TD Game Engine
*/
class EngineCore
{
private:
    /// Renderer
    Horde3D::Renderer* renderer;
    
    /// Lua State
    script::LuaState lua;
    
    /// GUI 
    
public:
    /**
    * Create new Engine Core
    */
    EngineCore();
    
    /**
    * Destructor
    */
    ~EngineCore();
    
    /**
    * Initialize
    */
    void init();
    
    /**
    * Resize Renderer
    */
    void resize(int width, int height);
    
    /**
    * Render a frame
    */
    void render();    
};


} //end namespace engine

#endif /* __ENGINECORE_HPP__ */
