#include <stdio.h>

#define paste(front, back) front##back

int main() {
  int name1 = 5;
  printf("%d\n", paste(name, 1));

  return 0;
}
