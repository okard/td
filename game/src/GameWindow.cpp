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
#include "GameWindow.hpp"

#include <glul/GlContext>
#include <glul/EventLoop>

#include <engine/lua/LuaState.hpp>

using namespace game;
using namespace engine;
using namespace glul;

/**
* Game Window Constructor
*/
GameWindow::GameWindow()
    : glul::GlWindow("game", 800, 600)
{
    engine.init();
}

/**
* Game Window Destructor
*/
GameWindow::~GameWindow()
{
}

/**
* Startup with specific script
*/
void GameWindow::startup(const char* file)
{
    engine.getLuaState()->LoadFile(file);
    engine.getLuaState()->Execute();
}
        
/**
* run
*/
void GameWindow::run()
{
    //TODO Improve Loop
    while(glul::EventLoopPtr->getEvent())
    {
        glul::EventLoopPtr->dispatch();
        engine.render();
    }
}

/**
* Resize Event
*/
void GameWindow::OnResize(const glul::Rect& rect)
{
    //engine.resize(rect.width, rect.height);
}

/**
* Render Event
*/
void GameWindow::OnRender()
{
    //engine.render();
    
    glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);
        glVertex3f( 0.0f, 1.0f, 0.0f);              // Top
        glColor3f(0, 1, 0);
        glVertex3f(-1.0f,-1.0f, 0.0f);              // Bottom Left
        glColor3f(0, 0, 1);
        glVertex3f( 1.0f,-1.0f, 0.0f);              // Bottom Right
    glEnd();
}



/**
* Get Engine
*/
engine::EngineCore& GameWindow::getEngine()
{
    return engine;
}
