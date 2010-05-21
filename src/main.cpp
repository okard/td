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

#include <common/Log.h>
#include <engine/Window.h>

#include <state/GameState.h>

#include<iostream>

/**
* main
*/
int main(int argc, char **argv) 
{
    ConsoleListener* l = new ConsoleListener();
    Log::Source().AddListener(l);
    LogEvent() << "Program started" << LogEvent::End;
    
    //TODO Initial load MenuState
    
    //Running main window
    Window*  w = new Window();
    //GameState
    GameState* gamestate = new GameState(w);
    w->SwitchState(gamestate, gamestate);
    w->run();
    
    return 0;
}
