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
#ifndef __EDITOR_ENGINETAB_HPP__
#define __EDITOR_ENGINETAB_HPP__

#include <QWidget> 
#include <QToolBar>

#include <engine/EngineCore.hpp>

#include "ui_EngineTab.h"
#include "EngineWidget.hpp"

namespace editor {
 
/**
* The Engine Tab
*/
class EngineTab : public QWidget, private Ui::EngineTab
{
    Q_OBJECT
        
private:
    /// Engine
    engine::EngineCore engine;
    
    /// Engine Widget
    EngineWidget engineWidget;
    
    /// Toolbar
    QToolBar* toolBar;
    
public:
    /**
    * Creates a new Main Window
    */
    EngineTab(QWidget *parent = 0);
    
    /**
    * Destructs Main Window
    */
    virtual ~EngineTab();
    
public slots:
    /**
    * Load a lua script into engine
    */
    void loadScript();
};
    
} //end namespace editor


#endif // __EDITOR_ENGINETAB_HPP__