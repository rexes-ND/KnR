#include <stdio.h>

int main() {
  int bl = 0;
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ')
      ++bl;
    else {
      if (bl > 0) {
        putchar(' ');
        bl = 0;
      }
      putchar(c);
    }
  }

  if (bl > 0)
    putchar(' ');

  return 0;
}
