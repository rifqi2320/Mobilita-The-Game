#include <stdio.h>
#include <stdlib.h>
#include "listdinpos.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListBuilding(ListDin *l, int capacity) {
    BUFFER(*l) = (int*)malloc(capacity*sizeof(ElType));
    CAPACITY(*l) = capacity;
    for (int i=0; i<capacity; i++) {
        ELMT(*l, i) = VAL_UNDEF;
    }
};
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list l kosong dengan kapasitas capacity + 1 */
/* Proses: Inisialisasi semua elemen list l dengan VAL_UNDEF */

void dealocate(ListDin *l) {
    free(l);
    CAPACITY(*l) = 0;
};
/* I.S. l terdefinisi; */
/* F.S. TI(l) dikembalikan ke system, CAPACITY(l)=0; nEff(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l) {
    int i=0,len=0;
    while (ELMT(l, i)!=VAL_UNDEF && i<CAPACITY(l)) {
        len++;
        i++;
    }
    return len;
};
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */