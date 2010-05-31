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

/**
* Constructor
*/
EngineApplication::EngineApplication() 
    : mRoot(0), mCamera(0), mWindow(0), mRunning(false), mState(0)
{
    //TODO Full support for multiple engine Applications
    
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
    
    //Initialize Resource Location
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation(".", "FileSystem");

    //create render window
    mWindow = mRoot->initialise(true, "td");
    mInputManager.Start(mWindow);
    
    //add listener
    mRoot->addFrameListener(this);
    WindowEventUtilities::addWindowEventListener(mWindow, this);
    
    //Scene Manager
    mSceneMng = mRoot->createSceneManager(Ogre::ST_GENERIC);
    mCamera = mSceneMng->createCamera("Camera0");
    mViewport = mWindow->addViewport(mCamera);
    mViewport->setDimensions(0.0f, 0.0f, 1.0f, 1.0f);
    mCamera->setAspectRatio((float)mViewport->getActualWidth() / (float)mViewport->getActualHeight());
    mCamera->setPosition(Vector3(0, 0, 100));
    mCamera->lookAt(Vector3(0, 0, 0));
    mCamera->setNearClipDistance(5);

    //Setup Mouse Cursor
    mMouseCursor = new MouseCursor("data/cursor.png");
    mMouseCursor->UpdateDimension(mWindow->getWidth(), mWindow->getHeight());
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
    
    mMouseCursor->setVisible(true);
    
    //set mouse cursor position
    mMouseCursor->UpdatePosition(mInputManager.Mouse()->getMouseState().X.abs, mInputManager.Mouse()->getMouseState().Y.abs);

    
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
    mRoot->startRendering();
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
    mState->Start(*this);
}


/**
* Get the Render Window
*/
RenderWindow* EngineApplication::getRenderWindow() const
{
    return mWindow;
}

/**
* Get the Scene Manager
*/
SceneManager* EngineApplication::getSceneMng() const
{
    return mSceneMng;
}

/**
* Get InputManager
*/
InputManager& EngineApplication::getInputManager()
{
    return mInputManager;
}





