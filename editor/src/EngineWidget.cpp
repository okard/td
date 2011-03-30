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
#include "EngineWidget.moc"

using namespace editor;
using namespace engine;

/**
* Creates new Engine Widget
*/
EngineWidget::EngineWidget(QWidget* parent, EngineInstance* engine)
    : QGLWidget(parent), engine(engine)
{
    //Register Editor Lua Functions here to
    //engine->getLuaState()
}

/**
* Initialize OpenGL
*/
void EngineWidget::initializeGL()
{
    engine->init();
}

/**
* Paint OpenGL
*/
void EngineWidget::paintGL()
{
    if(!this->isValid())
    {
        //no render context
    }
    
    //Call Engine Render Function
    engine->render();
}

/**
* Resize 
*/
void EngineWidget::resizeGL(int width, int height)
{
    //resize engine
    engine->resize(width, height);
}