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

#include "InputManager.h"

//Project Includes
#include <common/Log.h>

#ifdef OIS_WIN32_PLATFORM
	#include<windows.h>
#endif

/**
* Constructor
*/
InputManager::InputManager(const Ogre::RenderWindow* window) 
    : mInputManager(0), mMouse(0), mKeyboard(0), mWindow(0), mRegistered(false), mExclusive(false)
{
    Start(window);
}

/**
* Constructor
*/
InputManager::InputManager()
    : mInputManager(0), mMouse(0), mKeyboard(0), mWindow(0), mRegistered(false), mExclusive(false)
{
}

/**
* Destructor
*/
InputManager::~InputManager()
{

}

/**
* Start Input Manager
*/
void InputManager::Start(const Ogre::RenderWindow* window, bool autoExclusive, bool exclusive)
{
    //check if InputManager is already registered for a window
    if(mRegistered)
        throw "Already registed it is required to shutdown first";
    
    assert(window != 0);
    
    mRegistered = true;
    mWindow = const_cast<Ogre::RenderWindow*>(window);
    
    //Set Exclusive Input Mode
    if(autoExclusive)
    {
        mExclusive = mWindow->isFullScreen();
    }
    else
        mExclusive = exclusive;
    
    //Create Parameter List
    OIS::ParamList pl;
    size_t windowHnd = 0;
    std::ostringstream windowHndStr;
    mWindow->getCustomAttribute("WINDOW", &windowHnd);
    windowHndStr << windowHnd;
    pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));
    
    //When not Exclusive set right Parameter
    if(!mExclusive)
    {
        //TODO Hide or not Hide Mouse Cursor
        // non-exclusive input
        #if defined OIS_WIN32_PLATFORM
	ShowCursor(FALSE);
        pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_FOREGROUND" )));
        pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_NONEXCLUSIVE")));
        pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_FOREGROUND")));
        pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_NONEXCLUSIVE")));
        #elif defined OIS_LINUX_PLATFORM
        pl.insert(std::make_pair(std::string("x11_mouse_grab"), std::string("false")));
        pl.insert(std::make_pair(std::string("x11_mouse_hide"), std::string("true")));
        pl.insert(std::make_pair(std::string("x11_keyboard_grab"), std::string("false")));
        pl.insert(std::make_pair(std::string("XAutoRepeatOn"), std::string("true")));
        #endif
    }

    //Create Input System
    mInputManager = OIS::InputManager::createInputSystem(pl);
    mMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject(OIS::OISMouse, false));
    mKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject(OIS::OISKeyboard, false));
    
    //Initial Updating Dimensions
    UpdateDimension();
    
    //Set Event Callbacks
    mMouse->setEventCallback(this);
    mKeyboard->setEventCallback(this);
}

/**
* Shutdown InputManager
*/
void InputManager::Shutdown()
{
    mInputManager->destroyInputObject(mMouse);
    mInputManager->destroyInputObject(mKeyboard);
    OIS::InputManager::destroyInputSystem(mInputManager);
    mRegistered = false;
    mMouse = 0;
    mKeyboard = 0;
    mInputManager = 0;
    
    mMouseListener.clear();
    mKeyboardListener.clear();
}

/**
* Update Dimensions for Mouse Input
*/
void InputManager::UpdateDimension()
{
    if(mMouse != 0)
    {
        Common::LogEvent() << Common::LogType::Fatal << "Resize Mouse Input" << Common::LogEvent::End;
        unsigned int width, height, depth;
        int top, left;
        mWindow->getMetrics(width, height, depth, left, top);
        const OIS::MouseState &ms = mMouse->getMouseState();
        ms.width = width;
        ms.height = height;
    }
}

/**
* Capture the Events
*/
void InputManager::Capture()
{
    if(mMouse != 0)
        mMouse->capture();
    if(mKeyboard != 0)
        mKeyboard->capture();
}

/**
* Is exclusive Input
*/
bool InputManager::isExclusive() const
{
    return mExclusive;
}

/**
* Is registered
*/
bool InputManager::isRegistered() const
{
    return mRegistered;
}

/**
* Get the keyboard
*/
OIS::Keyboard* InputManager::Keyboard() const
{
    return mKeyboard;
}

/**
* Get the mouse
*/
OIS::Mouse* InputManager::Mouse() const
{
    return mMouse;
}

/**
* Mouse Moved
*/
bool InputManager::mouseMoved(const OIS::MouseEvent& arg)
{
    for(mMouseIterator = mMouseListener.begin(); mMouseIterator != mMouseListener.end(); mMouseIterator++)
        (*mMouseIterator)->mouseMoved(arg);
}

/**
* Mouse Button pressed
*/
bool InputManager::mousePressed(const OIS::MouseEvent& arg, OIS::MouseButtonID id)
{
    for(mMouseIterator = mMouseListener.begin(); mMouseIterator != mMouseListener.end(); mMouseIterator++)
        (*mMouseIterator)->mousePressed(arg, id);
}

/**
* Mouse Button released
*/
bool InputManager::mouseReleased(const OIS::MouseEvent& arg, OIS::MouseButtonID id)
{
    for(mMouseIterator = mMouseListener.begin(); mMouseIterator != mMouseListener.end(); mMouseIterator++)
        (*mMouseIterator)->mouseReleased(arg, id);
}

/**
* Key Pressed
*/
bool InputManager::keyPressed(const OIS::KeyEvent& arg)
{
    for(mKeyIterator = mKeyboardListener.begin(); mKeyIterator != mKeyboardListener.end(); mKeyIterator++)
        (*mKeyIterator)->keyPressed(arg);
}

/**
* Key released
*/
bool InputManager::keyReleased(const OIS::KeyEvent& arg)
{
    for(mKeyIterator = mKeyboardListener.begin(); mKeyIterator != mKeyboardListener.end(); mKeyIterator++)
        (*mKeyIterator)->keyReleased(arg);
}

/**
* Register Key Listener
*/
void InputManager::addKeyListener(OIS::KeyListener* listener)
{
    mKeyboardListener.push_back(listener);
}

/**
* Register Mouse Listener
*/
void InputManager::addMouseListener(OIS::MouseListener* listener)
{
    mMouseListener.push_back(listener);
}









