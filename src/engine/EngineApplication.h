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
#include <common/Log.h>
#include "EngineState.h"
#include "InputManager.h"
#include "MouseCursor.h"


// All OGRE objects are in the Ogre namespace.
using namespace Ogre;

/**
* Basic Ogre Application
*/
class EngineApplication :  public WindowEventListener, public FrameListener, public EngineState
{
    private:
        /// OGRE Root
        Root*                   mRoot;
        
        /// Default OGRE Camera
        Camera*                 mCamera;
        
        /// OGRE RenderWindow
        RenderWindow*           mWindow;
        
        /// flag indicating if the rendering loop is still running
        bool                    mRunning;
        
        ///Input Manager
        InputManager            mInputManager;
        
        ///Mouse Cursor
        MouseCursor*            mMouseCursor;
        
        ///Scene Manager
        SceneManager*           mSceneMng;
        
        ///Viewport
        Viewport*               mViewport;
    public:
        EngineApplication();
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
        
        
        RenderWindow* getRenderWindow() const;
        
        SceneManager* getSceneMng() const;
        
    private:
    
};

#endif // ENGINEAPPLICATION_H
