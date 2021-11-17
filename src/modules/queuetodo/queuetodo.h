#ifndef QUEUE_H
#define QUEUE_H

#include "../../utils/boolean.h"
#include "../item/item.h"
#include <stdlib.h>

typedef struct {
  Item buffer[100];
  int idxHead;
  int idxTail;
} Queue;

#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEAD(q) (q).buffer[(q).idxHead]
#define TAIL(q) (q).buffer[(q).idxTail]

void CreateQueue(Queue *q);

boolean isQueueEmpty(Queue q);

boolean isQueueFull(Queue q);

int lengthQueue(Queue q);

void enqueue(Queue *q, Item val);

void dequeue(Queue *q, Item *val);

#endif