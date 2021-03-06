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
#ifndef __GAMEWINDOW_HPP__
#define __GAMEWINDOW_HPP__

#include <glul/GlWindow.hpp>
#include <glul/Types.hpp>
#include <engine/EngineInstance.hpp>

namespace game {

/**
* Game Window
*/
class GameWindow : public glul::GlWindow
{
    private:
        /// Engine Core
        engine::EngineInstance engine;

        // Current Camera

    public:
        /**
        * Create new Game Window
        */
        GameWindow();

        /**
        * Destructes Game Window
        */
        ~GameWindow();
        
        /**
        * Startup with specific script
        */
        void startup(const char* file);
        
        /**
        * run
        */
        void run();
        
        /**
        * Resize Event
        */
        virtual void OnResize(const glul::Rect& rect);
        
        /**
        * Render Event
        */
        virtual void OnRender();

        /**
        * Get Engine
        */
        engine::EngineInstance& getEngine();
};
    
} //end namespace game
    
#endif /* __GAMEWINDOW_HPP__ */