#include <stdio.h>

int main() {
    int numbers[10];

    for (int i = 0; i < 10; i++) {
        int input = 0;

        printf("\nEnter a number");
        scanf("%i", &input);

        numbers[i] = input;
    }

    int get = 0;

    printf("Enter the index to retrieve: ");
    scanf("%i", &get);

    printf("Index %d has value %d", get, numbers[get]);
}
