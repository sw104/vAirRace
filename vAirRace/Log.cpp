//Logging class implementation.

#include "Log.h"

Log::Log(bool isTimeStamped, bool isConsoleLog, bool isLogFile, std::string logName)
{
    this->isTimeStamped = isTimeStamped;
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

void Log::write(std::string logData)
{
    if (isTimeStamped)
    {
        std::time_t t = std::time(NULL);
        struct tm buf;
        gmtime_s(&buf, &t);
        //Write timestamped entry.
        if (isLogFile)
            file << std::put_time(&buf, "%c %Z") << ": " << logData << std::endl;
        if (isConsoleLog)
            std::cout << std::put_time(&buf, "%c %Z") << ": " << logData << std::endl;
    }
    else
    {
        if (isLogFile)
            file << logData << std::endl;
        if (isConsoleLog)
            std::cout << logData << std::endl;
    }
}