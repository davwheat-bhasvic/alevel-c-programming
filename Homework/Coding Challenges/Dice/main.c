#include <stdio.h>

#define TARGET 10

int main() {
  // Maximum values for the two dice
  int max_value_a = 6, max_value_b = 6;

  printf("\nEnter the maximum number on die 1: ");
  scanf("%d", &max_value_a);

  printf("\nEnter the maximum number on die 2: ");
  scanf("%d", &max_value_b);

  // We need the higher of the two maxes in the A variable.
  if (max_value_a < max_value_b) {
    int temp = max_value_a;
    max_value_a = max_value_b;
    max_value_b = temp;
  }

  int counter = 0;

  // We check if it's less than TARGET because it's impossible to
  // reach the TARGET with one or more values being greater than it.
  for (int val1 = 1; val1 < TARGET && val1 <= max_value_a; val1++) {
    int desiredVal2 = TARGET - val1;

    // if the value we want on die 2 is higher than its max,
    // it's useless to us
    if (desiredVal2 <= max_value_b) {
      printf("\n%d + %d = %d", val1, desiredVal2, TARGET);
      counter++;
    }
  }

  // print total number of ways to get TARGET with correct
  // pluralisation
  printf("\n\nThere %s %d %s to get the sum %d.", counter == 1 ? "is" : "are", counter,
         counter == 1 ? "way" : "ways", TARGET);
}
