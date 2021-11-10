#ifndef MAPBUILDING_H
#define MAPBUILDING_H

#define MAP_CAP 27
#include "constant.h"

typedef struct {
  int buffer[MAP_CAP];
} MB;

#define MAPELMT(MP, i) (MP).buffer[i]

void CreateMB(MB *mb);
/* I.S. mb bebas */
/* F.S. terbentuk mapbuilding mb kosong */

void setVal(MB *mb, char key, int val);
/* I.S. mb terdefinisi */
/* F.S. value dimasukkan ke dalam index berdasarkan key */

int getVal(MB mb, char key);
/* Mengembalikan nilai dari key di mapbuilding, mengembalikan IDX_UNDEF jika tidak ditemukan */

#endif