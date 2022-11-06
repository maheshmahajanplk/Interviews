#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
#include <atomic>
/*********************************************************************
* Interview Question : Stop the deamon spawn thread on an event
/**************************************************************************************************
* Don't use volatile.It is useless for inter-thread communication.
* An atomic<bool> and join will suffice.
* Don't use lock and unlock. Use either unique_lock or lock_guard as appropriate.
* Don't use volatile unless you are dealing with memory-mapped hardware or unix signal-handlers.
******************************************************************************************************/
using namespace std;  // Kids, don't try this at home.

using stopper = atomic<bool>;

void function_( stopper *ptrStop) {
    for (int i = 0; i < 1000; i++) {
        if (*ptrStop) {
            break;
        }
        //doSomething();
        this_thread::sleep_for(chrono::milliseconds(5));
        cout << "Iteration " << i << endl;
        //this_thread::sleep_for(chrono::milliseconds(1));
    }
    *ptrStop = false;
    return;
}


int main() {
    stopper stop{ false };
    thread functionThread(function_, &stop);

    this_thread::sleep_for(chrono::milliseconds(100));

    stop = true;
    // // The following is optional
    ///while (stop == true) {
    //    this_thread::yield();
    //}
    cout << "Changed boolean variable value" << endl;
    functionThread.join();

    return 0;
}