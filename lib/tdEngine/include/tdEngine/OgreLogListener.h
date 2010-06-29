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

#ifndef OGRELOGLISTENER_H
#define OGRELOGLISTENER_H

//Ogre Includes
#include <OGRE/OgreLog.h>
#include <OGRE/OgreLogManager.h>

//Project Includes
#include <tdEngine/Log.h>

/**
* Use the Ogre Log Listener for Logging Output
*/ 
class OgreLogListener : public Common::LogListener
{
    private:
        ///Ogre Log Instance
        Ogre::Log* log;
    
        /**
        * Creates a new logger instance
        */
        OgreLogListener();
        
        void init(std::string name);
    public:        
        /**
        * Creates a new logger instance
        */
        OgreLogListener(std::string name);
        
        /**
        * Destructor
        */
        virtual ~OgreLogListener();
        
        /**
        * Log Event
        */
        virtual void logEvent(const Common::LogSource* src, const Common::LogEvent* event);
        
        /**
        * get default instance
        */
        static OgreLogListener* getSingletonPtr();
};

#endif // OGRELOGLISTENER_H
