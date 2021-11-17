#include "../src/engine.h"
#include <stdio.h>

int main(){
    waktu = 0;
    skor = 0;
    printf("Score:%.1f\n",skor);
    printf("Waktu:%.1f\n",waktu);
    addScore(100);
    printf("Score:%.1f\n",skor);
    addTime(1);
    printf("Waktu:%.1f\n",waktu);
    addTime(2);
    printf("Waktu:%.1f\n",waktu);
    return 0;
}