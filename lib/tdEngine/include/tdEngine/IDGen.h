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

#ifndef IDGEN_H
#define IDGEN_H

#include <string>
#include <sstream>

/**
* A Id Generator
*/
template<class T> class IDGen
{
    private:
        /// current id count
        static unsigned int mId;
        //static std::ostringstream stream;
    public: 
        /**
        * Generate a new ID
        */
        static std::string get(std::string prefix)
        {
            //TODO optimize
            std::ostringstream stream;
            stream << prefix << '_';
            stream.width(4);
            stream.fill('0');
            stream << std::hex << mId++;
            return stream.str();
        };
        
        /**
        * Generate pure int id
        */
        static unsigned int get()
        {
            return mId++;
        };
};

template<class T> unsigned int IDGen<T>::mId = 0;


#endif // IDGEN_H
