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

#include <tdEngine/RtsEnvironment.h>

#include <OGRE/Terrain/OgreTerrainMaterialGeneratorA.h>


/**
* Constructor
*/
RtsEnvironment::RtsEnvironment() 
 : mSceneManager(0), mViewport(0), mCamera(0), mRtsCamera(0), mInitialized(false), mRaySceneQuery(0)
{
    
}

/**
* Start environment
*/
void RtsEnvironment::Initialize(EngineApplication* engine)
{
    if(mInitialized)
        return;
    
     //Scene Manager, Viewport, Camera
    mSceneManager = engine->getRoot()->createSceneManager(Ogre::ST_EXTERIOR_CLOSE);
    
    mTerrain = CreateTerrain();
    
    //Camera
    mCamera = mSceneManager->createCamera("RtsCamera");
    
    //Viewport
    mViewport = engine->getRenderWindow()->addViewport(mCamera);
    mViewport->setDimensions(0.0f, 0.0f, 1.0f, 1.0f);
    
    //Camera
    mCamera->setAspectRatio((float)mViewport->getActualWidth() / (float)mViewport->getActualHeight());
    mCamera->setPosition(Vector3(0, 1000, 0));
    mCamera->setNearClipDistance(5);
    //rotate 90° around x axis
    mCamera->setOrientation(Ogre::Quaternion(-Ogre::Degree(90), Ogre::Vector3(1, 0, 0)));
    
    //Rts Camera
    mRtsCamera = new RtsCamera(mCamera);
    mRtsCamera->setLimits(Ogre::Vector3(0, 105, 0), Ogre::Vector3(1500, 1000, 1500));
    
    //Ray Scene Query
    mRaySceneQuery = mSceneManager->createRayQuery(Ogre::Ray());
    
    mInitialized = true;
}



/**
* Destructor
*/
RtsEnvironment::~RtsEnvironment()
{

}

/**
* Is Initialized
*/ 
bool RtsEnvironment::IsInitialized()
{
    return mInitialized;
}

/**
* Return Scene Manager
*/
SceneManager* RtsEnvironment::getSceneManager() const
{
    return mSceneManager;
}

/**
* Get Rts Camera
*/
RtsCamera* RtsEnvironment::getRtsCamera() const
{
    return mRtsCamera;
}

/**
* Get Terrain
*/
Terrain* RtsEnvironment::getTerrain() const
{
    return mTerrain;
}


Ogre::Terrain* RtsEnvironment::CreateTerrain()
{
    Ogre::TerrainGlobalOptions* topt = new Ogre::TerrainGlobalOptions();
    Ogre::Terrain* terrain = new Ogre::Terrain(mSceneManager);
    
    /*
    Ogre::TerrainMaterialGeneratorA::SM2Profile* matProfile =
    static_cast<Ogre::TerrainMaterialGeneratorA::SM2Profile*>(topt->getDefaultMaterialGenerator()->getActiveProfile());
   
    //matProfile->setLightmapEnabled(false);
    
    matProfile->setLayerNormalMappingEnabled(false);
    matProfile->setLayerSpecularMappingEnabled(false);
    matProfile->setLayerParallaxMappingEnabled(false);

    matProfile->setGlobalColourMapEnabled(false);
    matProfile->setReceiveDynamicShadowsDepth(false);

    topt->getDefaultMaterialGenerator()->setActiveProfile(matProfile);
    topt->setMaxPixelError(8);
    topt->setSkirtSize(2);
    */
    
    return terrain;
}

