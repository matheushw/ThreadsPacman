#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP

#include <mutex>
#include <condition_variable>

using namespace std;

class Semaphore {
    public:
        Semaphore (int _count = 0);

        void notify();

        void wait();

    private:
        mutex mtx;
        condition_variable cv;
        int count;
};


#endif
