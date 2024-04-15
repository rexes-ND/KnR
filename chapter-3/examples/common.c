#include <stdio.h>

int main() {
  int a[] = {1, 2, 3, 4};
  int b[] = {4, 8};

  int i, j;
  for (i = 0; i < 4; ++i) {
    for (j = 0; j < 2; ++j) {
      if (a[i] == b[j])
        goto found;
    }
  }

  printf("not found\n");
  return 0;

found:
  printf("found\n");
}
