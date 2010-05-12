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

#ifndef LOG_H
#define LOG_H

#include<string>

//STL Includes
#include<vector>

//TODO Fix stupid enum
namespace LogType
{
/**
* Logging Types
*/
enum LogType
{
  Verbose,
  Information,
  Warning,
  Error,
  Fatal
};
}

/**
* Represents a Log Event
*/
struct LogEvent
{
  LogType::LogType logType;
  std::string msg;
};

class LogSource;

/**
* LogListener
*/
class LogListener
{
  public:
    virtual ~LogListener()
    { }
    
  public:
    virtual void logEvent(const LogSource* src, const LogEvent* event) = 0;
};

/**
* LogSource 
*/
class LogSource
{
  friend class Log;
  
  private:
    const char* sourceName;
    std::vector<LogListener*> listener;
    
  private:
    LogSource();
    LogSource(const char* name);
    
    void logEvent(const LogSource* src, const LogEvent* event);
    
  public:
    void AddListener(LogListener* listener);
    void Log(LogType::LogType logType, const char* msg);
    void Verbose(const char* msg);
    void Information(const char* msg);
    void Warning(const char* msg);
    void Error(const char* msg);
    void Fatal(const char* msg);
};


/**
* Logger
*/
class Log : public LogListener
{
  private:
    static Log* logInstance;
    LogSource logSource;
  
  private:
    Log();
    virtual ~Log();
    
    static Log* getInstance();
  
  public:
    static LogSource* Source(const char* name);
    static LogSource* Source();
    
    virtual void logEvent(const LogSource* src, const LogEvent* event);
};

//TODO to seperate file
/**
* Console Listener
*/
class ConsoleListener : public LogListener
{
  public:
    virtual ~ConsoleListener();
    virtual void logEvent(const LogSource* src, const LogEvent* event);
};
#endif // LOG_H
