#ifndef TODOLIST_H
#define TODOLIST_H

#include "../../utils/boolean.h"
#include "../building/building.h"
#include "../item/item.h"
#include "../list_linked/list_linked.h"
#include "../tas/tas.h"
#include <stdio.h>
#include <stdlib.h>

typedef List Todolist;

typedef List InprogressList;

#define PICKUP(I) I.lPickup
#define DROPOFF(I) I.lDropoff
#define TYPE(I) I.type
#define PERISH_TIME(I) I.tPerish

void CreateTodoList(Todolist *l);

void addTodoList(Todolist *l, Item task);

void deleteTodoListAt(Todolist *l, Item *task);

void displayTodoList(Todolist l);

boolean isVIPinList(List l);

void CreateInProgress(InprogressList *l);

void addInProgress(InprogressList *l, Item task);

void deleteInProgressAt(InprogressList *l, Item *task);

void displayInProgress(InprogressList l, int waktu);

boolean isInPickupSpot(Building b, Todolist l);
// menghasilkan true jika di spot tersebut ada item yang bisa di pick up

void pick_up(Building b, Todolist *l, Tas *t, InprogressList *ip, int waktu,
             boolean VIPFlag);
// mendequeue item paling awal masuk di lokasi b pada list

boolean isInDropoffSpot(Building b, InprogressList ip);
// menghasilkan true jika di spot tersebut ada item yang bisa di dropoff

void dropOffItem(Building b, InprogressList *ip, Tas *t, int *money);
// drop isi tas paling atas
#endif