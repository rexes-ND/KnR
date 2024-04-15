#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
  int v[] = {1, 2, 3, 4};
  printf("%d\n", binsearch(4, v, 4));
  return 0;
}

int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;

  while (low < high) {
    mid = (low + high) / 2;
    if (x <= v[mid])
      high = mid;
    else
      low = mid + 1;
  }

  if (v[low] == x)
    return low;

  return -1;
}
