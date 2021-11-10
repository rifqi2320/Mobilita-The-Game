#include "listbuilding.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
void CreateListBuilding(ListBuilding *l, int capacity) {
  BUFFERListB(*l) = (Building *)malloc(capacity * sizeof(Building));
  CAPACITYListB(*l) = capacity;
  for (int i = 0; i < capacity; i++) {
    XCOORD(ELMTListB(*l, i)) = 0;
    YCOORD(ELMTListB(*l, i)) = 0;
    NAMEBUILDING(ELMTListB(*l, i)) = 0;
  }
};

void dealocateListBuilding(ListBuilding *l) {
  free(BUFFERListB(*l));
  CAPACITYListB(*l) = 0;
};

/* ********** SELEKTOR  ********** */
int lengthListBuilding(ListBuilding l) {
  int i = 0, len = 0;
  while (NAMEBUILDING(ELMTListB(l, i)) != 0 && i < CAPACITYListB(l)) {
    len++;
    i++;
  }
  return len;
};

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