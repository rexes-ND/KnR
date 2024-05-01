#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct nlist {        /* table entry */
  struct nlist *next; /* next entry in chain */
  char *name;         /* defined name */
  char *defn;         /* replacement text */
};

static struct nlist *hashtab[HASHSIZE]; /* pointer table */
unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);

int main() {
  struct nlist *np;
  install("name", "erkhes");
  install("composer", "kevin penkin");

  np = lookup("name");
  printf("%s\n", (np == NULL) ? "not found" : np->defn);
  np = lookup("composer");
  printf("%s\n", (np == NULL) ? "not found" : np->defn);
  np = lookup("na");
  printf("%s\n", (np == NULL) ? "not found" : np->defn);

  return 0;
}

/* hash: form hash value for string s */
unsigned hash(char *s) {
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;

  return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
  struct nlist *np;

  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(s, np->name) == 0)
      return np;

  return NULL;
}

struct nlist *install(char *name, char *defn) {
  struct nlist *np;
  unsigned hashval;

  if ((np = lookup(name)) == NULL) {
    np = (struct nlist *)malloc(sizeof(*np));
    if (np == NULL || (np->name = strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else {
    free((void *)np->defn);
  }
  if ((np->defn = strdup(defn)) == NULL)
    return NULL;
  return np;
}