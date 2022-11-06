#include<thread>
#include<mutex>
#include<iostream>
#include<condition_variable>


int count=0;
std::mutex mu;
std::condition_variable cv;

void print(int tid){

	std::unique_lock<std::mutex> lock(mu);
    while(count<10)
    {
        if(count%2==0 && (tid==2) ) //even
        {
            std::cout<<"tid= "<<tid<<": count="<<count<<"\n";
        }
        else if(count%2==1 && (tid==1)){ //odd numbers
            std::cout<<"tid="<<tid<<" : count="<<count<<"\n";
        }
        count++;
        mu.unlock();
        cv.notify_one(); //???
    }

}

int main()
{
    std::thread odd(print,1); //what you did here, are you running a thread or just declaring, I tell him ,depending on scheduler it will run or wait.
    std::thread even(print,2);
    if(odd.joinable())
    {
        odd.join();
    }
    if(even.joinable())
    {
        even.join();
    }
    return 0;
}
