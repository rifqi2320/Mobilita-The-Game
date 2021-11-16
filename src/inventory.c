#include "inventory.h"
#include "engine.h"
#include <stdio.h>

void MakeListGadget(LIST_GADGET *l) {
  int i;
  for (i = 0; i < JUMLAHGADGET; i++) {
    NAMAGADGET(*l, i) = "-";
    HARGAGADGET(*l, i) = VAL_UNDEF;
  }
}

void MakeListGadgetHQ(LIST_GADGET *l) {
  int i;
  for (i = 0; i < JUMLAHGADGET; i++) {
    if (i == 0) {
      NAMAGADGET(*l, i) = "Kain Pembungkus Waktu";
      HARGAGADGET(*l, i) = 800;
    } else if (i == 1) {
      NAMAGADGET(*l, i) = "Senter Pembesar";
      HARGAGADGET(*l, i) = 1200;
    } else if (i == 2) {
      NAMAGADGET(*l, i) = "Pintu Kemana Saja";
      HARGAGADGET(*l, i) = 1500;
    } else if (i == 3) {
      NAMAGADGET(*l, i) = "Mesin Waktu";
      HARGAGADGET(*l, i) = 3000;
    } else {
      NAMAGADGET(*l, i) = "Senter Pengecil";
      HARGAGADGET(*l, i) = 800;
    }
  }
}

int lengthListGadget(LIST_GADGET l) {
  int ctr = 0;
  int i;
  for (i = 0; i < JUMLAHGADGET; i++) {
    if (NAMAGADGET(l, i)[0] != '-') {
      ctr++;
    }
  }
  return ctr;
}

boolean isIdxEff(LIST_GADGET l, int i) {
  if (i < 0 || i >= JUMLAHGADGET) {
    return false;
  } else if (NAMAGADGET(l, i)[0] != '-') {
    return true;
  }
  return false;
}

boolean isLGFull(LIST_GADGET l) {
  if (lengthListGadget(l) == JUMLAHGADGET) {
    return true;
  }
  return false;
}
void buyGadget(LIST_GADGET *l, LIST_GADGET buy, MOBITA *MOB) {
  if (NAMEBUILDING(Posisi(*MOB)) == '8') {
    printf("Uang anda sekarang: %d Yen\n", Uang(*MOB));
    displayBuy(buy);
    int i, j;
    printf("Gadget mana yang ingin kau beli? (Ketik 0 jika ingin kembali)\n");
    printf("ENTER COMMAND: ");
    i = wordToInt(nextInput());
    if (i == 0) {
      printf("Kembali ke menu.\n");
    } else if (isLGFull(*l)) {
      printf("Inventory sudah penuh!\n");
    } else {
      if (i > 0 && i <= JUMLAHGADGET) {
        if (HARGAGADGET(buy, i - 1) > Uang(*MOB)) {
          printf("Uang tidak cukup untuk membeli Gadget!\n");
        } else {
          Uang(*MOB) -= HARGAGADGET(buy, i - 1);
          for (j = 0; j < JUMLAHGADGET; j++) {
            if (NAMAGADGET(*l, j)[0] == '-') {
              NAMAGADGET(*l, j) = getName(GADGET(buy, i - 1));
              HARGAGADGET(*l, j) = getPrice(GADGET(buy, i - 1));
              break;
            }
          }
          printf("%s berhasil dibeli!\n", getName(GADGET(buy, i - 1)));
        }
      } else {
        printf("Gadget tidak ditemukan, kembali ke menu.\n");
      }
    }
  } else {
    printf("Anda sedang tidak berada di HeadQuarters.\n");
  }
}

void useGadget(LIST_GADGET *l, Tas *t, MOBITA *MOB, InprogressList *ip,
               ListBuilding h) {
  GADGET gad;
  int i;
  displayInventory(*l);
  printf("Gadget mana yang ingin digunakan? (Ketik 0 jika ingin kembali)\n");
  printf("ENTER COMMAND: ");
  i = wordToInt(nextInput());
  if (i == 0) {
    printf("Kembali ke main menu.\n");
  } else if (isIdxEff(*l, i - 1)) {
    NAMA(gad) = NAMAGADGET(*l, i - 1);
    HARGA(gad) = HARGAGADGET(*l, i - 1);
    NAMAGADGET(*l, i - 1) = "-";
    HARGAGADGET(*l, i - 1) = VAL_UNDEF;
    process(gad, t, MOB, ip, h);
  } else {
    printf("Tidak ada gadget yang dapat digunakan.\n");
  }
}

void displayBuy(LIST_GADGET l) {
  printf("Gadget yang tersedia:\n");
  int i;
  for (i = 0; i < JUMLAHGADGET; i++) {
    printf("%d. %s (%d Yen)\n", i + 1, NAMAGADGET(l, i), HARGAGADGET(l, i));
  }
}

void process(GADGET gad, Tas *t, MOBITA *MOB, InprogressList *ip,
             ListBuilding h) {
  if (validateString(NAMA(gad), "Kain Pembungkus Waktu")) {
    KainWaktu(t, ip);
  } else if (validateString(NAMA(gad), "Senter Pembesar")) {
    SenterPembesar(t);
  } else if (validateString(NAMA(gad), "Pintu Kemana Saja")) {
    PintuKemanaSaja(MOB, h);
  } else if (validateString(NAMA(gad), "Mesin Waktu")) {
    MesinWaktu();
  } else if (validateString(NAMA(gad), "Senter Pengecil")) {
    SenterPengecil(t, MOB);
  }
}

void KainWaktu(Tas *t, InprogressList *ip) {
  if (TOP(*t).type == 'P') {
    TOP(*t).tPerish += waktu - TOP(*t).tPickup;
    Address now = FIRST(*ip);
    INFO(now).tPerish += waktu - TOP(*t).tPickup;
    printf("Kain Pembungkus Waktu berhasil digunakan!\n");
  } else {
    printf("Kain Pembungkus Waktu gagal digunakan!Kain terbuang.\n");
  }
}

void SenterPembesar(Tas *t) {
  t->capacity *= 2;
  if (t->capacity > 100) {
    t->capacity = 100;
  }
  printf("Senter Pembesar berhasil digunakan!\n");
}

void PintuKemanaSaja(MOBITA *MOB, ListBuilding h) {
  boolean pindah = false;
  while (!pindah) {
    displayListBuilding(h);
    printf("ENTER COMMAND: ");
    int x;
    x = wordToInt(nextInput());
    if (x > 0 && x <= lengthListBuilding(h)) {
      pindah = true;
      printf("Mobita berhasil pindah ke (%d %d).\n",
             XCOORD(ELMTListB(h, x - 1)), YCOORD(ELMTListB(h, x - 1)));
      move(MOB, ELMTListB(h, x - 1));
      Posisi(*MOB) = ELMTListB(h, x - 1);
    } else {
      printf("Lokasi tidak ditemukan, silahkan ulangi.\n");
    }
  }
}

void MesinWaktu() {
  waktu -= 50;
  if (waktu < 0) {
    waktu = 0;
  }
  printf("Mesin Waktu berhasil digunakan!\n");
}

void SenterPengecil(Tas *t, MOBITA *mob) {
  if (TOP(*t).type == 'H') {
    TOP(*t).type = 'S';
    Speed(*mob) -= 1;
    printf("Senter Pengecil berhasil digunakan!\n");
  } else {
    printf("Senter Pengecil gagal digunakan!Senter terbuang.\n");
  }
}

void checkEffectSenter(Tas *t, MOBITA *mob) {
  if (!isTasEmpty(*t)) {
    int i;
    for (i = IDX_TOP(*t); i >= 0; i--) {
      if ((*t).buffer[i].type == 'S') {
        (*t).buffer[i].type = 'H';
        Speed(*mob) += 1;
      }
    }
  }
}

void displayInventory(LIST_GADGET l) {
  int i;
  for (i = 0; i < JUMLAHGADGET; i++) {
    printf("%d. %s\n", i + 1, NAMAGADGET(l, i));
  }
}