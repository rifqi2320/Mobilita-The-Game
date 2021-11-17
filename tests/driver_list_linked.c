#include "../src/item.h"
#include "../src/list_linked.h"
#include <stdio.h>

int main() {
  List l;
  Item t;
  CreateList(&l);
  CreateItem(&t, 'N', 1, TIME_UNDEF, 'G', 'H');
  insertPrio(&l, t);
  return 0;
}