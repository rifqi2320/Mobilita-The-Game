#include "tokenmachine.h"
#include "charmachine.h"
#include <stdio.h>
#include <stdlib.h>

boolean endToken = false;
Token currentToken;

void copyToken() {
  /* Mengakuisisi Token dan menyimpan hasilnya dalam currentToken
      I.S. : currentChar adalah karakter pertama dari Token
      F.S. : currentToken berisi Token yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = TEXTMARK atau currentChar =
     LINEMARK; currentChar adalah karakter sesudah karakter terakhir yang
     diakuisisi.
  */
  currentToken.val = 0;
  // Proses currentChar selama karakter lalu maju sampai bukan karakter
  while ((currentChar != TEXTMARK) && (currentChar != BLANK) &&
         (currentChar != LINEMARK)) {
    // Asumsi setiap token angka atau huruf semua
    if ((currentChar < 'A') || (currentChar > 'Z')) {
      currentToken.val = currentToken.val * 10 + (currentChar - '0');
      currentToken.tkn = 'b';
    } else {
      currentToken.tkn = currentChar;
      currentToken.val = -1;
    }
    adv();
  }
}

void startToken(char *dir) {
  /* I.S. : currentChar sembarang
     F.S. : endToken = true, dan currentChar = MARK;
            atau endToken = false, currentToken adalah Token yang sudah
     diakuisisi, currentChar karakter pertama sesudah karakter terakhir Token */
  startWithPath(dir);
  ignoreBlank();
  if (currentChar == TEXTMARK) { // file kosong
    endToken = true;
  } else {
    endToken = false;
  }
}

void advToken() {
  /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
     F.S. : currentToken adalah Token terakhir yang sudah diakuisisi,
            currentChar adalah karakter pertama dari kata berikutnya, mungkin
     MARK Jika currentChar = MARK, maka endToken = true Proses : Akuisisi kata
     menggunakan procedure salinToken */
  ignoreBlank();
  copyToken();
  if (currentChar == TEXTMARK) {
    endToken = true;
  }
}
