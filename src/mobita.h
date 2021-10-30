#ifndef MOBITA_H
#define MOBITA_H

#include "point.h"
#include "engine.h"

typedef struct{
    POINT Posisi;
    int Uang;
} MOBITA;

#define Posisi(P) (P).Posisi
#define Uang(P) (P).Uang

void CreateMobita(MOBITA *MOB);
/*Membentuk mobita dengan posisi di headquarters dan uang = 0*/
/*I.S. MOB sudah terdefinisi*/
/*F.S. Terbentuk mobita sesuai definisi diatas*/

void move(MOBITA *MOB, POINT dest);
/*Memindahkan mobita ke posisi dest dan menambah waktu sesuai item dan ability yang dimiliki*/
/*I.S. MOB terdefinisi dan dest ada di listbuilding*/
/*F.S. Posisi MOB berubah jadi dest dan waktu bertambah sesuai item dan ability yang dimiliki*/



#endif