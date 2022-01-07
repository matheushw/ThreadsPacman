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
        //Mutex utilizado para dar lock em uma thread.
        mutex mtx;

        //Usado para fazer o gerênciamento de block de uma thread até que ela notificada para prosseguir.
        condition_variable cv;

        //Indica 
        int count;
};


#endif
