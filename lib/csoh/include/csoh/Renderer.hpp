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
#ifndef __CSOH_RENDERER_HPP__
#define __CSOH_RENDERER_HPP__

#include <csoh/Timer.hpp>
#include <csoh/gl/glRenderer.hpp>

namespace csoh {

/**
* Basic Renderer Interface
*/    
class Renderer
{
private:
    /// Implemented Renderer
    //NOTICE: This can be replace with an dxRenderer for a DirectX-Build
    glRenderer render;
    
    /// Timer
    Timer timer;
    
public:
    /**
    * Create new renderer
    */
    Renderer();
    
    /**
    * Destructs renderer
    */
    ~Renderer();
    
    /**
    * Initialize Renderer
    * May require valid Graphic Context
    */
    void init();
    
    /**
    * Resize Render Viewport
    */
    void resize(int x, int y, int width, int height);
    
    /**
    * Start Render Scene
    */
    void startRender();
    
    //Interface for SceneManager?
    // Rederer.render(Scene->CreateRenderList(Camera))
    //render(Camera* cam)
};
    

} //end namespace csoh

#endif // __CSOH_RENDERER_HPP__
