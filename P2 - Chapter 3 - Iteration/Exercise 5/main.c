#include <stdio.h>

int main() {
    int multiplier = 0,
            count = 0;

    printf("What times table would you like to see? ");
    scanf("%i", &multiplier);

    printf("How many times would you like to see it? ");
    scanf("%i", &count);
    printf("\n");

    for (int i = 1; i <= count; i++) {
        printf("%d * %d = %d\n", i, multiplier, i * multiplier);
    }

    return 0;
}
