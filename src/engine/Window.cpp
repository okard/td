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
#include<sstream>

/**
* Constructor
*/
Window::Window() : sf::RenderWindow(sf::VideoMode(800, 600, 32), "td")
{
   SetFramerateLimit(60);
   PreserveOpenGLStates(true);
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
  // Set color and depth clear value
  //glClearDepth(1.f);
  glClearColor(0.f, 0.f, 0.f, 0.f);

  Resize(GetWidth(), GetHeight());
}

/**
* Resize
*/
void Window::Resize(unsigned int width, unsigned int height)
{
    glViewport(0, 0, width, height);
  
    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1, 0, 1, -1, 1);
  
    glMatrixMode(GL_MODELVIEW);
    // set the ModelView matrix to identity
    glLoadIdentity();
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
	    
	    //Update ViewPort
	    if (Event.Type == sf::Event::Resized)
	      Resize(Event.Size.Width, Event.Size.Height);
 
	    //Handle Events here
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
	//Position is in Pixel
	frameLabel.SetPosition(GetWidth()-r.GetWidth(), 0.f);
	this->Draw(frameLabel);
	

	this->Display();
    }
}

/**
* Render Window
*/
void Window::Render(const sf::RenderTarget* target)
{
    //Basic OpenGL Initialization
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glColor3f(1.f,0.f,0.f);
    //Demo
    glBegin(GL_QUADS);
      glVertex3f( 0.f, 0.f, 0.f);
      glVertex3f( 0.f, .5f, 0.f);
      glVertex3f( .5f, .5f, 0.f);
      glVertex3f( .5f, 0.f, 0.f);
    glEnd();
}
    
/**
* Uppdate Logic
*/
void Window::Update(float timeElapsed)
{
    //Update Logic
}