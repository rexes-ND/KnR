#include <stdio.h>

#define MAXLINE 1000

void squeeze(char s1[], char s2[]);

int main() {
  char s1[MAXLINE] = "abcdabcdabcd";
  char s2[MAXLINE] = "ac";
  squeeze(s1, s2);
  printf("%s\n", s1);

  return 0;
}

void squeeze(char s1[], char s2[]) {
  int i, j, found;

  for (i = j = 0; s1[i] != '\0'; i++) {
    found = 0;
    for (int k = 0; !found && s2[k] != '\0'; ++k) {
      if (s1[i] == s2[k])
        found = 1;
    }
    if (!found)
      s1[j++] = s1[i];
  }

  s1[j] = '\0';
}
