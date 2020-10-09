#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 25

int main() {
    // Init randomiser, should only be called once.
    srand(time(NULL));

    char words[MAX_STRING_LENGTH][10] = {"elephant", "barbaric", "sanitise", "virus", "infectious"};
    int score = 0;

    for (int i = 0; i < 10; i++) {
        int len = strlen(words[i]);
        int missingIndex = rand() % len;

        // create temp array for the output
        char output[MAX_STRING_LENGTH];
        strcpy(output, words[i]);

        // hide char at the random index
        output[missingIndex] = '?';

        printf("%s", output);
        printf("\nWhat's the full word?");

        char input[MAX_STRING_LENGTH];
        fgets(input, MAX_STRING_LENGTH, stdin);

        printf("in=%s", input);
        printf("og=%s\n", words[i]);

        if (strcmp(input, words[i]) == 0) {
            printf("Correct! The word was %s\n\n", words[i]);
            score++;
        } else {
            printf("Incorrect. The word was %s\n\n", words[i]);
        }
    }

    printf("Score: %d", score);

    return 0;
}
