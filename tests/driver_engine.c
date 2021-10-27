#include "../src/engine.h"
#include <stdio.h>
float waktu;
int skor;

int main(){
    waktu = 0;
    skor = 0;
    printf("Score:%d\n",skor);
    printf("Waktu:%d\n",waktu);
    addScore(100);
    printf("Score:%d\n",skor);
    addTime(1);
    printf("Waktu:%d\n",waktu);
    addTime(2);
    printf("Waktu:%d\n",waktu);
    return 0;
}