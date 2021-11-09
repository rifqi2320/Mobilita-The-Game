#include "mobita.h"

void CreateMobita(MOBITA *MOB){
    Absis(Posisi(*MOB)) = 0;
    Ordinat(Posisi(*MOB)) = 0;
    Uang(*MOB) = 0;
    Speed(*MOB) = 1;
    speedBoost(*MOB) = 0;
    incCapacity(*MOB) = 0;
    returnToSender(*MOB) = 0;
}

void move(MOBITA *MOB, POINT dest){
    Posisi(*MOB) = dest;
    addTime(1);
}

void addAbility(MOBITA *MOB, char s){
    if (s == 's'){
        speedBoost(*MOB) = 10;
        Speed(*MOB) = 0.5;
    } else if (s == 'i'){
        incCapacity(*MOB) = 1;
    } else if (s == 'r'){
        returnToSender(*MOB) = 1;
    }
}

void removeAbility(MOBITA *MOB, char s){
    if (s == 's'){
        speedBoost(*MOB) = 0;
        Speed(*MOB) = 1;
    } else if (s == 'i'){
        incCapacity(*MOB) = 0;
    } else if (s == 'r'){
        returnToSender(*MOB) = 0;
    } 
}