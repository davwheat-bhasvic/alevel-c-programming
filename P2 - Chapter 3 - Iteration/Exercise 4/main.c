#include <stdio.h>
#include <math.h>


int validateArmstrongNumber(int number) {
    int isArmstrong = 1;

    // C99 always rounds towards 0
    int digit1 = number / 100, // get 1st digit
    digit2 = (number / 10) % 10, // gets 2nd digit
    digit3 = number % 10; // gets 3rd digit

    if (pow(digit1, 3) + pow(digit2, 3) + pow(digit3, 3) != number) isArmstrong = 0;

    return isArmstrong;
}

int checkArmstrongNum() {
    int number = 0;

    printf("\nEnter a 3-digit number to check if it's an Armstrong number: ");
    scanf(" %d", &number);

    int isArmstrong = validateArmstrongNumber(number);

    if (isArmstrong)
        printf("%d is an Armstrong number!", number);
    else
        printf("%d is not an Armstrong number.", number);
}

int findArmstrongNumbersInRange() {
    int start = 0, end = 0;

    printf("\nEnter beginning number: ");
    scanf(" %d", &start);

    printf("\nEnter end number: ");
    scanf(" %d", &end);

    // ensure start and ends are 3-digits
    if (start < 100) start = 100;
    if (end > 999) end = 999;

    for (int i = start; i <= end; i++) {
        if (validateArmstrongNumber(i)) printf("%d\n", i);
    }

    return 0;
}

int main() {
    printf("A Armstrong number is a 3-digit number which is equal to the sum of the cubes of its digits.\n");
    printf("e.g. 371 = 3^3 + 7^3 + 1^3\n");

    MENU_START:
    printf("\nChoose an option:\n1. check if a number is an Armstrong number\n2. find all Armstrong numbers in a specified range\n0. Exit\n\n");

    int option = 0;
    scanf("%d", &option);

    switch (option) {
        default:
            printf("Invalid option.");
            // I'm a hacky person.
            goto MENU_START;
        case 0:
            return 0;
        case 1:
            return checkArmstrongNum();
        case 2:
            return findArmstrongNumbersInRange();
    }
}