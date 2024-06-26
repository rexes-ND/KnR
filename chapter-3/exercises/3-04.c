#include <limits.h>
#include <stdio.h>
#include <string.h>

void itoa(long n, char s[]);
void reverse(char s[]);

int main() {
  char s[1000];
  int n = INT_MIN;
  itoa(n, s);
  printf("%s\n", s);

  return 0;
}

void itoa(long n, char s[]) {
  long i, sign;

  if ((sign = n) < 0)
    n = -n;
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
