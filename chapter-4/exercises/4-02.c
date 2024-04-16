#include <ctype.h>
#include <stdio.h>

double a_to_f(char s[]);

int main() {
  char s[] = "123.45e-6";
  printf("%f\n", a_to_f(s));

  return 0;
}

double a_to_f(char s[]) {
  double val, power;
  int i, sign, e, esign;

  for (i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  if (s[i] == 'e')
    i++;
  esign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (e = 0; isdigit(s[i]); i++) {
    e = 10 * e + (s[i] - '0');
  }
  for (int j = 0; j < e; ++j) {
    if (esign)
      power *= 10;
    else
      power /= 10;
  }

  return sign * val / power;
}
