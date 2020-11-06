#include <ctype.h>
#include <stdio.h>

int main() {
  char tempResp = ' ';

  int landAnimal = 0, flying = 0, honey = 0, stinging = 0, fourLegs = 0, tail = 0, fur = 0,
      domesticated = 0, fetch = 0, stripy = 0, orangeFur = 0, foodSource = 0, farmMilk = 0,
      bwFur = 0, intelligent = 0;

  printf("Is it a land animal? (Y/N)");
  scanf(" %c", &tempResp);
  if (tolower(tempResp) == 'y')
    landAnimal = 1;

  if (landAnimal) {
    printf("Does the animal have 4 legs? (Y/N)");
    scanf(" %c", &tempResp);
    if (tolower(tempResp) == 'y')
      fourLegs = 1;

    if (!fourLegs) {
      printf("Does the animal fly? (Y/N)");
      scanf(" %c", &tempResp);
      if (tolower(tempResp) == 'y')
        flying = 1;

      if (flying) {
        printf("Does the animal sting humans? (Y/N)");
        scanf(" %c", &tempResp);
        if (tolower(tempResp) == 'y')
          stinging = 1;

        printf("Does the animal produce honey? (Y/N)");
        scanf(" %c", &tempResp);
        if (tolower(tempResp) == 'y')
          honey = 1;
      }
    }

    printf("Does the animal have a tail? (Y/N)");
    scanf(" %c", &tempResp);
    if (tolower(tempResp) == 'y')
      tail = 1;

    printf("Is the animal often kept as a pet? (Y/N)");
    scanf(" %c", &tempResp);
    if (tolower(tempResp) == 'y')
      domesticated = 1;

    printf("Does the animal play fetch? (Y/N)");
    scanf(" %c", &tempResp);
    if (tolower(tempResp) == 'y')
      fetch = 1;

    printf("Does the animal have fur/wool? (Y/N)");
    scanf(" %c", &tempResp);
    if (tolower(tempResp) == 'y')
      fur = 1;
  } else {
    printf("Is the animal seen as very intelligent? (Y/N)");
    scanf(" %c", &tempResp);
    if (tolower(tempResp) == 'y')
      intelligent = 1;
  }

  if (fur) {
    printf("Is the animal stripy? (Y/N)");
    scanf(" %c", &tempResp);
    if (tolower(tempResp) == 'y')
      stripy = 1;

    printf("Does the animal have orange fur? (Y/N)");
    scanf(" %c", &tempResp);
    if (tolower(tempResp) == 'y')
      orangeFur = 1;

    if (!orangeFur) {
      printf("Does the animal have black and white fur? (Y/N)");
      scanf(" %c", &tempResp);
      if (tolower(tempResp) == 'y')
        bwFur = 1;
    }
  }

  printf("Do we farm the animal for food? (Y/N)");
  scanf(" %c", &tempResp);
  if (tolower(tempResp) == 'y')
    foodSource = 1;

  printf("Do we mass farm the animal's milk? (Y/N)");
  scanf(" %c", &tempResp);
  if (tolower(tempResp) == 'y')
    farmMilk = 1;

  if (landAnimal) {
    if (fourLegs) {
      if (tail) {
        if (domesticated) {
          if (fetch) {
            // land animal, 4 legs, has tail, held as pet, plays
            // fetch
            printf("Is it a dog?");
          } else {
            // land animal, 4 legs, has tail, held as pet, does NOT
            // plays fetch
            printf("Is it a cat?");
          }
        } else if (stripy) {
          if (orangeFur) {
            // land animal, 4 legs, has tail, NOT held as pet,
            // stripy fur, orange fur
            printf("Is it a tiger?");
          } else {
            // land animal, 4 legs, has tail, NOT held as pet,
            // stripy fur, NOT orange fur
            printf("Is it a zebra?");
          }
        } else {
          if (orangeFur) {
            // land animal, 4 legs, has tail, NOT held as pet, NOT
            // stripy, orange fur
            printf("Is it a lion?");
          } else if (foodSource) {
            if (farmMilk) {
              // land animal, 4 legs, has tail, NOT held as pet,
              // farmed for food, farmed for milk
              printf("Is it a cow?");
            } else {
              if (fur) {
                // land animal, 4 legs, has tail, NOT held as
                // pet, farmed for food, farmed for milk, has
                // wool
                printf("Is it a sheep?");
              } else {
                // land animal, 4 legs, has tail, NOT held as
                // pet, farmed for food, has NO fur
                printf("Is it a pig?");
              }
            }
          }
        }
      }
    } else {
      if (flying) {
        if (stinging) {
          if (honey) {
            printf("Is it a bee?");
          } else {
            printf("Is it a wasp?");
          }
        } else {
          printf("Is it a sparrow?");
        }
      } else {
        if (fur && bwFur) {
          printf("Is it a penguin?");
        }
      }
    }
  } else {
    if (intelligent) {
      // sea animal and smart
      printf("Is it a dolphin?");
    }
  }

  return 0;
}
