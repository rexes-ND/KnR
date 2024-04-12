#include <stdio.h>

int main() {
  int c, nwhite, nother;
  int ndigit[10];
  int nloweralpha[26];
  int nupperalpha[26];
  nwhite = nother = 0;
  for (int i = 0; i < 10; ++i)
    ndigit[i] = 0;
  for (int i = 0; i < 26; ++i) {
    nloweralpha[i] = 0;
    nupperalpha[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9')
      ++ndigit[c - '0'];
    else if (c >= 'a' && c <= 'z')
      ++nupperalpha[c - 'a'];
    else if (c >= 'A' && c <= 'Z')
      ++nloweralpha[c - 'A'];
    else if (c == ' ' || c == '\t' || c == '\n')
      ++nwhite;
    else
      ++nother;
  }

  printf("white space |");
  for (int j = 0; j < nwhite; ++j) {
    printf("*|");
  }
  printf("\n");
  printf("other       |");
  for (int j = 0; j < nother; ++j) {
    printf("*|");
  }
  printf("\n");
  for (int i = 0; i < 10; ++i) {
    printf("digit %d     |", i);
    for (int j = 0; j < ndigit[i]; ++j) {
      printf("*|");
    }
    printf("\n");
  }
  for (int i = 0; i < 26; ++i) {
    printf("alpha %c     |", 'a' + i);
    for (int j = 0; j < nloweralpha[i]; ++j) {
      printf("*|");
    }
    printf("\n");
  }
  for (int i = 0; i < 26; ++i) {
    printf("alpha %c     |", 'A' + i);
    for (int j = 0; j < nupperalpha[i]; ++j) {
      printf("*|");
    }
    printf("\n");
  }

  return 0;
}
