#include <ctype.h>
#include <stdio.h>

int main() {
  float user1 = 0, user2 = 0;
  char operation;

  printf("Enter first number:");
  scanf("%f", &user1);
  printf("Enter second number:");
  scanf("%f", &user2);

  printf("Choose your operation (+-*/):");
  scanf(" %c", &operation);

  switch (operation) {
    case '+':
      printf("%f + %f = %f", user1, user2, user1 + user2);
      break;
    case '-':
      printf("%f - %f = %f", user1, user2, user1 - user2);
      break;
    case '*':
      printf("%f * %f = %f", user1, user2, user1 * user2);
      break;
    case '/':
      printf("%f / %f = %f", user1, user2, user1 / user2);
      break;
  }

  return 0;
}
