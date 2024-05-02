#include <stdio.h>

int main() {
  char line[10];
  fgets(line, 10, stdin);
  printf("%s", line);

  return 0;
}