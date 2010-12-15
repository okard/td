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

#ifndef IENVIRONMENT_H
#define IENVIRONMENT_H

class EngineApplication;

/**
* Represents a Engine Environment
* e.g. SceneManager + Viewport + Camera
*
* Allow EngineStates to share an enviroment
*/
class IEnvironment
{
    
    public:
        /**
        * Destructor
        */
        virtual ~IEnvironment(){};
        
        /**
        * Initialize
        */
        virtual void Initialize(EngineApplication* engine) = 0;
        
        /**
        * Is initialized
        */
        virtual bool IsInitialized() = 0;
        
        //virtual void Dispose() = 0;
};

#endif // IENVIRONMENT_H
