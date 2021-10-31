#ifndef TODOLIST_H
#define TODOLIST_H

#include "list_linked.h"

typedef List Todolist;

void CreateTodoList(Todolist *l);

void addTodoList(Todolist *l, ElType task);

void deleteTodoListAt(Todolist *l, ElType *task);

boolean isVIPinList(Todolist l);

#endif