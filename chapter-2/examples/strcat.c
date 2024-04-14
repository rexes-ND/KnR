#include <stdio.h>
#define MAXLINE 1000
void str_cat(char s[], char t[]);

int main() {
  char s[MAXLINE] = "abc";
  char t[MAXLINE] = "def";
  str_cat(s, t);
  printf("%s\n", s);

  return 0;
}

void str_cat(char s[], char t[]) {
  int i, j;

  i = j = 0;
  while (s[i] != '\0')
    i++;
  while ((s[i++] = t[j++]) != '\0')
    ;
}
