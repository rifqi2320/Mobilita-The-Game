#include "../src/engine.h"
#include "../src/mobita.h"
#include <stdio.h>

int main(){
    MOBITA MOB;
    Building hq;
    Tas t;
    Todolist td;
    InprogressList ip;
    Item it;

    CreateItem(&it, 'N', 3, 9, '1','2');

    CreateTas(&t);
    CreateTodoList(&td);
    CreateInProgress(&ip);

    push(&t, it);
    addInProgress(&ip, it);

    CreateBuilding(&hq, 1, 1, 'A');

    CreateMobita(&MOB,hq);
    printf("Money Mobita : %d\n", Uang(MOB));
    printf("Speed Mobita : %d\n", Speed(MOB));
    printf("Ability speed boost : %d\n", speedBoost(MOB));
    printf("Ability increase capacity : %d\n", incCapacity(MOB));
    printf("Ability return : %d\n", returnToSender(MOB));
    printf("Lokasi Mobita sekarang : %d %d\n", XCOORD(Posisi(MOB)), YCOORD(Posisi(MOB)));
    printf("\n");

    Building a;
    CreateBuilding(&a, 2, 2, '1');

    move(&MOB, a);

    printf("Lokasi Mobita sekarang : %d %d\n", XCOORD(Posisi(MOB)), YCOORD(Posisi(MOB)));
    printf("\n");

    addAbility(&MOB,'s');
    addAbility(&MOB,'i');
    addAbility(&MOB,'r');

    printf("Ability speed boost : %d\n", speedBoost(MOB));
    printf("Ability increase capacity : %d\n", incCapacity(MOB));
    printf("Ability return : %d\n", returnToSender(MOB));
    printf("Speed Mobita : %d\n", Speed(MOB));
    printf("\n");

    removeAbility(&MOB,'s');
    removeAbility(&MOB,'r');

    printf("Ability speed boost : %d\n", speedBoost(MOB));
    printf("Ability increase capacity : %d\n", incCapacity(MOB));
    printf("Ability return : %d\n", returnToSender(MOB));
    printf("Speed Mobita : %d\n", Speed(MOB));
    printf("\n");

    changeSpeed(&MOB, 2);
    changeMoney(&MOB, 2.0);

    printf("Speed Mobita : %d\n", Speed(MOB));
    printf("Money Mobita : %d\n", Uang(MOB));
    printf("\n");

    mobitaReturn(MOB, &t, &td, &ip);

    return 0;
}