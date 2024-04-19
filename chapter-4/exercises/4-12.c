#include <stdio.h>

int itoa(int n, char s[], int sp);

int main() {
  char s[100];
  itoa(-12345, s, 0);
  printf("%s\n", s);
  return 0;
}

int itoa(int n, char s[], int sp) {
  if (n < 0) {
    s[sp] = '-';
    return itoa(-n, s, sp + 1);
  } else if (n < 10) {
    s[sp] = '0' + n;
    s[sp + 1] = '\0';
    return sp + 1;
  }
  sp = itoa(n / 10, s, sp);
  s[sp++] = '0' + n % 10;
  s[sp] = '\0';
  return sp;
}
