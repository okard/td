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

#ifndef PLAYER_H
#define PLAYER_H

//Cpp Includes
#include <string>

/**
* Represents a Player
*/
class Player
{
    private:
        /// Current credits(money) of player 
        int mCredits;
        
        /// Energy of player (for special abilities)
        int mEnergy;
        
        // Lives/Health Points
        // Buildings 
        // Researches
        
        /// Name of Player
        std::string name;
    
    public:
        /**
        * Constructor
        */
        Player();
        /**
        * Destructor
        */
        ~Player();
    
        //Points 
        //Energy
};

#endif // PLAYER_H
