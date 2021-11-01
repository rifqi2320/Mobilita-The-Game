#include "graph.h"
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void LoadGraph(Graph *g, Matrix m) {
    NODES(*g) = ROWS(m);
    for (int i = 0; i < NODES(*g); i++) {
        for (int j = 0; j < NODES(*g); j++) {
            ELMTGraph(*g, i, j) = ELMT(m, i, j);
        }
    }
};

boolean isConnected(Graph g, int rowAdj, int check) {
    return (ELMTGraph(i, j, g) == 1);
};