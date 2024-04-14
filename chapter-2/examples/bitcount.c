#include <stdio.h>

int bitcount(unsigned x);

int main() {
  printf("%d\n", bitcount(11));
  return 0;
}

int bitcount(unsigned x) {
  int b;

  for (b = 0; x != 0; x >>= 1)
    if (x & 01)
      b++;

  return b;
}
