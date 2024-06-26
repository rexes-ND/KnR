#include <stdio.h>

void str_cat(char *s, char *t);

int main() {
  char s[10] = "abc";
  char t[10] = "def";
  str_cat(s, t);
  printf("%s\n", s);

  return 0;
}

void str_cat(char *s, char *t) {
  while (*s != '\0')
    ++s;

  while ((*s = *t) != '\0') {
    ++s;
    ++t;
  }
}