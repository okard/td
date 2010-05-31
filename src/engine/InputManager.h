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

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <common/Log.h>

#include <OGRE/OgreRenderWindow.h>
#include <OIS/OIS.h>

/**
* InputManager Class
*/
class InputManager
{
    private:
        /// OIS InputManager
        OIS::InputManager*      mInputManager;
        /// OIS Mouse
        OIS::Mouse*             mMouse;
        /// OIS Keyboard
        OIS::Keyboard*          mKeyboard;  
        /// Render Window
        Ogre::RenderWindow*     mWindow;
        /// Is registered for render window
        bool                    mRegistered;
        /// Is exclusive Input
        bool                    mExclusive;
    public:
        /**
        * Create a new InputManager
        */
        InputManager(const Ogre::RenderWindow* window);
        
        /**
        * Create a new InputManager
        */
        InputManager();
        
        /**
        * Destructor
        */
        virtual ~InputManager();
        
        /**
        * Start Input
        */
        void Start(const Ogre::RenderWindow* window, bool autoExclusive = true, bool exclusive = false);
        
        /**
        * Shutdown Input
        */
        void Shutdown();
        
        /**
        * Update Dimensions for Mouse Input
        */
        void UpdateDimension();
        
        /**
        * Capture Events
        */
        void Capture();
        
        /**
        * Is Exclusive Input 
        */
        bool isExclusive() const;
        
        /**
        * Is Registed for current render window
        */
        bool isRegistered() const;
        
        /**
        * Get Mouse
        */ 
        OIS::Mouse* Mouse() const;
        
        /**
        * Get Keyboard
        */
        OIS::Keyboard* Keyboard() const;        
};

#endif // INPUTMANAGER_H
