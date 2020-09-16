#include <stdio.h>

#include "task1.h"
#include "task2.h"

int main() {
    const int Tasks = 2;
    int option = -1;

    const char *optionPrompts[Tasks] = {"Task 1", "Task 2"};

    // Array of functions
    const int (*functions[Tasks])() = {task1, task2};

    for (int i = 0; i < sizeof(functions) / sizeof(functions[0]); i++) {
        printf("%d. %s\n", i + 1, optionPrompts[i]);
    }

    printf("\n0. Exit\n");


    while (option < 0 || option > (sizeof(functions) / sizeof(functions[0]))) {
        printf("\nChoose an option: ");
        scanf("%d", &option);
    }

    if (option == 0) {
        return 0;
    }

    return functions[option - 1]();

    return 0;
}