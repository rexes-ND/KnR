#include <stdio.h>

char *month_name(int n);

int main() {
  printf("%s\n", month_name(0));
  printf("%s\n", month_name(10));

  return 0;
}

char *month_name(int n) {
  char *name[] = {"Illegal month", "January",   "February", "March",
                  "April",         "May",       "June",     "July",
                  "August",        "September", "October",  "November",
                  "December"};

  return (n < 1 || n > 12) ? name[0] : name[n];
}
