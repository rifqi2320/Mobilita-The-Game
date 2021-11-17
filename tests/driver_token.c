#include "../src/tokenmachine.h"
#include <stdio.h>

int main() {
  startToken("dummy.txt");
  if (endToken) {
    printf("Ekspresi kosong\n");
    return 0;
  }

  if (currentToken.tkn == 'b') {
    printf("%d ", currentToken.val);
  } else {
    printf("%c ", currentToken.tkn);
  }

  while (!endToken) {
    if (currentToken.tkn == 'b') {
      printf("%d ", currentToken.val);
    } else {
      printf("%c ", currentToken.tkn);
    }
    advToken();
  }

  return 0;
}