#include "lab.h"
#include "stdlib.h"


unsigned int invert_every_nth(unsigned int N, unsigned int bit) {
  if (bit == 0 || bit > 32) {
    printf("Error");
    exit(1);
  }
  
  unsigned int mask = 1 << (bit - 1);
  while (mask > 0) {
    N = (N ^ mask); 
    if ((int) mask < 0) break;
    mask = mask << bit;
  }
  return N;
}

unsigned int get_invert_offset(unsigned int a, unsigned int b) {
  unsigned int diff = a ^ b;
  for (int i = 0; i < 32; i++)
    if ((diff >> i) & 1) return i + 1; 
  return 0;
}

void print_bin(unsigned int N) {
  for (int i = 31; i > -1; i--)
    printf("%d", (N >> i) & 1);
}