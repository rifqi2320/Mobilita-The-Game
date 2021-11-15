#include "engine.h"
#include "inventory.h"
#include "io.h"
#include "list_linked.h"
#include "listbuilding.h"
#include "map.h"
#include "mobita.h"
#include "queuetodo.h"
#include "tas.h"
#include "todolist.h"

#include <stdio.h>

void displayHelp();

int main() {
  boolean started = false;
  printf("====MOBILITA====\n");
  // start screen

  // Temp Variable
  int tempInt;
  int tempInt2;
  char tempChar;
  char *tempString;
  Word tempWord;
  int gainedScore;//skor yang didapatkan setelah menyelesaikan misi

  // Engine Variable
  extern int waktu;
  extern int skor;

  // Object atau ADT
  Queue DP;              // Daftar Pesanan
  Map PT;                // Map
  MOBITA mob;            // Mobita
  Tas tas;               // Tas berisi Item
  LIST_GADGET inv;       // Inventory berisi Gadget
  LIST_GADGET gadgetbuy; // List Gadget yang ada di HQ
  Todolist todo;         // TodoList
  InprogressList ip;     // In Progress List

  while (!started) {
    // Ngeoutput menu
    tempInt = wordToInt(nextInput());
    if (tempInt == 1) {
      tempString = wordToString(nextInput());
      // Inisialisasi seluruh object dan adt
      inputConfig(tempString, &PT, &DP); // Berdasarkan config
      CreateMobita(&mob, ELMTListB(LBMap(PT), 0));
      CreateTas(&tas);
      MakeListGadget(&inv);
      CreateTodoList(&todo);
      CreateInProgress(&ip);
      MakeListGadgetHQ(&gadgetbuy);

      started = true;
    } else if (tempInt == 2) {
      return 0;
    } else {
      printf("Output tidak valid.\n");
    }
  }

  // Game Started
  while (started) {
    // int i;
    // printf("%d %c %c %c\n", TAIL(DP).tArrival, TAIL(DP).lPickup,
    //        TAIL(DP).lDropoff, TAIL(DP).type);
    // for (i = IDX_HEAD(DP); i <= IDX_TAIL(DP); i++) {
    //   printf("%d %c %c %c\n", DP.buffer[i].tArrival, DP.buffer[i].lPickup,
    //          DP.buffer[i].lDropoff, DP.buffer[i].type);
    // }
    updateData(&tas, &ip, &todo, &DP);
    printf("Waktu: %d\n", waktu);
    printf("Skor: %d\n",skor);
    printf("Lokasi Mobita: %c (%d,%d)\n\n", NAMEBUILDING(Posisi(mob)),
           XCOORD(Posisi(mob)), YCOORD(Posisi(mob)));
    printf("ENTER COMMAND: ");
    tempWord = nextInput();
    system("@cls||clear");
    if (validateWord(tempWord, "MOVE")) {
      displayMap(PT, Posisi(mob), todo, ip);
      tempInt = displayIsReachable(PT, Posisi(mob));
      do {
        printf("Masukkan no lokasi yang ingin dituju: ");
        tempInt2 = wordToInt(nextInput());
      } while (tempInt2 < 0 && tempInt2 >= tempInt);
      if (tempInt2 > 0) {
        move(&mob, getReachable(PT, Posisi(mob), tempInt2));
        updateData(&tas, &ip, &todo, &DP);
      }
    } else if (validateWord(tempWord, "PICK_UP")) {
      if (isInPickupSpot(Posisi(mob), todo)) {
        pick_up(Posisi(mob), &todo, &tas, &ip);
      } else {
        printf("Tidak ada item yang bisa di pickup\n");
      }
    } else if (validateWord(tempWord, "DROP_OFF")) {
      dropOffItem(Posisi(mob),&ip,&tas,&gainedScore);
      addScore(gainedScore);
    } else if (validateWord(tempWord, "MAP")) {
      displayMap(PT, Posisi(mob), todo, ip);
    } else if (validateWord(tempWord, "TO_DO")) {
      displayTodoList(todo);
    } else if (validateWord(tempWord, "IN_PROGRESS")) {
      displayInProgress(ip);
    } else if (validateWord(tempWord, "BUY")) {
      buyGadget(&inv, gadgetbuy, &mob);
    } else if (validateWord(tempWord, "INVENTORY")) {
      useGadget(&inv, &tas, &mob, &ip, LBMap(PT));
    } else if (validateWord(tempWord, "HELP")) {
      displayHelp();
    } else {
      printf("Masukkan Tidak Valid.\nGunakan command \"HELP\" untuk petunjuk "
             "penggunaan.\n");
    }
  }

  printf("OTSUKARE!!!\n");
  printf("SELAMAT, ANDA TELAH MENYELESAIKAN PERMAINAN INI!!\n");
  return 0;
}

void displayHelp() {
  printf("1. MOVE -> Untuk berpindah ke lokasi selanjutnya\n");
  printf("2. PICK_UP -> Untuk mengambil item di lokasi sekarang\n");
  printf("3. DROP_OFF -> Untuk mengantar item ke lokasi sekarang\n");
  printf("4. MAP -> Untuk memunculkan peta\n");
  printf("5. TO_DO -> Untuk menampilkan pesanan yang masuk ke To Do List\n");
  printf(
      "6. IN_PROGRESS -> Untuk menampilkan pesanan yang sedang dikerjakan\n");
  printf("7. BUY -> Untuk menampilkan gadget yang dapat dibeli lalu "
         "membelinya. Hanya dapat digunakan di Headquarter\n");
  printf("8. INVENTORY -> Untuk melihat gadget yang dimiliki dan "
         "menggunakannya\n");
  printf("9. HELP -> Untuk mengeluarkan list command dan kegunaannya\n");
}