#include <stdio.h>

int main() {
    int dataCount = 1;

    printf("How many numbers would you like to enter? ");
    scanf("%i", &dataCount);

    // If user inputs 0 or negative, avg is wrong (or crashes)
    if (dataCount < 1) dataCount = 1;

    int total = 0, i = 1;

    do {
        int num = 0;
        printf("Enter number: ");
        scanf("%i", &num);

        total += num;
        i += 1;
    } while (i <= dataCount);

    float avg = (float) total / (float) dataCount;
    printf("Average: %f", avg);

    return 0;
}
