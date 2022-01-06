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

pair<int, int> Ghost::checkForPacman(int i, int j, Campo *campo) {
    if (isValidPosition(i+1, j, campo) && campo->getMapIndex(i+1, j) == 'P') return make_pair(i+1, j);
    if (isValidPosition(i-1, j, campo) && campo->getMapIndex(i-1, j) == 'P') return make_pair(i-1, j);
    if (isValidPosition(i, j+1, campo) && campo->getMapIndex(i, j+1) == 'P') return make_pair(i, j+1);
    if (isValidPosition(i, j-1, campo) && campo->getMapIndex(i, j-1) == 'P') return make_pair(i, j-1);

    return make_pair(-1 ,-1);
}

int Ghost::positionsAvailable(int i, int j, Campo *campo) {
    int positionsCounter = 0;
    if (isValidPosition(i+1, j, campo)) positionsCounter++;
    if (isValidPosition(i-1, j, campo)) positionsCounter++;
    if (isValidPosition(i, j+1, campo)) positionsCounter++;
    if (isValidPosition(i, j-1, campo)) positionsCounter++;

    return positionsCounter;
}

//função para criar os fantasmas
void Ghost::ghostThread(Semaphore *semaphore, Campo *campo) {
    while(true){
        semaphore->wait();

        int i = position.first;
        int j = position.second;

        if(campo->getIsGameOver()) {
            semaphore->notify();
            break;
        }

        pair<int, int> pacmanPosition = checkForPacman(i, j, campo);
        if(pacmanPosition.first != -1 && pacmanPosition.second != -1) {
            campo->setPosition(i, j, previousPositionChar);
            campo->setPosition(pacmanPosition.first, pacmanPosition.second, 'G');
            campo->gameOver();
            campo->printMap();
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
    int i = position.first;
    int j = position.second;

    int positions = positionsAvailable(i, j, campo);

    if(previousPosition.first != -1 && previousPosition.second != -1 && positions > 1) positions--;

    // Significa que o fantasma está encurralado, logo ele não se movimentará.
    if(positions == 0) return;

    int randDirection = rand()%positions;

    campo->setPosition(i, j, previousPositionChar);

    if(isValidPosition(i+1, j, campo) && make_pair(i+1, j) != previousPosition) {
        if(randDirection == 0){
            previousPositionChar = campo->getMapIndex(i+1, j);
            campo->setPosition(i+1, j, 'G');
            position = make_pair(i + 1, j);
        }
        randDirection--;
    }

    if(isValidPosition(i-1, j, campo) && make_pair(i-1, j) != previousPosition) {
        if(randDirection == 0){
            previousPositionChar = campo->getMapIndex(i-1, j);
            campo->setPosition(i-1,j, 'G');
            position = make_pair(i - 1, j);
        }
        randDirection--;
    }

    if(isValidPosition(i, j+1, campo) && make_pair(i, j+1) != previousPosition) {
        if(randDirection == 0){
            previousPositionChar = campo->getMapIndex(i, j+1);
            campo->setPosition(i, j+1, 'G');
            position = make_pair(i, j + 1);
        }
        randDirection--;
    }

    if(isValidPosition(i, j-1, campo) && make_pair(i, j-1) != previousPosition) {
        if(randDirection == 0){
            previousPositionChar = campo->getMapIndex(i, j-1);
            campo->setPosition(i, j-1, 'G');
            position = make_pair(i, j - 1);
        }
        randDirection--;
    }

    previousPosition = make_pair(i, j);
}
