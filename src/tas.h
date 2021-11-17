#ifndef TAS_H
#define TAS_H

#include "boolean.h"
#include "constant.h"
#include "item.h"


#define MAXCAPACITY 100

typedef struct {
  Item buffer[MAXCAPACITY]; /* tabel penyimpan elemen */
  int idxTop;               /* alamat TOP: elemen puncak */
  int capacity;
} Tas;

/* ********* AKSES (Selektor) ********* */
/* Jika t adalah Tas, maka akses elemen : */
#define IDX_TOP(t) (t).idxTop
#define TOP(t) (t).buffer[(t).idxTop]

/* *** Konstruktor/Kreator *** */
void CreateTas(Tas *t);
/* I.S. sembarang; */
/* F.S. Membuat sebuah Tas t kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* - capacity tas bernilai 3 */
/* Proses : Melakukan alokasi, membuat sebuah t kosong */

/* ************ Prototype ************ */
boolean isTasEmpty(Tas t);
/* Mengirim true jika t kosong: lihat definisi di atas */
boolean isTasFull(Tas t);
/* Mengirim true jika tabel penampung nilai t Tas penuh */

/* ************ Menambahkan sebuah elemen ke Tas ************ */
void push(Tas *t, Item val);
/* Menambahkan val sebagai elemen Tas t */
/* I.S. t mungkin kosong, tabel penampung elemen Tas TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Tas ************ */
void pop(Tas *t, Item *val);
/* Menghapus val dari Tas t */
/* I.S. t tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */

void deleteTasAt(Tas *t, int i);
/* I.S. t terdefinisi dan i > 0 <= IDX_TOP(t) */
/* F.S. item dengan index ke-i di tas dihapus */

void increaseCapacity(Tas *t);
/* Meningkatkan kapasitas dari tas */
/* I.S. t terdefinisi dan capacity != MAXCAPACITY */
/* F.S. capacity tas t meningkat 1 */

int numOfHeavy(Tas t);
/* Mengembalikan jumlah item heavy di tas */

boolean isVIPinTop(Tas t);
/* Menghasilkan true jika item teratasnya ialah item vip*/
#endif
