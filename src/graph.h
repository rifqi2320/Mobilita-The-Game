#ifndef Graph_H
#define Graph_H

#include "boolean.h"
#include "matrix.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define NODE_CAP 100

typedef struct
{
   int contents[NODE_CAP][NODE_CAP];
   int nodeEff;
} Graph;

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Graph *** */
void LoadGraph(Graph *g, Matrix m);

boolean isConnected(Graph g, int rowAdj, int check);

/* *** Selektor *** */
#define NODES(G) (G).nodeEff
#define ELMTGraph(G, i, j) (G).contents[(i)][(j)]

#endif