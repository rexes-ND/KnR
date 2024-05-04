#include "unistd.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/dir.h>
#include <sys/stat.h>

typedef struct {
  long ino;
  char name[NAME_MAX + 1];
} Dirent;

typedef struct {
  int fd;
  Dirent d;
} Dir;

Dir *open_dir(char *dirname);
Dirent *read_dir(Dir *dfd);
void close_dir(Dir *dfd);

void fsize(char *);

int main(int argc, char **argv) {
  if (argc == 1)
    fsize(".");
  else
    while (--argc > 0)
      fsize(*++argv);

  return 0;
}

void dirwalk(char *, void (*fcn)(char *));

/* fsize: print the name of file "name" */
void fsize(char *name) {
  struct stat stbuf;
  if (stat(name, &stbuf) == -1) {
    fprintf(stderr, "fsize: can't access %s\n", name);
    return;
  }
  if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
    dirwalk(name, fsize);
  printf("%8ld %s\n", stbuf.st_size, name);
}

#define MAX_PATH 1024

/* dirwalk: apply fcn to all files in dir */
void dirwalk(char *dir, void (*fcn)(char *)) {
  // printf("dirwalk %s\n", dir);
  char name[MAX_PATH];
  Dirent *dp;
  Dir *dfd;

  if ((dfd = open_dir(dir)) == NULL) {
    fprintf(stderr, "dirwalk: can't open %s\n", dir);
    return;
  }
  while ((dp = read_dir(dfd)) != NULL) {
    if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, ".."))
      continue;
    if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name))
      fprintf(stderr, "dirwalk: name %s %s too long\n", dir, dp->name);
    else {
      sprintf(name, "%s/%s", dir, dp->name);
      (*fcn)(name);
    }
  }

  close_dir(dfd);
}

/* opendir: open a directory for readdir calls */
Dir *open_dir(char *dirname) {
  int fd;
  struct stat stbuf;
  Dir *dp;

  if ((fd = open(dirname, O_RDONLY, 0)) == -1 || fstat(fd, &stbuf) == -1 ||
      (stbuf.st_mode & S_IFMT) != S_IFDIR ||
      (dp = (Dir *)malloc(sizeof(Dir))) == NULL)
    return NULL;
  dp->fd = fd;

  return dp;
}

void close_dir(Dir *dp) {
  if (dp) {
    close(dp->fd);
    free(dp);
  }
}

#define DIRSIZ 14

/* readdir: read directory entries in sequence */
Dirent *read_dir(Dir *dp) {
  struct direct dirbuf;
  static Dirent d;

  while (read(dp->fd, (char *)&dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)) {
    if (dirbuf.d_ino == 0)
      continue;
    d.ino = dirbuf.d_ino;
    strncpy(d.name, dirbuf.d_name, DIRSIZ);
    d.name[DIRSIZ] = '\0';
    return &d;
  }

  return NULL;
}
