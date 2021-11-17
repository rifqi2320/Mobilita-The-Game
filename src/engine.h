/* Game Engine untuk menhitung waktu dan skor*/
#ifndef _ENGINE__H
#define _ENGINE__h
#include "queuetodo.h"
#include "tas.h"
#include "todolist.h"

/* Variabel Global*/
extern int waktu;       // waktu yang dihabiskan Mobita
extern int skor;        // skor Mobita
extern boolean VIPFlag; // Flag jika ada VIP

/* Fungsi dan Prosedur*/
void addScore(int val);
/*I.S. val terdefinisi*/
/*F.S. nilai skor bertambah sebesar val*/
void addTime(float multiplier);
/* I.S. multiplier terdefinisi */
/* F.S. waktu bertambah sebesar (1*multiplier)*/
/* multiplier adalah faktor pengali, defaultnya adalah 1, namun bisa diisi 2
 * atau 0.5 misalnya, untuk kasus heavy item atau speed boost*/
void updateData(Tas *t, InprogressList *ip, Todolist *todo, Queue *DP,
                int *Expired);
/* I.S. t, ip, todo, DP terdefinisi */
/* F.S. Tiap item yang sudah waktunya datang akan dimasukkan ke todo */
/*      Tiap item yang sudah expired dihapus dari ip dan tas */
void removePerishable(Tas *t, InprogressList *ip);

boolean finishedState(Building b, int finishedOrder, int jumlahPesanan);
#endif
