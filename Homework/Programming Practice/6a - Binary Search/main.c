#include <stdio.h>

#define MAX_INDEX 50

int search(int value, const int *array, int *comparisons);

int main() {
  setbuf(stdout, 0);
  int nums[MAX_INDEX];

  int comparisons = 0;

  for (int i = 0; i < MAX_INDEX; ++i) {
    nums[i] = i * 3;
  }

  int value = -1;
  sprintf("Enter search value: ");
  scanf_s("%d", &value);
  sprintf("\n");

  int foundAt = search(value, nums, &comparisons);

  printf("Comparisons: %d\nFound at: %d", comparisons, foundAt);

  return 0;
}

int search(int value, const int *array, int *comparisons) {
  int low = 0;
  int high = MAX_INDEX - 1;
  int mid = 0;
  int found = 0;

  while (found == 0 && high >= low) {
    mid = ((high - low) / 2) + low;
    int midItem = array[mid];

    if (midItem == value) {
      (*comparisons)++;
      found = 1;
    } else if (midItem < value) {
      low = mid + 1;
      (*comparisons) += 2;
    } else {
      high = mid - 1;
      (*comparisons) += 2;
    }
  }

  return mid;
}
