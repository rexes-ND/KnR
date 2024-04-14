#include <stdio.h>

int h_to_i(char s[]);

int main() {
  printf("%d\n", h_to_i("0xFF"));

  return 0;
}

int h_to_i(char s[]) {
  int res = 0;
  int i = 0;

  // Check 0x or 0X
  if (s[0] != '\0' && s[1] != '\0') {
    if (s[0] == '0' && (s[1] == 'x' || s[2] == 'X')) {
      i = 2;
    }
  }

  while ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') ||
         (s[i] >= 'A' && s[i] <= 'F')) {
    res *= 16;
    if (s[i] >= '0' && s[i] <= '9')
      res += (s[i] - '0');
    else if (s[i] >= 'a' && s[i] <= 'z')
      res += (s[i] - 'a' + 10);
    else
      res += (s[i] - 'A' + 10);
    ++i;
  }

  return res;
}