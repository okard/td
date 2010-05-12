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

#include "Log.h"

//Cpp Includes
#include<iostream>


//== LOGSOURCE ================================================================

/**
* Constructor 
*/
LogSource::LogSource() : sourceName("")
{
}

/**
* Constructor 
*/
LogSource::LogSource(const char* name) : sourceName(name)
{
}

void LogSource::AddListener(LogListener* listener)
{
  this->listener.push_back(listener);
}

void LogSource::logEvent(const LogSource* src, const LogEvent* event)
{
   //Inform all listener
    for(std::vector<LogListener*>::iterator it = listener.begin(); it != listener.end(); it++)
    {
      (*it)->logEvent(this, event);
    }
}

void LogSource::Log(LogType::LogType logType, const char* msg)
{
    //TODO make save
    LogEvent event;
    event.msg = msg;
    event.logType = logType;
    this->logEvent(this, &event);
}

void LogSource::Verbose(const char* msg)
{
  this->Log(LogType::Verbose, msg);
}

void LogSource::Information(const char* msg)
{
  this->Log(LogType::Information, msg);
}

void LogSource::Warning(const char* msg)
{
  this->Log(LogType::Warning, msg);
}

void LogSource::Error(const char* msg)
{
  this->Log(LogType::Error, msg);
}

void LogSource::Fatal(const char* msg)
{
  this->Log(LogType::Fatal, msg);
}


//== LOG ======================================================================

Log* Log::logInstance = 0;

Log::Log()
{
  
}

Log::~Log()
{
  
}

void Log::logEvent(const LogSource* src, const LogEvent* event)
{
  logSource.logEvent(src, event);
}

Log* Log::getInstance()
{
  if(Log::logInstance == 0)
    Log::logInstance  = new Log();
  return Log::logInstance;
}

/**
* Creates a new LogSource
*/
LogSource* Log::Source(const char* name)
{
  LogSource *log = new LogSource(name);
  
  //Add Default Listener
  
  log->AddListener(getInstance());
  
  return log;
}

LogSource* Log::Source()
{
  if(Log::logInstance == 0)
    Log::logInstance  = new Log();
  
  return &(getInstance()->logSource);
}

//== ConsoleListener ==========================================================
ConsoleListener::~ConsoleListener()
{
}

void ConsoleListener::logEvent(const LogSource* src, const LogEvent* event)
{
    std::cout << event->msg << std::endl;
}
    
  