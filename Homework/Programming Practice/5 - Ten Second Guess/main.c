#include <stdio.h>
#include <time.h>
#include <math.h>

int main() {
  printf("Guess when 10 seconds has passed!\n\n");
  printf("Press ENTER to start.\n");

  getchar();
  printf("Press ENTER after 10 secs.\n");
  time_t startTime = time(NULL);

  getchar();
  time_t endTime = time(NULL);

  double secsDiff = difftime(endTime, startTime);

  printf("%.f seconds have passed. You were %.f seconds off.\n", secsDiff, fabs(secsDiff - 10.0));
}
