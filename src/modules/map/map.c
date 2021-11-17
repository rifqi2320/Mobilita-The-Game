#include "map.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
void CreateMap(Map *PT, int N, int M, int L) {
  ListBuilding LB;
  MB mb;
  int i, j;
  NBMap(*PT) = L;
  WIDTHMap(*PT) = N;
  HEIGHTMap(*PT) = M;
  for (i = 0; i < L; i++) {
    for (j = 0; j < L; j++) {
      ELMTMap(*PT, i, j) = 0;
    }
  }
  CreateMB(&mb);
  MBMap(*PT) = mb;
  CreateListBuilding(&LB, L);
  LBMap(*PT) = LB;
};

void displayMap(Map PT, Building NobitaLoc, Todolist l, InprogressList ip) {
  int i, j;
  Building tempB;
  for (i = 0; i < WIDTHMap(PT) + 2; i++) {
    for (j = 0; j < HEIGHTMap(PT) + 2; j++) {
      if (i == 0 || j == 0 || i > WIDTHMap(PT) || j > HEIGHTMap(PT)) {
        printf("*");
      } else {
        tempB = searchCoord(LBMap(PT), i, j);
        if (!isMARKBuilding(tempB)) {
          if (isEqualBuilding(NobitaLoc, tempB)) {
            print_yellow(NAMEBUILDING(tempB));
          } else if (isInDropoffSpot(tempB, ip)) {
            print_blue(NAMEBUILDING(tempB));
          } else if (isInPickupSpot(tempB, l)) {
            print_red(NAMEBUILDING(tempB));
          } else if (isConnected(PT, NobitaLoc, tempB)) {
            print_green(NAMEBUILDING(tempB));
          } else {
            printf("%c", NAMEBUILDING(tempB));
          }
        } else {
          printf(" ");
        }
      }
    }
    printf("\n");
  }
};

boolean isConnected(Map PT, Building B1, Building B2) {
  int i = getVal(MBMap(PT), NAMEBUILDING(B1));
  int j = getVal(MBMap(PT), NAMEBUILDING(B2));
  return ELMTMap(PT, i, j) == 1;
}

void addBuilding(Map *PT, Building B, int idx) {
  appendBuilding(&(LBMap(*PT)), B);
  setVal(&(MBMap(*PT)), NAMEBUILDING(B), idx);
}

int displayIsReachable(Map PT, Building NobitaLoc) {
  printf("Posisi yang dapat dicapai:\n");
  int idx = 1;
  int i;
  Building tempB;
  for (i = 0; i < NBMap(PT); i++) {
    tempB = ELMTListB(LBMap(PT), i);
    if (isConnected(PT, tempB, NobitaLoc)) {
      printf("%d. %c (%d,%d)\n", idx, NAMEBUILDING(tempB), XCOORD(tempB),
             YCOORD(tempB));
      idx++;
    }
  }
  return idx;
}

Building getReachable(Map PT, Building NobitaLoc, int i) {
  int idx = 1;
  int j;
  Building tempB;
  for (j = 0; j < NBMap(PT); j++) {
    tempB = ELMTListB(LBMap(PT), j);
    if (isConnected(PT, tempB, NobitaLoc)) {
      if (idx == i) {
        return tempB;
      } else {
        idx++;
      }
    }
  }
  return MARKBuilding();
}