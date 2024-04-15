#include <stdio.h>

void shellsort(int v[], int n);

int main() {
  int v[4] = {2, 3, 1, 0};
  shellsort(v, 4);
  for (int i = 0; i < 4; ++i)
    printf("%d%s", v[i], i == 3 ? "\n" : " ");

  return 0;
}

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n) {
  int gap, i, j, temp;

  for (gap = n / 2; gap > 0; gap /= 2)
    for (i = gap; i < n; i++) {
      for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
        temp = v[j];
        v[j] = v[j + gap];
        v[j + gap] = temp;
      }
    }
}
