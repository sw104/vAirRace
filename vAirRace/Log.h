//Logging class declaration.
#ifndef LOG_H
#define LOG_H

#include <ctime>    //Timestamping.
#include <iomanip>

#include <iostream> //Console logging.
#include <fstream>  //File output operations.
#include <string>   //Message handling.

class Log   //File logging operations.
{
private:
    std::fstream file;  //Log file.
    bool isTimeStamped; //Timestamped logs?
    bool isConsoleLog;  //Output log to console?
    bool isLogFile;     //Output log to file?
    bool isMessageTyped;//Show log message types?

public:
    Log(bool isTimeStamped = true, bool isMessageTyped = false, bool isConsoleLog = false, bool isLogFile = true, std::string logName = "Log.log");    //Default Constructor.
    ~Log(); //Destructor - closes log file if applicable.
    void write(std::string logData, std::string messageType = "Log Entry");    //Write to log.
};

#endif