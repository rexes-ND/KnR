#include <stdio.h>

int setbits(unsigned x, int p, int n, unsigned y);

int main() {
  printf("%d\n", setbits(45, 3, 3, 27));
  return 0;
}

int setbits(unsigned x, int p, int n, unsigned y) {
  x &= ~(~(~0 << n) << (p + 1 - n));
  y &= ~(~0 << n);
  y <<= (p + 1 - n);
  return x + y;
}
