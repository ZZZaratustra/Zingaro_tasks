#include "cco07p2.h"

int identify_vals(int vals[], int n)
{
  int i, j;
  for (i = 0; i < n; i++)
    for (j = i+1; j < n; j++)
      if (vals[i] == vals[j]) return 1;
  return 0;
}

