#include "../src/point.h"
#include <stdio.h>


int main() {
  POINT P1, P2;
  int x, y;
  scanf("%d %d", &x, &y);
  P1 = MakePOINT(x, y);
  scanf("%d %d", &x, &y);
  P2 = MakePOINT(x, y);

  printf("Nilai kebenaran kedua point sama = %d\n", EQ(P1, P2));
  printf("Nilai kebenaran kedua point tidak sama = %d\n", NEQ(P1, P2));
  return 0;
}