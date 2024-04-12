#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c, state, nc;
  int hist[10];

  for (int i = 0; i < 10; ++i)
    hist[i] = 0;

  nc = 0;
  state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) {
        if (nc >= 10) {
          ++hist[9];
        } else {
          ++hist[nc - 1];
        }
        nc = 0;
      }
      state = OUT;
    } else {
      state = IN;
      ++nc;
    }
  }

  if (nc > 0) {
    if (nc >= 10) {
      ++hist[9];
    } else {
      ++hist[nc - 1];
    }
  }

  for (int i = 0; i < 10; ++i) {
    printf("|");
    for (int j = 0; j < hist[i]; ++j) {
      printf("*|");
    }
    printf("\n");
  }

  return 0;
}
