#include <stdlib.h>
#include <stdio.h>

#include "boolean.h"
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
    //memberikan trua jika ada item vip di list
    //kamus lokal
    Address p;//address yang mengarah ke elemen di indeks idx
    boolean found;//bernilai true jika ada item vip di list (type=='V')
    //algoritma
    p = FIRST(l);
    found = false;
    while(p!=NULL && !found){
        if((p->info.type=='V')){//jika ketemu
            found=true;
        }
        else{
            p = NEXT(p);
        }
    }
    //val ketemu atau sudah sampai ujung
    return found;
}

void displayTodoList(Todolist l){
    //kamus lokal
    Address x;//pointer untuk traversal
    int idx;//variabel untuk mencetak posisi urutan to do list
    //algoritma
    printf("Pesanan pada To Do List:\n");
    char* type;//tipe item di to do list
    if(!isEmpty(l)){//jika list tidak kosong
        idx = 1;
        x = FIRST(l);
        while(x!=NULL){//selama masih ada elemen
            printf("%d. %c -> %c (",idx,x->info.lPickup,x->info.lDropoff);
            switch(x->info.type){
                case 'N':  printf("Normal Item)\n");
                            break;
                case 'H':  printf("Heavy Item)\n");
                            break;
                case 'P':  printf("Perishable Item, sisa waktu %d)\n",x->info.tPerish);
                            break;
                case 'V':  printf("VIP Item)\n");
            }
            x = NEXT(x);
            idx++;
        }
    }
}
void displayInProgress(InprogressList l){
    //mencetak in progress list
    //kamus lokal
    Address x;//pointer untuk traversal
    int idx;//variabel untuk mencetak posisi urutan to do list
    //algoritma
    printf("Pesanan yang sedang diantarkan:\n");
    char* type;//tipe item di to do list
    if(!isEmpty(l)){//jika list tidak kosong
        idx = 1;
        x = FIRST(l);
        printf("1. Normal Item (Tujuan: H)");
        while(x!=NULL){//selama masih ada elemen
            printf("%d. ",idx);
            switch(x->info.type){
                case 'N':  printf("Normal Item (");
                            break;
                case 'H':  printf("Heavy Item (");
                            break;
                case 'P':  printf("Perishable Item (");
                            break;
                case 'V':  printf("VIP Item (");
            }
            printf("Tujuan: %c",x->info.lDropoff);
            if(x->info.type=='V'){//menampilkan waktu tersisa sampai hangus
                printf(", Sisa Waktu: %d)\n",x->info.tPerish);
            }
            else{
                printf(")\n");
            }
            x = NEXT(x);
            idx++;
        }
    }
}
boolean isInPickupSpot(Building b,Todolist l){
//menghasilkan true jika di spot tersebut ada item yang bisa di pick up
    //kamus lokal
    Address p;//pointer untuk traversal
    boolean found;//menghasilkan true jika ada item di building tersebut
    //algoritma
    found = false;
    if(!isEmpty(l) && !found){
        p = FIRST(l);
        while(p!=NULL){
            if(p->info.lPickup==b.name){//kalau ketemu
                found = true;
            }
            else{
                p = NEXT(p);
            }
        }
    }
    return found;
}
void pickUpItem(Building b,Todolist l,Item *item){
//mendequeue item paling awal di list 
//asumsi:Item sudah dipastikan ada melalui fungsi isInPickupSpot
    //kamus lokal
    Address p;//pointer untuk traversal
    int idx;//variabel untuk kounter
    //algoritma
    p = FIRST(l);
    idx = 0;
    while(p!=NULL){
        if(p->info.lPickup==b.name){
            deleteAt(&l,idx,item);
        }
        else{
            p = NEXT(p);
            idx++;
        }
    }
}
boolean isInDropoffSpot(Building b,Tas t){
//menghasilkan true jika di spot tersebut ada item yang bisa di dropoff
    //kamus lokal
    //algoritma
    return (TOP(t).lDropoff==b.name);
}

void dropOffItem(Building b,Todolist l,Tas t){
//drop isi tas paling atas

}