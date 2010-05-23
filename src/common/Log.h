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

//Cpp Includes
#include<string>
#include<sstream>

//STL Includes
#include<vector>

class LogSource;

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
const char* toString(LogType type);
}

/**
* Represents a Log Event
*/
class LogEvent
{
    private:
        std::ostringstream stream;
        LogType::LogType logType;
        LogSource& logSource;
        
        void log();
          
    public:
        enum LogEventAction { End }; 
        
        LogEvent(LogSource&);
        LogEvent(LogSource&, LogType::LogType); 
        LogEvent();
        LogEvent(LogType::LogType);
        ~LogEvent();
        
        std::ostringstream& GetStream();
        LogType::LogType GetType();
        
        LogEvent& operator<< (bool& val );
        LogEvent& operator<< (short& val );
        LogEvent& operator<< (unsigned short& val );
        LogEvent& operator<< (int& val );
        LogEvent& operator<< (unsigned int& val );
        LogEvent& operator<< (long& val );
        LogEvent& operator<< (unsigned long& val );
        LogEvent& operator<< (float& val );
        LogEvent& operator<< (double& val );
        LogEvent& operator<< (long double& val );
        LogEvent& operator<< (const void* val );
        LogEvent& operator<< (std::string& val); 
        LogEvent& operator<< (const char* val); 
        LogEvent& operator<< (LogType::LogType);
        LogEvent& operator<< (LogEventAction);
};


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
  friend class LogEvent;
  
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
};


/**
* Logger
*/
class Log : public LogListener
{
  private:
    LogSource logSource;
  
  private:
    Log();
    Log(const Log& cc);

  public:
    virtual ~Log();
      
    static LogSource* Source(const char* name);
    static LogSource& Source();
    
    static Log& getInstance();

    
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
