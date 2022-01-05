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
    previousPositionChar = '.';
    color = _color;
    srand(time(NULL));
}

int Ghost::getId() { 
    return id; 
}

bool Ghost::isValidPosition(int i, int j, Campo *campo) {
    if(i < MAP_LINES && i >= 0 && j < MAP_COLUMNS && j >= 0){
        int position = campo->getMapIndex(i, j);
        if (position == '*' || position == ' ' || position == '.' || position == 'P') {
            return true;
        }
    }
    return false;
}

//função para criar os fantasmas
void Ghost::ghostThread(Semaphore *semaphore, Campo *campo) {
    while(true){
        semaphore->wait();
        if(campo->getIsGameOver()) {
            semaphore->notify();
            break;
        }
        move(campo);
        campo->printMap();
        semaphore->notify();
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

    campo->setPosition(i, j, previousPositionChar);

    while(true) {
        if(isValidPosition(i+1, j, campo)) {
            if(randDirection == 0){
                previousPositionChar = campo->getMapIndex(i+1, j);
                campo->setPosition(i+1, j, 'G');
                position = make_pair(i + 1, j);
                break;
            }
            randDirection--;
        }

        if(isValidPosition(i-1, j, campo)) {
            if(randDirection == 0){
                previousPositionChar = campo->getMapIndex(i-1, j);
                campo->setPosition(i-1,j, 'G');
                position = make_pair(i - 1, j);
                break;
            }
            randDirection--;
        }

        if(isValidPosition(i, j+1, campo)) {
            if(randDirection == 0){
                previousPositionChar = campo->getMapIndex(i, j+1);
                campo->setPosition(i, j+1, 'G');
                position = make_pair(i, j + 1);
                break;
            }
            randDirection--;
        }

        if(isValidPosition(i, j-1, campo)) {
            if(randDirection == 0){
                previousPositionChar = campo->getMapIndex(i, j-1);
                campo->setPosition(i, j-1, 'G');
                position = make_pair(i, j - 1);
                break;
            }
            randDirection--;
        }
    }
}
