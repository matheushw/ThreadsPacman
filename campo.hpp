#ifndef CAMPO_HPP
#define CAMPO_HPP

#include <string>

#define MAP_LINES 24
#define MAP_COLUMNS 36

using namespace std;

class Campo {
    public:
        Campo(int init);
        bool isValidPosition(int i, int j);
        //Printa o mapa do jogo
        void printMap();
        //Preenche o mapa do jogo com as "bolinhas" que somarão pontos
        void fillMapWithPoints();
        //Muda o valor de um indice da matriz campo.
        void setPosition(int i, int j, char newValue);

    private:
        string campo[MAP_LINES];
};

#endif
