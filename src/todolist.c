#include <stdlib.h>
#include <stdio.h>

#include "todolist.h"

void CreateTodoList(Todolist *l){
    CreateList(*l);
}

void addTodoList(Todolist *l, Item task){
    insertLast(*l, task);
}

void deleteTodoListAt(Todolist *l, Item *task){
    deleteAt(*l, indexOf(*l, *task), task);
}

void CreateInProgress(InprogressList *l){
    CreateList(*l);
}

void addInProgress(InprogressList *l, Item task){
    insertLast(*l, task);
}

void deleteInProgressAt(InprogressList *l, Item *task){
    deleteAt(*l, indexOf(*l, *task), task);
}

boolean isVIPinList(Todolist l){
    
}