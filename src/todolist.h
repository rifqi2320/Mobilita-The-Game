#ifndef TODOLIST_H
#define TODOLIST_H

#include "list_linked.h"
#include "building.h"
#include "item.h"

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

boolean isVIPinList(Todolist l);

void CreateInProgress(InprogressList *l);

void addInProgress(InprogressList *l, Item task);

void deleteInProgressAt(InprogressList *l, Item *task);

void displayInProgress(InprogressList l);

boolean isInPickupSpot(Building b,Todolist l);
//menghasilkan true jika di spot tersebut ada item yang bisa di pick up

Item pickUpItem(Building b,Todolist l);
//mendequeue item paling awal di list 

#endif