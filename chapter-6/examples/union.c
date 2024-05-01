#include <stdio.h>

union u_tag {
  int ival;
  float fval;
  char *sval;
} u;

struct {
  char *name;
  int flags;
  int utype;
  union {
    int ival;
    float fval;
    char *sval;
  } u;
} symtab[100];

int main() {
  printf("float size: %lu\n", sizeof(float));
  printf("u_tag size: %lu\n", sizeof(union u_tag));
  printf("char* size: %lu\n", sizeof(char *));

  return 0;
}