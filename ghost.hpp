#ifndef GHOST_HPP
#define GHOST_HPP

#include <string>
#include "campo.hpp"
#include "semaphore.hpp"

using namespace std;

class Ghost {
    public:
        //Construtor
        Ghost (int _id, pair<int, int> _position, string _color);

        int getId();

        //função para criar os fantasmas
        void ghostThread(Semaphore *sem, Campo *campo);

        bool isValidPosition(int i, int j, Campo *campo);

        pair<int, int> getPosition();

        pair<int, int> checkForPacman(int i, int j, Campo *campo);

        int positionsAvailable(int i, int j, Campo *campo);

    private:
        int id;
        char previousPositionChar;
        pair<int, int> position;
        pair<int, int> previousPosition;
        string color;

        void move(Campo *campo);
};

#endif
