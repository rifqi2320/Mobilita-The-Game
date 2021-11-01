#ifndef LISTDINPOS_H
#define LISTDINPOS_H

#include "boolean.h"
#include "building.h"

/*  Kamus Umum */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define VAL_UNDEF -999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType; /* type indeks */
typedef struct
{
  Building *buffer; /* memori tempat penyimpan elemen (container) */
  int capacity;  /* ukuran elemen */
} ListBuilding;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  List kosong: semua elemen bernilai VAL_UNDEF
  Definisi elemen pertama : l.buffer[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i terbesar
                                             sehingga l.buffer[i] != VAL_UNDEF
  Definisi nEff: jumlah elemen efektif, di mana l.buffer[nEff] == VAL_UNDEF
                                             dan l.buffer[nEff-1] != VAL_UNDEF */

/* ********** SELEKTOR ********** */
#define BUFFERListB(l) (l).buffer
#define ELMTListB(l, i) (l).buffer[i]
#define CAPACITYListB(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListBuilding(ListBuilding *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list l kosong dengan kapasitas capacity + 1 */
/* Proses: Inisialisasi semua elemen list l dengan VAL_UNDEF */

void dealocateListBuilding(ListBuilding *l);
/* I.S. l terdefinisi; */
/* F.S. TI(l) dikembalikan ke system, CAPACITY(l)=0; nEff(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthListBuilding(ListBuilding l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

#endif