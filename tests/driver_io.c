#include "../src/io.c"

int main() {
  inputMain("dummy.txt");
  Word a = nextInput();
  printf(a.contents);
  printf("\n%d\n", a.length);
  printf(validateWord(a, "lmao") ? "Input benar\n" : "Input salah\n");
}