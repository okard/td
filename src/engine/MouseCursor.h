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

#ifndef MOUSECURSOR_H
#define MOUSECURSOR_H

#include <string>

#include <OGRE/Ogre.h>

/**
* A Mouse Cursor Class
*/
class MouseCursor
{
    private:
        /// The mouse cursor texture
        Ogre::TexturePtr mTexture;
        /// The mouse cursor material
        Ogre::MaterialPtr mMaterial;
        /// Overlay
        Ogre::Overlay* mGuiOverlay;
        /// Overlay container for mosue cursor
        Ogre::OverlayContainer* mCursorContainer;

        /// Window Width
        float mWindowWidth;
        /// Window Height
        float mWindowHeight;
    public:
        /**
        * Creates a new Mouse Cursor with given image file
        */
        MouseCursor(std::string image);
        
        /**
        * Update Dimensions of Overlay (Window Dimensions)
        */
        void UpdateDimension(unsigned int width, unsigned int height);
        
        /**
        * Set position of mouse cursor
        */
        void UpdatePosition(int x, int y);
        
        /**
        * Set visibility of mouse cursor
        */
        void setVisible(bool visible);
        
    private:
        /**
        * Load Image for MouseCursor
        */
        void LoadImage(std::string image);
   
};

#endif // MOUSECURSOR_H
