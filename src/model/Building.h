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

#ifndef BUILDING_H
#define BUILDING_H

//Project Includes
#include<model/GameObject.h>
#include<model/BuildingType.h>

// Forward Declarations
class BuildingType;

/**
* Represents a Building on the Map
* Can be created over BuildingType
*/
class Building : public GameObject
{
  public:
    /**
    * Fire Strategy
    */
    enum FireStrategy
    {
        Weakest = 0,
        Strongest = 1,
        Nearest = 2,
        Furthest = 3
    };

    /**
    * Fire Type
    */
    enum FireType
    {
        FollowPosition,
        CalculatePosition,
        CurrentPosition
    };  
      
    
    /**
    * Virtual Destructor for Interfacing
    */
    virtual ~Building(){}
    
    /**
    * Update game object
    */
    virtual void Update(int time) = 0;
    
    /**
    * Get building type
    */
    virtual BuildingType* GetType() = 0;
    
    /**
    * Get Fire Strategy
    */
    virtual FireStrategy getFireStrategy() const = 0;
    
    //TODO virtual void setFireStrategy(FireStrategy strat) = 0;
    
    /**
    * Get Fire Type
    */
    virtual FireType     getFireType() const = 0;
  
    //TODO Upgrade
    //TODO Level
    //TODO Bullet
    //TODO Range
    
    //For Blocking Buildings?
    //TODO CurrentHP
    //TODO HP
    
    //TODO Sprite
    //TODO Position
    

};

#endif // BUILDING_H
