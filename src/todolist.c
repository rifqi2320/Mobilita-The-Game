#include <stdlib.h>
#include <stdio.h>

#include "todolist.h"

void CreateTodoList(Todolist *l){
    CreateList(*l);
}

void addTodoList(Todolist *l, ElType task){
    insertLast(*l, task);
}

void deleteTodoListAt(Todolist *l, ElType *task){
    deleteAt(*l, indexOf(*l, *task), task);
}

void CreateInProgress(InprogressList *l){
    CreateList(*l);
}

void addInProgress(InprogressList *l, ElType task){
    insertLast(*l, task);
}

void deleteInProgressAt(InprogressList *l, ElType *task){
    deleteAt(*l, indexOf(*l, *task), task);
}

boolean isVIPinList(Todolist l){
    
}