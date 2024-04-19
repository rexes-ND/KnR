#include <stdio.h>
#include <string.h>

void reverse(char s[], int i, int j);

int main() {
  char s[] = "hello";
  reverse(s, 0, strlen(s) - 1);
  printf("%s\n", s);
  return 0;
}

void reverse(char s[], int i, int j) {
  if (i < j) {
    char t = s[i];
    s[i] = s[j];
    s[j] = t;
    reverse(s, i + 1, j - 1);
  }
}
