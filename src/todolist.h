#ifndef TODOLIST_H
#define TODOLIST_H

#include "list_linked.h"

typedef List Todolist;

typedef List InprogressList;

typedef Item ElType;
#define PICKUP(I) I.lPickup
#define DROPOFF(I) I.lDropoff
#define TYPE(I) I.type
#define PERISH_TIME(I) I.tPerish

void CreateTodoList(Todolist *l);

void addTodoList(Todolist *l, ElType task);

void deleteTodoListAt(Todolist *l, ElType *task);

void displayTodoList(Todolist l);

boolean isVIPinList(Todolist l);

void CreateInProgress(InprogressList *l);

void addInProgress(InprogressList *l, ElType task);

void deleteInProgressAt(InprogressList *l, ElType *task);

void displayInProgress(InprogressList l);



#endif