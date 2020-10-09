#include <stdio.h>
#include <string.h>

#define LENGTH 80

int isInArray(char value, char array[26]) {
    for (int i = 0; i < 26; i++) {
        if (array[i] == '\0') break;

        if (array[i] == value) return 1;
    }

    return 0;
}

int main() {
    char input[LENGTH];
    int vowels = 0, consonants = 0;

    printf("Enter string up to 80 chars:");
    fgets(input, LENGTH, stdin);

    for (int i = 0; i < LENGTH; i++) {
        // detect end of string
        if (input[i] == '\0') break;

        if (isInArray(input[i], "aeiou")) {
            vowels++;
        } else if (isInArray(input[i], "bcdfghjklmnpqrstvwxyz")) {
            consonants++;
        }
    }

    printf("\nVowels: %d\nConsonants: %d", vowels, consonants);

    return 0;
}
