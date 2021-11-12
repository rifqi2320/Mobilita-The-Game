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

int lengthQueue(Queue q) {
  if (isQueueEmpty(q)) {
    return 0;
  }
  return (IDX_TAIL(q) - IDX_HEAD(q)) + 1;
}

void enqueue(Queue *q, Item val) {
  // ngecek tail nya mentok
  if (IDX_TAIL(*q) == 100 - 1) {
    int i;
    Queue tempq;
    Item tempval;
    CreateQueue(&tempq);
    for (i = IDX_HEAD(*q); i <= IDX_TAIL(*q); i++) {
      dequeue(q, &tempval);
      enqueue(&tempq, tempval);
    }
    *q = tempq;
  } else if (isQueueEmpty(*q)) {
    IDX_HEAD(*q) = 0;
    IDX_TAIL(*q) = -1;
  }
  int j = IDX_HEAD(*q);
  int idx = -1;

  while ((idx == -1) && (j <= IDX_TAIL(*q))) {
    if ((*q).buffer[j].tArrival < val.tArrival) {
      idx = j;
    } else {
      j++;
    }
  }

  IDX_TAIL(*q) += 1;
  if (idx == -1) {
    TAIL(*q) = val;
  } else {
    int k;
    for (k = IDX_TAIL(*q) - 1; k >= idx; k--) {
      (*q).buffer[k + 1] = (*q).buffer[k];
    }
    (*q).buffer[idx] = val;
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