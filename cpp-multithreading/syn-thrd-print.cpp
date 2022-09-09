//thread-1 prints 1
//thread-2 prints 2
//likewise each thread print the number and increment it.
//one-by-one each thread is serialised for the execution
//Here thread count is dynamic(received at the execution).

#include<iostream>
#include<string>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<vector>
using namespace std;

mutex m;
condition_variable cv;
int counter,end_num,max_threads,turn;

/*void increament()
{
    // Fix #1: Any access to v should be done inside lock
    unique_lock<mutex> lock(m);
    while(counter<end_num)
    {
        counter=counter+1;
        cv.notify_all();
        cv.wait(lock);
    }
}*/

void print(int tid)
{
    
    unique_lock<mutex> lock(m);
    while(counter<end_num)
    {
        while(turn%max_threads!=tid)
            cv.wait(lock);
        cout << counter++ << " ";
        ++turn;
        if(turn==max_threads)
            turn=0;
        // Fix #3: no need to unlock here
        cv.notify_all();

    }
}

int main(int argc, char *argv[])
{
    if(argc!=3)
    {
        std::cout<<"Usage:<exe> <num-of-threads> <end-limit-number>"<<std::endl;
        exit(1);
    }
    max_threads = stoi(std::string(argv[1]));
    end_num     = stoi(std::string(argv[2]));
    
    std::vector<std::thread> vec;

    for(int i=0;i<max_threads;i++)
    {
        vec.push_back(std::thread(print,i));
    }

    for(auto &th : vec)
    {
        if(th.joinable())
            th.join();
    }
    
    cout<<endl<<"main is here!"<<endl;
    return 0;
}

