#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 25

// Casually stolen from Stack Overflow: https://stackoverflow.com/a/1431206
// License: CC BY-SA 2.5
char *ltrim(char *s)
{
    while(isspace(*s)) s++;
    return s;
}

char *rtrim(char *s)
{
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}

char *trim(char *s)
{
    return rtrim(ltrim(s));
}

int main() {
    // Init randomiser, should only be called once.
    srand(time(NULL));

    char words[MAX_STRING_LENGTH][25] = {"elephant", "barbaric", "sanitise", "virus", "infectious"};
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

        // if input and original words match...
        if (strcmp(trim(input), trim(words[i])) == 0) {
            printf("Correct! The word was %s\n\n", words[i]);
            score++;
        } else {
            printf("Incorrect. The word was %s\n\n", words[i]);
        }
    }

    printf("Score: %d", score);

    return 0;
}


