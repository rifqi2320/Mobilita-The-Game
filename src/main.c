#include "building.h"
#include "inventory.h"
#include "io.h"
#include "item.h"
#include "list_linked.h"
#include "listbuilding.h"
#include <stdio.h>

void displayHelp();

int main() {
  boolean started = false;
  printf("====MOBILITA====\n");
  // start screen

  // Temp Variable
  int tempInt;
  char tempChar;
  char *tempString;
  Word tempWord;

  // Object atau ADT
  Queue DP;          // Daftar Pesanan
  Map PT;            // Map
  MOBITA mob;        // Mobita
  Tas tas;           // Tas berisi Item
  LIST_GADGET inv;   // Inventory berisi Gadget
  Todolist todo;     // TodoList
  InprogressList ip; // In Progress List

  while (!started) {
    // Ngeoutput menu
    tempInt = wordToInt(nextInput());
    if (tempInt == 1) {
      tempWord = nextInput();

      // Inisialisasi seluruh object dan adt
      inputMain(tempWord, &PT, &DP); // Berdasarkan config
      CreateMobita(&mob);
      CreateTas(&tas);
      MakeListGadget(&inv);
      CreateTodoList(&todo);
      CreateInProgress(&ip);

      started = true;
    } else if (tempInt == 2) {
      return 0;
    } else {
      printf("Output tidak valid.\n");
    }
  }

  // Game Started
  while (started) {
    // Print situasi mobita
    printf("ENTER COMMAND: ");
    tempWord = nextInput();
    if (validateWord(tempWord, "MOVE")) {
      printf("MOVE\n");
    } else if (validateWord(tempWord, "PICK_UP")) {
      printf("PICK_UP\n");
    } else if (validateWord(tempWord, "DROP_OFF")) {
      printf("DROP_OFF\n");
    } else if (validateWord(tempWord, "MAP")) {
      printf("MAP\n");
    } else if (validateWord(tempWord, "TO_DO")) {
      printf("TO_DO\n");
    } else if (validateWord(tempWord, "IN_PROGRESS")) {
      printf("IN_PROGRESS\n");
    } else if (validateWord(tempWord, "BUY")) {
      printf("BUY\n");
    } else if (validateWord(tempWord, "INVENTORY")) {
      printf("INVENTORY\n");
    } else if (validateWord(tempWord, "HELP")) {
      displayHelp();
    } else {
      printf("Masukkan Tidak Valid.\n");
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