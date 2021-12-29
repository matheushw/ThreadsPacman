#include "colors.hpp"
#include "campo.hpp"
#include "semaphore.cpp"
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <random>

using namespace std;

int contador = 0;
int gp[] = {1, 1, 1 ,30};

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> distr(0, 3);

Campo campo();
Semaphore a(1);

bool isValidPosition(int i, int j) {
    if(i < LINES && i >= 0 && j < COLUMNS && j >= 0){
        if (campo[i][j] == '*' || campo[i][j] == ' ' || campo[i][j] == '.') {
            return true;
        }
    }
    return false;
}

void moveGhost(int i, int j, int ghost) {
    int randDirection = distr(gen);

    while(true) {
        if(isValidPosition(i+1, j)) {
            if(randDirection == 0){
                campo[i+1][j] = 'G';
                campo[i][j] = '.';
                gp[ghost] = i + 1;
                gp[ghost+1] = j;
                break;
            }
            randDirection--;
        }

        if(isValidPosition(i-1, j)) {
            if(randDirection == 0){
                campo[i-1][j] = 'G';
                campo[i][j] = '.';
                gp[ghost] = i - 1;
                gp[ghost+1] = j;
                break;
            }
            randDirection--;
        }

        if(isValidPosition(i, j+1)) {
            if(randDirection == 0){
                campo[i][j+1] = 'G';
                campo[i][j] = '.';
                gp[ghost] = i;
                gp[ghost+1] = j + 1;
                break;
            }
            randDirection--;
        }

        if(isValidPosition(i, j-1)) {
            if(randDirection == 0){
                campo[i][j-1] = 'G';
                campo[i][j] = '.';
                gp[ghost] = i;
                gp[ghost+1] = j - 1;
                break;
            }
            randDirection--;
        }

    }
}

//função que printa o mapa do jogo
void printMap() {
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
void fillMapWithPoints() {
    for (int i=0; i<LINES;i++){
        for (int j=0;j<COLUMNS;j++){
            if(campo[i][j] != 'x' && campo[i][j] != '#'){
                campo[i][j] = '.';
            }
        }
    }
}

//função para criar os fantasmas
void* ghostThread() {
    while(true){
        a.wait();
        contador++;
        // cout<<"soma-> "<<contador<<"\n";
        moveGhost(gp[0], gp[1], 0);
        printMap();
        a.notify();
        sleep(1);
    }
}

void* ghostThread2() {
    while(true){
        a.wait();
        contador--;
        moveGhost(gp[2], gp[3], 2);
        // cout<<"subtrai -> "<<contador<<"\n";
        printMap();
        a.notify();
        sleep(1);
    }
}

int main () {

    fillMapWithPoints();
    campo[gp[0]][gp[1]] = 'G';
    campo[gp[2]][gp[3]] = 'G';
    printMap();

    thread th1(ghostThread);
    thread th2(ghostThread2);

    th1.join();
    th2.join();

    return 0;
}
