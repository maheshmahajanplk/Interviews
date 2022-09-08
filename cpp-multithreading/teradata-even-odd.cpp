#include<iostream>
#include<mutex>
#include<condition_variable>
#include<thread>

int global=0;
std::mutex mu;
std::condition_variable cv;

void printEven(int tid)
{
	for(;global<=10;)
	{
		std::unique_lock<std::mutex> locker(mu);
		cv.wait(locker,[](){ (((global==0) || ((global%2) == 0)));});
		std::cout<< "tid="<<tid<<" global="<<global;
		++global;
		locker.unlock();
		cv.notify_all();
	}
}

void printOdd(int tid)
{
	for(;global<=10;)
	{
		std::unique_lock<std::mutex> locker(mu);
		cv.wait(locker,[](){ (((global%2) == 1));} );
		std::cout<< "tid="<<tid<<" global="<<global;
		++global;
		locker.unlock();
		cv.notify_all();
	}
}

int main()
{
	std::thread t1(printOdd,1);//1,3,5,7,9 till global<10
	std::thread t2(printEven,2);//2,4,6,8

    if(t1.joinable())
	    t1.join();
    if(t2.joinable())
	    t2.join();

	return 0;
}