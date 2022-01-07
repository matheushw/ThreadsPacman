#ifndef PACMAN_HPP
#define PACMAN_HPP

#include <string>
#include "campo.hpp"
#include "semaphore.hpp"

using namespace std;


class Pacman{
    public:
        Pacman(int _id, pair<int, int> _position);

        //Função executada pela thread do pacman, checa os pontos e garante a movimentação 
        //executada em looping, recebendo os direcionais, atualizando os pontos 
        void pacmanThread(Campo *campo, Semaphore *semaphore, int *pontos);

        //função que irá percorrer a matriz verificando posições válidas para que o fantasma se mova
        bool isValidPosition(int i, int j, Campo *campo);
        
    private:
        int id;
        pair<int, int> previousPosition;
        pair<int, int> position;

};

int getPontos(Pacman P);

#endif
