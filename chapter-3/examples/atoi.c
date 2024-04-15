#include <ctype.h>
#include <stdio.h>

int a_to_i(char s[]);

int main() {
  printf("%d\n", a_to_i("1234"));
  return 0;
}

int a_to_i(char s[]) {
  int i, n, sign;

  for (i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (n = 0; isdigit(s[i]); i++)
    n = 10 * n + (s[i] - '0');

  return sign * n;
}
