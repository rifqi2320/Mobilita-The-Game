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

void useGadget(LIST_GADGET *l,int i,Tas *t, MOBITA *MOB){
    GADGET g;
    if(isIdxEff(*l,i)){
        NAMA(g) = NAMAGADGET(*l,i);
        HARGA(g) = HARGAGADGET(*l,i); 
        NAMAGADGET(*l,i)="-";
        HARGAGADGET(*l,i)=VAL_UNDEF;
        process(g,t,MOB);
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

void process(GADGET g,Tas *t,MOBITA *MOB){
    if(NAMA(g) == "Kain Pembungkus Waktu"){
        KainWaktu(t);
    }
    else if(NAMA(g) == "Senter Pembesar"){
        SenterPembesar(t);
    }
    else if(NAMA(g)== "Pintu Kemana Saja"){
        PintuKemanaSaja(MOB);
    }
    else if(NAMA(g)== "Mesin Waktu"){
        MesinWaktu();
    }
    else if(NAMA(g)== "Senter Pengecil"){
        SenterPengecil(t);
    }
}

void KainWaktu(Tas *t){
    boolean used = false;
    for(int i=IDX_TOP(*t);i<=0;i--){
        if(t->buffer[i].type=="P"){
        t->buffer[i].tPerish=0;
        t->buffer[i].type="N";
        printf("Senter Pengecil berhasil digunakan!");
        used = true;
        break;
        }
    }
    if(!used){
            printf("Kain Pembungkus Waktu gagal digunakan!Kain terbuang.");
    }
}

void SenterPembesar(Tas *t){
    t->capacity *= 2;
    if(t->capacity>100){
        t->capacity=100;
    }
    printf("Senter Pembesar berhasil digunakan!");
}

void PintuKemanaSaja(MOBITA *MOB){
    printf("Tentukan koordinat Tujuan: ");
    int x,y;
    scanf("%d %d",&x,&y);
    Absis(Posisi(*MOB)) = x;
    Ordinat(Posisi(*MOB)) = y;
}

void MesinWaktu(){
    waktu-=50;
    if(waktu<0){
        waktu=0;
    }
    printf("Mesin Waktu berhasil digunakan!");
}

void SenterPengecil(Tas *t){
    boolean used = false;
    for(int i=IDX_TOP(*t);i<=0;i--){
        if(t->buffer[i].type=="H"){
        t->buffer[i].type="N";
        printf("Senter Pengecil berhasil digunakan!");
        used = true;
        break;
        }
    }
    if(!used){
        printf("Senter Pengecil gagal digunakan!Senter terbuang.");
    }
}

void displayInventory(LIST_GADGET l){
    for(int i=0;i<JUMLAHGADGET;i++){
        printf("%d. %s\n",i+1,NAMAGADGET(l,i));
    }
}