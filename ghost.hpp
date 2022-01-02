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

        pair<int, int> getPosition();


    private:
        int id;
        pair<int, int> previousPosition;
        pair<int, int> position;
        string color;

        void move(Campo *campo);
};

#endif
