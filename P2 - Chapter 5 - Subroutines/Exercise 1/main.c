#include <stdio.h>

int divEleven(int number);

int main() {
  puts("Enter a number to divide by 11.");

  int number;
  scanf_s("%i", &number);

  printf("%d", divEleven(number));

  return 0;
}

int divEleven(const int number) {
  return number / 11;
}