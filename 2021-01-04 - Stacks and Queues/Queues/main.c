#include <stdlib.h>
#include <stdio.h>

void enqueue();

void dequeue();

void printQ();

int Q[10] = {-1}, front = 0, rear = 0, inQ = 0;
//line 11 works out the size of my array by dividing the array
//reserved memory by the data type it finds in the first index
int qSize = sizeof(Q) / sizeof(Q[0]);

int main() {
  int choice = 0;
  do {
    printf("Do you want to add(1), remove(2) or quit(3)?: ");
    scanf_s("%d", &choice);
    if (choice == 1) {
      enqueue();
    } else if (choice == 2) {
      dequeue();
    } else if (choice == 3) {
      break;
    } else {
      printf("Enter a valid choice.");
    }
  } while (choice != 3);
  return -1;
}

void printQ() {
  printf("\n");
  for (int i = 0; i < qSize; i++) {
    printf("%d | ", Q[i]);
  }
  printf("\n\n");
}

void enqueue() {
  int insert = 0;

  if (inQ >= qSize) {
    // queue is full
    printf("\n\n=== OVERFLOW ===\n\n");
    return;
  }

  printf("\n\nEnter number to enqueue: ");
  scanf_s("%d", &insert);

  Q[rear] = insert;

  rear++;
  inQ++;

  if (rear + 1 >= qSize) {
    // max rear
    rear = 0;
  }

  printf("\n");
  printQ();
}

void dequeue() {
  if (inQ <= 0) {
    printf("\n\n=== UNDERFLOW ===\n\n");
    return;
  }

  int val = Q[front];
  Q[front] = 0;

  inQ--;
  front++;

  if (front + 1 >= qSize) {
    // max front
    front = 0;
  }

  printQ();
}






