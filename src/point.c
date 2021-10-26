#include "point.h"
#include <stdio.h>

POINT MakePOINT(int X, int Y) {
  POINT P;
  Absis(P) = X;
  Ordinat(P) = Y;
  return P;
};

boolean EQ(POINT P1, POINT P2) {
  return (Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2));
};

boolean NEQ(POINT P1, POINT P2) {
  return !((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
};