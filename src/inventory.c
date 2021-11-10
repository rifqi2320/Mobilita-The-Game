#include <stdio.h>
#include "inventory.h"
#include "engine.h"

int waktu;

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

void useGadget(LIST_GADGET *l,int i,Tas *t, MOBITA *MOB,ListBuilding h){
    GADGET gad;
    if(isIdxEff(*l,i)){
        NAMA(gad) = NAMAGADGET(*l,i);
        HARGA(gad) = HARGAGADGET(*l,i); 
        NAMAGADGET(*l,i)="-";
        HARGAGADGET(*l,i)=VAL_UNDEF;
        process(gad,t,MOB,h);
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

void process(GADGET gad,Tas *t,MOBITA *MOB,ListBuilding h){
    if(NAMA(gad) == "Kain Pembungkus Waktu"){
        KainWaktu(t);
    }
    else if(NAMA(gad) == "Senter Pembesar"){
        SenterPembesar(t);
    }
    else if(NAMA(gad)== "Pintu Kemana Saja"){
        PintuKemanaSaja(MOB,h);
    }
    else if(NAMA(gad)== "Mesin Waktu"){
        MesinWaktu();
    }
    else if(NAMA(gad)== "Senter Pengecil"){
        SenterPengecil(t);
    }
}

void KainWaktu(Tas *t){
    if(TOP(*t).type=='P'){
        TOP(*t).tPerish+=waktu-TOP(*t).tPickup;
        printf("Senter Pengecil berhasil digunakan!");
    }
    else{
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

void PintuKemanaSaja(MOBITA *MOB,ListBuilding h){
    boolean pindah = false;
    while(!pindah){
        for(int i = 0;i<lengthListBuilding(h);i++){
            printf("%d. (%d %d)\n",i+1,XCOORD(ELMTListB(h, i)),YCOORD(ELMTListB(h, i)));
        }
        printf("Tentukan koordinat Tujuan: ");
        int x;
        scanf("%d",&x);
        if(x>0 && x<=lengthListBuilding(h)){
            pindah = true;
            printf("Mobita berhasil pindah ke (%d %d).\n",XCOORD(ELMTListB(h, x-1)),YCOORD(ELMTListB(h, x-1)));
            Absis(Posisi(*MOB)) = XCOORD(ELMTListB(h, x-1));
            Ordinat(Posisi(*MOB)) = YCOORD(ELMTListB(h, x-1));
        }
        else{
            printf("Lokasi tidak ditemukan, silahkan ulangi.\n");
        }
    }
}

void MesinWaktu(){
    waktu-=50;
    if(waktu<0){
        waktu=0;
    }
    printf("Mesin Waktu berhasil digunakan!");
}

Item SenterPengecil(Tas *t){
    Item C;
    CreateItem(&C,'-', -1, -1, '-','-');
    if(TOP(*t).type=='H'){
        TOP(*t).type='N';
        printf("Senter Pengecil berhasil digunakan!");
        return TOP(*t);
    }
    else{
        printf("Senter Pengecil gagal digunakan!Senter terbuang.");
        return C;
    }
}

void displayInventory(LIST_GADGET l){
    for(int i=0;i<JUMLAHGADGET;i++){
        printf("%d. %s\n",i+1,NAMAGADGET(l,i));
    }
}