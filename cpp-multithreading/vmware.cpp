//thread-1 prints 1-10
//thread-2 prints 11-20
//likewise thread-10 prints 91-100
//Fault : Order of threads is not maintined here but priting 10 ahed numbers is working
#include<iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<condition_variable>

std::mutex mu;
int count=1;
std::condition_variable cv;

void Print10(int tid)
{
    std::unique_lock<std::mutex> lock(mu);

    for(int i=0;i<10;i++) //only 10 times increments and print by a indivisual thread
            std::cout<<"tid="<<tid<<" count="<<count++<<"\n";
}
int main()
{
    std::vector<std::thread> vec;

    for(int i=0;i<10;i++)
    {
            vec.push_back(std::thread(Print10,i));
    }

    for(auto &th : vec)
    {
            if(th.joinable())
                    th.join();
    }
    return 0;
}