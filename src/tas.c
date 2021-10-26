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

void increaseCapacity(Tas *t) { t->capacity += 1; }