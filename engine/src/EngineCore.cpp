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

#include "egCom.h"
#include "egModules.h"
#include "egRenderer.h"

using namespace engine;
using namespace Horde3D;

/**
* Create new engine core
*/
EngineCore::EngineCore()
    : renderer(new Horde3D::Renderer())
{
}

/**
* Destructor
*/
EngineCore::~EngineCore()
{
    delete renderer;
}

/**
* Initialize Engine core
*/
void EngineCore::init()
{
    //fix Module Class
    Modules::init();
    Modules::config().setOption(EngineOptions::MaxLogLevel, 4.0);
    renderer->init();
}

/**
* Resize Renderer
*/
void EngineCore::resize(int width, int height)
{
    
}

/**
* Render a frame
*/
void EngineCore::render()
{
    
}


