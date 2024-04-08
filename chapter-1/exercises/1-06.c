#include <stdio.h>

int main() {
  printf("%d\n", (getchar() != EOF)); // CTRL-D
  printf("%d\n", (getchar() != EOF)); // Any

  return 0;
}
