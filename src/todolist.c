#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"
#include "todolist.h"

void CreateTodoList(Todolist *l) { CreateList(l); }

void addTodoList(Todolist *l, Item task) { insertLast(l, task); }

void deleteTodoListAt(Todolist *l, Item *task) {
  deleteAt(l, indexOf(*l, *task), task);
}

void CreateInProgress(InprogressList *l) { CreateList(l); }

void addInProgress(InprogressList *l, Item task) { insertLast(l, task); }

void deleteInProgressAt(InprogressList *l, Item *task) {
  deleteAt(l, indexOf(*l, *task), task);
}
boolean isVIPinList(Todolist l) {
  // memberikan trua jika ada item vip di list
  // kamus lokal
  Address p;     // address yang mengarah ke elemen di indeks idx
  boolean found; // bernilai true jika ada item vip di list (type=='V')
  // algoritma
  p = FIRST(l);
  found = false;
  while (p != NULL && !found) {
    if ((p->info.type == 'V')) { // jika ketemu
      found = true;
    } else {
      p = NEXT(p);
    }
  }
  // val ketemu atau sudah sampai ujung
  return found;
}

void displayTodoList(Todolist l) {
  // kamus lokal
  Address x; // pointer untuk traversal
  int idx;   // variabel untuk mencetak posisi urutan to do list
  // algoritma
  if (!isListEmpty(l)) { // jika list tidak kosong
    printf("Pesanan pada To Do List:\n");
    idx = 1;
    x = FIRST(l);
    while (x != NULL) { // selama masih ada elemen
      printf("%d. %c -> %c (", idx, x->info.lPickup, x->info.lDropoff);
      switch (x->info.type) {
      case 'N':
        printf("Normal Item)\n");
        break;
      case 'H':
        printf("Heavy Item)\n");
        break;
      case 'P':
        printf("Perishable Item, sisa waktu %d)\n", x->info.tPerish);
        break;
      case 'V':
        printf("VIP Item)\n");
      }
      x = NEXT(x);
      idx++;
    }
    printf("\n");
  }
  else{//list kosong
    printf("Belum ada item yang perlu diantarkan!\n\n");
  }
}
void displayInProgress(InprogressList l) {
  // mencetak in progress list
  // kamus lokal
  Address x; // pointer untuk traversal
  int idx;   // variabel untuk mencetak posisi urutan to do list
  // algoritma
  if (!isListEmpty(l)) { // jika list tidak kosong
    printf("Pesanan yang sedang diantarkan:\n");
    idx = 1;
    x = FIRST(l);
    // printf("1. Normal Item (Tujuan: H)");
    while (x != NULL) { // selama masih ada elemen
      printf("%d. ", idx);
      switch (x->info.type) {
      case 'N':
        printf("Normal Item (");
        break;
      case 'H':
        printf("Heavy Item (");
        break;
      case 'P':
        printf("Perishable Item (");
        break;
      case 'V':
        printf("VIP Item (");
      }
      printf("Tujuan: %c", x->info.lDropoff);
      if (x->info.type == 'P') { // menampilkan waktu tersisa sampai hangus
        printf(", Sisa Waktu: %d)\n", x->info.tPerish);
      } else {
        printf(")\n");
      }
      x = NEXT(x);
      idx++;
    }
    printf("\n");
  }
  else{//list kosong
    printf("Tidak ada item yang sedang diantarkan.\n\n");
  }
}
boolean isInPickupSpot(Building b, Todolist l) {
  // menghasilkan true jika di spot tersebut ada item yang bisa di pick up
  // kamus lokal
  Address p;     // pointer untuk traversal
  boolean found; // menghasilkan true jika ada item di building tersebut
  // algoritma
  // printf("Cekcek\n");
  found = false;
  if (!isListEmpty(l)) {
    p = l;
    while (p != NULL && !found) {
      if (p->info.lPickup == b.name) { // kalau ketemu
        found = true;
      } else {
        p = NEXT(p);
      }
    }
  }
  return found;
}
void pick_up(Building b, Todolist *l, Tas *t, InprogressList *ip, int waktu) {
  // pick_up(Posisi(mob), &todo, &tas, &ip)
  //  mendequeue item paling awal di list
  //  asumsi:Item sudah dipastikan ada melalui fungsi isInPickupSpot
  //  kamus lokal
  Address p;     // pointer untuk traversal
  int idx;       // variabel untuk kounter
  Item tempItem; // Variable temporary utk item
  boolean found; // bernilai true item sudah terpickup
  // algoritma
  p = FIRST(*l);
  idx = 0;
  found = false;
  while (p != NULL) {
    if (INFO(p).lPickup == b.name && !found) {
      if (t->capacity > IDX_TOP(*t) + 1) { // tas belum penuh
        deleteAt(l, idx, &tempItem);
        pickupItem(&tempItem, waktu);
        insertFirst(ip, tempItem);
        push(t, tempItem);
        printf("Pesanan berupa ");
        switch (tempItem.type) {
        case 'N':
          printf("Normal Item");
          break;
        case 'H':
          printf("Heavy Item");
          break;
        case 'P':
          printf("Perishable Item");
          break;
        case 'V':
          printf("VIP Item");
          break;
        }
        printf(" berhasil diambil!\n");
        printf("Tujuan pesanan: %c\n\n",tempItem.lDropoff);
      } else { // tas penuh
        printf("Tas Penuh! Kirimkan paket yang ada di tas terlebih dahulu!\n\n");
      }
      found = true;
    } else {
      p = NEXT(p);
      idx++;
    }
  }
}
boolean isInDropoffSpot(Building b, InprogressList ip) {
  // menghasilkan true jika di spot tersebut ada item yang bisa di dropoff
  // kamus lokal
  // algoritma
  if (isListEmpty(ip)) {
    return false;
  } else {
    return (INFO(FIRST(ip)).lDropoff == b.name);
  }
}

void dropOffItem(Building b, InprogressList *ip, Tas *t, int *money) {
  // drop isi tas paling atas
  // kamus lokal
  Item val; // variabel dummy untuk menyimpan hasil yang di pop
  // algoritma
  pop(t, &val);
  deleteFirst(ip, &val);
  *money = VALUE(val);
  printf("Pesanan ");
  switch (val.type) {
  case 'N':
    printf("Normal Item");
    break;
  case 'H':
    printf("Heavy Item");
    break;
  case 'P':
    printf("Perishable Item");
    break;
  case 'V':
    printf("VIP Item");
    break;
  }
  printf(" berhasil diantarkan\n");
  printf("Uang yang didapatkan: %d Yen\n\n",val.value);
}