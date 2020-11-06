#include <stdio.h>
#include <string.h>

#define GRID_WIDTH 4
#define GRID_HEIGHT 4

int printGrid(int** grid) {
  for (int i = 0; i < GRID_HEIGHT; i++) {
    for (int j = 0; j < GRID_WIDTH; j++) {
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }

  return 0;
}

int removeBlocks(char grid[GRID_HEIGHT][GRID_WIDTH]) {
  printf("%c", grid[0][0]);

  // x is width, y is height;
  for (int y = 0; y < GRID_HEIGHT; y++) {
    for (int x = 0; x < GRID_WIDTH; x++) {
      char source = grid[y][x];

      int matches = 0;
      int indexes[GRID_HEIGHT * GRID_WIDTH][2];

      int xOffset = 0;
      int wasMatch = 1;

      printf("Searching for %c from [%d][%d]...\n", source, y, x);
      while (xOffset - 1 >= 0 && wasMatch == 1) {
        xOffset--;
        wasMatch = 0;

        if (grid[y][x + xOffset] == source) {
          indexes[matches][1] = x + xOffset;
          indexes[matches][0] = y;
          matches++;
          wasMatch = 1;
          printf("matched %c at [%d][%d])\n", grid[y][x + xOffset], y, x + xOffset);
        }
      }

      wasMatch = 1;
      xOffset = 0;

      while (xOffset + 1 <= GRID_WIDTH && wasMatch == 1) {
        xOffset++;
        wasMatch = 0;

        if (grid[y][x + xOffset] == source) {
          indexes[matches][1] = x + xOffset;
          indexes[matches][0] = y;
          matches++;
          wasMatch = 1;
          printf("matched %c at [%d][%d])\n", grid[y][x + xOffset], y, x + xOffset);
        }
      }

      wasMatch = 1;
      int yOffset = 0;

      printf("Searching for %c from [%d][%d]...\n", source, y, x);
      while (yOffset - 1 >= 0 && wasMatch == 1) {
        yOffset--;
        wasMatch = 0;

        if (grid[y + yOffset][x] == source) {
          indexes[matches][1] = x;
          indexes[matches][0] = y + yOffset;
          matches++;
          wasMatch = 1;
          printf("matched %c at [%d][%d])\n", grid[y + yOffset][x], y + yOffset, x);
        }
      }

      wasMatch = 1;
      yOffset = 0;

      while (yOffset - 1 <= GRID_HEIGHT && wasMatch == 1) {
        yOffset++;
        wasMatch = 0;

        if (grid[y + yOffset][x] == source) {
          indexes[matches][1] = x;
          indexes[matches][0] = y + yOffset;
          matches++;
          wasMatch = 1;
          printf("matched %c at [%d][%d])\n", grid[y + yOffset][x], y + yOffset, x);
        }
      }

      if (matches > 0)
        printf("Found a block of %d %c's\n", matches + 1, source);
    }
  }
}

int main() {
  char originalGrid[GRID_HEIGHT][GRID_WIDTH] = {
      {'R', 'R', 'G', 'B'}, {'G', 'R', 'B', 'G'}, {'R', 'R', 'G', 'B'}, {'G', 'B', 'R', 'B'}};

  char currentgrid[GRID_HEIGHT][GRID_WIDTH];
  memcpy(currentgrid, originalGrid, sizeof(char) * GRID_WIDTH * GRID_HEIGHT);

  //    currentgrid[0][0] = 'X';

  removeBlocks(currentgrid);

  return 0;
}
