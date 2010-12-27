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

#include <tdEngine/OgreLogListener.h>

/**
* Constructor
*/
OgreLogListener::OgreLogListener() : log(0)
{
   init("application.log");
}

/**
* Creates a new OgreLogListener with given filename
*/
OgreLogListener::OgreLogListener(std::string name) : log(0)
{
  init(name);
}

/**
* initialize listener
*/
void OgreLogListener::init(std::string name)
{
    //create LogManage if not exist
    if(Ogre::LogManager::getSingletonPtr() == 0)
        Ogre::LogManager* mng = new Ogre::LogManager();
    
    //add default log if not exist
    if(Ogre::LogManager::getSingleton().getDefaultLog() == 0)
        Ogre::LogManager::getSingleton().createLog("ogre.log", true, true);
    
    //add application log
    log = Ogre::LogManager::getSingleton().createLog(name, false, true);
}



/**
* Destructor
*/
OgreLogListener::~OgreLogListener()
{
    Ogre::LogManager::getSingleton().destroyLog(log);
}


/**
* Log Event
*/
void OgreLogListener::logEvent(const Common::LogSource* src, const Common::LogEvent* event)
{
    Common::LogEvent* ev = const_cast<Common::LogEvent*>(event);
    log->logMessage(ev->GetStream().str());
}

/**
* Get default instance
*/ 
OgreLogListener* OgreLogListener::getSingletonPtr()
{
    static OgreLogListener listener;
    return &listener;
}

