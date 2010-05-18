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

#ifndef GAMESTATE_H
#define GAMESTATE_H

//Project Includes
#include <common/Log.h>
#include <engine/Window.h>
#include <engine/LogicState.h>
#include <engine/RenderState.h>
#include <engine/ResourceManager.h>

#include <data/lua/LuaState.h>
#include <data/lua/LuaInterface.h>
#include <data/lua/LuaBuildingType.h>


/**
* The Game State
*/
class GameState : public RenderState, public LogicState
{
  private:
    LuaState* luaState;
    LuaInterface* luaInterface;
    Window* window;
    ResourceManager* res;
    sf::Sprite cursor;
    //TODO Available Buildings
    //TODO Available Researches
    
    //TODO Current Map
    //TODO Current Buildings
    //TODO Current Stage
    //TODO Creatures
  public:
    GameState(Window* window);
    ~GameState();
    
    virtual void Update(float timeElapsed);
    virtual void Render(const sf::RenderTarget* target);
};

#endif // GAMESTATE_H
