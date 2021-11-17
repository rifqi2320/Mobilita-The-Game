#include "io.h"
#include <stdio.h>

int main() {
  Map PT;
  int P;
  int n, m;
  char *s1;
  char *s2;
  Queue DP;
  int i, j;
  inputConfig("dummy.txt", &PT, &DP, &P);
  printf("%d %d\n", PT.width, PT.height);
  printf("%d %d\n", ELMTListB(LBMap(PT), 0).coordinate.X,
         ELMTListB(LBMap(PT), 0).coordinate.Y);
  for (i = 0; i < NBMap(PT); i++) {
    printf("%c %d %d\n", ELMTListB(LBMap(PT), i).name,
           ELMTListB(LBMap(PT), i).coordinate.X,
           ELMTListB(LBMap(PT), i).coordinate.Y);
  }
  for (i = 0; i < NBMap(PT); i++) {
    for (j = 0; j < NBMap(PT); j++) {
      printf("%d ", ELMTMap(PT, i, j));
    }
    printf("\n");
  }
  printf("%d %d\n", lengthQueue(DP), P);
  for (i = lengthQueue(DP) - 1; i >= 0; i--) {
    printf("%d %c %c %c\n", DP.buffer[i].tArrival, DP.buffer[i].lPickup,
           DP.buffer[i].lDropoff, DP.buffer[i].type);
  }
  printf("Ketikkan 'lmao': ");
  Word a = nextInput();
  printf(a.contents);
  printf("\n%d\n", a.length);
  printf(validateWord(a, "lmao") ? "Input benar\n" : "Input salah\n");
  printf("n = ");
  n = wordToInt(nextInput());
  printf("m = ");
  m = wordToInt(nextInput());
  printf("n + m = %d\n", n + m);
  printf("Masukan 1: ");
  s1 = wordToString(nextInput());
  printf("Masukan 2: ");
  s2 = wordToString(nextInput());
  printf(validateString(s1, s2) ? "Masukan 1 dan 2 sama\n"
                                : "Masukan 1 dan 2 beda\n");
  return 0;
}