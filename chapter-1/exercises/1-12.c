#include <stdio.h>

#define IN 1  /* inside of a word */
#define OUT 0 /* outside of a word */

int main() {
  int c, state;

  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        putchar('\n');
        state = OUT;
      }
    } else {
      state = IN;
      putchar(c);
    }
  }
  if (state == IN)
    putchar('\n');

  return 0;
}
