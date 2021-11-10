#include "inventory.h"
#include <stdio.h>

int main(){
    LIST_GADGET l1,l2;
    Tas t;
    MOBITA M;
    Graph g;
    MakeListGadget(&l1);
    MakeListGadget(&l2);
    CreateTas(&t);
    CreateMobita(&M);
    l1 = {{"Kain Pembungkus Waktu",800},{"Senter Pembesar",1200},{"Pintu Kemana Saja",1500},{"Mesin Waktu",3000},{"Senter Pengecil",800}};
    printf("%d",length(l2));
    buyGadget(&l2,l1,2,1000);
    buyGadget(&l2,l1,2,2000);
    printf("%d",length(l2));
    displayBuy(l1);
    displayInventory(l2);
    useGadget(&l2,1,&t,&M,&g);
    useGadget(&l2,2,&t,&M,&g);
}