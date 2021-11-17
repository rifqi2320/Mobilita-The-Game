#include "../src/io.h"

int main() {
  Word a = nextInput();
  printf(a.contents);
  printf("\n%d\n", a.length);
  printf(validateWord(a, "lmao") ? "Input benar\n" : "Input salah\n");
  return 0;
}