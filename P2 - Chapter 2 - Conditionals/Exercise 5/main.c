#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char gender = ' ';
    int age = 0;

    printf("Input gender (M or F) and then your age");
    scanf("%c %i", &gender, &age);

    printf("\n%i", age);

    if (toupper(gender) == 'F') {
        printf("You chose Female and you entered %c", gender);
    } else if (toupper(gender) == 'M') {
        printf("You chose Male and you entered %c", gender);
    }

    if (islower(gender) != 0) {
        printf("\nYou entered a lowercase letter\n");
    } else if (isupper(gender) != 0) {
        printf("\nYou entered an uppercase letter\n");
    } else if (isalpha(gender) == 0) {
        printf("\nYou didn't enter a letter\n");
    } else if (ispunct(gender) != 0) {
        printf("\nYou entered punctuation\n");
    } else if (isspace(gender) != 0) {
        printf("\nYou entered whitespace\n");
    }

    // This doesn't work... `isdigit` only works on ints (and if we're parsing an int with scanf,
    // `age` will always be a number anyway, even if a number wasn't entered.

    // if (isdigit(age) == 0) {
    //     printf("\nYou didn't enter a number for age\n");
    // }

    system("pause");
    return 0;
}
