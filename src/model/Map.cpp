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

#include "Map.h"

#include <OGRE/OgreConfigFile.h>

/**
* Constructor
*/
Map::Map(RtsEnvironment* environment)
    : mRtsEnv(environment)
{

}

/**
* Load Map from File
*/
void Map::Load(std::string fileName)
{
    //Load Config for now 
    Ogre::ConfigFile conf;
    conf.load(fileName, "General", "\t:=", true);
 
    //Load Heightmap
    Ogre::Image img;
    img.load(conf.getSetting("Heightmap.image"), "General");

    //set data up
    Ogre::Terrain::ImportData imp;
    imp.inputImage = &img;
    imp.terrainSize = img.getWidth();
    imp.worldSize = 1500;
    imp.inputScale = 100;
    imp.minBatchSize = 33;
    imp.maxBatchSize = 65;
    //imp.constantHeight = 100;
    imp.pos = Ogre::Vector3(750, 0, 750);
    imp.terrainAlign = Ogre::Terrain::ALIGN_X_Z;
    
    //Load Texture
    imp.layerList.resize(2);
    imp.layerList[0].worldSize = 1500;
    imp.layerList[0].textureNames.push_back(conf.getSetting("WorldTexture"));
    //imp.layerList[1].worldSize = 50;
    //imp.layerList[1].textureNames.push_back(conf.getSetting("DetailTexture"));
    
    
    //set up terrain
    mRtsEnv->getTerrain()->prepare(imp);
    mRtsEnv->getTerrain()->load();
    
    //Blend Map on/off for places possible to build?
    
    
    //set limits for camera
}

