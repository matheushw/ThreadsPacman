#ifndef PACMAN_HPP
#define PACMAN_HPP

#include <string>
#include "campo.hpp"
#include "semaphore.hpp"

using namespace std;

class Pacman{
    public:
        Pacman(int _id, pair<int, int> _position);
        void pacmanThread(Campo *campo, Semaphore *semaphore, int *pontos);
        bool isValidPosition(int i, int j, Campo *campo);
    private:
        int id;
        pair<int, int> previousPosition;
        pair<int, int> position;

};

int getPontos(Pacman P);

#endif
