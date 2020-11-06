#include <stdio.h>

int main() {
  int num = 0;

  printf(
      "A magic number is one which is divisible by 7 or 3, and, when "
      "multiplied by 5, is below 100.\n");

  do {
    printf("\nEnter a number to check if it's MaGiCaL (or 100 to quit): ");
    scanf("%i", &num);

    int isMagic = 1;

    // If not a multiple of 7 or 3, it's not magic
    if (num % 7 != 0 && num % 3 != 0)
      isMagic = 0;

    // If >= 100 when multiplied by 5, it's not magic
    if (num * 5 >= 100)
      isMagic = 0;

    if (isMagic)
      printf("It is MaGiCaL!");
    else
      printf("It's not magical.");
  } while (num != 100);

  return 0;
}
