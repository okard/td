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


/**
* Constructor
*/
RtsCamera::RtsCamera(Ogre::Camera* camera) : mCamera(camera)
{

    
}

/**
* Destructor
*/
RtsCamera::~RtsCamera()
{

}


void RtsCamera::moveDown(const Ogre::Real v)
{
    mCamera->move(Ogre::Vector3(0, 0, -v));
}

void RtsCamera::moveLeft(const Ogre::Real v)
{
    mCamera->move(Ogre::Vector3(-v, 0, 0));
}

void RtsCamera::moveRight(const Ogre::Real v)
{
    mCamera->move(Ogre::Vector3(+v, 0, 0));
}

void RtsCamera::moveUp(const Ogre::Real v)
{
    mCamera->move(Ogre::Vector3(0, 0, +v));
}

void RtsCamera::zoomIn(const Ogre::Real v)
{

}

void RtsCamera::zoomOut(const Ogre::Real v)
{

}

