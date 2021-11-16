#include "charmachine.h"
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
boolean finishedState(Building b, int finishedOrder, int jumlahPesanan);

int main() {
  boolean started = false;

  // Temp Variable
  int tempInt;
  int tempInt2;
  char *tempString;
  Word tempWord;
  int gainedMoney; // uang yang didapatkan setelah menyelesaikan misi
  int jumlahPesanan;
  int finishedOrder; // jumlah pesanan yang selesai

  // Engine Variable
  extern int waktu;
  // extern int skor;

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
    printf("=============================MOBILITA=============================="
           "=\n");
    printf("\"Bisakah Kamu Mengantarkan Semua Paket Ini dan Membantu "
           "Keluargamu?\"\n");
    printf("List Command:\n");
    printf("1.NEW GAME\n");
    printf("2.EXIT\n");
    printf("Pilih Command(dalam angka): ");
    // start screen
    // Ngeoutput menu
    tempInt = wordToInt(nextInput());
    if (tempInt == 1) {
      do {
        printf("Masukkan nama file config: ");
        tempString = wordToString(nextInput());
      } while (!isFileExist(tempString));
      // Inisialisasi seluruh object dan adt
      inputConfig(tempString, &PT, &DP, &jumlahPesanan); // Berdasarkan config
      CreateMobita(&mob, ELMTListB(LBMap(PT), 0));
      CreateTas(&tas);
      MakeListGadget(&inv);
      CreateTodoList(&todo);
      CreateInProgress(&ip);
      MakeListGadgetHQ(&gadgetbuy);
      started = true;
      finishedOrder = 0;
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
    if (finishedState(Posisi(mob), finishedOrder, jumlahPesanan)) {
      started = false;
    } else {
      // printf("Skor: %d\n", skor);
      printf("Waktu: %d\n", waktu);
      printf("Uang: %d Yen\n", Uang(mob));
      printf("Lokasi Mobita: %c (%d,%d)\n", NAMEBUILDING(Posisi(mob)),
             XCOORD(Posisi(mob)), YCOORD(Posisi(mob)));
      printf("Jumlah pesanan yang harus dikerjakan: %d\n\n",
             jumlahPesanan - finishedOrder);
      printf("ENTER COMMAND: ");
      tempWord = nextInput();
      system("@cls||clear");
      if (finishedState(Posisi(mob), finishedOrder, jumlahPesanan)) {
        started = false;
      } else if (validateWord(tempWord, "MOVE")) {
        displayMap(PT, Posisi(mob), todo, ip);
        tempInt = displayIsReachable(PT, Posisi(mob));
        do {
          printf("Masukkan no lokasi yang ingin dituju (Ketik 0 jika ingin "
                 "kembali): ");
          tempInt2 = wordToInt(nextInput());
        } while (tempInt2 < 0 || tempInt2 >= tempInt);
        if (tempInt2 > 0) {
          move(&mob, getReachable(PT, Posisi(mob), tempInt2));
          updateData(&tas, &ip, &todo, &DP);
        }
      } else if (validateWord(tempWord, "PICK_UP")) {
        if (isInPickupSpot(Posisi(mob), todo)) {
          pick_up(Posisi(mob), &todo, &tas, &ip, waktu);
          changeSpeed(&mob, (1 + numOfHeavy(tas)));
        } else {
          printf("Pesanan tidak ditemukan!\n\n");
        }
      } else if (validateWord(tempWord, "DROP_OFF")) {
        if (isInDropoffSpot(Posisi(mob), ip)) {
          dropOffItem(Posisi(mob), &ip, &tas, &gainedMoney);
          changeMoney(&mob, gainedMoney);
          changeSpeed(&mob, (1 + numOfHeavy(tas)));
          checkEffectSenter(&tas,&mob);
          finishedOrder++;
        } else {
          printf("Tidak ada pesanan yang dapat diantarkan!\n\n");
        }
      } else if (validateWord(tempWord, "MAP")) {
        displayMap(PT, Posisi(mob), todo, ip);
      } else if (validateWord(tempWord, "TO_DO")) {
        displayTodoList(todo);
      } else if (validateWord(tempWord, "IN_PROGRESS")) {
        displayInProgress(ip, waktu);
      } else if (validateWord(tempWord, "BUY")) {
        buyGadget(&inv, gadgetbuy, &mob);
      } else if (validateWord(tempWord, "INVENTORY")) {
        useGadget(&inv, &tas, &mob, &ip, LBMap(PT));
      } else if (validateWord(tempWord, "HELP")) {
        displayHelp();
      } else if (validateWord(tempWord, "RETURN")) {
        mobitaReturn(mob, &tas, &todo, &ip);
        checkEffectSenter(&tas,&mob);
      }else {
        printf("Masukkan Tidak Valid.\nGunakan command \"HELP\" untuk petunjuk "
               "penggunaan.\n");
      }
    }
  }
  printf("\nOTSUKARE!!!\n");
  printf("SELAMAT, ANDA TELAH MENYELESAIKAN PERMAINAN INI!!\n");
  printf("WAKTU YANG ANDA HABISKAN: %d", waktu);
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
boolean finishedState(Building b, int finishedOrder, int jumlahPesanan) {
  return (NAMEBUILDING(b) == '8') && (finishedOrder == jumlahPesanan);
}