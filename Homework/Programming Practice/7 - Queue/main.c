#include <stdlib.h>
#include <stdio.h>

void enqueue();

void dequeue();

void printQ();

#define QUEUE_SIZE 10

//declare the queue and the pointers needed
int queue[QUEUE_SIZE] = {}, front = 0, rear = 0, inQ = 0;

int main() {
  int choice = 0;
  do {
    //ask what they want to do
    printf("\nDo you want to add(1), remove(2) or quit(3)?: ");
    scanf_s("%d", &choice);
    //call the correct function or quit
    if (choice == 1) {
      enqueue();
    } else if (choice == 2) {
      dequeue();
    } else if (choice == 3) {
      break;
    } else {
      printf("\nEnter a valid choice.");
    }
  } while (choice != 3);
}

void printQ() {
  //prints out the queue array
  printf("\n");
  for (int i = 0; i < QUEUE_SIZE; i++) {
    printf(" %d |", queue[i]);
  }
  printf("\n\n");
}

void enqueue() {
  if (inQ == QUEUE_SIZE) {
    printf("\n\nQueue is full!\n");
    return;
  }

  int input = -1;

  printf("\nData to enqueue: ");
  scanf_s("%d", &input);
  printf("\n");

  ++inQ;
  queue[rear++] = input;

  printQ();
}

void dequeue() {
  if (inQ == 0) {
    printf("\n\nQueue is empty!\n");
    return;
  }

  int data = queue[front];
  queue[front++] = -1;

  printf("Dequeued %d", data);
}