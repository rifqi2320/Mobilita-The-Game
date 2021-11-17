#include "../src/wordmachine.h"
#include <stdio.h>

int main() {
  int i;
  startWord();
  int geser = currentWord.length;
  while (!endWord) {
    for (i = 0; i < currentWord.length; i++) {
      int valword = currentWord.contents[i];
      int val = (int)((valword + geser - 65) % 26 + 65);
      char huruf = val;
      printf("%c", huruf);
    }
    advWord();
    if (!endWord) {
      printf(" ");
    }
  }
  printf(".\n");
  return 0;
}