#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);

int main() {
  int len;

  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    int i = len - 1;
    if (line[i] == '\n')
      --i;
    while (i >= 0 && (line[i] == ' ' || line[i] == '\t'))
      --i;
    if (i >= 0) {
      if (line[len - 1] == '\n') {
        line[++i] = '\n';
      }
      line[i + 1] = '\0';
      printf("%s", line);
    }
  }

  return 0;
}

int get_line(char s[], int lim) {
  int c, i, nowhite;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
