#include <stdio.h>
#include <stdlib.h>
#include "lab7v12.h"

#define N 50
#define POWER 12
#define NUMBERS 35

int main() {
  rand_init();
  int a[NUMBERS] = {0};
  for (int i = 0; i < N; i++) {
    double s = frand(3.5, POWER) - 1.5;
    printf("%d\n", int(s * 10));
  }
}