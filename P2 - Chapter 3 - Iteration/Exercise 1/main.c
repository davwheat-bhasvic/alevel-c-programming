#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 10
#define ATTEMPTS_AVAILABLE 5

int main() {
  // initialise randomizer
  srand(time(NULL));

  int randomNumber = (rand() % MAX_NUMBER) + 1, pGuess = 0, guessesRemaining = ATTEMPTS_AVAILABLE;

  while (guessesRemaining > 0) {
    printf("Guess my random number (1-%d): ", MAX_NUMBER);
    scanf("%d", &pGuess);

    if (pGuess == randomNumber) {
      printf("Congratulations!\n");
      break;
    } else {
      if (pGuess > randomNumber)
        printf("Your guess was too high!\n");
      else
        printf("Your guess was too low!\n");

      guessesRemaining -= 1;
    }
  }

  if (guessesRemaining == 0) {
    printf("\nYou've run out of guesses. You lose!");
  }

  printf("\nThe number was %d", randomNumber);

  return 0;
}
