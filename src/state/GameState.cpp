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

#include "GameState.h"


/**
* Constructor
*/
GameState::GameState(Window* window) : window(window), res(ResourceManager::GetInstance())
{
    luaInterface = LuaInterface::Instance(luaState);
    
    luaState.LoadFile("data/buildings/canontower.lua");
    luaState.Execute();
    
    BuildingType* type = luaInterface->GetBuildingType("CanonTower");
    if(type == 0)
      Log::Source()->Information("No CanonTower");
    else
    {
      Building* b = type->Create();
      b->Update(500);
    }
    
    //load cursor
    cursor.SetImage(res->GetImage("data/cursor.tga"));
    cursor.Resize(0.05f, 0.05f);
}

/**
* Destrcutor
*/
GameState::~GameState()
{
  //delete luaState;
}

/**
* Render Function
*/
void GameState::Render(const sf::RenderTarget* target)
{
  
    //Basic OpenGL Initialization
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    //glEnable(GL_TEXTURE_2D);
    //Map
    //Buildings
    //Creatures
    //Bullets
    //GUI
    //Mouse Cursor
    
    sf::Vector2f pos = window->ConvertCoords(window->GetInput().GetMouseX(), 
					     window->GetInput().GetMouseY(), NULL);
					  
    //std::cout << "X: " << pos.x << " Y: " << pos.y << std::endl;
    
    sf::Shape quad = sf::Shape::Rectangle(pos.x-0.1f, pos.y-0.1f, pos.x+0.1f, pos.y+0.1f, sf::Color::Red);
    
    cursor.SetPosition(pos);
    
    //window->Draw(quad);
    window->Draw(cursor);
    
    
}

/**
* Logic Update
*/
void GameState::Update(float timeElapsed)
{

}
