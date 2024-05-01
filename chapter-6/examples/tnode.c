#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100

typedef int Length;
Length len, maxlen;
Length *lengths[1];

typedef char *String;
String p, lineptr[1000], alloc(int);
int str_cmp(String, String);

typedef struct tnode *Treeptr;

typedef struct tnode { /* the tree node */
  char *word;          /* points to the text */
  int count;           /* number of occurences */
  struct tnode *left;  /* left child */
  struct tnode *right; /* right child */
} Treenode;

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

int main() {
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      root = addtree(root, word);
  treeprint(root);

  return 0;
}

struct tnode *talloc(void);

/* addtree: add a note with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {
  int cond;

  if (p == NULL) {
    p = talloc();
    p->word = strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    p->count++;
  else if (cond < 0)
    p->left = addtree(p->left, w);
  else
    p->right = addtree(p->right, w);

  return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p) {
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
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

/* talloc: make a tnode */
// v1
// struct tnode *talloc(void) {
//   return (struct tnode *)malloc(sizeof(struct tnode));
// }

// v2
Treeptr talloc(void) { return (Treeptr)malloc(sizeof(Treenode)); }

/* strdup: make a duplicate of s */
// char *strdup(char *s) {
//   char *p;

//   p = (char *)malloc(strlen(s) + 1); /* +1 for '\0' */
//   if (p != NULL)
//     strcpy(p, s);

//   return p;
// }
