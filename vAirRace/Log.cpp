//Logging class implementation.

#include "Log.h"

Log::Log(bool isTimeStamped, bool isMessageTyped, bool isConsoleLog, bool isLogFile, std::string logName)
{
    this->isTimeStamped = isTimeStamped;
    this->isMessageTyped = isMessageTyped;
    this->isConsoleLog = isConsoleLog;
    this->isLogFile = isLogFile;
    //Append the log file if it already exists.
    if (isLogFile)
        file.open(logName, std::fstream::out | std::fstream::app);
}

Log::~Log()
{
    if (isLogFile)
        file.close();
}

void Log::write(std::string logData, std::string messageType)
{
    messageType.append(": ");
    if (isTimeStamped)
    {
        std::time_t t = std::time(NULL);
        struct tm buf;
        gmtime_s(&buf, &t);
        //Write timestamped entry.
        if (isLogFile)
            file << std::put_time(&buf, "%c %Z") << ": " << ((isMessageTyped) ? (messageType) : ("")) << logData << std::endl;
        if (isConsoleLog)
            std::cout << std::put_time(&buf, "%c %Z") << ": " << ((isMessageTyped) ? (messageType) : ("")) << logData << std::endl;
    }
    else
    {
        if (isLogFile)
            file << ((isMessageTyped) ? (messageType) : ("")) << logData << std::endl;
        if (isConsoleLog)
            std::cout << ((isMessageTyped) ? (messageType) : ("")) << logData << std::endl;
    }
}