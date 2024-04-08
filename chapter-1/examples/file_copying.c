#include <stdio.h>

// v1
int main() {
  int c;

  //   c = getchar(); // Assignment can appear part of a larger expression.
  while ((c = getchar()) != EOF) {
    putchar(c);
  }

  return 0;
}
