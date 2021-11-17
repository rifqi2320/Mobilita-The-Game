#include "mapbuilding.h"

void CreateMB(MB *mb) {
  int i;
  MAPELMT(*mb, 0) = 0; // HQ diletakkan di index 0
  for (i = 1; i < MAP_CAP; i++) {
    MAPELMT(*mb, i) = IDX_UNDEF;
  }
}

void setVal(MB *mb, char key, int val) {
  int idx;
  if (key == '8') {
    idx = 0;
  } else {
    idx = (int)(key - 'A' + 1);
  }
  MAPELMT(*mb, idx) = val;
}

int getVal(MB mb, char key) {
  int idx;
  if (key == '8') {
    idx = 0;
  } else {
    idx = (int)(key - 'A' + 1);
  }
  return MAPELMT(mb, idx);
}