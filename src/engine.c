/* Implementasi Untuk Game Engine*/
#include "engine.h"

/* Variabel eksternal*/
int waktu;//waktu yang dihabiskan Mobita
int skor;//skor Mobita


/* Realisasi fungsi dan prosedur*/
void addScore(int val){
    /*I.S. val terdefinisi*/
    /*F.S. nilai skor bertambah sebesar val*/
    //kamus lokal
    //algoritma
    skor += val;
}
void addTime(float multiplier){
    /* I.S. multiplier terdefinisi */
    /* F.S. waktu bertambah sebesar (1*multiplier)*/
    /* multiplier adalah faktor pengali, defaultnya adalah 1, namun bisa diisi 2 atau 0.5 misalnya, untuk kasus heavy item atau speed boost*/
    //kamus lokal
    //algoritma
    waktu += multiplier;
}
void removePerishable(Tas *t,InprogressList *ip){
    //menghapus semua elemen perishable di tas yang waktunya dah habis
    //kamus lokal
    int i;//variabel untuk kounter
    int j;//variabel untuk kounter
    //algoritma
    if(!isTasEmpty(*t)){
        i = 0;
        while(i<=IDX_TOP(*t)){
            if(t->buffer[i].type=='P' && t->buffer[i].tPerish==0){
                //delete dari in progress list
                deleteInProgressAt(ip, &(t->buffer[i]));
                //delete isi
                j = i;
                while(j<IDX_TOP(*t)){
                    t->buffer[j] = t->buffer[j+1];
                    j++;
                }
                IDX_TOP(*t)--;
            }
            i++;
        }
}