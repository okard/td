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

#include "EngineApplication.h"

//Project Includes
#include <common/Log.h>

//Due Ogres stupidity? plugins.cfg seems not to work cross platform specific 
// so diff filename here
#ifdef WIN32
    const char PLUGINSCFG[] = "data/plugins.win.cfg";
#else
    const char PLUGINSCFG[] = "data/plugins.linux.cfg";
#endif


/**
* Constructor
*/
EngineApplication::EngineApplication() 
    : mRoot(0), mWindow(0), mRunning(false), mState(0)
{
    //TODO Full support for multiple engine Applications
    
    //initialize Root if it is not already done
    if(Root::getSingletonPtr() == 0)
    {
        mRoot = new Root(PLUGINSCFG, "data/ogre.cfg", "ogre.log");
        
        //restore config
        if(!mRoot->restoreConfig())
        {
            if (!mRoot->showConfigDialog())
            {
                Common::LogEvent() << Common::LogType::Fatal << "Can't initialize Ogre" << Common::LogEvent::End;
            }
        }
    }
    else
        mRoot = Root::getSingletonPtr();
    
    //initialise
    if(!mRoot->isInitialised())
        mRoot->initialise(false);
    
    //Initialize Resource Location
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation(".", "FileSystem");

    //create render window
    //mWindow = mRoot->initialise(true, "td");
    mWindow = this->createRenderWindow();
    mInputManager.Start(mWindow);
    
    //add listener
    mRoot->addFrameListener(this);
    WindowEventUtilities::addWindowEventListener(mWindow, this);

    //Setup Mouse Cursor
    mMouseCursor = new MouseCursor("data/cursor.png");
    mMouseCursor->UpdateDimension(mWindow->getWidth(), mWindow->getHeight());
    mMouseCursor->setVisible(true);
}

/**
* Destructor
*/
EngineApplication::~EngineApplication()
{
    mInputManager.Shutdown();
    mRoot->removeFrameListener(this);
    WindowEventUtilities::removeWindowEventListener(mWindow, this);
    delete mMouseCursor;
}

/**
* Frame Event
*/
bool EngineApplication::frameStarted(const Ogre::FrameEvent& evt)
{
    mInputManager.Capture();
    if (mInputManager.Keyboard()->isKeyDown(OIS::KC_ESCAPE))
        return mRunning = false;
    
    //set mouse cursor position
    mMouseCursor->UpdatePosition(mInputManager.Mouse()->getMouseState().X.abs, mInputManager.Mouse()->getMouseState().Y.abs);

    if(mState != 0)
        mState->Update();
    
    return mRunning;
}

/**
* Resize Event
*/
void EngineApplication::windowResized(RenderWindow* rw)
{
    mInputManager.UpdateDimension();
    mMouseCursor->UpdateDimension(rw->getWidth(), rw->getHeight());
}


/**
* Window Closed Event
*/
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

    //init render system
    mRoot->getRenderSystem()->_initRenderTargets();
    mRoot->clearEventTimes();
    
    //main loop
    while(true)
    {
        //system message loop
        Ogre::WindowEventUtilities::messagePump();
        
        //render frames
        if(!mRoot->renderOneFrame())
            break;
    }
}

/**
* Stop Engine Application
*/
void EngineApplication::Stop()
{
    mRunning = false;
}


/**
* Start a State
*/
void EngineApplication::StartState(EngineState* state, bool shutdown)
{
    assert(state != 0);
    
    if(shutdown && mState != 0)
        mState->Shutdown();
    
    mState = state;
    mState->Start(this);
}


/**
* return ogre root
*/
Root* EngineApplication::getRoot() const
{
    return mRoot;
}


/**
* Get the Render Window
*/
RenderWindow* EngineApplication::getRenderWindow() const
{
    return mWindow;
}


/**
* Get InputManager
*/
InputManager& EngineApplication::getInputManager()
{
    return mInputManager;
}


/**
* Create Render Window
*/
RenderWindow* EngineApplication::createRenderWindow()
{
    //add config parser for default window
    return mRoot->createRenderWindow("td", 1024, 768, false);
}


