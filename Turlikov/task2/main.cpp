#include "hamming.h"

int main() {
  unsigned char arr[2][6] = {0};

  for (unsigned char n = 1; n < 6; n++) {
    printf("\nerrors count: %d\n", n);
    for (unsigned char e = 0; e < 32; e++) {
      if (count_ones(e) == n) {
        unsigned char temp = 0;
        for (unsigned char m = 0; m < 4; m++) {
          temp += (m == decoder(channel(coder(m), e)));
          //? debug
          printf(" mess: "); printf_bin(m);
          printf(" code: "); printf_bin(coder(m));
          printf(" err: "); printf_bin(e);
          printf(" chann: "); printf_bin(channel(coder(m), e));
          printf(" dec: "); printf_bin(decoder(channel(coder(m), e)));
          if (m == decoder(channel(coder(m), e))) printf(" [WOW]");
          printf("\n");
          //? debug
        }
        arr[0][n - 1] += (temp == 4);
        arr[1][n - 1] += 1;
      }
    }
  }

  for (unsigned char N = 1; N < 6; N++)
    printf("%d error(s): fixed %d / %d\n", N, arr[0][N - 1], arr[1][N - 1]);
}

// 👀