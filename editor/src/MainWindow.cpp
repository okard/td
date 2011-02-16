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
#include "MainWindow.moc"

#include <engine/EngineCore.hpp>
#include "EngineWidget.hpp"


#include <QTextEdit>

using namespace editor;

/**
* Main Window Constructor
*/
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    //setup ui
    setupUi(this);
    
    // Connect actions to slots
    connect(actionNewEngineWindow, SIGNAL(triggered()), this, SLOT(newEngineTab()));
    connect(actionNewScriptWindow, SIGNAL(triggered()), this, SLOT(newScriptTab()));
}

/**
* Main Window Destructor
*/
MainWindow::~MainWindow()
{
}


/**
* Add new EngineTab
*/
void MainWindow::newEngineTab()
{
    //TODO Add here a Engine Widget
    
    engine::EngineCore* engine = new engine::EngineCore();
    
    QString str = "engine test";
    TabContainer->addTab(static_cast<QWidget*>(new EngineWidget(this, engine)), str);
}

/**
* New Script Tab
*/
void MainWindow::newScriptTab()
{
    //TODO Add here a QScintilla
    QString str = "script test";
    TabContainer->addTab(static_cast<QWidget*>(new QTextEdit(this)), str);
}