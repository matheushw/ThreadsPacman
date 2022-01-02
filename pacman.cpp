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

void Pacman::pacmanThread(Campo *campo, Semaphore *semaphore) {
    timeout(20);
    while(true){
        semaphore->wait();

        char c = getch();
        int i = position.first;
        int j = position.second;

        if(c == 'w' && campo->isValidPosition(i-1, j)) {
            position = make_pair(i-1, j);
            campo->setPosition(i-1, j, 'P');
            campo->setPosition(i, j, ' ');
        } else if (c == 's' && campo->isValidPosition(i+1, j)) {
            position = make_pair(i+1, j);
            campo->setPosition(i+1, j, 'P');
            campo->setPosition(i, j, ' ');
        } else if (c == 'd' && campo->isValidPosition(i, j+1)) {
            position = make_pair(i, j+1);
            campo->setPosition(i, j+1, 'P');
            campo->setPosition(i, j, ' ');
        } else if (c == 'a' && campo->isValidPosition(i, j-1)) {
            position = make_pair(i, j-1);
            campo->setPosition(i, j-1, 'P');
            campo->setPosition(i, j, ' ');
        }

        campo->printMap();
        semaphore->notify();
        this_thread::sleep_for(chrono::milliseconds(180));
    }
}

// bool MapController::checkGhostsColision(int x, int y) {
//   for (int i = 0; i < ghostsCurrPos.size(); i++) {
//     if (ghostsCurrPos[i].first == x &&
//         ghostsCurrPos[i].second == y) { // Colision with another ghost
//       return true;
//     } else if (ghostsCurrPos[i].first == pacmanX &&
//                ghostsCurrPos[i].second == pacmanY) { // Colision with pacman
//       gameRunning = false;
//     }
//   }

//   return false;
// }