#include <string>
#include <iostream>
#include <ncurses.h>
#include "campo.hpp"
#include "pacman.hpp"

using namespace std;

Campo::Campo (int init) {
    campo[0]  = "####################################";
    campo[1]  = "#                ##                #";
    campo[2]  = "# ##### ######## ## ######### #### #";
    campo[3]  = "# ##### ######## ## ######### #### #";
    campo[4]  = "#                                  #";
    campo[5]  = "# ##### # ################# # #### #";
    campo[6]  = "#       #        ###        #      #";
    campo[7]  = "####### ######## ### ######## ######";
    campo[8]  = "xxxxxx# #                   # #xxxxx";
    campo[9]  = "xxxxxx# #                   # #xxxxx";
    campo[10] = "xxxxxx# #  ###############  # #xxxxx";
    campo[11] = "xxxxxx#    ###############    #xxxxx";
    campo[12] = "xxxxxx# #  ###############  # #xxxxx";
    campo[13] = "xxxxxx# #                   # #xxxxx";
    campo[14] = "xxxxxx# #                   # #xxxxx";
    campo[15] = "####### #  ###############  # ######";
    campo[16] = "#                ###               #";
    campo[17] = "# ##### #######  ###  ####### #### #";
    campo[18] = "#     #                            #";
    campo[19] = "##### # #  ############### # #######";
    campo[20] = "#       #        ###       #       #";
    campo[21] = "################ ### ############# #";
    campo[22] = "#                                  #";
    campo[23] = "####################################";
    fillMapWithPoints();
}

//função que printa o mapa do jogo
void Campo::printMap() {
    clear();
    
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    for (int i=0; i<MAP_LINES;i++){
        for (int j=0;j<MAP_COLUMNS;j++){
            if(campo[i][j] == 'x'){
                printw(" ");
            } else if (campo[i][j] == '#' || campo[i][j] == ' '){
                attron(COLOR_PAIR(2));
                printw("%c", campo[i][j]);
            } else if (campo[i][j] == '.'){
                attron(COLOR_PAIR(2));
                printw("%c", campo[i][j]);
            } else if (campo[i][j] == 'G') {
                attron(COLOR_PAIR(1));
                printw("%c", campo[i][j]);
            } else if (campo[i][j] == 'P') {
                attron(COLOR_PAIR(3));
                printw("%c", campo[i][j]);
            }
        }
        printw("\n");
    }
    refresh();
}

//função para preencher o mapa do jogo com as "bolinhas" que somarão pontos.
void Campo::fillMapWithPoints() {
    for (int i=0; i<MAP_LINES;i++){
        for (int j=0;j<MAP_COLUMNS;j++){
            if(campo[i][j] != 'x' && campo[i][j] != '#'){
                campo[i][j] = '.';
            }
        }
    }
}

//Muda o valor de um indice da matriz campo.
void Campo::setPosition(int i, int j, char newValue) {
    campo[i][j] = newValue;
}

//Getter de um indice da matrix campo.
char Campo::getMapIndex(int i, int j)  {
    return campo[i][j];
}

//Checa se o jogo acabou.
bool Campo::getIsGameOver()  {
    return isGameOver;
}

//Indica o fim do jogo.
void Campo::gameOver()  {
    isGameOver = true;
}
