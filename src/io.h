/* File: tokenmachine.h */
/* Definisi Token Machine */

#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include "boolean.h"
#include "charmachine.h"
#include "tokenmachine.h"

void inputMain(Word dir, ListBuilding *LB, Matrix *m, Building *HQ,List *tempListItem);
/* Menerima konfigurasi file */

/* Menerima input matriks adjacency dan membuat matriks peta sejumlah (N+1)X(N+1) dengan N : jumlah bangunan
Format yaitu biner (0,1) misalnya di baris ke-1 terdapat 0 0 1 0 berarti 
nilai 1 yaitu kolom ke 2 atau bangunan ke-2 (B) dapat dicapai oleh bangunan ke-1 (A)
*/

/* Menerima daftar Bangunan beserta koordinatnya untuk digunakan membuat Map
Format input misalny "A 1 2" berarti bangunan A berada di kooordinat 1,2 
*/

/* Menerima daftar pesanan yaitu berbagai item : normal, perishable, heavy, VIP item 
Jika input merupakan perishable maka disertai dengan waktu expire item tersebut 
Format input misalny "1 M B H" berarti waktu pesanan masuk yaitu waktu ke-1,
lokasi pick-up di M dan lokasi drop-off di B, dan merupakan heavy item
*/

boolean validateWord(Word w, char a[]);
/*
Fungsi untuk membandingkan ADT Word dengan string yang diinput juga, 
mengeluarkan true jika sama, false jika tidak
*/

Word nextInput();
/*
Menyalakan mesin kata dan mengakuisisi 1 input line selanjutnya
dan mengembalikannya dalam bentuk Word
*/

char *wordToString(Word w);
/*
Mengubah masukan ADT Word menjadi string yang akan dikembalikan fungsi
*/

int wordToInt(Word w);
/*
Mengubah masukan ADT Word menjadi int yang akan dikembalikan fungsi
*/


int wordToInt(Word w);


Token nextToken();
/*
Melanjutkan pembacaan ke token selanjutnya menggunakan mesintoken
dan mengembalikan token yang diakuisisi
*/

#endif
