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
#include <engine/EngineInstance.hpp>

//cul includes
#include <cul/String.hpp>
#include <cul/Convert.hpp>

//CSOH Includes
#include <csoh/RenderContext.hpp>

//libRocket Includes
#include <Rocket/Core.h>

// Engine Includes
#include <engine/Exception.hpp>
#include <engine/lua/LuaState.hpp>
#include <engine/ui/SystemInterface.hpp>
#include <engine/ui/RenderInterfaceOpenGL.hpp>

using engine::EngineInstance;
using engine::lua::LuaState;

#include <string>

template<typename T>
cul::string GenId()
{
    //TODO optimize?
    static unsigned int id = 0;
    cul::string str("id-\0");
    char* idStr = cul::Str::to(++id);
    str += idStr;
    delete idStr;
    
    return str;
}

/**
* Create new engine core
*/
EngineInstance::EngineInstance()
    : renderer(new csoh::RenderContext()),
      lua(new lua::LuaState()), 
      ui(0),
      uiName(5)
{    
    //general init
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
    
    // Initialize libRocket Context
    // Store name in a memory safe container
    uiName = GenId<Rocket::Core::Context>();
    ui = Rocket::Core::CreateContext(uiName.c_str(), Rocket::Core::Vector2i(1024, 768));
    
    //TODO Register Lua Interface
}

/**
* Destructor
*/
EngineInstance::~EngineInstance()
{
    //destroy csoh renderer
    delete renderer;
    
    //destroy librocket context
    ui->RemoveReference();
}

/**
* Initialize Engine core
*/
void EngineInstance::init()
{   
    //Initialize Render Stuff
    renderer->init();
}

/**
* Resize Renderer
*/
void EngineInstance::resize(int width, int height)
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
void EngineInstance::render()
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
LuaState* EngineInstance::getLuaState()
{
    return lua;
}


/**
* Get libRocket Context
*/
Rocket::Core::Context* EngineInstance::getUiContext()
{
    return ui;
}


