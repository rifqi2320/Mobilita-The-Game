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
void cetakSkor();
/*I.S. skor terdefinisi*/
/*F.S. mencetak skor ke layar*/
#endif