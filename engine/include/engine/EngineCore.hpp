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


//forward declaration
namespace csoh {
    class Renderer;
}

namespace Rocket {
    namespace Core {
        class Context;
    }
}

namespace engine {
    namespace script {
        class LuaState;
    }
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
    csoh::Renderer* renderer;
    
    /// Lua State
    script::LuaState* lua;
    
    /// GUI 
    Rocket::Core::Context* ui;

private:
    static void initialize();
    
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

    /**
    * Get Lua State
    */
    script::LuaState* getLuaState();
    
    /**
    * Get libRocket Context
    */
    Rocket::Core::Context* getUiContext();
    
};


} //end namespace engine

#endif /* __ENGINECORE_HPP__ */
