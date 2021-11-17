/* Game Engine untuk menhitung waktu dan skor*/
#ifndef _ENGINE__H
#define _ENGINE__h
#include "../building/building.h"
#include "../queuetodo/queuetodo.h"
#include "../tas/tas.h"
#include "../todolist/todolist.h"


/* Variabel Global*/
extern int waktu;       // waktu yang dihabiskan Mobita
extern int skor;        // skor Mobita
extern boolean VIPFlag; // Flag jika ada VIP
extern boolean halftime;
// Jika true berarti terdapat 0.5 detik tambahan pada waktu

/* Fungsi dan Prosedur*/
void addScore(int val);
/*I.S. val terdefinisi*/
/*F.S. nilai skor bertambah sebesar val*/
void addTime(int multiplier);
/* I.S. multiplier terdefinisi */
/* F.S. waktu bertambah sebesar (1*multiplier)*/
/* multiplier adalah faktor pengali, defaultnya adalah 1, namun bisa diisi 2
 * atau 0.5 misalnya, untuk kasus heavy item atau speed boost*/
void updateData(Tas *t, InprogressList *ip, Todolist *todo, Queue *DP,
                int *Expired);
/* I.S. t, ip, todo, DP terdefinisi */
/* F.S. Tiap item yang sudah waktunya datang akan dimasukkan ke todo */
/*      Tiap item yang sudah expired dihapus dari ip dan tas */

boolean finishedState(Building b, int finishedOrder, int jumlahPesanan);
#endif
