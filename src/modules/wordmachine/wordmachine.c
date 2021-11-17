#include "wordmachine.h"

boolean endWord;
Word currentWord;

void ignoreBlank() {
  while (currentChar == BLANK || currentChar == LINEMARK) {
    adv();
  }
}

void startWord() {
  start();
  ignoreBlank();
  advWord();
}

void advWord() {
  ignoreBlank();
  if (currentChar == BLANK || currentChar == LINEMARK) {
    endWord = true;
  } else {
    copyWord();
  }
}

void copyWord() {
  int i = 0;
  while ((currentChar != LINEMARK) && (currentChar != BLANK)) {
    if (i < CAPACITY) {
      currentWord.contents[i] = currentChar;
      i++;
    }
    adv();
  }
  currentWord.length = i;
}