#include "todolist.h"
#include <stdio.h>

int main() {
  Tas t;
  Item N, V, H;
  CreateTas(&t);
  CreateItem(&N, 'N', 2, 2, 'A', 'B');
  CreateItem(&V, 'V', 2, 2, 'A', 'B');
  CreateItem(&H, 'H', 2, 2, 'A', 'B');

  Todolist td;
  CreateTodoList(&td);
  addTodoList(&td, N);
  addTodoList(&td, H);
  addTodoList(&td, V);

  displayTodoList(td);

  deleteTodoListAt(&td, &V);

  displayTodoList(td);

  InprogressList ip;

  CreateInProgress(&ip);
  addInProgress(&ip, N);
  addInProgress(&ip, V);

  int waktu = 2;
  displayInProgress(ip, waktu);

  if (isVIPinList(ip)) {
    printf("Ada VIP nih\n");
  }

  deleteInProgressAt(&ip, &V);

  displayInProgress(ip, waktu);

  deleteInProgressAt(&ip, &N);

  Building a;
  CreateBuilding(&a, 2, 2, 'A');

  if (isInPickupSpot(a, td)) {
    printf("Di Pickup cuy\n");
  }

  pick_up(a, &td, &t, &ip, waktu, isVIPinList(td));

  displayInProgress(ip, waktu);

  Building b;
  CreateBuilding(&b, 3, 3, 'B');

  if (isInDropoffSpot(b, ip)) {
    printf("Di Dropoff cuy\n");
  }

  int money = 100;

  dropOffItem(b, &ip, &t, &money);

  displayInProgress(ip, waktu);

  return 0;
}