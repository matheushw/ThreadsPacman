#include "campo.hpp"
#include "semaphore.hpp"
#include "colors.hpp"
#include "ghost.hpp"
#include "pacman.hpp"
#include <iostream>
#include <thread>
#include <ncurses.h>

using namespace std;

Semaphore semaphore(1);
Campo campo(1);
int pontos = 0;

void printGameOver(int pontos){
    clear();
    printw("-\t----------------------\t-\n");
    printw("-\t    FIM DE JOGO!!!    \t-\n");
    printw("-\tVoce fez %d pontos!!!!\t-\n", pontos);
    printw("-\t                      \t-\n");
    printw("-\t  Obrigado por jogar! \t-\n");
    printw("-\t----------------------\t-\n");
    refresh();
}


int main () {
    initscr();

    Ghost gh1(0, make_pair(1,1), GREEN);
    Ghost gh2(1, make_pair(1,30), YELLOW);
    Ghost gh3(2, make_pair(22,1), CYAN);
    Ghost gh4(3, make_pair(22,30), WHITE);
    Ghost gh5(4, make_pair(11,9), WHITE);
    Pacman pc(1, make_pair(10,29));

    campo.setPosition(1, 1, 'G');
    campo.setPosition(1, 30, 'G');
    campo.setPosition(22, 1, 'G');
    campo.setPosition(22, 30, 'G');
    campo.setPosition(11, 9, 'G');
    campo.setPosition(10, 29, 'P');

    thread th1(&Ghost::ghostThread, gh1, &semaphore, &campo);
    thread th2(&Ghost::ghostThread, gh2, &semaphore, &campo);
    thread th3(&Ghost::ghostThread, gh3, &semaphore, &campo);
    thread th4(&Ghost::ghostThread, gh4, &semaphore, &campo);
    thread th5(&Ghost::ghostThread, gh5, &semaphore, &campo);
    thread th6(&Pacman::pacmanThread, pc, &campo, &semaphore, &pontos);

    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();

    printGameOver(pontos);

    return 0;
}
