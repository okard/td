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
#include <csoh/Timer.hpp>

#include <csoh/Platform.hpp>

// Include Right Header
#ifdef CSOH_WIN32
    #include<windows.h>
#else
    #include <time.h>
#endif


using csoh::Timer;

#ifdef CSOH_LINUX
/**
* get time
*/
static float getTimeMS()
{
    timespec curTime;
    clock_gettime(CLOCK_REALTIME, &curTime);
    return curTime.tv_sec*1000.0f + curTime.tv_nsec/1000000.0f;
}
#endif

/**
* Create new Timer
*/
Timer::Timer()
{
}

/**
* Create new Timer
*/
Timer::Timer(bool start)
{
    if(start)
        this->start();
}

/**
* Destructs timer
*/
Timer::~Timer()
{
}
    

/**
* Start timer
*/
void Timer::start()
{
    if(running)
        return;
    
    lastTime = getTimeMS();
    
    running = true;
}

/**
* Stop timer
*/
float Timer::stop()
{
    if(!running)
        return 0.0f;
    
    float t = time();
    running = false;
    return t;
}

/**
* Reset timer
*/
void Timer::reset()
{
    if(!running)  
        lastTime = .0f;
    else
        lastTime = getTimeMS();
}

/**
* Elapsed time in ms
*/
float Timer::time()
{
    if(!running)
        return .0f;
    
    //get cur time and subtract
    float curt = getTimeMS();
    
    return curt-lastTime;
}

/**
* Is the timer running or stopped
*/
bool Timer::isRunning()
{
    return running;
}


/*
    Windows:
    QueryPerformanceCounter
    
    POSIX:
    clock_gettime(CLOCK_MONOTONIC, &ts); // Works on FreeBSD
    int clock_getres(clockid_t clock_id, struct timespec *res);
    nanosleep?;
*/ 
