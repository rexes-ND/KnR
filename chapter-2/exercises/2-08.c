#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main() {
  printf("%d\n", rightrot(45, 2));
  return 0;
}

unsigned rightrot(unsigned x, int n) {
  unsigned uppermost = 1;
  while (uppermost << 1)
    uppermost <<= 1;

  while (n--) {
    x = (x & 1) * uppermost + (x >> 1);
  }

  return x;
}