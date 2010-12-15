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

//Basic Log Macro
#define LOG(x) Common::Log::Source().Event() << x << Common::LogEvent::End;

//Debug Log Macro
#ifdef DEBUG
    #define DEBUGMSG(x) Common::LogEvent() << x << Common::LogEvent::End;
#else
    #define DEBUGMSG(x) /*x*/
#endif




// Common Namespace
namespace Common
{

//forward declaration
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
    
    /**
    * Convert a LogType to String
    */
    const char* toString(LogType type);
}

/**
* Represents a Log Event
*/
class LogEvent
{
    private:
        /// string string for formatting
        std::ostringstream stream;
        /// log event type
        LogType::LogType logType;
        /// LogSource
        LogSource& logSource;
        
        /**
        * Log the current message
        */
        void log();  
    public:
        /**
        * Log Event Actions
        */
        enum LogEventAction { End, Endl }; 
        
        LogEvent(LogSource&);
        LogEvent(LogSource&, LogType::LogType); 
        LogEvent();
        LogEvent(LogType::LogType);
        ~LogEvent();
        
        std::ostringstream& GetStream();
        LogType::LogType GetType();
        LogSource& GetLogSource();
        
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
        /// Log Source Name
        const char* sourceName;
        /// Listener
        std::vector<LogListener*> listener;
    
        ///internal log event?
        LogEvent* event;
    private:
        LogSource();
        LogSource(const char* name);
        ~LogSource();
 
    protected:
        /**
        * Internal Log Event Dispatch to Listener
        */
        void logEvent(const LogSource* src, const LogEvent* event); 
    public:
        /**
        * Add a log listener to log source
        */
        void AddListener(LogListener* listener);
        
        /**
        * Log a Simple Message
        */
        void Log(LogType::LogType logType, const char* msg);  
        
        /**
        * Get a Default Event
        */
        LogEvent& Event();
};


/**
* Logger
*/
class Log : public LogSource, public LogListener
{
  private:
    Log();
    Log(const Log& cc);

  public:
    virtual ~Log();
    
    /**
    * Create a new LogSource with given name 
    */
    static LogSource* Source(const char* name);
    
    /**
    * Return the default LogSource
    */
    static LogSource& Source();
    
    /**
    * Get Instacne of logging class
    */
    static Log& getInstance();

    /**
    * Implemented Log Listener Interface
    */
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

} //end namespace common
#endif // LOG_H
