#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_VALUE 30

int isPrime(int number) {
    int i;

    for (i = 2; i < number; i++) {
        if (number % i == 0 && i != number) return 0;
    }

    return 1;
}

int main() {
    srand(time(NULL));

    int credits = 10;

    while (credits > 0) {
        int wager = 0, guess = -1;

        while (wager < 1 || wager > credits) {
            printf("\n\nYou have %d credits.\n", credits);
            printf("How much would you like to bet? ");
            scanf("%d", &wager);
        }

        while (guess < 0 || guess > MAX_VALUE) {
            printf("\n\nWhich number do you want to place your wager on? ");
            scanf("%i", &guess);
        }

        int randomNumber = rand() % MAX_VALUE;
//        printf("%d\n", randomNumber);

        if (guess == randomNumber) {
            // They've guessed correctly
            int winMultiplier = 0;

            if (isPrime(randomNumber)) winMultiplier += 5;
            if (randomNumber % 10 == 0) winMultiplier += 3;
            if (randomNumber < 5) winMultiplier += 2;

            if (winMultiplier == 0) winMultiplier = 1;

            printf("Congratulations! You guessed correctly!\n");
            printf("You won %d credits with a %dx multiplier (%d credits total)!\n", wager, winMultiplier,
                   wager * winMultiplier);

            credits += wager * winMultiplier;
        } else {
            // They're wrong
            credits -= wager;

            printf("Oh no, you guessed incorrectly. The number was %d.", randomNumber);
        }
    }

    printf("Hello, World!\n");
    return 0;
}
