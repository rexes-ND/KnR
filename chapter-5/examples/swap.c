#include <stdio.h>

void swap(int *px, int *py);

int main() {
  int x, y;
  x = 1;
  y = 2;
  swap(&x, &y);
  printf("%d %d\n", x, y);

  return 0;
}

void swap(int *px, int *py) {
  int temp;

  temp = *px;
  *px = *py;
  *py = temp;
}
