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

#include "RtsCamera.h"

#include <common/Log.h>

/**
* Constructor
*/
RtsCamera::RtsCamera(Ogre::Camera* camera) : mCamera(camera)
{
    assert(camera != 0);
    
    
    mLimitAMin = Ogre::Degree(40);
    mLimitAMax = Ogre::Degree(90);
}

/**
* Destructor
*/
RtsCamera::~RtsCamera()
{

}

/**
* Return the Ogre Camera
*/
Ogre::Camera* RtsCamera::getCamera()
{
    return mCamera;
}

/**
* Limited Movement for Camera
*/
void RtsCamera::move(const Ogre::Vector3& vec)
{
    Ogre::Vector3 vecMov(mCamera->getPosition() + vec);
    
    //Check for Limits
    vecMov.x = Ogre::Math::Clamp<Ogre::Real>(vecMov.x, mLimitTL.x, mLimitDR.x);
    vecMov.y = Ogre::Math::Clamp<Ogre::Real>(vecMov.y, mLimitTL.y, mLimitDR.y);
    vecMov.z = Ogre::Math::Clamp<Ogre::Real>(vecMov.z, mLimitTL.z, mLimitDR.z);
    
    mCamera->setPosition(vecMov);
    //mCamera->move(vecMov);
}

/**
* Set limits for camera
*/
void RtsCamera::setLimits(Ogre::Vector3 tl, Ogre::Vector3 dr)
{
    mLimitTL = tl;
    mLimitDR = dr;
}

/**
* Move camera down
*/
void RtsCamera::moveDown(const Ogre::Real v)
{
    this->move(Ogre::Vector3(0, 0, +v));
}

/**
* Move camera left
*/
void RtsCamera::moveLeft(const Ogre::Real v)
{
    this->move(Ogre::Vector3(-v, 0, 0));
}

/**
* Move camera right
*/
void RtsCamera::moveRight(const Ogre::Real v)
{
    this->move(Ogre::Vector3(+v, 0, 0));
}

/**
* Move camera up
*/
void RtsCamera::moveUp(const Ogre::Real v)
{
    this->move(Ogre::Vector3(0, 0, -v));
}

/**
* Zoom in
*/
void RtsCamera::zoomIn(const Ogre::Real v)
{
    this->move(Ogre::Vector3(0, -v, 0));
    
    //TODO Optimize
    Ogre::Degree d((mLimitAMax-mLimitAMin) / (mLimitDR.y-mLimitTL.y) * v);
    
    Ogre::Radian r;
    Ogre::Vector3 vec(1, 0, 0);
    mCamera->getOrientation().ToAngleAxis(r, vec);
    
    if(r > mLimitAMin)
        mCamera->rotate(Ogre::Vector3(1, 0, 0), d);
}


/**
* Zoom out
*/
void RtsCamera::zoomOut(const Ogre::Real v)
{
    this->move(Ogre::Vector3(0, +v, 0));
    
    //TODO Optimize
    Ogre::Degree d((mLimitAMax-mLimitAMin) / (mLimitDR.y-mLimitTL.y) * v);
    
    Ogre::Radian r;
    Ogre::Vector3 vec(1, 0, 0);
    mCamera->getOrientation().ToAngleAxis(r, vec);
    
    if(r < mLimitAMax)
        mCamera->rotate(Ogre::Vector3(1, 0, 0), -d);
}

