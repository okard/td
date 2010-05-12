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

#ifndef WINDOW_H
#define WINDOW_H

//SFML Includes
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

//Project Includes
#include "State.h"
#include "RenderState.h"

/**
* Window Class
*/
class Window : public sf::RenderWindow, State, RenderState
{
  private:
    sf::Clock Clock;
    float timeElapsed;
    
    sf::String frameLabel;
    
    //TODO RenderState
    //TODO LogicState
  
  public:
    Window();
    ~Window();
    
    ///////////////////////////////////////////////////////////////////////////
    //Methods
    void run();
    
    //From RenderState
    virtual void Render(const sf::RenderTarget* target);
    
    //From logic State
    virtual void Update(float timeElapsed);
    
    
  private:
    void InitializeGL();
    void Resize(unsigned int width, unsigned int height);
};

#endif // WINDOW_H
