#include "../src/listbuilding.h"
#include <stdio.h>

int main() {
    ListBuilding LB;
    CreateListBuilding(&LB, 2);
    Building B;
    int n, m;
    char name;
    scanf("%d %d", &n, &m);
    scanf(" %c", &name);
    CreateBuilding(&B, n, m, name);
    appendBuilding(&LB, B);
    int len1 = lengthListBuilding(LB);
    printf("panjang List Building = %d\n", len1);
    shrinkListBuilding(&LB, 2);
    len1 = lengthListBuilding(LB);
    printf("panjang List Building setelah shrink = %d\n", len1);
    displayListBuilding(LB);
}