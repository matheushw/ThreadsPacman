#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP

#include <mutex>
#include <condition_variable>

using namespace std;

class Semaphore {
    public:
        Semaphore (int _count = 0);
        //Incrementa o counter e notifíca que a proxima thread pode acessar a região crítica.
        void notify();
        //Bloca a thread até que ela receba uma notificação de que pode seguir para o acesso a região crítica.
        void wait();

    private:
        //Mutex utilizado para dar lock em uma thread.
        mutex mtx;
        //Usado para fazer o gerênciamento de block de uma thread até que ela notificada para prosseguir.
        condition_variable cv;
        //Indica o número de threds com acesso a região crítica.
        int count;
};


#endif
