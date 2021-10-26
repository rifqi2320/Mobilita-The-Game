#include "charmachine.h"
#include "item.h"
#include "matrix.h"
#include "point.h"
#include "tokenmachine.h"
#include <stdio.h>

char currentChar;
boolean endToken;
Token currentToken;

Token nextToken() {
  Token tempToken;
  if (!endToken) {
    tempToken = currentToken;
    advToken();
  }
  return Token;
}

void inputMain(char dir[] /*Masukkin output config*/) {
  int i, j, k; // Iterator
  int N, M;    // tempItemkuran Peta (10 <= N <= 20; 10 <= M <= 30)
  int L;       // Jumlah Gedung (4 <= L <= 26)
  int P;       // Jumlah Pesanan (5 <= P <= 30)

  // Item sementara
  char temptype;
  int temptArrival;
  char templPickup;
  char templDropoff;
  Item tempItem;

  Matrix m;
  startToken(dir);
  POINT tempListPoint[27]; // Nanti diganti pake list dynamic of point buat
                           // building
  Item tempListItem[30];   // Nanti diganti pake linked list of Item buat daftar
                           // pesanan

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
    tempListPoint[i] =
        MakePoint(nextToken().val, nextToken().val); // Ganti Setter
  })

  // Input adjacency matrix
  CreateMatrix(N, M, &m);
  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      ELMT(m, i, j) = nextToken().val;
    }
  }

  // Input jumlah pesanan
  P = nextToken().val;

  // Input item pesanan
  for (i = 0; i < P; i++) {
    temptArrival = nextToken().val;
    temptype = nextToken().tkn;
    templPickup = nextToken().tkn;
    templDropoff = nextToken().tkn;
    if (temptype != 'P') {
      temptPerish = TIME_UNDEF;
    } else {
      temptPerish = nextToken().val;
    }
    CreateItem(&tempItem, temptype, temptArrival, temptPerish, templPickup,
               templDropoff);
    tempListItem[i] = tempItem; // Ganti setter
  }
};