#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    // initialise randomizer
    srand(time(NULL));

    int randomNumber = (rand() % 10) + 1, pGuess;

    printf("Guess my random number (1-10): ");
    scanf("%d", &pGuess);

    if (pGuess == randomNumber) {
        printf("Congratulations!");
    } else if (abs(randomNumber - pGuess) == 1) {
        printf("So close!");
    } else {
        printf("Sorry, wrong answer.");
    }

//    printf("\n\nThe number was %d", randomNumber);

    return 0;
}
