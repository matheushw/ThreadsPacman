#include "campo.hpp"
#include "ghost.hpp"
#include "semaphore.hpp"
#include <unistd.h>
#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

Ghost::Ghost (int _id, pair<int, int> _position, string _color) {
    id = _id;
    position = _position;
    previousPosition = make_pair(-1, -1);
    color = _color;
    srand(time(NULL));
}

int Ghost::getId() { 
    return id; 
}

//função para criar os fantasmas
void Ghost::ghostThread(Semaphore *sem, Campo *campo) {
    while(true){
        sem->wait();
        move(campo);
        campo->printMap();
        sem->notify();
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

pair<int, int> Ghost::getPosition() {
    return position;
}

void Ghost::move(Campo *campo){
    int randDirection = rand()%4;
    int i = position.first;
    int j = position.second;

    while(true) {
        if(campo->isValidPosition(i+1, j)) {
            if(randDirection == 0){
                campo->setPosition(i+1, j, 'G');
                campo->setPosition(i, j, '.');
                position = make_pair(i + 1, j);
                break;
            }
            randDirection--;
        }

        if(campo->isValidPosition(i-1, j)) {
            if(randDirection == 0){
                campo->setPosition(i-1,j, 'G');
                campo->setPosition(i,j, '.');
                position = make_pair(i - 1, j);
                break;
            }
            randDirection--;
        }

        if(campo->isValidPosition(i, j+1)) {
            if(randDirection == 0){
                campo->setPosition(i, j+1, 'G');
                campo->setPosition(i, j, '.');
                position = make_pair(i, j + 1);
                break;
            }
            randDirection--;
        }

        if(campo->isValidPosition(i, j-1)) {
            if(randDirection == 0){
                campo->setPosition(i, j-1, 'G');
                campo->setPosition(i, j, '.');
                position = make_pair(i, j - 1);
                break;
            }
            randDirection--;
        }
    }
}
