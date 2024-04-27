#include <stdio.h>

int str_len(char *s);

int main() {
  printf("%d\n", str_len("hello"));

  return 0;
}

int str_len(char *s) {
  // v1
  //   int n;

  //   for (n = 0; *s != '\0'; s++)
  //     n++;

  //   return n;

  // v2
  char *p = s;

  while (*p != '\0')
    p++;

  return p - s;
}
