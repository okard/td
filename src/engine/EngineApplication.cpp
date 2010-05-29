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

#include "EngineApplication.h"

/**
* Constrcutor
*/
EngineApplication::EngineApplication() 
    : mRoot(0), mGenericCamera(0), mWindow(0), mRunning(false)
{
    //initialize Root if it is not already done
    if(Root::getSingletonPtr() == 0)
        mRoot = new Root("data/plugins.cfg", "data/ogre.cfg", "ogre.log");
    else
        mRoot = Root::getSingletonPtr();
    
    //restore config
    if(!mRoot->restoreConfig())
    {
        if (!mRoot->showConfigDialog())
        {
            Common::LogEvent() << Common::LogType::Fatal << "Can't initialize Ogre" << Common::LogEvent::End;
        }
    }
    

    //create render window
    mWindow = mRoot->initialise(true, "td");
    mInputManager.Start(mWindow);
    
    //add listener
    mRoot->addFrameListener(this);
    WindowEventUtilities::addWindowEventListener(mWindow, this);
    
}

/**
* Destructor
*/
EngineApplication::~EngineApplication()
{
    mInputManager.Shutdown();
    mRoot->removeFrameListener(this);
    WindowEventUtilities::removeWindowEventListener(mWindow, this);
}

/**
* Frame Event
*/
bool EngineApplication::frameStarted(const Ogre::FrameEvent& evt)
{
    mInputManager.Capture();
    if (mInputManager.Keyboard()->isKeyDown(OIS::KC_ESCAPE))
        return mRunning = false;

    
    return mRunning;
}

/**
* Resize Event
*/
void EngineApplication::windowResized(RenderWindow* rw)
{
    
}


void EngineApplication::windowClosed(RenderWindow* rw)
{
    mRunning = false;
}


/**
* Run Application
*/
void EngineApplication::Run()
{
    mRunning = true;
    mRoot->startRendering();
}



