#include <stdio.h>
#include <string.h>

// length of pre-set word
#define LENGTH 6

int main() {
    char word[] = "dinner";
    char guess[] = "??????";
    int guessCount = 1;

    while (strcmp(word, guess) != 0 && guessCount <= 5) {
        char input[LENGTH + 1];

        printf("%s", guess);
        printf("\nGuess the word:");
        // gets is bad! >:(
        fgets(input, LENGTH + 1, stdin);

        for (int i = 0; i < LENGTH; i++) {
            // if letter in guess matches letter in word...
            if (input[i] == word[i]) {
                // ...overwrite the letter in the guess variable
                guess[i] = input[i];
            }
        }

        guessCount++;
    }

    if (guessCount > 5) {
        printf("You lose!");
    } else {
        printf("You win!");
    }
}
