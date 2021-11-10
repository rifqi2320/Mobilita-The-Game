#include "io.h"
#include "item.h"
#include <stdio.h>

int main() {
  boolean started = false;
  printf("====MOBILITA====\n");
  // start screen
  int tempInt;
  char tempChar;
  char *tempString;
  Word tempWord;

  while (!started) {
    // Ngeoutput menu
    tempInt = wordToInt(nextInput());
    if (tempInt == 1) {
      tempWord = nextInput();
      inputMain(tempWord); // kayaknya inputnya map aja
    } else if (tempint == 2) {
      return 0;
    } else {
      printf("Output tidak valid.\n");
    }
  }

  // Game Started
  while (started) {
    printf("ENTER COMMAND: ");
    tempWord = nextInput();
    if (validateWord(tempWord, "MOVE")) {
      // MOVE
    } else if (validateWord(tempWord, "PICK_UP")) {

    } else if (validateWord(tempWord, "DROP_OFF")) {

    } else if (validateWord(tempWord, "MAP")) {

    } else if (validateWord(tempWord, "TO_DO")) {

    } else if (validateWord(tempWord, "IN_PROGRESS")) {

    } else if (validateWord(tempWord, "BUY")) {

    } else if (validateWord(tempWord, "INVENTORY")) {

    } else if (validateWord(tempWord, "HELP")) {

    } else {
      printf("Masukkan Tidak Valid.\n")
    }
  }

  printf("OTSUKARE!!!\n");
  printf("SELAMAT, ANDA TELAH MENYELESAIKAN PERMAINAN INI!!\n");
  return 0;
}