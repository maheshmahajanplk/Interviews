//city corporation
#include<thread>
#include<mutex>
#include<condition_variable>
#include<vector>


class Queue{
		std::vector<int> m_vec;
		std::mutex mu;
		std::condition_variable cv;
		int counter;
		bool done;
	public:
		
		Queue():counter(0),done(false),cv(),mu(),
		{}

        ~Queue(){

        }
		
		void put(int& data){
			for(int i=0;i<100;i++){
				{
				std::unique_lock<std::mutex> lock(mu);
				m_vec.push_back(i);
				counter++;
				}
				cv.notify_one();
			
			std::unique_lock<std::mutex> lock(mu);
			done=true;
			cv.notify_one();
            }
		}
		
		void get(int a){
			std::unique_lock<std::mutex> lock(mu);
			while(!done){
                cv.wait(lock);
            }
				
			while(!m_vec.empty()){
				a = m_vec.pop_back();
				counter--;
			}
		}
};


int main()
{
	Queue que= new Queue();
	int a;
	std::thread t2(&Queue::put,que);
	std::thread t1(&Queue::get,que, std::ref(a));
    return 0;
}