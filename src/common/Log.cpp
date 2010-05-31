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

namespace Common
{

//== LOGTYPE ==================================================================

namespace LogType {
const char* toString(LogType type)
{
    switch(type)
    {
        case Information: return "Information";
        case Verbose: return "Verbose";
        case Warning: return "Warning";
        case Error: return "Error";
        case Fatal: return "Fatal";
        default: return "";
    };
}
}

//== LOGEVENT =================================================================

/**
* Constructor
*/
LogEvent::LogEvent(LogSource& source) : logSource(source), logType(LogType::Information)
{
}

/**
* Constructor
*/
LogEvent::LogEvent(LogSource& source, LogType::LogType type): logSource(source), logType(type)
{
}

/**
* Constructor
*/
LogEvent::LogEvent() : logSource(Log::Source()), logType(LogType::Information)
{
}

/**
* Constructor
*/
LogEvent::LogEvent(LogType::LogType type) : logSource(Log::Source()), logType(type)
{
}


/**
* Destructor
*/
LogEvent::~LogEvent()
{
   log();
}

/**
* Internal log event
*/
void LogEvent::log()
{
    if(stream.str().size() > 0)
    {
        logSource.logEvent(&logSource, this);
        stream.clear();
        stream.str("");
    }
}

/**
* Returning the interal ostringstream for logging listener
*/
std::ostringstream& LogEvent::GetStream()
{
    return stream;
}

/**
* Return the type
*/
LogType::LogType LogEvent::GetType()
{
    return logType;
}

/**
* Gets the LogSource
*/
LogSource& LogEvent::GetLogSource()
{
    return logSource;
}

/**
* Append a bool value to log message
*/
LogEvent& LogEvent::operator<<(bool& val)
{
    stream << val;
    return *this;
}

/**
* Append a short int value to log message
*/
LogEvent& LogEvent::operator<<(short int& val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(short unsigned int& val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(int& val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(unsigned int& val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(long int& val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(long unsigned int& val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(float& val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(double& val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(long double& val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(const void* val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(std::string& val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(const char* val)
{
    stream << val;
    return *this;
}

/**
* Set LogType of log message
*/
LogEvent& LogEvent::operator<<(LogType::LogType type)
{
    logType = type;
    return *this;
}


/**
* Execute Log Action
*/
LogEvent& LogEvent::operator<<(LogEvent::LogEventAction )
{
    log();
    return *this;
}



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

/**
* Add Log Listener
*/
void LogSource::AddListener(LogListener* listener)
{
  this->listener.push_back(listener);
}

/**
* Dispatch logevent to listener
*/
void LogSource::logEvent(const LogSource* src, const LogEvent* event)
{
   //Inform all listener
    for(std::vector<LogListener*>::iterator it = listener.begin(); it != listener.end(); it++)
    {
      (*it)->logEvent(this, event);
    }
}

/**
* Log a Simple Message
*/
void LogSource::Log(LogType::LogType logType, const char* msg)
{
    //TODO make save
    LogEvent event(*this, logType);
    event << msg;
    this->logEvent(this, &event);
}


//== LOG ======================================================================

/**
* Constructor
*/
Log::Log()
{
  
}

/**
* Destructor
*/
Log::~Log()
{
  
}

/**
* LogListener interface
* dispatch the event to the internal log source
*/
void Log::logEvent(const LogSource* src, const LogEvent* event)
{
  LogSource::logEvent(src, event);
}

/**
* Get Instance
*/
Log& Log::getInstance()
{
    static Log instance;
    return instance;
};


/**
* Creates a new LogSource
*/
LogSource* Log::Source(const char* name)
{
  LogSource *log = new LogSource(name);
  
  //Add Default Listener
  log->AddListener(&Log::getInstance());
  
  return log;
}

/**
* Return Default LogSource
*/
LogSource& Log::Source()
{
    return Log::getInstance();
}

//== ConsoleListener ==========================================================
/**
* Constructor
*/
ConsoleListener::~ConsoleListener()
{
}

/**
* Log event to console
*/
void ConsoleListener::logEvent(const LogSource* src, const LogEvent* event)
{
    LogEvent* ev = const_cast<LogEvent*>(event);
    if(ev->GetType() >= LogType::Error)
        std::cerr << ev->GetStream().str() << std::endl;
    else
        std::cout << LogType::toString(ev->GetType()) << ": " << ev->GetStream().str() << std::endl;
}

} //end namespace common
    
  