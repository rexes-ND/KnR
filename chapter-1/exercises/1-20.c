#include <stdio.h>

#define TAB_WIDTH 4
#define MAXLINE 1000

int get_line(char line[], int maxline);

int main() {
  int len;

  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    int space = TAB_WIDTH;
    for (int i = 0; i < len; ++i) {
      if (line[i] == '\t') {
        for (int j = 0; j < space; ++j) {
          putchar(' ');
        }
        space = TAB_WIDTH;
      } else {
        putchar(line[i]);
        --space;
        if (space == 0)
          space = TAB_WIDTH;
      }
    }
  }

  return 0;
}

int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}
