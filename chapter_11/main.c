#include <stdio.h>

// int i;
void avg_sum(double a[], int n, double *avg, double *sum);

int main() {
  /*
  double arr[] = {3, 5, 2, 10, 30};
  int n = sizeof(arr) / sizeof(arr[0]);

  double total_avg, total_sum;
  double *avg, *sum;
  avg = &total_avg;
  sum = &total_sum;

  printf("total_avg: %f\n", total_avg);
  printf("total_sum: %f\n", total_sum);

  avg_sum(arr, n, avg, sum);

  printf("total_avg: %f\n", total_avg);
  printf("total_sum: %f\n", total_sum);
  */

  /*
  int i = 10;
  int *p;
  int *q;
  */

  /*
  a: CE
  b: UB
  c: CE
  d: CE  assigning &&int to &int
  e: p = *&q
  f: p = q
  g: CE
  h: CE
  i: *p = *q
  */
}

void avg_sum(double a[], int n, double *avg, double *sum) {
  int idx;
  for (idx = 0; idx < n; idx++) {
    *sum += a[idx];
  }
  *avg = *sum / idx;
}
