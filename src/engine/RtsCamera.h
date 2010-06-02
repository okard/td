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

#ifndef RTSCAMERA_H
#define RTSCAMERA_H

#include <OGRE/OgreCamera.h>

/**
* A RTS style camera class
*/
class RtsCamera
{
    Ogre::Camera* mCamera;
    
    //Current Angle
    Ogre::Radian mAngle;
    
    public:
        RtsCamera(Ogre::Camera* camera);
        ~RtsCamera();
        
        //top and height of map and camera (y)
        
        //length of zoom axis
        
        //The Edges 
        //void setLimits()
        
        
        //void setPosition()
        
        void zoomIn(const Ogre::Real v);
        void zoomOut(const Ogre::Real v);
        
        void moveUp(const Ogre::Real v);
        void moveDown(const Ogre::Real v);
        void moveLeft(const Ogre::Real v);
        void moveRight(const Ogre::Real v);
};

#endif // RTSCAMERA_H
