#include "campo.hpp"
#include "semaphore.hpp"
#include "colors.hpp"
#include "ghost.hpp"
#include "pacman.hpp"
#include <iostream>
#include <thread>
#include <pthread.h>
#include <ncurses.h>

using namespace std;

Semaphore semaphore(1);
Campo campo(1);

int main () {
    initscr();

    Ghost gh1(0, make_pair(1,1), GREEN);
    Ghost gh2(1, make_pair(1,30), YELLOW);
    Ghost gh3(2, make_pair(22,1), CYAN);
    Ghost gh4(3, make_pair(22,30), WHITE);

    Pacman pc(1, make_pair(10,29));

    thread th1(&Ghost::ghostThread, gh1, &semaphore, &campo);
    thread th2(&Ghost::ghostThread, gh2, &semaphore, &campo);
    thread th3(&Ghost::ghostThread, gh3, &semaphore, &campo);
    thread th4(&Ghost::ghostThread, gh4, &semaphore, &campo);

    thread th5(&Pacman::pacmanThread, pc, &campo, &semaphore);

    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();

    return 0;
}
