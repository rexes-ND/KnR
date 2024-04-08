#include <stdio.h>

// v1
// int main() {
//   long nc;

//   nc = 0;
//   while (getchar() != EOF)
//     ++nc;
//   printf("%ld\n", nc);

//   return 0;
// }

// v2
int main() {
  double nc;

  for (nc = 0; getchar() != EOF; ++nc)
    ;
  printf("%.0f\n", nc);
}
