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
void cetakSkor(){
    /*I.S. skor terdefinisi*/
    /*F.S. mencetak skor ke layar*/
    printf("Waktu: %d",skor);
}