#include "../src/charmachine.c"
#include "../src/tokenmachine.c"
#include <stdio.h>

int main() {
  startToken("dummy.txt");
  while (!endToken) {
    advToken();
    printf("%c", currentToken.tkn);
  }
  return 0;
}