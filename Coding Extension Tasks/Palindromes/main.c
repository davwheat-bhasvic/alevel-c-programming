#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 512

int removeSpaces(char string[MAX_LENGTH]) {
  const unsigned int length = strlen(string);
  char newString[MAX_LENGTH] = {'\0'};

  int counter = 0;
  for (int i = 0; i < length; i++) {
    if (!isspace(string[i])) {
      newString[counter] = string[i];
      counter++;
    }
  }

  // copy back to original variable
  strcpy_s(string, MAX_LENGTH, newString);

  return 0;
}

int reverseStr(char string[MAX_LENGTH]) {
  char newString[MAX_LENGTH] = {'\0'};
  const int length = (int)strlen(string);

  int counter = 0;
  for (int i = length - 1; i >= 0; i--) {
    newString[counter] = string[i];
    counter++;
  }

  strcpy_s(string, MAX_LENGTH, newString);

  return 0;
}

int main() {
  printf("Check if two strings are palindromes!\n");
  printf("\nFirst string:");

  char str1[MAX_LENGTH];
  fgets(str1, MAX_LENGTH, stdin);
  removeSpaces(str1);

  char str2[MAX_LENGTH];
  strcpy_s(str2, MAX_LENGTH, str1);

  reverseStr(str1);

  if (strcmp(str1, str2) == 0) {
    puts("It's a palindrome!");
  } else {
    puts("Not a palindrome.");
  }

  return 0;
}
