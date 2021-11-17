#include "item.h"

void CreateItem(Item *I, char type, int tArrival, int tPerish, char lPickup,
                char lDropoff) {
  I->type = type;
  switch (type) {
  case 'N':
    I->value = 200;
    break;
  case 'H':
    I->value = 400;
    break;
  case 'P':
    I->value = 400;
    break;
  case 'V':
    I->value = 600;
    break;
  default:
    break;
  }
  I->tArrival = tArrival;
  I->tPerish = tPerish;
  I->lPickup = lPickup;
  I->lDropoff = lDropoff;
}

boolean isItemArrived(Item I, int time) { return time >= I.tArrival; }

boolean isItemExpired(Item I, int time) {
  return time >= (I.tPickup + I.tPerish);
}

boolean isItemPickedUp(Item I) { return I.tPickup != TIME_UNDEF; }

void pickupItem(Item *I, int time) { I->tPickup = time; }

void resetItem(Item *I) { I->tPickup = TIME_UNDEF; }