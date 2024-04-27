#include <stdio.h>

int strend(char *s, char *t);

int main() {
  {
    char s[10] = "abcdef";
    char t[10] = "def";
    printf("strend(abcdef, def): %d\n", strend(s, t));
  }
  {
    char s[10] = "abcef";
    char t[10] = "def";
    printf("strend(abcef, def): %d\n", strend(s, t));
  }

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

int strend(char *s, char *t) {
  while (*s != '\0') {
    if (str_cmp(s, t) == 0)
      return 1;
    ++s;
  }
  if (*s == *t)
    return 1;
  return 0;
}