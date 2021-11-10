#ifndef TODOLIST_H
#define TODOLIST_H

#include "list_linked.h"

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



#endif