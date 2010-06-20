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

#ifndef ENGINEAPPLICATION_H
#define ENGINEAPPLICATION_H

//Cpp Includes
#include <memory>

//OGRE Includes
#include <OGRE/Ogre.h>


//Project Includes
#include "IEngineState.h"
#include "InputManager.h"
#include "MouseCursor.h"


// All OGRE objects are in the Ogre namespace.
using namespace Ogre;

/**
* Basic Ogre Application
*/
class EngineApplication :  public WindowEventListener, public FrameListener
{
    private:
        /// OGRE Root
        Root*                   mRoot;
        
        /// OGRE RenderWindow
        RenderWindow*           mWindow;
        
        /// flag indicating if the rendering loop is still running
        bool                    mRunning;
        
        ///Input Manager
        InputManager            mInputManager;
        
        ///Mouse Cursor
        MouseCursor*            mMouseCursor;
        
        ///Current Engine State
        IEngineState*            mState;
        
        /// Elapsed Time
        unsigned int            mElapsedTime;
    public:
        /**
        * Constructor
        */
        EngineApplication();
        
        /**
        * Destructor
        */
        virtual ~EngineApplication();
        
        /**
        * Window Resize Event
        */
        void windowResized (RenderWindow *rw);
        
        /**
        * Window Close Event
        */
        void windowClosed(RenderWindow* rw);
        
        /**
        * Called once per frame.
        */
        bool frameStarted(const FrameEvent& evt);

        /**
        * Run Application
        */
        void Run();
        
        /**
        * Stop Application
        */
        void Stop();
        
        /**
        * Start State
        */
        void StartState(IEngineState* state, bool shutdown = true);
        
        /**
        * Get RenderWindow
        */
        RenderWindow* getRenderWindow() const;
        
        /**
        * Get Ogre Root
        */
        Root* getRoot() const;
        
        /**
        * Get Input Manager
        */
        InputManager& getInputManager();
        
        /**
        * Get elapsed time in microseconds
        */
        unsigned int getElapsedTime();
        
    protected:
        /**
        * Create the Render Window
        */
        virtual RenderWindow* createRenderWindow();
    
};

#endif // ENGINEAPPLICATION_H
