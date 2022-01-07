#ifndef GHOST_HPP
#define GHOST_HPP

#include <string>
#include "campo.hpp"
#include "semaphore.hpp"

using namespace std;

class Ghost {
    public:
        //Construtor
        Ghost (int _id, pair<int, int> _position);

        //retorna id
        int getId();

        //função que a thread irá executar
        void ghostThread(Semaphore *sem, Campo *campo);

        //função que irá percorrer a matriz verificando posições válidas para que o fantasma se mova
        bool isValidPosition(int i, int j, Campo *campo);
        
        //retorna as coordenadas do fantasma
        pair<int, int> getPosition();

        //função que irá verificar em todas as possibilidades próximas de movimentação se o pacman está posicionado em uma delas, retornando a dupla xy
        pair<int, int> checkForPacman(int i, int j, Campo *campo);

        //função que irá checar o número de posições possíveis de serem ocupadas pelo fantasma
        int positionsAvailable(int i, int j, Campo *campo);

    private:
        int id;
        char previousPositionChar;
        pair<int, int> position;
        pair<int, int> previousPosition;

        void move(Campo *campo);
};

#endif
