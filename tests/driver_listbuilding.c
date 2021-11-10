#include "../src/listbuilding.h"
#include <stdio.h>

int main() {
    ListBuilding LB;
    CreateListBuilding(&LB, 17);
    Building B;
    CreateBuilding(&B, 1, 2, 'A');
    appendBuilding(&LB, B);
    Building search = searchCoord(LB, 1, 2);
    printf("%c", NAMEBUILDING(search));
    printf("nilai kebenaran Building Mark = %d", isMARKBuilding(search));
}