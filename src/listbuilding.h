#ifndef LISTBUILDING
#define LISTBUILDING

#include "boolean.h"
#include "building.h"

/*  Kamus Umum */
// #define IDX_UNDEF -1 <- gaperlu karena nanti di deklarasi di global
/* Indeks tak terdefinisi*/
// #define VAL_UNDEF -999
/* Nilai elemen tak terdefinisi*/

#define BUILDING_CAP 27

/* Definisi elemen dan koleksi objek */
typedef int IdxType; /* type indeks */
typedef struct {
  Building *buffer; /* memori tempat penyimpan elemen (container) */
  int capacity;     /* ukuran elemen */
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
                                             dan l.buffer[nEff-1] != VAL_UNDEF
*/

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

Building searchCoord(ListBuilding l, int X, int Y);
/* Mengirimkan building yang mempunyai posisi (X,Y) */
/* Jika tidak ditemukan akan mengeluarkan MARKBuilding */

/* ********** OPERATOR  ********** */
void appendBuilding(ListBuilding *l, Building B);
/* I.s. l dan B terdefinisi */
/* F.S. Building akan dimasukkan ke dalam list building */

void copyListBuilding(ListBuilding lIn, ListBuilding *lOut);
/* I.S. lIn terdefinisi */
/* F.S. terbentuk list baru lOut yang sama persis dengan lIn */

void growListBuilding(ListBuilding *l, int num);
/* I.S. l terdefinisi */
/* F.S. realokasi list input yang lebih besar */
/*      kapasitasnya sebesar CAPACITY(*l) + num*/

void shrinkListBuilding(ListBuilding *l, int num);
/* I.S. l terdefinisi num > capacity *l */
/* F.S. */

#endif