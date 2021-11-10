#include "../src/map.h"
#include <stdio.h>


int main() {
    int a = 10;
    char a = getChar(a);
    printf("%c", c);
    Map PT;
    ListBuilding LB;
    CreateListBuilding(&LB, 12);
    POINT HQ = MakePOINT(1,1);
    CreateMap(&PT, 10, 10, HQ, LB);
    for (int i = 0; i <= ROWMap(*PT); i++) {
        for (int j = 0; j <= COLMap(*PT); j++) {
            printf("%c", ELMTMap(*PT, i, j));
        }
    }
}