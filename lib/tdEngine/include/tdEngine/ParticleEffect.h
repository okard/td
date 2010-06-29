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

#ifndef PARTICLEEFFECT_H
#define PARTICLEEFFECT_H

#include <OGRE/OgreSceneManager.h>
#include <OGRE/OgreParticleSystem.h>

/**
* A Particle Effect
*/
class ParticleEffect
{
    private:
        /// how long the Particle effect live
        int mLiveTime;
        
        /// The parent SceneManager
        Ogre::SceneManager* mSceneMng;
        
        /// The scene node effect getting attached
        Ogre::SceneNode* mSceneNode;
        
        /// Particle System
        Ogre::ParticleSystem* mParticleSystem;
        
        /// is alive
        bool mAlive;
        
    public:
        /**
        * Create Particle Effect
        */
        ParticleEffect();
        
        /**
        * Destructor
        */
        ~ParticleEffect();
        
        /**
        * Create
        */
        void Create(Ogre::SceneManager* sceneMng, Ogre::SceneNode* sceneNode, std::string particleName);
        
        /**
        * Destroy
        */
        void Destroy();
        
        /**
        * isAlive
        */
        bool isAlive();
};

#endif // PARTICLEEFFECT_H
