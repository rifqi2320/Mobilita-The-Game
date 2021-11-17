/* Implementasi Untuk Game Engine*/
#include "engine.h"

/* Variabel eksternal*/
int waktu; // waktu yang dihabiskan Mobita
int skor;  // skor Mobita
boolean VIPFlag;
boolean halftime;

/* Realisasi fungsi dan prosedur*/
void addScore(int val) {
  /*I.S. val terdefinisi*/
  /*F.S. nilai skor bertambah sebesar val*/
  // kamus lokal
  // algoritma
  skor += val;
}
void addTime(int multiplier) {
  /* I.S. multiplier terdefinisi */
  /* F.S. waktu bertambah sebesar (1*multiplier)*/
  /* multiplier adalah faktor pengali, defaultnya adalah 1, namun bisa diisi 2
   * atau 0.5 misalnya, untuk kasus heavy item atau speed boost*/
  // kamus lokal
  // algoritma
  waktu += multiplier;
}

void updateData(Tas *t, InprogressList *ip, Todolist *todo, Queue *DP,
                int *Expired) {
  int i;
  Item tempItem;
  // Update daftar pesanan dan todolist
  if (!isQueueEmpty(*DP)) {
    while (HEAD(*DP).tArrival <= waktu && IDX_HEAD(*DP) != -1) {
      dequeue(DP, &tempItem);
      addTodoList(todo, tempItem);
    }
  }
  // Update tas dan inprogress list
  if (!isTasEmpty(*t)) {
    i = 0;
    while (i <= IDX_TOP(*t)) {
      if (t->buffer[i].type == 'P' && isItemExpired(t->buffer[i], waktu)) {
        deleteInProgressAt(ip, &(t->buffer[i]));
        deleteTasAt(t, i);
        (*Expired)++;
      } else {
        i++;
      }
    }
  }
  // Update VIP
  if (isVIPinList(*todo) || isVIPinList(*ip)) {
    VIPFlag = true;
  } else {
    VIPFlag = false;
  }
}

boolean finishedState(Building b, int finishedOrder, int jumlahPesanan) {
  return (NAMEBUILDING(b) == '8') && (finishedOrder == jumlahPesanan);
}
