#include <stdio.h>

#define MAXLINE 1000

int main() {
  int i, c, stop;

  //   for (i = 0; i < MAXLINE - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
  //     ;

  i = 0;
  stop = 0;
  while (!stop) {
    if (i >= MAXLINE - 1)
      stop = 1;
    else {
      c = getchar();
      if (c == '\n') {
        stop = 1;
      } else if (c == EOF) {
        stop = 1;
      } else {
        ++i;
      }
    }
  }
  printf("%d\n", i);

  return 0;
}