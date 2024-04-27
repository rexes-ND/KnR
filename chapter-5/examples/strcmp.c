#include <stdio.h>

int str_cmp(char *s, char *t);

int main() {
  printf("%d\n", str_cmp("hello", "hello"));

  return 0;
}

int str_cmp(char *s, char *t) {
  // v1
  //   int i;

  //   for (i = 0; s[i] == t[i]; i++)
  //     if (s[i] == '\0')
  //       return 0;

  //   return s[i] - t[i];

  // v2
  for (; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}
