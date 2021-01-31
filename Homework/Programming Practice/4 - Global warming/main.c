#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_YEAR 1900
#define MAX_YEAR 2017
#define YEARS (MAX_YEAR - MIN_YEAR)

#define MAX_TEMP 32
#define MIN_TEMP 14
#define MAX_TEMP_DIFF (MAX_TEMP - MIN_TEMP)

double summerTemp[YEARS] = {0};
double meanTemp = 0;

char* getOutput(double fourYearAvg);

int main() {
  setbuf(stdin, NULL);

  srand(time(NULL));

  for (int i = 0; i < YEARS; i++) {
    // get random temp
    double randomTemp = (double)(rand() % (MAX_TEMP_DIFF * 100)) / 100 + MIN_TEMP;
    summerTemp[i] = randomTemp;
    meanTemp += randomTemp;
    // printf("%f\n", randomTemp);
  }

  // calculate mean
  meanTemp /= YEARS;

  int chosenYear = 0;

  while (chosenYear > (MAX_YEAR - 3) || chosenYear < MIN_YEAR) {
    printf("Choose year to check: ");
    scanf("%d", &chosenYear);
    printf("\n");
  }

  double fourYearAvg = 0.0;
  int yearOffset = chosenYear - MIN_YEAR;

  // TODO: Refactor to iteration and convert the number of years to check with to #define var.
  fourYearAvg = 0.25 * (summerTemp[yearOffset] + summerTemp[yearOffset + 1] +
                        summerTemp[yearOffset + 2] + summerTemp[yearOffset + 3]);

  printf("Four year average    Total average   Output\n");
  printf("%.1f *C              %.1f *C         %s\n", fourYearAvg, meanTemp,
         getOutput(fourYearAvg));

  return 0;
}

char* getOutput(double fourYearAvg) {
  if (fourYearAvg <= meanTemp - 4)
    return "Cool";
  else if (fourYearAvg >= meanTemp + 4)
    return "Hot";
  else
    return "Average";
}
