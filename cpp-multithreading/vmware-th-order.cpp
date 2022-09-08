#include<iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;
mutex mu;
int count=1;
bool isDone = true;
condition_variable cv;
    
void Print10(int tid)
{
    unique_lock<std::mutex> lock(mu);
    
    // Wait until condition --> Wait till count/10 = tid
    while(count/10 != tid)
        cv.wait(lock);
    
    // Core logic 
    for(int i=0;i<10;i++)
        cout<<"tid="<<tid<<" count="<<count++<<"\n";
            
    // Release the current thread thus ensuring serailization
    cv.notify_one();
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