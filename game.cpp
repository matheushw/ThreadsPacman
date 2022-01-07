#include "campo.hpp"
#include "semaphore.hpp"
#include "ghost.hpp"
#include "pacman.hpp"
#include <iostream>
#include <thread>
#include <ncurses.h>

using namespace std;

Semaphore semaphore(1);
Campo campo(1);
int pontos = 0;

int main () {
    initscr();

    //Instanciando os fantasmas.
    Ghost gh1(0, make_pair(1,1));
    Ghost gh2(1, make_pair(1,30));
    Ghost gh3(2, make_pair(22,1));
    Ghost gh4(3, make_pair(22,30));
    Ghost gh5(4, make_pair(11,9));

    //Instanciando o pacman.
    Pacman pc(1, make_pair(10,29));

    //Setando as posições dos personangens no campo.
    campo.setPosition(1, 1, 'G');
    campo.setPosition(1, 30, 'G');
    campo.setPosition(22, 1, 'G');
    campo.setPosition(22, 30, 'G');
    campo.setPosition(11, 9, 'G');
    campo.setPosition(10, 29, 'P');

    //Inicializando as threads dos fantasmas.
    thread th1(&Ghost::ghostThread, gh1, &semaphore, &campo);
    thread th2(&Ghost::ghostThread, gh2, &semaphore, &campo);
    thread th3(&Ghost::ghostThread, gh3, &semaphore, &campo);
    thread th4(&Ghost::ghostThread, gh4, &semaphore, &campo);
    thread th5(&Ghost::ghostThread, gh5, &semaphore, &campo);

    //Inicializando a thread do pacman.
    thread th6(&Pacman::pacmanThread, pc, &campo, &semaphore, &pontos);

    //Espera todas as threads finalizarem sua execução
    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();

    //Printa a pontuação final.
    clear();
    printw("-\t----------------------\t-\n");
    printw("-\t    FIM DE JOGO!!!    \t-\n");
    printw("-\tVoce fez %d pontos!!!!\t-\n", pontos);
    printw("-\t                      \t-\n");
    printw("-\t  Obrigado por jogar! \t-\n");
    printw("-\t----------------------\t-\n");
    refresh();

    return 0;
}
