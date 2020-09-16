#include <stdio.h>
#include <math.h>

int task1() {
    int numberOfWalls = 0;
    float lengthOfWalls = 0;
    float heightOfWalls = 0;

    const float bricksPerMetreRow = 1.5;
    const float bricksPerPallet = 100;

    printf("\nEnter number of walls:");
    scanf("%d", &numberOfWalls);
    printf("\nEnter length of walls:");
    scanf("%f", &lengthOfWalls);
    printf("\nEnter height of walls (rows of bricks):");
    scanf("%f", &heightOfWalls);

    const float bricksNeeded = numberOfWalls * lengthOfWalls * heightOfWalls * bricksPerMetreRow;

    printf("\nYou need %f bricks.", bricksNeeded);
    printf("\nThis equates to %f pallets (with %f bricks spare)", ceil(bricksNeeded / bricksPerPallet),
           bricksPerPallet - remainder(bricksNeeded, bricksPerPallet));

    return 0;
}