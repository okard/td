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

#include "ParticleEffect.h"

#include <OGRE/OgreMovableObject.h>

#include "IDGen.h"

/**
* Create new Particle Effect
*/
ParticleEffect::ParticleEffect()
    : mLiveTime(0), mSceneMng(0), mSceneNode(0), mAlive(false)
{
   
}

/**
* Destructor
*/
ParticleEffect::~ParticleEffect()
{
    if(mAlive)
        Destroy();
}

/**
* Create Particle Effect
*/
void ParticleEffect::Create(Ogre::SceneManager* sceneMng, Ogre::SceneNode* sceneNode, std::string particleName)
{
    if(mAlive)
        return;
    
    mSceneMng = sceneMng;
    mSceneNode = sceneNode;
    
    mParticleSystem = mSceneMng->createParticleSystem(IDGen<ParticleEffect>::get("ParticleEffect"), particleName);
    mSceneNode->attachObject(mParticleSystem);
    
    mAlive = true;
}

/**
* Destroy Particle Effect
*/
void ParticleEffect::Destroy()
{
    if(!mAlive)
        return;
    
    mSceneNode->detachObject(mParticleSystem);
    mSceneMng->destroyParticleSystem(mParticleSystem);
    
    mSceneMng = 0;
    mSceneNode = 0;
    mParticleSystem = 0;
    mAlive = false;
}

/**
* Is Alive
*/
bool ParticleEffect::isAlive()
{
    return mAlive;
}

