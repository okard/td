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

#ifndef RTSAPPLICATION_H
#define RTSAPPLICATION_H

//#include <OGRE/Plugins/OctreeSceneManager/OgreTerrainSceneManager.h>

#include <OGRE/OgreViewport.h>
#include <OGRE/OgreCamera.h>

#include "EngineApplication.h"
#include "IEnvironment.h"
#include "RtsCamera.h"

/**
* Realtime Strategy Enviroment Class
*/
class RtsEnvironment : public IEnvironment
{
    private:
        /// Scene Manager
        Ogre::SceneManager* mSceneManager;
        
        /// Viewport
        Ogre::Viewport* mViewport;
        
        /// Camera
        Ogre::Camera* mCamera;
        
        /// Rts Camera
        RtsCamera* mRtsCamera;
        
        /// Is initialized
        bool mInitialized;
    public:
        /**
        * Constructor
        */
        RtsEnvironment();
        
        /**
        * Destructor
        */
        virtual ~RtsEnvironment();
        
        /**
        * Initialize the enviroment
        */
        virtual void Initialize(EngineApplication* engine); 
        
        /**
        * Is Environment initialized
        * return true or false
        */
        virtual bool IsInitialized(); 
        
        //virtual bool Dispose();
        
        /**
        * get Rts Camera
        */
        RtsCamera* getRtsCamera() const;
        
        /**
        * Get Scene Manager
        */
        Ogre::SceneManager* getSceneManager() const;
};

#endif // RTSAPPLICATION_H
