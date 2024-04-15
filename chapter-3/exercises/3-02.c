#include <stdio.h>
#define MAXLINE 1000

void escape(char s[], char t[]);

int main() {
  // V1
  // char s[MAXLINE] = "to be replaced";
  // char t[MAXLINE] = "\t\t\n\n";

  // V2
  char s[MAXLINE] = "\\t\\ta\\n\\na";
  char t[MAXLINE] = "to be replaced";
  escape(s, t);
  printf("%s", t);

  return 0;
}

void escape(char s[], char t[]) {
  // V1
  // s ("\t", "\n") <- t ('\t', \n')

  //   int i, j;

  //   for (i = j = 0; t[j] != '\0'; ++j) {
  //     switch (t[j]) {
  //     case '\n':
  //       s[i++] = '\\';
  //       s[i++] = 'n';
  //       break;
  //     case '\t':
  //       s[i++] = '\\';
  //       s[i++] = 't';
  //       break;
  //     default:
  //       s[i++] = t[j];
  //       break;
  //     }
  //   }

  //   s[i] = '\0';

  // V2
  // s ("\t", "\n") -> t ('\t', '\n')

  int i, j;

  for (i = j = 0; s[i] != '\0'; ++i) {
    if (s[i] == '\\') {
      switch (s[i + 1]) {
      case 't':
        i++;
        t[j++] = '\t';
        break;
      case 'n':
        i++;
        t[j++] = '\n';
        break;
      default:
        break;
      }
    } else {
      t[j++] = s[i];
    }
  }

  t[j] = '\0';
}
