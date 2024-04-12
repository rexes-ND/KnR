#include <stdio.h>

#define TAB_WIDTH 4
#define MAXLINE 1000

int get_line(char line[], int maxline);

int main() {
  int len;

  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    int space = TAB_WIDTH;

    int sc = 0;

    for (int i = 0; i < len; ++i) {
      if (line[i] == ' ') {
        ++sc;
      } else {
        if (sc < space) {
          for (int j = 0; j < sc; ++j) {
            putchar(' ');
          }
          space -= sc;
          sc = 0;
        } else {
          // sc >= space
          if (space == 1) {
            putchar(' ');
            --sc;
          } else {
            putchar('\t');
            sc -= space;
          }
          space = TAB_WIDTH;
          while (sc >= TAB_WIDTH) {
            putchar('\t');
            sc -= TAB_WIDTH;
          }
          for (int j = 0; j < sc; ++j) {
            putchar(' ');
          }
          space -= sc;
          sc = 0;
        }
        if (line[i] == '\t') {
          space = TAB_WIDTH;
        } else {
          putchar(line[i]);
          --space;
          if (space == 0)
            space = TAB_WIDTH;
        }
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
