#include <stdio.h>
#include <string.h>

enum boolean { NO, YES };

int str_len(char s[]);

int main() {
  printf("%d %d\n", NO, YES);
  printf("%d\n", str_len("hello, "
                         "world!"));
  printf("%lu\n", strlen("hello, "
                         "world!"));

  return 0;
}

int str_len(char s[]) {
  int i;

  while (s[i] != '\0')
    ++i;

  return i;
}
