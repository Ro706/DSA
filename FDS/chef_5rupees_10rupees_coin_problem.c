#include <stdio.h>

int main(void) {
  int n, arr[3], d;

  // Check for valid input.
  if (scanf("%d", &n) != 1 || n < 1) {
    return 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      if (scanf("%d", &arr[j]) != 1) {
        return 1;
      }
    }

    d = arr[2];
    if (d == 0) {
      return 1;
    }

    // Calculate and print the result.
    int result = arr[0] * 5 + arr[1] * 10;
    printf("%d\n", result / d);
  }

  return 0;
}
