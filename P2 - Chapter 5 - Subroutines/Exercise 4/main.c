#include <stdio.h>

#define SCORE_COUNT 5
#define MIN_SCORE 0
#define MAX_SCORE 75

void editScores(int scores[SCORE_COUNT]);

void printScores(int scores[SCORE_COUNT]);

int main() {
  int scores[SCORE_COUNT] = {MIN_SCORE - 1, MIN_SCORE - 1, MIN_SCORE - 1, MIN_SCORE - 1,
                             MIN_SCORE - 1};

  for (int i = 0; i < SCORE_COUNT; i++) {
    while (scores[i] < MIN_SCORE || scores[i] > MAX_SCORE) {
      printf("Enter score %d:", i + 1);
      scanf_s("%i", &scores[i]);
      puts("");
    }
  }

  printScores(scores);
  editScores(scores);
  printScores(scores);

  return 0;
}

void editScores(int scores[SCORE_COUNT]) {
  for (int i = 0; i < SCORE_COUNT; i++) {
    if (scores[i] <= 20) {
      scores[i] = 0;
    }
  }
}

void printScores(int scores[SCORE_COUNT]) {
  printf("Scores: ");
  for (int i = 0; i < SCORE_COUNT; i++) {
    printf(i == SCORE_COUNT - 1 ? "%d\n" :  // last val, finish with new line no command
               "%d, ",                      // not last val, add comma
           scores[i]);
  }
}