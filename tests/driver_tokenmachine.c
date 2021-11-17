#include "../src/tokenmachine.h"
#include <stdio.h>

int main() {
  startToken("dummy.txt");
  while (!endToken) {
    advToken();
    printf("%c", currentToken.tkn);
  }
  return 0;
}