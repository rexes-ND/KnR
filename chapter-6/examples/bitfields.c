#include <stdio.h>

struct {
  unsigned int is_keyword : 1;
  unsigned int is_extern : 1;
  unsigned int is_static : 1;
} flags;

int main() {
  printf("flags size: %lu\n", sizeof(flags));

  return 0;
}
