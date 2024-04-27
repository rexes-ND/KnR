#include <stdio.h>

void str_cpy(char *s, char *t);

int main() {
  char s[10] = "world";
  char t[10] = "hello";
  str_cpy(s, t);
  printf("%s\n", s);
  return 0;
}

void str_cpy(char *s, char *t) {
  // v1
  //   int i;
  //   i = 0;
  //   while ((s[i] = t[i]) != '\0')
  //     i++;

  // v2
  //   while ((*s = *t) != '\0') {
  //     s++;
  //     t++;
  //   }

  // v3
  while ((*s++ = *t++))
    ;
}
