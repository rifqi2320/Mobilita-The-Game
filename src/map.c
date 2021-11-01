#include "map.h"
#include "pcolor.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
char getChar(int idx) {
   char symbol = (char)('A' + idx - 1);
   return symbol;
}

void CreateMap(Map *PT, int N, int M, POINT HQ, ListBuilding LB) {
    ROWMap(*PT) = N+2;
    COLMap(*PT) = M+2;

    for (int i = 0; i <= ROWMap(*PT); i++) {
        for (int j = 0; j <= COLMap(*PT); j++) {
            if (i == 0) {
                ELMTMap(*PT, i, j) = '*';
            } else if (j == 0) {
                ELMTMap(*PT, i, j) = '*';
            } else if (i == ROWMap(*PT)-1) {
                ELMTMap(*PT, i, j) = '*';
            } else if (j == COLMap(*PT)-1) {
                ELMTMap(*PT, i, j) = '*';
            } else {
                if (i == Absis(HQ) && j == Ordinat(HQ)) {
                    ELMTMap(*PT, i, j) = '8';
                } else {
                    ELMTMap(*PT, i, j) = ' ';
                }
            }
        }
    }

    // Iterasi untuk menentukan lokasi headquarters, lokasi gedung - gedung
    for (int i = 0; i < lengthListBuilding(LB); i++) {
        int xaxis  = XCOORD(ELMTListB(LB, i));
        int yaxis = YCOORD(ELMTListB(LB, i));

        ELMTMap(*PT, xaxis, yaxis) = NAME(ELMTListB(LB, i));
    }
};

void displayMap(Map *PT, Building NobitaLoc, Todolist l, Matrix m) {
    int xaxis = XCOORD(NobitaLoc);
    int yaxis = YCOORD(NobitaLoc);
    int name = NAME(NobitaLoc);
    Graph g;
    LoadGraph(&g, m);
    for (int i = 1; i < ROWMap(*PT); i++) {
        for (int j = 1; j < COLMap(*PT); j++) {
            if (ELMTMap(*PT, i, j) != ' ') {
                if (i == xaxis && j = yaxis) {
                    print_yellow(name);
                } else if (isConnected(g, i, xaxis) && /* tidak todolist*/) { // diganti building dapet pickup dropoff
                    char c = getChar(i);
                    print_green(c)
                } else if (/*todolist*/) { // diganti buat dapet pickup dropoff
                    char from, dest;
                    print_red(from);
                    print_blue(dest);
                } else {
                    char c = getChar(i);
                    print_black(c);
                }
            }
        }
    }
};
