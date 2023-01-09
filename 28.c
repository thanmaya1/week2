#include <stdio.h>
#include <stdlib.h>

void quicksort(int *array, int left, int right) {
  // base case: if the array has fewer than 2 elements, it is already sorted
  if (right - left < 1) {
    return;
  }

  // choose pivot element
  int pivot = array[left];

  // initialize pointers
  int i = left + 1;
  int j = right;

  // partition the array
  while (i <= j) {
    if (array[i] <= pivot) {
      i++;
    } else if (array[j] > pivot) {
      j--;
    } else {
      // swap array[i] and array[j]
      int temp = array[i];
      array[i] = array[j];
      array[j] = temp;
      i++;
      j--;
    }
  }

  // move pivot element to its final position
  array[left] = array[j];
  array[j] = pivot;

  // recursively apply quicksort to left and right subarrays
  quicksort(array, left, j - 1);
  quicksort(array, j + 1, right);
}

int main() {
  // read number of elements
  int n;
  scanf("%d", &n);

  // read array
  int *array = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  // sort array using quicksort
  quicksort(array, 0, n - 1);

  // print sorted array
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  free(array);
  return 0;
}
