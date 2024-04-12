#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
void reverse(char s[], int len);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    reverse(line, len);
    printf("%s", line);
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

void reverse(char s[], int len) {
  int i, temp;
  i = 0;

  if (s[len - 1] == '\n') {
    --len;
  }
  --len;

  while (i < len) {
    int temp = s[i];
    s[i] = s[len];
    s[len] = temp;
    ++i;
    --len;
  }
}