#include<iostream>
#include<mutex>
#include<condition_variable>
#include<thread>

int global=0,max;
std::mutex mu;
std::condition_variable cv;

void printEven(int tid)
{
	for(;global<max;)
	{
		std::unique_lock<std::mutex> locker(mu);
		while((global%2) != 0)
		cv.wait(locker);
		std::cout<< "tid="<<tid<<" global="<<global<<"\n";
		++global;
		locker.unlock();
		cv.notify_all();
	}
}

void printOdd(int tid)
{
	for(;global<10;)
	{
		std::unique_lock<std::mutex> locker(mu);
		while((global%2) != 1) //waiting a thread to satify this condition
		cv.wait(locker);
		std::cout<< "tid="<<tid<<" global="<<global<<"\n";
		++global;
		locker.unlock();
		cv.notify_all();
	}
}

int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        std::cout<<"Usage:<exe> <max-number-to-print>"<<std::endl;
        exit(1);
    }
	max = stoi(std::string(argv[1]));
	std::thread t1(printOdd,1);//1,3,5,7,9 till global<10
	std::thread t2(printEven,2);//2,4,6,8

    if(t1.joinable())
	    t1.join();
    if(t2.joinable())
	    t2.join();

	return 0;
}