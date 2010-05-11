/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

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

#include "Window.h"

/**
* Constructor
*/
Window::Window() : sf::Window(sf::VideoMode(800, 600, 32), "td")
{
  
}

/**
* Run Window/Game
*/
void Window::run()
{
    //represents the game loop
    bool Running = true;
    while (Running)
    {
	//Handle Events
	sf::Event Event;
	while (this->GetEvent(Event))
	{
	    // Process event
	    // Window closed
	    if (Event.Type == sf::Event::Closed)
		this->Close();

	    // Escape key pressed
	    if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
		this->Close();
	    
	    //Handle Events here
	}
	
	//Calculate time
	float Time = this->Clock.GetElapsedTime();
	this->Clock.Reset();
	
	//Update Logic
	
	//Render

	this->Display();
    }
}