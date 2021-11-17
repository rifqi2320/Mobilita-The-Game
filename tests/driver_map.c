#include "../src/map.h"
#include <stdio.h>

int main() {
  Map PT;
  Todolist todo;
  InprogressList ip;
  Building a, b, hq;
  Item A;
  int i;
  CreateMap(&PT, 3, 3, 4);
  CreateTodoList(&todo);
  CreateInProgress(&ip);
  CreateItem(&A, 'N', 2, 3, 'Y', 'Z');
  CreateBuilding(&hq, 1, 1, '8');
  addBuilding(&PT, hq, 0);
  CreateBuilding(&b, 1, 2, 'Z');
  addBuilding(&PT, b, 1);
  CreateBuilding(&a, 1, 3, 'Y');
  addBuilding(&PT, a, 2);
  CreateBuilding(&b, 3, 3, 'X');
  addBuilding(&PT, b, 3);
  insertFirst(&todo, A);
  insertFirst(&ip, A);
  ELMTMap(PT, 0, 3) = 1;
  ELMTMap(PT, 3, 0) = 1;
  displayMap(PT, hq, todo, ip);
  printf(isConnected(PT, hq, b) ? "hq and X are connected\n"
                                : "hq and X arent connected\n");
  printf(isConnected(PT, hq, a) ? "hq and Y are connected\n"
                                : "hq and Y arent connected\n");
  i = displayIsReachable(PT, hq);
  printf("There are %d buildings that are reachable from hq\n", i - 1);
  ELMTMap(PT, 0, 2) = 1;
  ELMTMap(PT, 2, 0) = 1;
  i = displayIsReachable(PT, hq);
  printf("There are %d buildings that are reachable from hq\n", i - 1);
  b = getReachable(PT, hq, 1);
  printf("Building %c is no 1\n", NAMEBUILDING(b));
  b = getReachable(PT, hq, 2);
  printf("Building %c is no 2\n", NAMEBUILDING(b));
  return 0;
}