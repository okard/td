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

#include "ResourceManager.h"

//set instance pointer to null
ResourceManager* ResourceManager::instance = 0;

/**
* Constructor
*/
ResourceManager::ResourceManager()
{

}

/**
* Destructor
*/
ResourceManager::~ResourceManager()
{

}

/**
* Get Image from ResourceManager
*/
const sf::Image& ResourceManager::GetImage(std::string path)
{
  if(images.find(path) == images.end())
  {
    if(!images[path].LoadFromFile(path))
    {
        LogEvent() << "Loading Failed: " << path;
    }
    else
        LogEvent() << "Loading Image: " << path;
  }
  
  sf::Image& img = images[path];
  return img;
}


/**
* Get ResourceManager Instance
*/ 
ResourceManager* ResourceManager::GetInstance()
{
  if(instance == 0)
    instance = new ResourceManager();
  return instance;
}

