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
#ifndef __CSOH_GLSHADER_HPP__
#define __CSOH_GLSHADER_HPP__

#include "GL.hpp"

namespace csoh {
  
/**
* Open GL Shader
*/
class glShader
{
    friend class glProgram;
    
private:
    /// Shader Id
    GLuint shaderId;
    
    /// Shader Type
    GLenum type;
    
public:
    /**
    * Create new OpenGL Shader
    * GL_VERTEX_SHADER or
    * GL_FRAGMENT_SHADER
    */
    glShader(GLenum type);
    
    /**
    * Destructor
    */
    ~glShader();
    
    /**
    * Compile Shader
    */
    void compile(const char* src); 
};

/**
* OpenGL Shader Program
*/
class glProgram
{
private:
    GLint progId;
    
public:
    /**
    * Create new opengl shader program
    */
    glProgram();
    
    /**
    * Destructs opengl shader program
    */
    ~glProgram();
    
    /**
    * Attach a shader to program
    */
    void attach(glShader* shader);
    
    /**
    * Detach shader from program
    */
    void detach(glShader* shader);
    
    /**
    * Link shader
    */
    void link();
    
    /**
    * Use shader
    */
    void use();
};
    
    
} //end namespace csoh

#endif // __CSOH_GLSHADER_HPP__
