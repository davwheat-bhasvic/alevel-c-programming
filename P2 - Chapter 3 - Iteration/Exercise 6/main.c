#include <stdio.h>

int main() {
  int length = 10;

  for (int i = 0; i <= length; i++) {
    for (int j = 0; j < length; j++) {
      char out[] = "Y";

      if (j < length - i)
        out[0] = 'X';

      printf("%s", out);
    }

    printf("\n");
  }

  return 0;
}
