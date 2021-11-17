#include "modules/charmachine/charmachine.h"
#include "modules/engine/engine.h"
#include "modules/inventory/inventory.h"
#include "modules/io/io.h"
#include "modules/list_linked/list_linked.h"
#include "modules/listbuilding/listbuilding.h"
#include "modules/map/map.h"
#include "modules/mobita/mobita.h"
#include "modules/queuetodo/queuetodo.h"
#include "modules/tas/tas.h"
#include "modules/todolist/todolist.h"

#include <stdio.h>

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
  int Expired;       // Jumlah pesanan yang gagal diantarkan (perishable)

  // Engine Variable
  extern int waktu;
  extern boolean VIPFlag;

  // Object atau ADT
  Queue DP;              // Daftar Pesanan
  Map PT;                // Map
  MOBITA mob;            // Mobita
  Tas tas;               // Tas berisi Item
  LIST_GADGET inv;       // Inventory berisi Gadget
  LIST_GADGET gadgetbuy; // List Gadget yang ada di HQ
  Todolist todo;         // TodoList
  InprogressList ip;     // In Progress List
  Item droppedItem;      // Item yang baru saja diturunkan

  while (!started) {
    printf(
        "  /$$      /$$  /$$$$$$  /$$$$$$$  /$$$$$$ /$$       /$$$$$$ "
        "/$$$$$$$$ "
        "/$$$$$$ \n | $$$    /$$$ /$$__  $$| $$__  $$|_  $$_/| $$      |_  "
        "$$_/|__  $$__//$$__  $$\n | $$$$  /$$$$| $$  \\ $$| $$  \\ $$  | $$  "
        "| $$        | $$     | $$  | $$  \\ $$\n | $$ $$/$$ $$| $$  | $$| "
        "$$$$$$$   | $$  | $$        | $$     | $$  | $$$$$$$$\n | $$  $$$| "
        "$$| $$  | $$| $$__  $$  | $$  | $$        | $$     | $$  | $$__  $$\n "
        "| $$\\  $ | $$| $$  | $$| $$  \\ $$  | $$  | $$        | $$     | $$  "
        "| $$  | $$\n | $$ \\/  | $$|  $$$$$$/| $$$$$$$/ /$$$$$$| $$$$$$$$ "
        "/$$$$$$   | $$  | $$  | $$\n |__/     |__/ \\______/ |_______/ "
        "|______/|________/|______/   |__/  |__/  |__/\n");
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
      Expired = 0;
    } else if (tempInt == 2) {
      return 0;
    } else {
      printf("Output tidak valid.\n");
    }
  }

  // Game Started
  while (started) {
    updateData(&tas, &ip, &todo, &DP, &Expired);
    if (finishedState(Posisi(mob), finishedOrder + Expired, jumlahPesanan)) {
      started = false;
    } else {
      printf("Waktu: %d\n", waktu);
      printf("Uang: %d Yen\n", Uang(mob));
      printf("Lokasi Mobita: %c (%d,%d)\n", NAMEBUILDING(Posisi(mob)),
             XCOORD(Posisi(mob)), YCOORD(Posisi(mob)));
      printf(
          VIPFlag
              ? "TERDAPAT PESANAN ZHISUKA, SILAHKAN PRIORITASKAN PESANANNYA\n"
              : "");
      printf("Jumlah pesanan yang harus dikerjakan: %d\n\n",
             jumlahPesanan - finishedOrder - Expired);
      printf("ENTER COMMAND: ");
      tempWord = nextInput();
      // system("@cls||clear");
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
        }
      } else if (validateWord(tempWord, "PICK_UP")) {
        if (isInPickupSpot(Posisi(mob), todo)) {
          pick_up(Posisi(mob), &todo, &tas, &ip, waktu, VIPFlag);
          if (TOP(tas).type == 'H') {
            if (speedBoost(mob) > 0) {
              removeAbility(&mob, 's');
            }
            changeSpeed(&mob, (1 + numOfHeavy(tas)));
          }
        } else if (isVIPinTop(tas)) {
          printf("Antarkan pesanan Zhisuka terlebih dahulu!\n");
        } else {
          printf("Pesanan tidak ditemukan!\n\n");
        }
      } else if (validateWord(tempWord, "DROP_OFF")) {
        if (isInDropoffSpot(Posisi(mob), ip)) {
          droppedItem = TOP(tas);
          dropOffItem(Posisi(mob), &ip, &tas, &gainedMoney);
          changeMoney(&mob, gainedMoney);
          checkEffectSenter(&tas, &mob);
          finishedOrder++;
          if (droppedItem.type == 'H') {
            if (numOfHeavy(tas) == 0) {
              addAbility(&mob, 's');
              printf("Ability Speed Boost berhasil diaktifkan.\n\n");
            } else {
              changeSpeed(&mob, (1 + numOfHeavy(tas)));
            }
          } else if (droppedItem.type == 'P') { // yg di drop perishable item
            increaseCapacity(&tas);
            printf("Ability Increase Capacity berhasil diaktifkan.\n\n");
          } else if (droppedItem.type == 'V' &&
                     returnToSender(mob) != 1) { // yg di drop VIP
            addAbility(&mob, 'r');
            printf("Ability Return To Sender berhasil diaktifkan.\n\n");
          }
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
        printf("1. MOVE -> Untuk berpindah ke lokasi selanjutnya\n");
        printf("2. PICK_UP -> Untuk mengambil item di lokasi sekarang\n");
        printf("3. DROP_OFF -> Untuk mengantar item ke lokasi sekarang\n");
        printf("4. MAP -> Untuk memunculkan peta\n");
        printf(
            "5. TO_DO -> Untuk menampilkan pesanan yang masuk ke To Do List\n");
        printf("6. IN_PROGRESS -> Untuk menampilkan pesanan yang sedang "
               "dikerjakan\n");
        printf("7. BUY -> Untuk menampilkan gadget yang dapat dibeli lalu "
               "membelinya. Hanya dapat digunakan di Headquarter\n");
        printf("8. INVENTORY -> Untuk melihat gadget yang dimiliki dan "
               "menggunakannya\n");
        printf(
            "9. RETURN -> Untuk menggunakan ability return to sender (setelah "
            "mengirimkan VIP item)\n");
        printf(
            "10. HELP -> Untuk mengeluarkan list command dan kegunaannya\n\n");
      } else if (validateWord(tempWord, "RETURN")) {
        mobitaReturn(mob, &tas, &todo, &ip);
        if (returnToSender(mob) == 1) {
          checkEffectSenter(&tas, &mob);
        }
        if (speedBoost(mob) == 0) {
          changeSpeed(&mob, (1 + numOfHeavy(tas)));
        }
      } else {
        printf("Masukkan Tidak Valid.\nGunakan command \"HELP\" untuk petunjuk "
               "penggunaan.\n");
      }
    }
  }
  printf("\nOTSUKARE!!!\n");
  printf("SELAMAT, ANDA TELAH MENYELESAIKAN PERMAINAN INI!!\n");
  printf("WAKTU YANG ANDA HABISKAN: %d\n", waktu);
  printf("PESANAN YANG BERHASIL ANDA KIRIMKAN: %d dari %d\n", finishedOrder,
         finishedOrder + Expired);
  return 0;
}