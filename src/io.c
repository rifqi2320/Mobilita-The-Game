#include "charmachine.h"
#include "item.h"
#include "matrix.h"
#include "point.h"
#include "tokenmachine.h"
#include "wordmachine.h"
#include <stdio.h>
#include "list_linked.h"

char currentChar;
boolean endToken;
Token currentToken;
Word currentWord;

boolean validateWord(Word w, char a[]) {
  boolean eq = true;
  int i = 0;
  while (eq && i < w.length) {
    if (w.contents[i] != a[i]) {
      eq = false;
    }
    i++;
  }
  return eq;
}

Word nextInput() {
  startWord();
  return currentWord;
}

Token nextToken() {
  Token tempToken;
  if (!endToken) {
    advToken();
    tempToken = currentToken;
  }
  return tempToken;
}

void inputMain(char dir[] /*Masukkin output config*/) {
  int i, j, k; // Iterator
  int N, M;    // tempItemkuran Peta (10 <= N <= 20; 10 <= M <= 30)
  int L;       // Jumlah Gedung (4 <= L <= 26)
  int P;       // Jumlah Pesanan (5 <= P <= 30)

  // Item sementara
  char temptype;
  int temptArrival;
  int temptPerish;
  char templPickup;
  char templDropoff;
  Item tempItem;

  Matrix m; // Nanti diganti pake Matrix dari argument biar jadi output

  POINT tempListPoint[27]; // Nanti diganti pake list dynamic of point buat
                           // building
                           /*
  Item tempListItem[30];   // Nanti diganti pake linked list of Item buat daftar
                           // pesanan
  */
  List tempListItem;       //list untuk menyimpan daftar pesanan


  startToken(dir);

  // Input Ukuran Matriks
  N = nextToken().val;
  M = nextToken().val;

  // Input lokasi HQ
  tempListPoint[0] = MakePOINT(nextToken().val, nextToken().val); // Ganti
                                                                  // setter

  // Input jumlah bangunan
  L = nextToken().val;

  // Input karakter dan lokasi bangunan
  for (i = 1; i <= L; i++) {
    nextToken().tkn;
    tempListPoint[i] =
        MakePOINT(nextToken().val, nextToken().val); // Ganti Setter
  }

  // Input adjacency matrix
  CreateMatrix(N, M, &m);
  for (i = 0; i <= L; i++) {
    for (j = 0; j <= L; j++) {
      ELMT(m, i, j) = nextToken().val;
    }
  }

  //Menginisialisasi List Item
  CreateList(&tempListItem);
  // Input jumlah pesanan
  P = nextToken().val;

  // Input item pesanan
  for (i = 0; i < P; i++) {
    temptArrival = nextToken().val;
    templPickup = nextToken().tkn;
    templDropoff = nextToken().tkn;
    temptype = nextToken().tkn;
    if (temptype != 'P') {
      temptPerish = TIME_UNDEF;
    } else {
      temptPerish = nextToken().val;
    }
    CreateItem(&tempItem, temptype, temptArrival, temptPerish, templPickup,
               templDropoff);
    insertFirst(&tempListItem,tempItem);
   // tempListItem[i] = tempItem; // Ganti setter
  }
};