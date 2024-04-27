#include <stdio.h>

int main(int argc, char *argv[]) {
  // v1
  //   int i;

  //   for (i = 1; i < argc; i++)
  //     printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
  //   printf("\n");

  //   return 0;

  // v2
  while (--argc > 0)
    printf("%s%s", *++argv, (argc > 1) ? " " : "");
  printf("\n");

  return 0;
}
