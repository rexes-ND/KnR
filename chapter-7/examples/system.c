#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("before system(date)\n");
  system("date");
  printf("after system(date)\n");

  return 0;
}
