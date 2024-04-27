#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 100
#define BUFSIZE 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);

int main(int argc, char *argv[]) {
  double op2;

  while (--argc > 0) {
    ++argv;
    if (isdigit((*argv)[0])) {
      push(atof(*argv));
    } else {
      switch ((*argv)[0]) {
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else {
          printf("error: zero divisor\n");
          return -1;
        }
        break;
      default:
        printf("error: unknown command %s\n", *argv);
        return -1;
        break;
      }
    }
  }
  printf("\t%.8g\n", pop());

  return 0;
}

int sp = 0;
double val[MAXVAL];

void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}
