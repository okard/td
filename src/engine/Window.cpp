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

#include "Window.h"

//CPP Includes
#include <iostream>
#include <sstream>

/**
* Constructor
*/
Window::Window() : sf::RenderWindow(sf::VideoMode(800, 600, 32), "td")
{
   SetFramerateLimit(60);
   //PreserveOpenGLStates(true);
   ShowMouseCursor(false);
   InitializeGL();
   
   //Init Frame Label
   frameLabel.SetFont(sf::Font::GetDefaultFont());
}

/**
* Destructor
*/
Window::~Window()
{
}

/**
* Initialize OpenGL
*/
void Window::InitializeGL()
{
  Resize(GetWidth(), GetHeight());
}

/**
* Resize
*/
void Window::Resize(unsigned int width, unsigned int height)
{
    glViewport(0, 0, width, height);
    
    sf::View& v = this->GetDefaultView();
    v.SetFromRect(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
  
    /*
    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1, 0, 1, -1, 1);
    
    
  
    glMatrixMode(GL_MODELVIEW);
    // set the ModelView matrix to identity
    glLoadIdentity();
    */
}


/**
* Run Window/Game
*/
void Window::run()
{
    //represents the game loop
    bool Running = true;
    while (Running && this->IsOpened())
    {
	//Handle Events
	while (this->GetEvent(lastEvent))
	{
	    // Process event
	    // Window closed
	    if (lastEvent.Type == sf::Event::Closed)
		this->Close();

	    // Escape key pressed
	    if ((lastEvent.Type == sf::Event::KeyPressed) && (lastEvent.Key.Code == sf::Key::Escape))
		this->Close();
	    
	    //Update ViewPort
	    if (lastEvent.Type == sf::Event::Resized)
	      Resize(lastEvent.Size.Width, lastEvent.Size.Height);
 
	    //Handle Events here
	    //if(Event.Type == sf::Event::MouseMoved)
	      
	}
	
	//Calculate time
	timeElapsed = this->Clock.GetElapsedTime();
	this->Clock.Reset();
	
	//Update Logic
	this->Update(timeElapsed);
	
	//Render
	this->Clear();
	this->SetActive();
	this->Render(this);
	
	//Frame Rate Label
	std::ostringstream out;
	out.precision(3);
	out << 1.f / GetFrameTime();;
	frameLabel.SetText(sf::Unicode::Unicode::Text(out.str()));
	sf::FloatRect r = frameLabel.GetRect();
	
	//std::cout << "Bottom: " << r.Bottom << " Left: " << r.Left;
	//std::cout << "Right: " << r.Right << " Top: " << r.Top << std::endl;
	
	//Position is in Pixel
	frameLabel.SetScale(0.005f, 0.005f);
	frameLabel.SetPosition(0.0f, 0.0f);
	this->Draw(frameLabel);
	

	this->Display();
    }
}

/**
* Render Window
*/
void Window::Render(const sf::RenderTarget* target)
{
    if(renderState != 0)
      renderState->Render(target);
}
    
/**
* Update Logic
*/
void Window::Update(float timeElapsed)
{
    //Update Logic
    if(logicState != 0)
      logicState->Update(timeElapsed);
}

/**
* Switch State
*/
void Window::SwitchState(LogicState* state, RenderState* renderState)
{
  this->renderState = renderState;
  this->logicState = state;
}
