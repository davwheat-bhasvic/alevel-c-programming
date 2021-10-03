#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ARRAY_SIZE(arr)     (sizeof(arr) / sizeof((arr)[0]))
#define ITEMS 10
#define MAX_VAL 10
#define MAX_VAL_DIGITS 4
#define PRINT_ARRAY 0

#define STR_(X) #X
#define STR(X) STR_(X)

int bubbleSort(int *array, int array_size);

int insertionSort(int *array, int array_size);

void fillArray(int *array, int array_size);

void printArray(int *array, int array_size);

int *copyArray(int *src, size_t len);

int arrayCompare(const int *array1, const int *array2, int array_size);

void sort();

void search();

int linearSearch(const int *array, int array_size, int searchTerm);

int binarySearch(const int *array, int array_size, int searchTerm);

int main() {
  int input = 0;

  while (input > 2 || input < 1) {
    printf("\n1. Sort");
    printf("\n2. Search");

    scanf_s("%d", &input);
  }

  switch (input) {
    default:
    case 1:
      sort();
      break;

    case 2:
      search();
      break;
  }
}

void sort() {
  int numbers1[ITEMS];

  fillArray(numbers1, ARRAY_SIZE(numbers1));
  int *numbers2 = copyArray(numbers1, ARRAY_SIZE(numbers1));

  int bubbleComparisons = bubbleSort(numbers1, ARRAY_SIZE(numbers1));
  int insertionComparisons = insertionSort(numbers2, ARRAY_SIZE(numbers1));

  printf("\nSort completed. Comparing sorted arrays...");

  if (arrayCompare(numbers1, numbers2, ARRAY_SIZE(numbers1)) == 0) {
    printf("\n!!! - Array validation failed -- something has gone horribly wrong.\n");
  }

  printf("\n   Bubble comparisons: %d", bubbleComparisons);
  printf("\nInsertion comparisons: %d", insertionComparisons);
}

void search() {
#define SEARCH_ITEM_COUNT 10

  int numbers1[SEARCH_ITEM_COUNT];

  for (int i = 0; i < SEARCH_ITEM_COUNT; ++i) {
    printf("\nEnter number for item %d:", i + 1);
    scanf_s("%d", &numbers1[i]);
  }

  int input = 0;

  while (input > 2 || input < 1) {
    printf("\n\n1. Linear search");
    printf("\n2. Binary search (will auto-sort)");

    scanf_s("%d", &input);
  }

  int searchTerm = 0;
  printf("\nSearch term: ");
  scanf_s("%d", &searchTerm);

  int result = -2;

  switch (input) {
    default:
    case 1:
      result = linearSearch(numbers1, ARRAY_SIZE(numbers1), searchTerm);
      break;
    case 2:
      insertionSort(numbers1, ARRAY_SIZE(numbers1));
      result = binarySearch(numbers1, ARRAY_SIZE(numbers1), searchTerm);
      break;
  }

  printf("\nValue was found at index %d of the array.", result);
}

int linearSearch(const int *array, int array_size, int searchTerm) {
  for (int i = 0; i < array_size; i++) {
    if (array[i] == searchTerm) {
      printf("\nIndex %d: %d is equal to search term %d", i, array[i], searchTerm);
      printf("\nFound at index %d", i);
      return i;
    } else {
      printf("\nIndex %d: %d is not equal to search term %d", i, array[i], searchTerm);
    }
  }

  printf("\nNot found in array.");
  return -1;
}

int binarySearch(const int *array, int array_size, int searchTerm) {
  int found = -1, low = 0, high = array_size - 1;

  while (high >= low && found == -1) {
    int middle = (high + low) / 2;

    if (array[middle] == searchTerm) {
      found = middle;
      printf("\nIndex %d: %d is equal to search term %d", middle, array[middle], searchTerm);
      break;
    }

    if (array[middle] > searchTerm) {
      // Discard upper half
      printf("\nIndex %d: %d is greater than search term %d. Discarding upper half.", middle, array[middle],
             searchTerm);
      high = middle - 1;
    } else {
      // Discard lower half
      printf("\nIndex %d: %d is less than search term %d. Discarding lower half.", middle, array[middle], searchTerm);
      low = middle + 1;
    }
  }

  if (found == -1) {
    printf("\nNot found in array.");
  } else {
    printf("\nFound at index %d", found);
  }

  return found;
}

int arrayCompare(const int *array1, const int *array2, int array_size) {
  for (int i = 0; i < array_size; ++i) {
    if (array1[i] != array2[i]) return 0;
  }

  return 1;
}

int *copyArray(int *src, size_t len) {
  int *p = malloc(len * sizeof(int));
  memcpy(p, src, len * sizeof(int));
  return p;
}

void fillArray(int *array, int array_size) {
  srand(time(NULL));

  for (int i = 0; i < array_size; i++) {
    array[i] = rand() % MAX_VAL;
  }
}

int insertionSort(int *array, int array_size) {
  int comparisons = 0;

  for (int i = 1; i < array_size; i++) {
    int peekedItem = array[i];
    int comparisonIndex = i;

    int didLoop = 0;

    while (comparisonIndex > 0 && array[comparisonIndex - 1] > peekedItem) {
      didLoop = 1;
      ++comparisons;
      array[comparisonIndex] = array[comparisonIndex - 1];
      --comparisonIndex;
    }

    if (didLoop == 0) {
      ++comparisons;
    }

    array[comparisonIndex] = peekedItem;

#if PRINT_ARRAY == 1
    printArray(array, array_size);
#endif
  }

  return comparisons;
}

int bubbleSort(int *array, int array_size) {
  int hasChanged = 1;
  int knownSorted = 0;
  int comparisonCount = 0;

  while (hasChanged == 1) {
    hasChanged = 0;

    for (int i = 0; i < array_size - 1 - knownSorted; i++) {
      ++comparisonCount;

      if (array[i] > array[i + 1]) {
        hasChanged = 1;
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
    ++knownSorted;

#if PRINT_ARRAY == 1
    printArray(array, array_size);
#endif
  }

  return comparisonCount;
}

void printArray(int *array, int array_size) {
  for (int i = 0; i < array_size; i++) {
    printf("%"STR(MAX_VAL_DIGITS)"d ", array[i]);
  }
  printf("\n");
}