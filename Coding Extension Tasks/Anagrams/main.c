#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 256

int main() {
    char str1[MAX_LENGTH] = {'\0'};
    char str2[MAX_LENGTH] = {'\0'};

    puts("Enter first string:");
    fgets(str1, MAX_LENGTH, stdin);

    puts("Enter second string:");
    fgets(str2, MAX_LENGTH, stdin);

    const int str1len = (int) strlen(str1);
    const int str2len = (int) strlen(str2);

    if (str1len != str2len) {
        puts("Not an anagram.");
        return 0;
    }

    char str2copy[MAX_LENGTH] = {'\0'};
    strcpy_s(str2copy, MAX_LENGTH, str2);

    int isAnagram = 1;

    // iterate over every char in str1
    for (int i = 0; i < str1len; i++) {
        int foundMatch = 0;

        // iterate over every char in str2
        for (int x = 0; x < str2len; x++) {
            // if we find a match for the i-th char of str1 in str2...
            if (str1[i] == str2copy[x]) {
                foundMatch = 1;
                // remove matched char so we can't match 3 a's with the same a
                str2copy[x] = '\0';
                break;
            }
        }

        // if we couldn't find a match, exit the loop to stop wasting time
        // as we know it's not an anagram
        if (foundMatch == 0) {
            isAnagram = 0;
            break;
        }
    }

    if (isAnagram == 0) {
        puts("Not an anagram");
    } else {
        puts("It's an anagram");
    }

    return 0;
}
