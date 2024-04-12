#include <stdio.h>
#define MAXLINE 1000

// v1
// int get_line(char line[], int maxline);
// void copy(char to[], char from[]);

// int main() {
//   int len, max;

//   char line[MAXLINE];
//   char longest[MAXLINE];

//   max = 0;

//   while ((len = get_line(line, MAXLINE)) > 0) {
//     if (len > max) {
//       max = len;
//       copy(longest, line);
//     }
//   }

//   if (max > 0)
//     printf("%s", longest);

//   return 0;
// }

// int get_line(char s[], int lim) {
//   int c, i;

//   for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
//     s[i] = c;
//   if (c == '\n') {
//     s[i] = c;
//     ++i;
//   }
//   s[i] = '\0';
//   return i;
// }

// void copy(char to[], char from[]) {
//   int i;

//   i = 0;
//   while ((to[i] = from[i]) != '\0')
//     ++i;
// }

int max;
char line[MAXLINE];
char longest[MAXLINE];

int get_line(void);
void copy(void);

int main() {
  int len;
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = get_line()) > 0)
    if (len > max) {
      max = len;
      copy();
    }
  if (max > 0)
    printf("%s", longest);
  return 0;
}

int get_line(void) {
  int c, i;
  extern char line[];

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

void copy(void) {
  int i;
  extern char line[], longest[];

  i = 0;
  while ((longest[i] = line[i]) != '\0')
    ++i;
}
