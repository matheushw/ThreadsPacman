#include <mutex>
#include <condition_variable>
#include "semaphore.hpp"

using namespace std;
        
Semaphore::Semaphore (int _count) {
    count = _count;
}

void Semaphore::notify() {
    unique_lock<mutex> lock(mtx);
    count++;
    cv.notify_one();
}

void Semaphore::wait() {
    unique_lock<mutex> lock(mtx);
    while(count == 0) {
        cv.wait(lock);
    }
    count--;
}
