#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
  printf("Minimum value of signed char: %d\n", SCHAR_MIN);
  printf("Maximum value of signed char: %d\n", SCHAR_MAX);
  printf("Minimum value of unsigned char: %u\n", 0);
  printf("Minimum value of unsigned char: %u\n", UCHAR_MAX);
  printf("Minimum value of signed short: %d\n", SHRT_MIN);
  printf("Maximum value of signed short: %d\n", SHRT_MAX);
  printf("Minimum value of unsigned short: %u\n", 0);
  printf("Minimum value of unsigned short: %u\n", USHRT_MAX);
  printf("Minimum value of signed int: %d\n", INT_MIN);
  printf("Maximum value of signed int: %d\n", INT_MAX);
  printf("Minimum value of unsigned int: %u\n", 0);
  printf("Maximum value of unsigned int: %u\n", UINT_MAX);
  printf("Minimum value of long: %ld\n", LONG_MIN);
  printf("Maximum value of long: %ld\n", LONG_MAX);
  printf("Minimum value of unsigned long: %lu\n", 0UL);
  printf("Maximum value of unsigned long: %lu\n", ULONG_MAX);
  printf("Minimum value of float: %f\n", FLT_MIN);
  printf("Maximum value of float: %f\n", FLT_MAX);
  printf("Minimum value of double: %f\n", DBL_MIN);
  printf("Maximum value of double: %f\n", DBL_MAX);
  printf("Minimum value of long double: %Lf\n", LDBL_MIN);
  printf("Maximum value of long double: %Lf\n", LDBL_MAX);
  return 0;
}
