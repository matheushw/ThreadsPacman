#include <mutex>
#include <condition_variable>
#include "semaphore.hpp"

using namespace std;
        
Semaphore::Semaphore (int _count) {
    count = _count;
}

//Incrementa o counter e notifíca que a proxima thread pode acessar a região crítica.
void Semaphore::notify() {
    unique_lock<mutex> lock(mtx);
    count++;
    cv.notify_one();
}

//Bloca a thread até que ela receba uma notificação de que pode seguir para o acesso a região crítica.
void Semaphore::wait() {
    unique_lock<mutex> lock(mtx);
    while(count == 0) {
        cv.wait(lock);
    }
    count--;
}
