#include "cco07p2.h"
#include "type.h"
#include <stdio.h>

int identify_vals(int vals[], int n) {
  int i, j;
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++)
      if (vals[i] == vals[j]) {
        puts("val BAD");
        return 1;
      }
  puts("val OK");
  return 0;
}

int identify_right(int snow1[], int snow2[], int pos) {
  for (int i = 0; i < 6; i++) {
    int overflow = (i + pos) % 6;
    if (snow1[i] != snow2[overflow]) {
      printf("R: snow1[%d] != snow2[%d]\n", i, overflow);
      return 0;
    }
  }
  puts("r snow1 == snow2");
  return 1;
}

int identify_left(int snow1[], int snow2[], int pos) {
  /* for (int i = 5; i >= 0; i--) { */
  for (int i = 0; i < 6; i++) {
    int overflow = pos - i;
    if (overflow < 0)
      overflow += 6;
    if (snow1[i] != snow2[overflow]) {
      printf("L: snow1[%d] != snow2[%d]\n", i, overflow);
      return 0;
    }
  }
  puts("l snow1 == snow2");
  return 1;
}

int are_identical(int snow1[], int snow2[]) {
  for (int i = 0; i < 6; i++) {
    if (identify_left(snow1, snow2, i))
      return 1;
    if (identify_right(snow1, snow2, i))
      return 1;
  }
  return 0;
}

/* void identify_identical(int snowflakes[][6], int n) { */
int solve_snowflakes(int snowflakes[][6], int n) {
  for (int i = 0; i < n; i++)
    if (identify_vals(snowflakes[i], 6))
      return 0;

  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (are_identical(snowflakes[i], snowflakes[j])) {
        puts("Twin found");
        return 1;
      }
  puts("No two snowflakes");
  return 0;
}

int test_main() {
  int snowflakes[2][6] = {{0, 1, 2, 3, 4, 5}, {4, 5, 0, 1, 2, 3}};
  int _snowflakes[2][6] = {{4, 5, 0, 1, 2, 3}, {5, 4, 3, 2, 1, 0}};
  solve_snowflakes(_snowflakes, 2);
  return 0;
}
