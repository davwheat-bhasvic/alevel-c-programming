#include <stdio.h>

int task3() {
    const int charDiff = 97 - 65;
    char letter;

    printf("\nEnter an uppercase character: ");
    // space before %c needed to ignore whitespace from enter key
    scanf(" %c", &letter);

    printf("\nHere's it in lower case: %c", letter + charDiff);

    return 0;
}
