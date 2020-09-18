#include <stdio.h>

int task2() {
    int i;
    float f;
    char c;

    printf("Enter an integer: ");
    scanf("%d", &i);

    printf("Enter a float: ");
    scanf("%f", &f);

    printf("Enter a letter: ");
    // space before %c needed to ignore whitespace from enter key
    scanf(" %c", &c);

    printf("\n\n%d - %f = %f", i, f, (float) i - f);
    printf("\n%f * %d = %f", (float) i - f, c, ((float) i - f) * (float) c);

    return 0;
}
