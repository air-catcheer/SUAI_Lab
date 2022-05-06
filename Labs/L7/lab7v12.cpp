#include <stdlib.h>
#include <time.h>

#include "lab7v12.h"

void rand_init() {
  srand(time(NULL));
}

double frand(double n, int count) {
  double sum = 0;
  // находим среднее арифметическое
  for (int i = 0; i < count; i++)
    sum += rand_1() * n;
  return sum / count;
}
