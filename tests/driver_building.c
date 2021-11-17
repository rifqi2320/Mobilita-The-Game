#include "../src/building.h"
#include <stdio.h>

int main() {
  Building B1, B2, MB;
  int N1 = 0, M1 = 0, N2 = 0, M2 = 0;
  char name1, name2;
  MB = MARKBuilding();
  // input B1
  scanf("%d", &N1);
  scanf("%d", &M1);
  scanf(" %c", &name1);
  // input B2
  scanf("%d", &N2);
  scanf("%d", &M2);
  scanf(" %c", &name2);
  CreateBuilding(&B1, N1, M1, name1);
  CreateBuilding(&B2, N2, M2, name2);

  // display B1 B2
  printf("Koordinat B1 : %d %d, NAMA B1 : %c\n", XCOORD(B1), YCOORD(B1),
         NAMEBUILDING(B1));
  printf("Koordinat B2 : %d %d, NAMA B2 : %c\n", XCOORD(B2), YCOORD(B2),
         NAMEBUILDING(B2));

  printf("Nilai kebenaran MB adalah MARKBUILDING : %d\n", isMARKBuilding(MB));
  printf("Nilai kebenaran B1 == B2 : %d", isEqualBuilding(B1, B2));
  return 0;
}