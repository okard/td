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

#ifndef ENGINEAPPLICATION_H
#define ENGINEAPPLICATION_H

//Cpp Includes
#include <memory>

//OGRE Includes
#include <OGRE/Ogre.h>
#include <OIS/OIS.h>

//Project Includes
#include "EngineState.h"


// All OGRE objects are in the Ogre namespace.
using namespace Ogre;

/**
* Basic Ogre Application
*/
class EngineApplication :  public WindowEventListener, public FrameListener, public EngineState
{
    private:
        /// OGRE Root
        std::auto_ptr<Root>     root;
        /// Default OGRE Camera
        Camera*                 genericCamera;
        /// OGRE RenderWindow
        RenderWindow*           window;
        /// flag indicating if the rendering loop is still running
        bool                    engineManagerRunning;
        
        //OIS Input devices
        OIS::InputManager*      mInputManager;
        OIS::Mouse*             mMouse;
        OIS::Keyboard*          mKeyboard;     
    public:
        EngineApplication();
        virtual ~EngineApplication();
        
        void Run();
    
};

#endif // ENGINEAPPLICATION_H
