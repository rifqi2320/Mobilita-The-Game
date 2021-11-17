#include "../src/listbuilding.h"
#include <stdio.h>

int main() {
  ListBuilding LB;
  CreateListBuilding(&LB, 1);
  Building B;
  int n, m, len;
  char name;
  scanf("%d %d", &n, &m);
  scanf(" %c", &name);
  CreateBuilding(&B, n, m, name);
  appendBuilding(&LB, B);

  // Test panjang LB setelah di append
  len = lengthListBuilding(LB);
  printf("panjang List Building = %d\n", len);

  // Test panjang LB setelah dishrink
  shrinkListBuilding(&LB, 1);
  len = lengthListBuilding(LB);
  printf("panjang List Building setelah shrink = %d\n", len);
  displayListBuilding(LB);

  // Test panjang LB setelah dishrink lalu digrow lagi
  growListBuilding(&LB, 1);
  len = lengthListBuilding(LB);
  printf("panjang List Building setelah di grow lagi = %d\n", len);
  CreateBuilding(&B, n, m, name);
  appendBuilding(&LB, B);
  displayListBuilding(LB);
  return 0;
}