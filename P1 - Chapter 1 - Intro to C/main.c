#include <stdio.h>

#include "prime-or-composite.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"

#define MENU_OPTION_COUNT 4

int main() {
  int option = -1;

  // Menu option text
  const char* optionPrompts[MENU_OPTION_COUNT] = {"Bob's Bricks", "Pathway 1 Practice - Q1",
                                                  "Pathway 1 Practice - Q2", "Prime or Composite"};

  // Array of functions
  const int (*functions[MENU_OPTION_COUNT])() = {task1, task2, task3, primeOrCompositeTask};

  // For each function in array, print a menu option
  for (int i = 0; i < sizeof(functions) / sizeof(functions[0]); i++) {
    printf("%d. %s\n", i + 1, optionPrompts[i]);
  }

  printf("\n0. Exit\n");

  // While option is out of range...
  while (option < 0 || option > (sizeof(functions) / sizeof(functions[0]))) {
    printf("\nChoose an option: ");
    scanf("%d", &option);
  }

  // Exit if option is 0
  if (option == 0) {
    return 0;
  }

  // Run the selected task
  return functions[option - 1]();
}
