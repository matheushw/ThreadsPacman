#ifndef CAMPO_HPP
#define CAMPO_HPP

#include <string>

#define MAP_LINES 24
#define MAP_COLUMNS 36
#define MAX_POINTS 370

using namespace std;

class Campo {
    public:
        Campo(int init);
        //Printa o mapa do jogo
        void printMap();
        //Preenche o mapa do jogo com as "bolinhas" que somarão pontos
        void fillMapWithPoints();
        //Muda o valor de um indice da matriz campo.
        void setPosition(int i, int j, char newValue);
        //Getter de um indíce do mapa
        char getMapIndex(int i, int j);
        //Indica que o jogo acabou
        void gameOver();
        //Verifica se o jogo acabou
        bool getIsGameOver();

    private:
        string campo[MAP_LINES];
        bool isGameOver;
};

#endif
