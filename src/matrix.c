#include "matrix.h"

void CreateMatrix(int nRow, int nCol, Matrix *m) {
  ROWS(*m) = nRow;
  COLS(*m) = nCol;
}