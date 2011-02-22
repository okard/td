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

#include <QTextEdit>


#include <engine/EngineCore.hpp>

#include "EngineWidget.hpp"
#include "EngineTab.hpp"


using namespace editor;

/**
* Main Window Constructor
*/
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    //setup ui
    setupUi(this);
    showMaximized();
    
    //what is better?
    TabContainer->setMovable(true);
    TabContainer->setTabPosition(QTabWidget::South);
    
    // Connect actions to slots
    connect(actionNewEngineWindow, SIGNAL(triggered()), this, SLOT(newEngineTab()));
    connect(actionNewScriptWindow, SIGNAL(triggered()), this, SLOT(newScriptTab()));
    
    //EngineWidgets with specific startup lua for 
    //- Map Editor
    //- Material Editor
    //- Model Viewer
    //- Animation Viewer
    
    /*
    struct EngineApp
    {
        QString name;
        QString script;
    }
    QList<EngineApp> logins;

    QSettings settings;
    settings.beginWriteArray("logins");
    for (int i = 0; i < logins.size(); ++i) {
        settings.setArrayIndex(i);
        settings.setValue("name", list.at(i).name);
        settings.setValue("script", list.at(i).script);
    }
    settings.endArray();
    
    */
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
    int id = TabContainer->addTab(new EngineTab(this), tr("Engine"));
    TabContainer->setTabIcon(id, actionNewEngineWindow->icon());
}

/**
* New Script Tab
*/
void MainWindow::newScriptTab()
{
    //TODO Add here a QScintilla
    int id = TabContainer->addTab(new QTextEdit(this), tr("Script Editor"));
    TabContainer->setTabIcon(id, actionNewScriptWindow->icon());
}