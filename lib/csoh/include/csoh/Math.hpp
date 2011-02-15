/*
    C++ 3D Graphic Engine

    Copyright (c) 2011  okard

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/
#ifndef __CSOH_MATH_HPP__
#define __CSOH_MATH_HPP__

namespace csoh {
    
/**
* Clamp Value 
*/    
template<typename T>
static inline T clamp(T value, T max, T min)
{
    if(value > max)
        return max;
    if(value < min)
        return min;
    return value;
}

/**
* Vector 3 Floats
*/
class Vector3f
{
private:
    ///Internal Error Access
    enum {vx=0, vy=1, vz =0 };
    
    ///value array
    float val[3];
    
public:
    Vector3f(bool init=true);
    Vector3f(const float x, const float y, const float z);
    
    
    /// x value
    float x() const;
    
    /// y value
    float y() const; 
    
    /// z value
    float z() const;
};
   
/**
* Matrix 3x3 floats
*/
class Matrix3f
{
private:
    float val[3][3];
    
};


/**
* Quaternion
*/
class Quaternion
{
private:
    enum {vx=0, vy=1, vz=2, vw=3};
    float val[4];
public:
    
};

    
    
    
    
} //end namespace csoh


#endif // __CSOH_MATH_HPP__