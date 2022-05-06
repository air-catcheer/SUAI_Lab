// Написать генератор псевдослучайных чисел,
// равномерно распределенных на интервале [-1.5, 2] (использовать rand()).
// Подсчитать частоты попадания в каждый из интервалов длиной 0.1 при выборке 500000
// + !вероятность попадания в каждый массив! 

#include <stdio.h>
#include "frand.h"

#define N 500000
#define POWER 12
#define INTERVALS 35

int main() {
  rand_init();
  int a[INTERVALS + 1] = {0};
  for (int i = 0; i < N; i++)
   {
    double s = frand(3.5, POWER);
    a[(int)(s * 10)] += 1;
  }

  for (int i = 0; i < INTERVALS; i++)
   {
      double z = (double)a[i] / N;
      printf("a[%d] = %d %f\n", i, a[i], z);
   }
}