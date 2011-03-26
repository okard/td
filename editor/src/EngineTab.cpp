/*
    Tower Defense Game
    Copyright (C) 2011  okard

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
#include "EngineTab.moc"

#include <QToolBar>
#include <QFileDialog>

#include <engine/lua/LuaState.hpp>

using editor::EngineTab;

/**
* Creates a new Main Window
*/
EngineTab::EngineTab(QWidget *parent)
    : QWidget(parent), 
      engineWidget(this, &engine)
{
      //setup ui
    setupUi(this);

    toolBar = new QToolBar(this);
    toolBar->addAction(actionLoadScript);
    toolBar->addAction(actionOpenLuaConsole);
    toolBar->setMovable(false);

    this->layout()->addWidget(toolBar);
    this->layout()->addWidget(&engineWidget);
    
    
    connect(actionLoadScript, SIGNAL(triggered()), this, SLOT(loadScript()));
}

/**
* Destructs Main Window
*/
EngineTab::~EngineTab()
{
}


/**
* Load a lua script into engine
*/
void EngineTab::loadScript()
{
     QString fileName = QFileDialog::getOpenFileName(this, tr("Load Script"), NULL, tr("Script Files (*.lua)"));
     
     if(fileName.size() <= 0)
         return;
     
     engine.getLuaState()->LoadFile(fileName.toStdString().c_str());
     engine.getLuaState()->Execute();
}