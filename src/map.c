#include "map.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
void CreateMap(int N, int M, POINT HQ, ListBuilding LB, Matrix M, Map *PT) {
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
                ELMTMap(*PT, i, j) = ' ';
            }
        }
    }

    // Iterasi untuk menentukan lokasi headquarters, lokasi gedung - gedung
    for (int i = 1; i < ROWMap(*PT); i++) {
        for (int j = 1; j < COLMap(*PT); j++) {
            if (i == Absis(HQ) && j == Ordinat(HQ)) {
                ELMTMap(*PT, i, j) = '8';
            }
        }
    }
};

void displayMap(POINT NLoc /* to-do list */ , Map *PT);
