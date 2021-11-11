#include "../src/inventory.h"
#include <stdio.h>

int main(){
    LIST_GADGET l1,l2;
    Tas t;
    MOBITA M;
    MakeListGadget(&l1);
    MakeListGadget(&l2);
    CreateTas(&t);
    MakeListGadgetHQ(&l1);
    printf("%d",lengthListGadget(l2));
    buyGadget(&l2,l1,2,&M);
    buyGadget(&l2,l1,2,&M);
    printf("%d",lengthListGadget(l2));
    displayBuy(l1);
    displayInventory(l2);
}