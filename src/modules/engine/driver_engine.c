#include "engine.h"
#include <stdio.h>

int main() {
  waktu = 0;
  skor = 0;
  printf("Score:%d\n", skor);
  printf("Waktu:%d\n", waktu);

  // fungsi addScore
  addScore(100);
  printf("Score:%d\n", skor);

  // fungsi addTime
  addTime(1);
  printf("Waktu:%d\n", waktu);
  addTime(2);
  printf("Waktu:%d\n", waktu);

  // fungsi update data
  Tas t;
  CreateTas(&t);
  Todolist todo;
  CreateTodoList(&todo);
  InprogressList ip;
  CreateInProgress(&ip);
  Queue q;
  CreateQueue(&q);
  Item I;
  CreateItem(&I, 'N', 2, 2, 'A', 'B');
  push(&t, I);
  addInProgress(&ip, I);
  addTodoList(&todo, I);
  waktu = 100;
  CreateItem(&I, 'P', 2, 2, 'A', 'B');
  push(&t, I);
  addInProgress(&ip, I);
  addTodoList(&todo, I);
  CreateItem(&I, 'V', 2, 2, 'A', 'B');
  push(&t, I);
  addInProgress(&ip, I);
  addTodoList(&todo, I);
  int expired;
  expired = 0;
  updateData(&t, &ip, &todo, &q, &expired);
  printf("Jumlah yang expired:%d\n", expired);
  if (VIPFlag && isQueueEmpty(q)) {
    displayTodoList(todo);
    printf("\n");
    printf("Aman\n");
    displayInProgress(ip, 1);
    printf("\n");
  }

  // fungsi finished state
  Building B1;
  CreateBuilding(&B1, 4, 5, '8');
  int finisheOrder = 9;
  int jumlahPesanan = 10;
  if (finishedState(B1, finisheOrder, jumlahPesanan)) {
    printf("Semestinya belum kelar.\n");
  }
  finisheOrder++;
  if (finishedState(B1, finisheOrder, jumlahPesanan)) {
    printf("Sekarangg baru kelar.\n");
  }
  return 0;
}
