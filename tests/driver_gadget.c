#include "../src/gadget.h"
#include <stdio.h>

int main(){
    GADGET a;
    char *p = "tubes alstrukdat";
    int b = 100;
    a = makeGadget(p,b);
    char *name = getName(a);
    int price = getPrice(a);
    printf("%s %d",name,price);
}