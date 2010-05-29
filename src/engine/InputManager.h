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

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <common/Log.h>

#include <OGRE/Ogre.h>
#include <OIS/OIS.h>

/**
* InputManager Class
*/
class InputManager
{
    private:
        //OIS Input devices
        OIS::InputManager*      mInputManager;
        OIS::Mouse*             mMouse;
        OIS::Keyboard*          mKeyboard;  
        
        Ogre::RenderWindow*     mWindow;
        bool                    mRegistered;
        bool                    mExclusive;
    public:
        InputManager(const Ogre::RenderWindow* window);
        InputManager();
        virtual ~InputManager();
        
        void Start(const Ogre::RenderWindow* window, bool autoExclusive = true, bool exclusive = false);
        void Shutdown();
        
        void UpdateDimension();
        
        void Capture();
        
        //Exclusive
        bool getExclusive();
        
        bool isRegistered();
        
        OIS::Mouse* Mouse() const;
        OIS::Keyboard* Keyboard() const;
        
};

#endif // INPUTMANAGER_H
