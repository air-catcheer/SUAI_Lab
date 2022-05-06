#include <stdlib.h>
#include <time.h>

#include "frand.h"

void rand_init() {
  srand(time(NULL));
}

// применяем центральную предельную теорему
// (нахождение среднего арифметического нескольких случайных чисел)

double frand(double n, int count) {
  double sum = 0;
  // находим среднее арифметическое
  for (int i = 0; i < count; i++)
    sum += rand_1 * n;  // n - верхняя граница диапазона,
  // в котором генерируются случайные числа [0..n]

  return sum / count;
}
