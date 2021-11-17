#include "list_linked.h"

/* IMPLEMENTASI */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
  /* I.S. sembarang             */
  /* F.S. Terbentuk list kosong */
  // kamus lokal
  // algoritma
  FIRST(*l) = NULL;
}
/****************** TEST LIST KOSONG ******************/
boolean isListEmpty(List l) {
  /* Mengirim true jika list kosong */
  // kamus lokal
  // algoritma
  return FIRST(l) == NULL;
}
/****************** GETTER SETTER ******************/
Item getElmt(List l, int idx) {
  /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
  /* F.S. Mengembalikan nilai elemen l pada indeks idx */
  // kamus lokal
  int i;     // variabel untuk melakukan traversal pada list
  Address p; // address yang mengarah ke elemen di indeks idx
  // algoritma
  // karena indeks yang validnya 0..length(l),maka diasummsikan tidak kosong
  p = FIRST(l);
  i = 0;
  while (i < idx) {
    p = NEXT(p);
    i++;
  }
  // i=idx
  return INFO(p);
}
void setElmt(List *l, int idx, Item val) {
  /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
  /* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
  // kamus lokal
  int i;     // variabel untuk melakukan traversal pada list
  Address p; // address yang mengarah ke elemen di indeks idx
  // algoritma
  p = FIRST(*l);
  i = 0;
  while (i < idx) {
    p = NEXT(p);
    i++;
  }
  // i=idx
  INFO(p) = val;
}
int indexOf(List l, Item val) {
  /* I.S. l, val terdefinisi */
  /* F.S. Mencari apakah ada elemen list l yang bernilai val */
  /* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
  // Mengembalikan IDX_UNDEF jika tidak ditemukan
  // kamus lokal
  Address p;     // address yang mengarah ke elemen di indeks idx
  int idx;       // indeks yang dicari
  boolean found; // bernilai true jika val ada di list
  // algoritma
  idx = 0;
  p = FIRST(l);
  found = false;
  while (p != NULL && !found) {
    if ((p->info.type == val.type) && (p->info.value == val.value) &&
        (p->info.tPickup == val.tPickup) && (p->info.tPerish == val.tPerish) &&
        (p->info.tArrival == val.tArrival) &&
        (p->info.lPickup == val.lPickup) &&
        (p->info.lDropoff == val.lDropoff)) { // jika ketemu
      found = true;
    } else {
      p = NEXT(p);
      idx++;
    }
  }
  // val ketemu atau sudah sampai ujung
  if (!found) { // jika sudah sampai ujung gak ketemu
    idx = IDX_UNDEF;
  }
  return idx;
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, Item val) {
  /* I.S. l mungkin kosong */
  /* F.S. Melakukan alokasi sebuah elemen dan */
  /* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
  /* Jika alokasi gagal: I.S.= F.S. */
  // kamus lokal
  Address x; // node baru dengan info berisi val yang ingin ditambahkan
  // algoritma
  x = newNode(val);
  if (x != NULL) {          // jika alokasi sukses
    if (!isListEmpty(*l)) { // jika l tidak kosong
      NEXT(x) = FIRST(*l);
    }
    FIRST(*l) = x;
  }
}
void insertLast(List *l, Item val) {
  /* I.S. l mungkin kosong */
  /* F.S. Melakukan alokasi sebuah elemen dan */
  /* menambahkan elemen list di akhir: elemen terakhir yang baru */
  /* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
  // kamus lokal
  Address x; // node baru dengan info berisi val yang ingin ditambahkan
  Address p; // pointer untuk traversal
  // algoritma
  x = newNode(val);
  if (x != NULL) {         // jika alokasi sukses
    if (isListEmpty(*l)) { // jika l kosong
      FIRST(*l) = x;
    } else { // l tidak kosong
      p = FIRST(*l);
      while (NEXT(p) != NULL) { // selama belum sampe elemen terakhir
        p = NEXT(p);
      }
      NEXT(p) = x;
    }
  }
}
void insertPrio(List *l, Item val) {
  /* I.S. l mungkin kosong */
  /* F.S. Melakukan alokasi sebuah elemen dan */
  /* memasukkan elemen tersebut ke list dengan urutannya dipengaruhi waktu
   * pesanan masuk,semakin kecil waktunya,semakin di "depan" elemen berada */
  /* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
  // kamus lokal
  Address x; // node baru dengan info berisi val yang ingin ditambahkan
  Address p; // pointer untuk traversal
  // algoritma
  x = newNode(val);
  if (x != NULL) {         // jika alokasi sukses
    if (isListEmpty(*l)) { // jika l kosong
      FIRST(*l) = x;
    } else { // l tidak kosong
      p = FIRST(*l);
      while (NEXT(p) != NULL &&
             (x->info.tArrival >
              p->info.tArrival)) { // selama belum sampe elemen terakhir dan ada
                                   // yg waktu datangnya lebih kecil atau sama
                                   // dengan si val
        p = NEXT(p);
      }
      // udah sampai di alamat terakhir atau elemen sesudahnya lebih besar waktu
      // tibanya
      // jika di elemen terakhir
      if (NEXT(p) == NULL) {
        NEXT(p) = x;
      } else if (val.tArrival > p->info.tArrival) {
        NEXT(x) = NEXT(p);
        NEXT(p) = NEXT(x);
      }
    }
  }
}
void insertAt(List *l, Item val, int idx) {
  /* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu
   * 0..length(l) */
  /* F.S. Melakukan alokasi sebuah elemen dan */
  /* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di
   * i) */
  /* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
  // kamus lokal
  Address x; // node baru dengan info berisi val yang ingin ditambahkan
  Address p; // pointer untuk traversal
  int i;     // variabel untuk kounter
  // algoritma
  if (idx == 0) { // jika ingin dumasukkan ke elemen pertama
    insertFirst(l, val);
  } else { // ingin dimasukkan ke selain elemen pertama
    x = newNode(val);
    if (x != NULL) { // jika alokasi sukses
      p = FIRST(*l);
      i = 0;
      while (i < idx - 1) { // selama belum sampe indeks yang dituju
        p = NEXT(p);
        i++;
      }
      NEXT(x) = NEXT(p);
      NEXT(p) = x;
    }
  }
}
/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, Item *val) {
  /* I.S. List l tidak kosong  */
  /* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
  /*      dan alamat elemen pertama di-dealokasi */
  // kamus lokal
  Address x; // alamat untuk menyimpan elemen pertama
  // algoritma
  *val = INFO(FIRST(*l));
  x = FIRST(*l);
  FIRST(*l) = NEXT(FIRST(*l));
  free(x);
}
void deleteLast(List *l, Item *val) {
  /* I.S. list tidak kosong */
  /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
  /*      dan alamat elemen terakhir di-dealokasi */
  // kamus lokal
  Address x; // pointer untuk traversal
  Address p; // alamat untuk menyimpan elemen yg ingin dihapus
  // algoritma
  x = FIRST(*l);
  if (NEXT(x) == NULL) { // jika cuma 1 elemen
    *val = INFO(x);
    p = x;
    FIRST(*l) = NULL;
    free(p);
  } else { // lebih dari 1 elemen
    while (NEXT(NEXT(x)) != NULL) {
      x = NEXT(x);
    }
    *val = INFO(NEXT(x));
    p = NEXT(x);
    NEXT(x) = NULL;
    free(p);
  }
}
void deleteAt(List *l, int idx, Item *val) {
  /* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l)
   */
  /* F.S. val diset dengan elemen l pada indeks ke-idx. */
  /*      Elemen l pada indeks ke-idx dihapus dari l */
  // kamus lokal
  Address x; // pointer untuk traversal
  Address p; // alamat untuk menyimpan elemen yg ingin dihapus
  int i;     // variabel untuk kounter
  // algoritma
  if (idx == 0) { // jika yang dihapus elemen pertama
    deleteFirst(l, val);
  } else if (idx == lengthList(*l) - 1) { // jika yang dihapus elemen terakhir
    deleteLast(l, val);
  } else { // jika yang dihapus diantara elemen pertama dan terakhir
    x = FIRST(*l);
    i = 0;
    while (i < idx - 1) {
      x = NEXT(x);
      i++;
    }
    *val = INFO(NEXT(x));
    p = NEXT(x);
    NEXT(x) = NEXT(NEXT(x));
    free(p);
  }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
/*void displayList(List l){*/
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
// kamus lokal
/*   Address x;//pointer untuk traversal
   //algoritma
   if(isEmpty(l)){//jika list kosong
       printf("[]");
   }
   else{//list tidak kosong
       printf("[");
       x = FIRST(l);
       while(NEXT(x)!=NULL){//selama bukan elemen terakhir
           printf("%d,",INFO(x));
           x = NEXT(x);
       }
       //mencetak elemen terakhir
       printf("%d]",INFO(x));
   }
}*/
int lengthList(List l) {
  /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
  // kamus lokal
  int ctr;   // counter untuk mnghitung banyaknya elemen list
  Address x; // pointer untuk traversal
  // algoritma
  ctr = 0;
  x = FIRST(l);
  while (x != NULL) { // selama elemen di list masih ada
    ctr++;
    x = NEXT(x);
  }
  return ctr;
}