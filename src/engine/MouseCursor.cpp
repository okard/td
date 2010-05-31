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

#include "MouseCursor.h"

/**
* Constructor
*/
MouseCursor::MouseCursor(std::string image)
{
    mMaterial = Ogre::MaterialManager::getSingleton().create("MouseCursor/default", "General");
    LoadImage(image);
     
    mCursorContainer = static_cast<Ogre::OverlayContainer*>(Ogre::OverlayManager::getSingletonPtr()->createOverlayElement("Panel", "MouseCursor"));
    mCursorContainer->setMaterialName(mMaterial->getName());
    mCursorContainer->setPosition(0, 0);

    mGuiOverlay = Ogre::OverlayManager::getSingletonPtr()->create("MouseCursor");
    mGuiOverlay->setZOrder(649);
    mGuiOverlay->add2D(mCursorContainer);
    mGuiOverlay->show();
}

/**
* Set Dimension of Window 
*/
void MouseCursor::UpdateDimension(unsigned int width, unsigned int height)
{
    mWindowWidth = (width > 0) ? width : 1;
    mWindowHeight = (height > 0) ? height : 1;
    
    mCursorContainer->setWidth(mTexture->getWidth() / mWindowWidth);
    mCursorContainer->setHeight(mTexture->getHeight() / mWindowHeight);
}

/**
* Update the Position of Mouse Cursor
*/
void MouseCursor::UpdatePosition(int x, int y)
{
    Ogre::Real rx = Ogre::Math::Clamp<Ogre::Real>(x / mWindowWidth, 0.0f, 1.0f);
    Ogre::Real ry = Ogre::Math::Clamp<Ogre::Real>(y / mWindowHeight,0.0f, 1.0f);
    mCursorContainer->setPosition(rx, ry);
}

/**
* Set visibility of mouse cursor
*/
void MouseCursor::setVisible(bool visible)
{
    if(!visible)
        mCursorContainer->hide();
    else
        mCursorContainer->show();
}

/**
* Load the Cursor Image
*/
void MouseCursor::LoadImage(std::string image)
{
    mTexture = Ogre::TextureManager::getSingleton().load(image, "General");
    
    Ogre::TextureUnitState *pTexState;
    if(mMaterial->getTechnique(0)->getPass(0)->getNumTextureUnitStates())
    {
        pTexState = mMaterial->getTechnique(0)->getPass(0)->getTextureUnitState(0);
    }
    else
    {
        pTexState = mMaterial->getTechnique(0)->getPass(0)->createTextureUnitState( mTexture->getName() );
    }
    pTexState->setTextureAddressingMode(Ogre::TextureUnitState::TAM_CLAMP);
    mMaterial->getTechnique(0)->getPass(0)->setSceneBlending(Ogre::SBT_TRANSPARENT_ALPHA);
}


