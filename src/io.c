#include "io.h"
#include <stdio.h>

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

char *wordToString(Word w) {
  char *buffer;
  int i;
  for (i = 0; i < w.length; i++) {
    buffer[i] = w.contents[i];
  }
  buffer[w.length] = 0;
  return buffer;
}

int wordToInt(Word w) {
  int res = 0;
  int i;
  for (i = 0; i < w.length; i++) {
    res *= 10;
    res += w.contents[i] - '0';
  }
  return res;
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

void inputMain(Word dir, Map *PT, Queue *DP) {
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

  // Building sementara
  Building tempB;

  startToken(wordToString(dir));

  // Input Ukuran Matriks
  N = nextToken().val;
  M = nextToken().val;

  // Input lokasi HQ
  CreateBuilding(&tempB, nextToken().val, nextToken().val, '8');

  // Input jumlah bangunan
  L = nextToken().val;

  // Inisialisasi Map
  CreateMap(PT, N, M, L);
  addBuilding(PT, tempB, 0);

  // Input karakter dan lokasi bangunan
  for (i = 1; i <= L; i++) {
    char name = nextToken().tkn;
    CreateBuilding(&tempB, nextToken().val, nextToken().val, name);
    addBuilding(PT, tempB, i);
  }

  // Input adjacency matrix ke map
  for (i = 0; i <= L; i++) {
    for (j = 0; j <= L; j++) {
      ELMTMap(*PT, i, j) = nextToken().val;
    }
  }

  // Menginisialisasi List Item
  CreateQueue(DP);
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
    enqueue(DP, tempItem);
  }
};