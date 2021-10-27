/* Game Engine untuk menhitung waktu dan skor*/
#ifndef _ENGINE__H
#define _ENGINE__h

/* Variabel Global*/
extern int waktu;//waktu yang dihabiskan Mobita
extern int skor;//skor Mobita

/* Fungsi dan Prosedur*/
void addScore(int val);
/*I.S. val terdefinisi*/
/*F.S. nilai skor bertambah sebesar val*/
void cetakWaktu();
/*I.S. waktu terdefinisi*/
/*F.S. mencetak waktu sekarang ke layar*/
void addTime(float multiplier);
/* I.S. multiplier terdefinisi */
/* F.S. waktu bertambah sebesar (1*multiplier)*/
/* multiplier adalah faktor pengali, defaultnya adalah 1, namun bisa diisi 2 atau 0.5 misalnya, untuk kasus heavy item atau speed boost*/
#endif
