

```c 
  // Reverse the array, using 2 pointers
  int numbers[10] = {42, 17, 93, 58, 29, 76, 31, 84, 66, 55};
  int n = sizeof(numbers) / sizeof(numbers[0]);

  printf("before\n");
  print_array(numbers, n);

  int i = -1, j = n;
  while (i++ < j--) {
    int temp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = temp;
  }

  printf("after\n");
  print_array(numbers, n);

void print_array(int *arr, int n) {
  for (int idx = 0; idx < n; idx++)
    printf("%d: %d\n", idx, arr[idx]);
}
```
