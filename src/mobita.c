#include "mobita.h"

void CreateMobita(MOBITA *MOB){
    Absis(Posisi(*MOB)) = 0;
    Ordinat(Posisi(*MOB)) = 0;
    Uang(*MOB) = 0;
}

void move(MOBITA *MOB, POINT dest){
    Posisi(*MOB) = dest;
    addTime(1);
}