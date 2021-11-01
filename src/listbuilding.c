#include <stdio.h>
#include <stdlib.h>
#include "listdinpos.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListBuilding(ListBuilding *l, int capacity) {
    BUFFERListB(*l) = (int*)malloc(capacity*sizeof(ElType));
    CAPACITYListB(*l) = capacity;
    for (int i=0; i<capacity; i++) {
        ELMTListB(*l, i) = VAL_UNDEF;
    }
};
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list l kosong dengan kapasitas capacity + 1 */
/* Proses: Inisialisasi semua elemen list l dengan VAL_UNDEF */

void dealocateListBuilding(ListBuilding *l) {
    free(l);
    CAPACITYListB(*l) = 0;
};
/* I.S. l terdefinisi; */
/* F.S. TI(l) dikembalikan ke system, CAPACITY(l)=0; nEff(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthListBuilding(ListBuilding l) {
    int i=0,len=0;
    while (ELMTListB(l, i)!=VAL_UNDEF && i<CAPACITYListB(l)) {
        len++;
        i++;
    }
    return len;
};
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */