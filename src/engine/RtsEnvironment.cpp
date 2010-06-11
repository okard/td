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

#include "RtsEnvironment.h"


/**
* Constructor
*/
RtsEnvironment::RtsEnvironment() : mSceneManager(0), mViewport(0), mCamera(0), mRtsCamera(0), mInitialized(false)
{
    
}

/**
* Start environment
*/
void RtsEnvironment::Initialize(EngineApplication* engine)
{
    if(mInitialized)
        return;
    
     //Scene Manager, Viewport, Camera
    mSceneManager = engine->getRoot()->createSceneManager(Ogre::ST_EXTERIOR_CLOSE);
    
    //Camera
    mCamera = mSceneManager->createCamera("RtsCamera");
    
    //Viewport
    mViewport = engine->getRenderWindow()->addViewport(mCamera);
    mViewport->setDimensions(0.0f, 0.0f, 1.0f, 1.0f);
    
    //Camera
    mCamera->setAspectRatio((float)mViewport->getActualWidth() / (float)mViewport->getActualHeight());
    mCamera->setPosition(Vector3(0, 1000, 0));
    mCamera->setNearClipDistance(5);
    //rotate 90° around x axis
    mCamera->setOrientation(Ogre::Quaternion(-Ogre::Degree(90), Ogre::Vector3(1, 0, 0)));
    
    //Rts Camera
    mRtsCamera = new RtsCamera(mCamera);
    mRtsCamera->setLimits(Ogre::Vector3(250, 105, 250), Ogre::Vector3(750, 700, 750));
    
   mInitialized = true;
}



/**
* Destructor
*/
RtsEnvironment::~RtsEnvironment()
{

}

/**
* Is Initialized
*/ 
bool RtsEnvironment::IsInitialized()
{
    return mInitialized;
}

/**
* Return Scene Manager
*/
SceneManager* RtsEnvironment::getSceneManager() const
{
    return mSceneManager;
}

/**
* Get Rts Camera
*/
RtsCamera* RtsEnvironment::getRtsCamera() const
{
    return mRtsCamera;
}


