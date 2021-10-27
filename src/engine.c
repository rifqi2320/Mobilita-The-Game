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
void cetakWaktu(){
    /*I.S. waktu terdefinisi*/
    /*F.S. mencetak waktu sekarang ke layar*/
    printf("Waktu: %d",skor);
}
void addTime(float multiplier){
    /* I.S. multiplier terdefinisi */
    /* F.S. waktu bertambah sebesar (1*multiplier)*/
    /* multiplier adalah faktor pengali, defaultnya adalah 1, namun bisa diisi 2 atau 0.5 misalnya, untuk kasus heavy item atau speed boost*/
    //kamus lokal
    //algoritma
    waktu += multiplier;
}