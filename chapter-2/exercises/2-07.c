#include <stdio.h>

int invert(unsigned x, int p, int n);

int main() {
  printf("%d\n", invert(45, 4, 4));
  return 0;
}

int invert(unsigned x, int p, int n) { return x ^ ~(~0 << n) << (p + 1 - n); }
