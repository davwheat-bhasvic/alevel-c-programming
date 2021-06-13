#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(int key, int strlen, const char* string);

char* decrypt(int key, int strlen, const char* string);

int getAlphaPos(char c);

char getNewAlphaChar(char c, int key);

int main() {
  setbuf(stdout, NULL);

  int key = 0;
  char string[9999] = "\0";

  printf("Enter key: ");
  scanf_s("%d", &key);

  if (key < 1 || key > 26) {
    printf("Invalid key entry.");
    return 1;
  }

  printf("\nEnter text: ");
  scanf_s("%9998s", &string, 9999);

  printf("\nEncrypted: %s", encrypt(key, strlen(string), string));
  printf("\nDecrypted: %s", decrypt(key, strlen(string), string));

  return 0;
}

char* encrypt(int key, int strlen, const char* string) {
  char* encrypted = malloc(strlen + 1);
  memset(encrypted, 0, (strlen + 1) * sizeof(char));

  for (int i = 0; i < strlen; i++) {
    char letter = string[i];
    encrypted[i] = getNewAlphaChar(letter, key);
  }

  encrypted[strlen] = '\0';

  return encrypted;
}

char* decrypt(int key, int strlen, const char* string) {
  int decryptKey = -key;
  char* decrypted = malloc(strlen + 1);
  ;
  memset(decrypted, 0, (strlen + 1) * sizeof(char));

  for (int i = 0; i < strlen; i++) {
    char letter = string[i];
    decrypted[i] = getNewAlphaChar(letter, decryptKey);
  }

  decrypted[strlen] = '\0';

  return decrypted;
}

int getAlphaPos(char c) {
  return toupper(c) - 'A';
}

char getNewAlphaChar(char c, int key) {
  int pos = getAlphaPos(c);
  int newPos = pos + key;

  if (newPos >= 26)
    newPos -= 26;
  else if (newPos < 0)
    newPos += 26;

  if (isupper(c)) {
    return (char)('A' + newPos);
  } else if (islower(c)) {
    return (char)('a' + newPos);
  } else {
    return c;
  }
}
