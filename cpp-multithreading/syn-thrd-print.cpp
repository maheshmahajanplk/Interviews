#include<iostream>
#include<string>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<memory>
using namespace std;

mutex m;
condition_variable cv;
int v=0;
void increament()
{
    // Fix #1: Any access to v should be done inside lock
    unique_lock<mutex> lock(m);

    while(v<10)
    {
        v=v+1;
        cv.notify_all();

        // Fix #2: wait for print function
        cv.wait(lock);
    }
}

void print()
{
    // See Fix #1
    unique_lock<mutex> lock(m);

    while(v<10)
    {
        cv.wait(lock);
        cout << v << " ";
        // Fix #3: no need to unlock here
        cv.notify_all();
    }
}
int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        std::cout<<"Usage:<exe> <num-of-threads>"<<std::endl;
        exit(1);
    }
    int max_threads = stoi(std::string(argv[1]));
    thread t1(increament);
    thread t2(print);

    t1.join();
    t2.join();

    cout<<endl<<"main is here!"<<endl;
    

    return 0;
}

