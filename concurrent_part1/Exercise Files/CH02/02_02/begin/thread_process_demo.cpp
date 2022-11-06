/**
 * Threads that waste CPU cycles
 */
#include <thread>
#include <chrono>
#include <unistd.h>
#include <sstream> // for ostringstream

// a simple function that wastes CPU cycles "forever"
void cpu_waster() {
    std::ostringstream oss;
    oss << std::this_thread::get_id();
    printf("CPU Waster Process ID: %d\n", getpid());
    printf("CPU Waster Thread ID %s\n", oss.str().c_str());
    while(true) continue; //try commenting it 
}

int main() {
    std::ostringstream oss;
    oss << std::this_thread::get_id();
    printf("Main Process ID: %d\n", getpid());
    printf("Main Thread ID: %s\n", oss.str().c_str());
    std::thread thread1(cpu_waster);
    std::thread thread2(cpu_waster); 

    while(true) { // keep the main thread alive "forever"
  	std::this_thread::sleep_for(std::chrono::seconds(1));
    }
   //thread1.join(); //if main thread not alive then core dump happens make it running using above loop of do join like below
   //thread2.join();
}
