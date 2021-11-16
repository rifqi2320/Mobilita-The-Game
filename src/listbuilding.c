#include "listbuilding.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
void CreateListBuilding(ListBuilding *l, int capacity) {
  BUFFERListB(*l) = (Building *)malloc(capacity * sizeof(Building));
  CAPACITYListB(*l) = capacity;
  int i;
  for (i = 0; i < capacity; i++) {
    ELMTListB(*l, i) = MARKBuilding();
  }
};

void dealocateListBuilding(ListBuilding *l) {
  free(BUFFERListB(*l));
  CAPACITYListB(*l) = 0;
};

/* ********** SELEKTOR  ********** */
int lengthListBuilding(ListBuilding l) {
  int i = 0, len = 0;
  while (!isMARKBuilding(ELMTListB(l, i)) && i < CAPACITYListB(l)) {
    len++;
    i++;
  }
  return len;
};

Building searchCoord(ListBuilding l, int X, int Y) {
  int i = 0;
  boolean found = false;
  while (i < lengthListBuilding(l) && !found) {
    if (XCOORD(ELMTListB(l, i)) == X && YCOORD(ELMTListB(l, i)) == Y) {
      found = true;
    } else {
      i++;
    }
  }
  if (found) {
    return ELMTListB(l, i);
  } else {
    return MARKBuilding();
  }
}

/* ********** OPERATOR  ********** */
void appendBuilding(ListBuilding *l, Building B) {
  ELMTListB(*l, lengthListBuilding(*l)) = B;
}

void copyListBuilding(ListBuilding lIn, ListBuilding *lOut) {
  CreateListBuilding(lOut, CAPACITYListB(lIn));
  int i;
  for (i = 0; i < lengthListBuilding(lIn); i++) {
    ELMTListB(*lOut, i) = ELMTListB(lIn, i);
  }
}

void growListBuilding(ListBuilding *l, int num) {
  ListBuilding templ;
  int i;
  copyListBuilding(*l, &templ);
  dealocateListBuilding(l);
  CreateListBuilding(l, CAPACITYListB(templ) + num);
  for (i = 0; i < lengthListBuilding(templ); i++) {
    ELMTListB(*l, i) = ELMTListB(templ, i);
  }
  dealocateListBuilding(&templ);
}

void shrinkListBuilding(ListBuilding *l, int num) {
  ListBuilding templ;
  int i;
  copyListBuilding(*l, &templ);
  dealocateListBuilding(l);
  CreateListBuilding(l, CAPACITYListB(templ) - num);
  for (i = 0; i < lengthListBuilding(templ) && i < CAPACITYListB(*l); i++) {
    ELMTListB(*l, i) = ELMTListB(templ, i);
  }
  dealocateListBuilding(&templ);
}

void displayListBuilding(ListBuilding l) {
  printf("Posisi yang dapat dicapai:\n");

  int i;
  for (i = 0; i < CAPACITYListB(l); i++) {
    printf("%d. %c (%d,%d)\n", i + 1, NAMEBUILDING(ELMTListB(l, i)),
           XCOORD(ELMTListB(l, i)), YCOORD(ELMTListB(l, i)));
  }

  printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");
}