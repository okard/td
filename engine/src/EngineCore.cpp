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
#include "EngineCore.hpp"

//Horde3D
#include "egCom.h"
#include "egModules.h"
#include "egRenderer.h"

//LibRocket
#include <Rocket/Core.h>

#include "script/LuaState.hpp"
#include "ui/SystemInterface.hpp"
#include "ui/RenderInterfaceOpenGL.hpp"

using namespace engine;
using namespace Horde3D;

/**
* Create new engine core
*/
EngineCore::EngineCore()
    : renderer(new Horde3D::Renderer()),
      ui(Rocket::Core::CreateContext("default", Rocket::Core::Vector2i(1024, 768))),
      lua(new script::LuaState())
{    
    initialize();
    renderer->init();
}

/**
* Destructor
*/
EngineCore::~EngineCore()
{
    delete renderer;
    delete ui;
}


/**
* EngineCore Initialize
*/
void EngineCore::initialize()
{
    static bool init = false;
    
    if(!init)
    {
        //Initialize Static Horde3D Stuff
        //TODO Rewrite Horde3D Module Class for more generic initialization
        Modules::init();
        Modules::config().setOption(EngineOptions::MaxLogLevel, 4.0);
    
        //Initialize Static liBRocket Stuff
        Rocket::Core::SetSystemInterface(new SystemInterface());
        Rocket::Core::SetRenderInterface(new RenderInterfaceOpenGL());
        Rocket::Core::Initialise();
        
        //TODO Register Lua Interface
        
        //init done
        init = true;
    }
}


/**
* Initialize Engine core
*/
void EngineCore::init()
{

}

/**
* Resize Renderer
*/
void EngineCore::resize(int width, int height)
{
    //resize horde renderer
    renderer->resize(0,0, width, height);
    
    //resize libRocket ui
    ui->SetDimensions(Rocket::Core::Vector2i(width, height));
}

/**
* Render a frame
*/
void EngineCore::render()
{
    //render Horde3D
    //renderer->render( CameraNode *camNode );
    //renderer->finalizeFrame();
    
    //render UI
    //ui->Update();
    //ui->Render();
}

/**
* Get Lua State
*/
script::LuaState* EngineCore::getLuaState()
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


