#ifndef NODE_H
#define NODE_H

#include "../item/item.h"
#include <stdlib.h>

typedef struct node *Address;
typedef struct node {
  Item info;
  Address next;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(Item val);

#endif
