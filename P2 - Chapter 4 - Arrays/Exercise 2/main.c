#include <stdio.h>

int main() {
  int nums[3];

  printf("Enter num 1");
  scanf("%d", &nums[0]);
  printf("Enter num 2");
  scanf("%d", &nums[1]);
  printf("Enter num 3");
  scanf("%d", &nums[2]);

  // rule 1
  if ((nums[0] + nums[1] + nums[2]) % 3 != 0) {
    printf("invalid 1");
  } else if (
      // rule 2 - checks if item is one less than last
      nums[2] - nums[0] == 1 || nums[0] - nums[1] == 1 || nums[1] - nums[2] == 1) {
    printf("invalid 2");
  } else {
    printf("valid");
  }

  return 0;
}
