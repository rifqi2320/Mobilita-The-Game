#include "../src/graph.h"
#include <stdio.h>

int main() {
    Matrix m;
    CreateMatrix(4, 4, &m);
    for (int i = 0; i < ROWS(m); i++) {
        for (int j = 0; j <COLS(m); j++) {
            if (j%2==0) {
                ELMT(m, i, j) = 0;
            } else {
                ELMT(m, i, j) = 1;
            }
        }
    }
    Graph g;
    LoadGraph(&g,m);
    if (isConnected(g, 1, 1)) {
        printf("Benar\n");
    } else {
        printf("Salah\n");
    }
}