#include <stdio.h>

int Q[10], rear = 0;
const int stackSize = sizeof(Q) / sizeof(Q[0]);

void push();

void pop();

int main() {

  int choice = 0;
  do {
    printf("Do you want to add(1), remove(2) or quit(3)?: ");
    scanf("%d", &choice);
    if (choice == 1) {
      push();
    } else if (choice == 2) {
      pop();
    } else if (choice == 3) {
      break;
    } else {
      printf("Enter a valid choice.\n");
    }
  } while (choice != 3);
  return -1;
}

void push() {
  int input = 0;

  if (rear + 1 >= stackSize) {
    printf("No room\n");
    return;
  }

  printf("\nEnter number to add:");
  scanf_s("%d", &input);

  Q[rear] = input;
  rear++;
}

void pop() {
  if (rear == 0) {
    printf("Nothing to pop!\n");
    return;
  }

  rear--;
  int val = Q[rear];
  Q[rear] = 0;
  printf("\nPopped %d", val);
}