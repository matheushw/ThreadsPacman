#include <string>
#include <iostream>
#include "campo.hpp"
#include "colors.hpp"

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
    campo[17] = "# ##### #######  ###  ####### ######";
    campo[18] = "#     #                            #";
    campo[19] = "##### # #  ############### # #######";
    campo[20] = "#       #        ###       #       #";
    campo[21] = "# ############## ### ############# #";
    campo[22] = "#                                  #";
    campo[23] = "####################################";
    fillMapWithPoints();
}

bool Campo::isValidPosition(int i, int j) {
    if(i < LINES && i >= 0 && j < COLUMNS && j >= 0){
        if (campo[i][j] == '*' || campo[i][j] == ' ' || campo[i][j] == '.') {
            return true;
        }
    }
    return false;
}

//função que printa o mapa do jogo
void Campo::printMap() {
    for (int i=0; i<LINES;i++){
        for (int j=0;j<COLUMNS;j++){
            if(campo[i][j] == 'x'){
                cout<<' ';
            } else if (campo[i][j] == '#' || campo[i][j] == ' '){
                cout<<MAGENTA<<campo[i][j]<<RESET;
            } else if (campo[i][j] == '.'){
                cout<<BOLDWHITE<<campo[i][j]<<RESET;
            } else if (campo[i][j] == 'G') {
                cout<<RED<<campo[i][j]<<RESET;
            }
        }
        cout<<"\n";
    }
}

//função para preencher o mapa do jogo com as "bolinhas" que somarão pontos
void Campo::fillMapWithPoints() {
    for (int i=0; i<LINES;i++){
        for (int j=0;j<COLUMNS;j++){
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
