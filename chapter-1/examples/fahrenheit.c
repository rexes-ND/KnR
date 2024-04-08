#include <stdio.h>

/*
    print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300
*/

// v1
// int main() {
//   int fahr, celsius;
//   int lower, upper, step;

//   lower = 0;   /* lower limit of temperature scale */
//   upper = 300; /* upper limit */
//   step = 20;   /* step size */

//   fahr = lower;
//   while (fahr <= upper) {
//     celsius = 5 * (fahr - 32) / 9;
//     printf("%3d %6d\n", fahr, celsius);
//     fahr = fahr + step;
//   }
//   return 0;
// }

// v2
// int main() {
//   float fahr, celsius;
//   float lower, upper, step;

//   lower = 0;   /* lower limit of temperature scale */
//   upper = 300; /* upper limit */
//   step = 20;   /* step size */

//   fahr = lower;
//   while (fahr <= upper) {
//     celsius = 5.0 / 9.0 * (fahr - 32);
//     printf("%3.0f %6.1f\n", fahr, celsius);
//     fahr = fahr + step;
//   }
//   return 0;
// }

#define LOWER 0
#define UPPER 300
#define STEP 20

// v3
int main() {
  int fahr;

  for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));

  return 0;
}
