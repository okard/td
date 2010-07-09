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

#ifndef ENGINESTATE_H
#define ENGINESTATE_H

class EngineApplication;

/**
* A State for an EngineApplication
*/
class IEngineState
{
    public:
        /**
        * Interface destructor
        */
        virtual ~IEngineState(){}
   
        /**
        * Start the State
        */
        virtual void Start(EngineApplication* engine) = 0;
        
        /**
        * Stop the State and Shutdown
        */
        virtual void Shutdown() = 0;
        
        /**
        * Update State 
        */
        virtual void Update() = 0;
        
        //virtual void Pause() = 0;
        //virtual bool isRunning() = 0;
        
        //Update Event (frameStarted)
        //Flags for Engine State? Update|Mouse|Keyboard
};

#endif // ENGINESTATE_H
