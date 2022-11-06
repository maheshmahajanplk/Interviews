#include<iostream>
#include "logger.hpp"
using namespace std;
int Logger::cntr=0;
mutex Logger::mtx;

Logger::Logger()
{
    cntr++;
    cout << "New instance created" << endl;
}

void Logger::Log(string msg)
{
    cout << msg << endl;
}

Logger *Logger::getLogger()
{
    if(loggerInstance==nullptr) //double checking required as locking is expensive operation would happen first time only
    {
        mtx.lock(); //just to enter single thread simultaneously
        if(loggerInstance==nullptr)
        {
        loggerInstance= new Logger();
        }
        mtx.unlock();
    }
    return loggerInstance;
}