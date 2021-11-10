#ifndef TODOLIST_H
#define TODOLIST_H

#include "list_linked.h"

typedef List Todolist;

typedef List InprogressList;
/*
typedef task{

}Task;
*/
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