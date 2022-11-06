#ifndef logger_h
#define logger_h

#include <string>
#include <mutex>

class Logger
{
    static int cntr; //just to print instances count
    static Logger *loggerInstance; //to access instance of logger by different logger object
    static mutex mtx; //3:to make thread-safe
    
    //Restrict user to not to create Logger object
    Logger(); //1
    Logger(const Logger&);
    Logger operator= (const Logger&);
    

public:
    static Logger *getLogger(); //2
    void Log(std::string msg);
};
#endif 
