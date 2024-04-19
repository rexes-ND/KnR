#include <stdio.h>

#define dprint(expr) printf(#expr " = %g\n", expr)

int main() {
  double d = 5;
  dprint(d);
  return 0;
}
