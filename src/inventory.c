#include <stdio.h>
#include "inventory.h"

void MakeListGadget(LIST_GADGET *l){
    for (int i=0;i<JUMLAHGADGET;i++){
        NAMAGADGET(*l,i) = "-";
        HARGAGADGET(*l,i) = VAL_UNDEF;
    }
}

int length(LIST_GADGET l){
    int ctr=0;
    for (int i=0;i<JUMLAHGADGET;i++){
        if(NAMAGADGET(l,i)!="-"){
            ctr++;
        }
    }
    return ctr;
}

boolean isIdxEff(LIST_GADGET l, int i){
    if(NAMAGADGET(l,i)!="-"){
        return true;
    }
    return false;
}
boolean isFull(LIST_GADGET l){
    if(length(l)==JUMLAHGADGET){
        return true;
    }
    return false;
}
void buyGadget(LIST_GADGET *l,LIST_GADGET buy,int i,int harga){
    if(isFull(*l)){
        printf("Inventory sudah penuh!\n");
    }
    else if(isIdxEff(buy,i)){
        if(HARGAGADGET(buy,i)>harga){
            printf("Uang tidak cukup untuk membeli Gadget!\n");
        }
        else{
            harga-=HARGAGADGET(buy,i);
            for(int j=0;j<JUMLAHGADGET;j++){
                if(NAMAGADGET(*l,j)=="-"){
                    NAMAGADGET(*l,j)=getName(GADGET(buy,i));
                    HARGAGADGET(*l,j)=getPrice(GADGET(buy,i));
                }
            }
        }
    }
    else{
        printf("Gadget tidak ditemukan.\n");
    }
}

void useGadget(LIST_GADGET *l,int i){
    if(isIdxEff(*l,i)){
        NAMAGADGET(*l,i)="-";
        HARGAGADGET(*l,i)=VAL_UNDEF;
    }
    else{
        printf("Tidak ada gadget yang dapat digunakan");
    }
}
void displayBuy(LIST_GADGET l){
    printf("Gadget yang tersedia:\n");
    for(int i=0;i<JUMLAHGADGET;i++){
        printf("%d. %s (%d Yen)\n",i+1,NAMAGADGET(l,i),HARGAGADGET(l,i));
    }
}
void displayInventory(LIST_GADGET l){
    for(int i=0;i<JUMLAHGADGET;i++){
        printf("%d. %s\n",i+1,NAMAGADGET(l,i));
    }
}