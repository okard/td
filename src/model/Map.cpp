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
    imp.layerList[1].worldSize = 50;
    imp.layerList[1].textureNames.push_back(conf.getSetting("DetailTexture"));
    
    
    //set up terrain
    mRtsEnv->getTerrain()->prepare(imp);
    mRtsEnv->getTerrain()->load();
    
    /*
    Ogre::Terrain* mTerrain = mRtsEnv->getTerrain();
    Ogre::TerrainLayerBlendMap* blendMap0 = mTerrain->getLayerBlendMap(1);
    //Ogre::TerrainLayerBlendMap* blendMap1 = mTerrain->getLayerBlendMap(2);
    Ogre::Real minHeight0 = 70;
    Ogre::Real fadeDist0 = 40;
    Ogre::Real minHeight1 = 70;
    Ogre::Real fadeDist1 = 15;
    float* pBlend0 = blendMap0->getBlendPointer();
    //float* pBlend1 = blendMap1->getBlendPointer();
    for (Ogre::uint16 y = 0; y < mTerrain->getLayerBlendMapSize(); ++y)
    {
        for (Ogre::uint16 x = 0; x < mTerrain->getLayerBlendMapSize(); ++x)
        {
            Ogre::Real tx, ty;

            blendMap0->convertImageToTerrainSpace(x, y, &tx, &ty);
            Ogre::Real height = mTerrain->getHeightAtTerrainPosition(tx, ty);
            Ogre::Real val = (height - minHeight0) / fadeDist0;
            val = Ogre::Math::Clamp(val, (Ogre::Real)0, (Ogre::Real)1);

            val = (height - minHeight1) / fadeDist1;
            val = Ogre::Math::Clamp(val, (Ogre::Real)0, (Ogre::Real)1);
            //*pBlend1++ = val * 255;
        }
    }
    blendMap0->dirty();
    //blendMap1->dirty();
    blendMap0->update();
    //blendMap1->update();
    //*/
    
    
    //set limits for camera
}

