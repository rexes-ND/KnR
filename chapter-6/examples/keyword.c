#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXWORD 100

struct key {
  char *word;
  int count;
} keytab[] = {"auto",  0, "break",    0, "case",    0, "char",     0,
              "const", 0, "continue", 0, "default", 0, "unsigned", 0,
              "void",  0, "volatile", 0, "while",   0};

#define NKEYS (sizeof(keytab) / sizeof(struct key))

int getword(char *, int);
// v1
// int binsearch(char *, struct key *, int);

// v2
struct key *binsearch(char *, struct key *, int);

/* count C keywords */
int main() {
  char word[MAXWORD];
  struct key *p;

  // v1
  // while (getword(word, MAXWORD) != EOF)
  //   if (isalpha(word[0]))
  //     if ((n = binsearch(word, keytab, NKEYS)) >= 0)
  //       keytab[n].count++;
  // for (n = 0; n < NKEYS; n++)
  //   if (keytab[n].count > 0)
  //     printf("%4d %s\n", keytab[n].count, keytab[n].word);

  // v2
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      if ((p = binsearch(word, keytab, NKEYS)) != NULL)
        p->count++;
  for (p = keytab; p < keytab + NKEYS; p++)
    if (p->count > 0)
      printf("%4d %s\n", p->count, p->word);

  return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
// v1
// int binsearch(char *word, struct key tab[], int n) {
//   int cond;
//   int low, high, mid;

//   low = 0;
//   high = n - 1;
//   while (low <= high) {
//     mid = (low + high) / 2;
//     if ((cond = strcmp(word, tab[mid].word)) < 0)
//       high = mid - 1;
//     else if (cond > 0)
//       low = mid + 1;
//     else
//       return mid;
//   }

//   return -1;
// }

// v2
struct key *binsearch(char *word, struct key *tab, int n) {
  int cond;
  struct key *low = &tab[0];
  struct key *high = &tab[n];
  struct key *mid;

  while (low < high) {
    mid = low + (high - low) / 2;
    if ((cond = strcmp(word, mid->word)) < 0)
      high = mid;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return NULL;
}

int getch(void);
void ungetch(int);

/* getword: get next word or character from input */
int getword(char *word, int lim) {
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while (isspace(c = getch()))
    ;
  if (c != EOF)
    *w++ = c;
  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for (; --lim > 0; w++)
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many character\n");
  else
    buf[bufp++] = c;
}
