#include <stdio.h>

int main() {
    int numbers[10];

    for (int i = 0; i < 10; i++) {
        int input = 0;

        printf("\nEnter a number");
        scanf("%i", &input);

        numbers[i] = input;
    }

    float average = 0;
    int low = numbers[0], high = numbers[0], higherCount = 0;

    for (int i = 0; i < 10; i++) {
        average += numbers[i];
    }

    // calculate average
    average /= 10;

    for (int i = 0; i < 10; i++) {
        if (numbers[i] > average) higherCount++;

        if (numbers[i] > high) high = numbers[i];
        else if (numbers[i] < low) low = numbers[i];
    }

    printf("\nAverage: %f", average);
    printf("\nHighest: %d", high);
    printf("\nLowest: %d", low);
    printf("\nHigher than avg: %d", higherCount);
}
