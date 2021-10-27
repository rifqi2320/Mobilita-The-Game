#include "gadget.h"
#include <stdio.h>

GADGET makeGadget(char *a, int b){
    GADGET g;
    HARGA(g) = b;
    NAMA(g) = a;
    return g;
}

char* getName(GADGET a){
    return NAMA(a);
}

int getPrice(GADGET a){
    return HARGA(a);
}