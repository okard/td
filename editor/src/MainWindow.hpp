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
#ifndef __EDITOR_MAINWINDOW_HPP__
#define __EDITOR_MAINWINDOW_HPP__

#include <QMainWindow> 

#include "ui_MainWindow.h"

namespace editor {

/**
* Editor Main Window 
*/
class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT
    
public:
    /**
    * Creates a new Main Window
    */
    MainWindow(QWidget *parent = 0);
    
    /**
    * Destructs Main Window
    */
    virtual ~MainWindow();

public slots:
    void newEngineTab();
    void newScriptTab();
    
};

} //end namespace editor

#endif //__EDITOR_MAINWINDOW_HPP__
