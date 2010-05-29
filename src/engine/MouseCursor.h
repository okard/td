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
        Ogre::TexturePtr mTexture;
        Ogre::MaterialPtr mMaterial;
        
        Ogre::Overlay* mGuiOverlay;
        Ogre::OverlayContainer* mCursorContainer;

        float mWindowWidth;
        float mWindowHeight;
    public:
        MouseCursor(std::string image);
        
        void UpdateDimension(unsigned int width, unsigned int height);
        void UpdatePosition(int x, int y);
        
        void setVisible(bool visible);
        
    private:
        void LoadImage(std::string image);
   
};

#endif // MOUSECURSOR_H
