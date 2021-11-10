#include "../src/engine.c"
#include "../src/mobita.c"
#include <stdio.h>

int main(){
    MOBITA MOB;
    CreateMobita(&MOB);
    addAbility(&MOB,'s');
    addAbility(&MOB,'i');
    addAbility(&MOB,'r');

    POINT a;
    Absis(a) = 3;
    Ordinat(a) = 3;

    move(&MOB, a);
    removeAbility(&MOB,'s');
    Absis(a) = 3;
    Ordinat(a) = 2;
    move(&MOB, a);

    return 0;
}