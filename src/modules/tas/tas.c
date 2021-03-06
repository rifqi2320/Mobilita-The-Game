#include "tas.h"

void CreateTas(Tas *t) {
  IDX_TOP(*t) = IDX_UNDEF;
  t->capacity = 3;
}

boolean isTasEmpty(Tas t) { return IDX_TOP(t) == IDX_UNDEF; }

boolean isTasFull(Tas t) { return IDX_TOP(t) == t.capacity - 1; }

void push(Tas *t, Item val) {
  IDX_TOP(*t) += 1;
  TOP(*t) = val;
}

void pop(Tas *t, Item *val) {
  *val = TOP(*t);
  IDX_TOP(*t) -= 1;
}

void deleteTasAt(Tas *t, int i) {
  int j = i;
  while (j < IDX_TOP(*t)) {
    t->buffer[j] = t->buffer[j + 1];
    j++;
  }
  IDX_TOP(*t) -= 1;
}

void increaseCapacity(Tas *t) { t->capacity += 1; }

int numOfHeavy(Tas t) {
  // kamus lokal
  int counter; // jumlah item heavy
  int i;       // variabel untuk looping
  // algoritma
  counter = 0;
  for (i = 0; i <= IDX_TOP(t); i++) {
    if (t.buffer[i].type == 'H') {
      counter++;
    }
  }
  return counter;
}
boolean isVIPinTop(Tas t) {
  /* Menghasilkan true jika item teratasnya ialah item vip*/
  return TOP(t).type == 'V';
}