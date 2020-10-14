#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUMBER_COUNT 10
#define RANDOM_MAX_VALUE 50

int main() {
    // Init randomiser, should only be called once.
    srand(time(NULL));

    int numbers[NUMBER_COUNT];

    // Generate 10 random numbers and store them in the array
    for (int i = 0; i < NUMBER_COUNT; i++) {
        numbers[i] = rand() % RANDOM_MAX_VALUE;
        printf("%d ", numbers[i]);
    }

    // spacing
    printf("\n\n");

    // Bubble sort
    int swaps_made = -1;
    int loop_counter = 0;
    while (swaps_made != 0) {
        swaps_made = 0;
        loop_counter++;

        printf("\nLoop #%d\n", loop_counter);

        for (int i = 0; i < NUMBER_COUNT - 1; i++) {
            printf("Checking index %d against %d\n", i, i + 1);

            if (numbers[i] > numbers[i + 1]) {
                printf("! %d is larger than %d. Swapping...\n", numbers[i], numbers[i + 1]);

                int valueAbove = numbers[i + 1];
                numbers[i + 1] = numbers[i];
                numbers[i] = valueAbove;
                swaps_made++;
            }
        }
    }

    printf("\nNo swaps made. Complete!\n");

    // spacing
    printf("\n\n");

    // They should be sorted now?
    for (int i = 0; i < NUMBER_COUNT; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
