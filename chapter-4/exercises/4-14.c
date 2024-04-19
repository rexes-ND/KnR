#include <stdio.h>

#define swap(t, x, y)                                                          \
  {                                                                            \
    t temp;                                                                    \
    temp = x;                                                                  \
    x = y;                                                                     \
    y = temp;                                                                  \
  }

int main() {
  int a, b;
  a = 3;
  b = 5;
  swap(int, a, b);
  printf("%d %d\n", a, b);

  return 0;
}
