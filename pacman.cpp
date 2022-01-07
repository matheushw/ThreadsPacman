#include <string>
#include <ncurses.h>
#include <chrono>
#include <thread>
#include "campo.hpp"
#include "semaphore.hpp"
#include "pacman.hpp"

Pacman::Pacman(int _id, pair<int, int> _position) {
    id = _id;
    position = _position;
    previousPosition = make_pair(-1, -1);
}

//função que irá percorrer a matriz verificando posições válidas para que o fantasma se mova
bool Pacman::isValidPosition(int i, int j, Campo *campo) {
    if(i < MAP_LINES && i >= 0 && j < MAP_COLUMNS && j >= 0){
        char position = campo->getMapIndex(i,j);
        if (position == '*' || position == ' ' || position == '.' || position == 'G') {
            return true;
        }
    }
    return false;
}

void Pacman::pacmanThread(Campo *campo, Semaphore *semaphore, int *pontos) {
    timeout(20);
    while(true){
        semaphore->wait();

        if(campo->getIsGameOver()) {
            semaphore->notify();
            break;
        }

        char c = getch();
        int i = position.first;
        int j = position.second;

        if((c == 'w' || c == 65) && isValidPosition(i-1, j, campo)) {
            if(campo->getMapIndex(i-1, j) == '.') {
                (*pontos)++;
            }

            position = make_pair(i-1, j);
            campo->setPosition(i-1, j, 'P');
            campo->setPosition(i, j, ' ');
        } else if ((c == 's' || c == 66) && isValidPosition(i+1, j, campo)) {
            if(campo->getMapIndex(i+1, j) == '.') {
                (*pontos)++;
            }

            position = make_pair(i+1, j);
            campo->setPosition(i+1, j, 'P');
            campo->setPosition(i, j, ' ');
        } else if ((c == 'd' || c == 67) && isValidPosition(i, j+1, campo)) {
            if(campo->getMapIndex(i, j+1) == '.') {
                (*pontos)++;
            }

            position = make_pair(i, j+1);
            campo->setPosition(i, j+1, 'P');
            campo->setPosition(i, j, ' ');
        } else if ((c == 'a' || c == 68) && isValidPosition(i, j-1, campo)) {
            if(campo->getMapIndex(i, j-1) == '.') {
                (*pontos)++;
            }

            position = make_pair(i, j-1);
            campo->setPosition(i, j-1, 'P');
            campo->setPosition(i, j, ' ');
        }

        if(*pontos == MAX_POINTS) {
            campo->gameOver();
        }

        campo->printMap();
        semaphore->notify();
        this_thread::sleep_for(chrono::milliseconds(180));
    }
}
