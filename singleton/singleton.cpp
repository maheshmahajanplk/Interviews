#include <iostream>
#include <thread>
#include "logger.hpp"
static Logger *getLogger();
using namespace std;
int user1logs()
{
    Logger *logger1 = Logger::getLogger();
    logger1->Log("Message from User1");
}

int user2logs()
{
    Logger *logger2 = Logger::getLogger();
    logger2->Log("Message from User2");
}

int main()
{
    thread t1(user1logs);
    thread t2(user2logs);
    t1.join();
    t2.join();

    return 0;
}
