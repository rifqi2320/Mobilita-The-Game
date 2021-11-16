#include "io.h"
#include <stdio.h>
#include <stdlib.h>

boolean validateString(char *a, char *b) {
  int i = 0;
  while (a[i] == b[i] && a[i] != '\x00' && b[i] != '\x00') {
    i++;
  }
  return (a[i] == '\x00' && b[i] == '\x00');
}

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
  char *buffer = (char *)malloc(sizeof(char) * w.length);
  int i;
  for (i = 0; i < w.length; i++) {
    buffer[i] = (char)w.contents[i];
  }
  buffer[w.length] = '\x00';
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

void inputConfig(char *dir, Map *PT, Queue *DP,int* jumlahPesanan) {
  int k = 0, j = 0, i, m, n;
  int N, M; // tempItemkuran Peta (10 <= N <= 20; 10 <= M <= 30)
  int L;    // Jumlah Gedung (4 <= L <= 26)
  int P;    // Jumlah Pesanan (5 <= P <= 30)

  // Variable Sementara
  int tempInt1;
  int tempInt2;

  // Item sementara
  char temptype;
  int temptArrival;
  int temptPerish;
  char templPickup;
  char templDropoff;
  Item tempItem;

  // Building sementara
  Building tempB;

  Token config[999];
  startToken(dir);
  while (!endToken) {
    advToken();
    config[k] = currentToken;
    k++;
  }
  N = config[j++].val;
  M = config[j++].val;

  // Membuat Headquarter
  tempInt1 = config[j++].val;
  tempInt2 = config[j++].val;
  CreateBuilding(&tempB, tempInt1, tempInt2, '8');

  // Input jumlah bangunan
  L = config[j++].val;

  // Inisialisasi Map
  CreateMap(PT, N, M, L);
  addBuilding(PT, tempB, 0);

  // Input karakter dan lokasi bangunan
  for (i = 1; i <= L; i++) {
    char name = config[j++].tkn;
    tempInt1 = config[j++].val;
    tempInt2 = config[j++].val;
    CreateBuilding(&tempB, tempInt1, tempInt2, name);
    addBuilding(PT, tempB, i);
  }

  // Input adjacency matrix ke map
  for (m = 0; m <= L; m++) {
    for (n = 0; n <= L; n++) {
      ELMTMap(*PT, m, n) = config[j++].val;
    }
  }

  // Menginisialisasi List Item
  CreateQueue(DP);
  // Input jumlah pesanan
  P = config[j++].val;
  *jumlahPesanan = P;
  // Input item pesanan
  for (i = 0; i < P; i++) {
    temptArrival = config[j++].val;
    templPickup = config[j++].tkn;
    templDropoff = config[j++].tkn;
    temptype = config[j++].tkn;
    if (temptype != 'P') {
      temptPerish = TIME_UNDEF;
    } else {
      temptPerish = config[j++].val;
    }
    CreateItem(&tempItem, temptype, temptArrival, temptPerish, templPickup,
               templDropoff);
    enqueue(DP, tempItem);
  }
}