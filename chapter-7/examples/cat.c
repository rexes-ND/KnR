#include <stdio.h>
#include <stdlib.h>

/* cat: concatenate files*/
int main(int argc, char *argv[]) {
  // v1
  // FILE *fp;
  // void filecopy(FILE *, FILE *);
  // if (argc == 1)
  //   filecopy(stdin, stdout);
  // else
  //   while (--argc > 0)
  //     if ((fp = fopen(*++argv, "r")) == NULL) {
  //       printf("cat: can't open %s\n", *argv);
  //       return 1;
  //     } else {
  //       filecopy(fp, stdout);
  //       fclose(fp);
  //     }

  // v2
  FILE *fp;
  void filecopy(FILE *, FILE *);
  char *prog = argv[0];

  if (argc == 1) /* no args; copy standard output */
    filecopy(stdin, stdout);
  else
    while (--argc > 0)
      if ((fp = fopen(*++argv, "r")) == NULL) {
        fprintf(stderr, "%s: can't open %s\n", prog, *argv);
        exit(1);
      } else {
        filecopy(fp, stdout);
        fclose(fp);
      }
  if (ferror(stdout)) {
    fprintf(stderr, "%s: error writing stdout\n", prog);
    exit(2);
  }

  exit(0);
}

/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp) {
  int c;

  while ((c = getc(ifp)) != EOF)
    putc(c, ofp);
}
