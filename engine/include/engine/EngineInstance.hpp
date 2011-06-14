/*
    TD Game Engine
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

#include <cul/String.hpp>


//forward declaration
namespace csoh {
    class RenderContext;
}

namespace Rocket {
    namespace Core {
        class Context;
    }
}

namespace engine {
    namespace lua {
        class LuaState;
    }
}

//engine namespace
namespace engine {

//fix double named init functions
    
/**
* TD Game Engine
*/
class EngineInstance
{
private:
    /// Renderer
    csoh::RenderContext* renderer;
    
    /// Lua State
    lua::LuaState* lua;
    
    /// GUI Context
    Rocket::Core::Context* ui;
    /// GUI Context Name
    cul::string uiName;
    
public:
    /**
    * Create new Engine Core
    */
    EngineInstance();
    
    /**
    * Destructor
    */
    ~EngineInstance();
    
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

    /**
    * Get Lua State
    */
    lua::LuaState* getLuaState();
    
    /**
    * Get libRocket Context
    */
    Rocket::Core::Context* getUiContext();
    
};


} //end namespace engine

#endif /* __ENGINECORE_HPP__ */
