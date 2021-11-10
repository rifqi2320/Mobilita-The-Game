#include "queuetodo.h"

void CreateQueue(Queue *q) {
  IDX_HEAD(*q) = -1;
  IDX_TAIL(*q) = -1;
}

boolean isQueueEmpty(Queue q) {
  return (IDX_HEAD(q) == -1) && (IDX_TAIL(q) == -1);
}

boolean isQueueFull(Queue q) {
  return (IDX_HEAD(q) == 0) && (IDX_TAIL(q) == 100 - 1);
}

int length(Queue q) {
  if (isEmpty(q)) {
    return 0;
  }
  return (IDX_TAIL(q) - IDX_HEAD(q)) + 1;
}

void enqueue(Queue *q, Item val) {
  if (isEmpty(*q)) {
    IDX_HEAD(*q) = 0;
    IDX_TAIL(*q) = 0;
    TAIL(*q) = val;
  } else {
    if (IDX_TAIL(*q) == 100 - 1) {
      int i;
      for (i = IDX_HEAD(*q); i <= IDX_TAIL(*q); i++) {
        (*q).buffer[i - IDX_HEAD(*q)] = (*q).buffer[i];
      }
      IDX_TAIL(*q) -= IDX_HEAD(*q);
      IDX_HEAD(*q) = 0;
    }
    IDX_TAIL(*q)++;
    TAIL(*q) = val;

    int j = IDX_TAIL(*q);
    while (((*q).buffer[j - 1].tArrival > val.tArrival) &&
           (j != IDX_HEAD(*q))) {
      (*q).buffer[j] = (*q).buffer[j - 1];
      (*q).buffer[j - 1] = val;
      j--;
    }
  }
}

void dequeue(Queue *q, Item *val) {
  *val = HEAD(*q);
  if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
    IDX_HEAD(*q) = -1;
    IDX_TAIL(*q) = -1;
  } else {
    IDX_HEAD(*q)++;
  }
}