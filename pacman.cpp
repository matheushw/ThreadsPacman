#include "campo.hpp"
#include "semaphore.hpp"
#include "colors.hpp"
#include "ghost.hpp"
#include <iostream>
#include <thread>
#include <pthread.h>

using namespace std;

Semaphore semaphore(1);
Campo campo(1);

int main () {
    Ghost gh1(0, make_pair(1,1), GREEN);
    Ghost gh2(1, make_pair(1,30), YELLOW);
    Ghost gh3(2, make_pair(22,1), GREEN);
    Ghost gh4(3, make_pair(22,30), YELLOW);
    campo.setPosition(1, 1, 'G');
    campo.setPosition(1, 30, 'G');
    
    campo.printMap();

    thread th1(&Ghost::ghostThread, gh1, &semaphore, &campo);
    thread th2(&Ghost::ghostThread, gh2, &semaphore, &campo);
    thread th3(&Ghost::ghostThread, gh3, &semaphore, &campo);
    thread th4(&Ghost::ghostThread, gh4, &semaphore, &campo);

    th1.join();
    th2.join();
    th3.join();
    th4.join();

    return 0;
}
