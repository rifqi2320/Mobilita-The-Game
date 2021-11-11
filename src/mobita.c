#include "mobita.h"

void CreateMobita(MOBITA *MOB, Building HQ) {
  Posisi(*MOB) = HQ;
  Uang(*MOB) = 0;
  Speed(*MOB) = 1;
  speedBoost(*MOB) = 0;
  incCapacity(*MOB) = 0;
  returnToSender(*MOB) = 0;
}

void changeSpeed(MOBITA *MOB, float val) { Speed(*MOB) = val; }

void move(MOBITA *MOB, Building dest) {
  Posisi(*MOB) = dest;
  addTime(Speed(*MOB));

  if (speedBoost(*MOB) > 1) {
    speedBoost(*MOB)--;
  }

  if (speedBoost(*MOB) == 1) {
    removeAbility(MOB, 's');
  }
}

void addAbility(MOBITA *MOB, char s) {
  if (s == 's') {
    speedBoost(*MOB) = 11;
    changeSpeed(MOB, 0.5);
  } else if (s == 'i') {
    incCapacity(*MOB) = 1;
  } else if (s == 'r') {
    returnToSender(*MOB) = 1;
  }
}

void removeAbility(MOBITA *MOB, char s) {
  if (s == 's') {
    speedBoost(*MOB) = 0;
    changeSpeed(MOB, 1);
  } else if (s == 'i') {
    incCapacity(*MOB) = 0;
  } else if (s == 'r') {
    returnToSender(*MOB) = 0;
  }
}

void mobitaReturn(MOBITA *MOB, Tas *t, Todolist *td, InprogressList *ip) {
  if (returnToSender(*MOB) == 0) {
    printf("Mobita tidak memiliki Ability Return To Sender!\n");
  } else {
    Item tmp = TOP(*t);

    if (tmp.type == 'V') {
      printf("VIP Item gagal dikembalikan");
    } else {
      pop(t, &tmp);
      deleteInProgressAt(ip, &tmp);
      tmp.tPickup = 0;
      addTodoList(td, tmp);
      if (tmp.type == 'N') {
        printf("Normal Item berhasil dikembalikan ke Pick Up Point %c\n",
               tmp.lPickup);
      } else if (tmp.type == 'H') {
        printf("Heavy Item berhasil dikembalikan ke Pick Up Point %c\n",
               tmp.lPickup);
      } else if (tmp.type == 'P') {
        printf("Perishable Item berhasil dikembalikan ke Pick Up Point %c\n",
               tmp.lPickup);
      }
    }
  }
}
