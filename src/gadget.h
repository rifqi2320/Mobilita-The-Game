#ifndef GADGET_H
#define GADGET_H

#include "boolean.h"

typedef struct
{
   char *nama; /* nama gadget */
   int harga; /* harga gadget */
} GADGET;

/* *** Notasi Akses: Selektor HARGA *** */
#define NAMA(G) (G).nama
#define HARGA(G) (G).harga

GADGET makeGadget(char *a, int b);
char* getName(GADGET a);
int getPrice(GADGET a);

#endif