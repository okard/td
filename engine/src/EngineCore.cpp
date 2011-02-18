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
#include <engine/EngineCore.hpp>

//CSOH Includes
#include <csoh/Renderer.hpp>

//libRocket Includes
#include <Rocket/Core.h>

// Engine Includes
#include <engine/Exception.hpp>
#include <engine/lua/LuaState.hpp>
#include <engine/ui/SystemInterface.hpp>
#include <engine/ui/RenderInterfaceOpenGL.hpp>

using engine::EngineCore;
using engine::lua::LuaState;

#include <string>

template<typename T>
const char* GenId()
{
    static unsigned int id = 0;
    std::string str("id-");
    str += ++id;
    return str.c_str();
}

/**
* Create new engine core
*/
EngineCore::EngineCore()
    : renderer(new csoh::Renderer()),
      lua(new lua::LuaState()), ui(0)
{    
    //general init
    initialize();
    
    // Can Initialize Rocket Context without valuid OpenGL Context
    ui = Rocket::Core::CreateContext(GenId<Rocket::Core::Context>(), Rocket::Core::Vector2i(1024, 768));
    
    //TODO Register Lua Interface
}

/**
* Destructor
*/
EngineCore::~EngineCore()
{
    //delete horde renderer
    delete renderer;
    
    //delete ui
    ui->RemoveReference();
    delete ui;
}


/**
* Static EngineCore Initialize
*/
void EngineCore::initialize()
{
    static bool init = false;
    
    // Initialize Things here only once in whole program
    if(!init)
    {
        //Initialize Static liBRocket Stuff
        Rocket::Core::SetSystemInterface(new SystemInterface());
        Rocket::Core::SetRenderInterface(new RenderInterfaceOpenGL());
        if(!Rocket::Core::Initialise())
        {
            throw Exception("Can't initialize Rocket::Core");
        }
        
        //init done
        init = true;
    }
}

/**
* Initialize Engine core
*/
void EngineCore::init()
{
    //Initialize Render Stuff
    renderer->init();
}

/**
* Resize Renderer
*/
void EngineCore::resize(int width, int height)
{
    //resize horde renderer
    renderer->resize(0,0, width, height);
    
    //resize libRocket ui 
    //Rocket::Core::Vector2i dim(width, height);
    //ui->SetDimensions(dim);
}

/**
* Render a frame
*/
void EngineCore::render()
{
    //render
    renderer->startRender();
    //renderer->render( CameraNode *camNode );
    //renderer->finalizeFrame();
    
    //render UI
    //ui->
    ui->Render();
    ui->Update();
}

/**
* Get Lua State
*/
LuaState* EngineCore::getLuaState()
{
    return lua;
}


/**
* Get libRocket Context
*/
Rocket::Core::Context* EngineCore::getUiContext()
{
    return ui;
}


