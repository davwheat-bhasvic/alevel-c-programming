#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Determines if the program should run in debug
// mode or in production mode
#define IS_DEBUG 0

Present presentList[PresentCount];
House KidsInStreet[StreetCount][HouseCount];

void PropagatePresentList();
void FillKidsInStreet();
void PrefillPresentList();

House FillHouseWithPresents(int streetNum, int houseNum);

Present ChooseRandomPresent();
int IsValidPresentCombo(Present* presents, int childCount);

void DisplaySpendPerStreet();

void main() {
  // Fix no output from debugger
  setbuf(stdout, NULL);

  srand(time(0));

  FillKidsInStreet();

#if IS_DEBUG == 1
  // Use prefilled list of presents for debugging
  PrefillPresentList();
#else
  // But ask the elves for Production
  PropagatePresentList();
#endif

  printf("Done.");

  /**
   * Fill the houses with presents! Who doesn't like free stuff?!
   */
  for (int street = 0; street < StreetCount; street++) {
    for (int house = 0; house < HouseCount; house++) {
      KidsInStreet[street][house] = FillHouseWithPresents(street, house);
    }
  }

  /**
   * Print info about spending in each street (as per brief).
   */
  DisplaySpendPerStreet();
}

/**
 * Fills up the presentList with the amount of presents
 * defined in `main.h` (PresentCount).
 */
void PropagatePresentList() {
  for (int i = 0; i < PresentCount; i++) {
    Present thisPresent;
    char description[64], priceStr[64];
    double price;

    /**
     * Get present details from user
     */
    puts("Enter present name:");
    fgets(description, sizeof(description), stdin);
    // fgets likes keeping the \n at the end of strings, so this removes it
    RemoveFinalNewLine(description);

    puts("Enter present price:");
    fgets(priceStr, sizeof(priceStr), stdin);

    /**
     * Parse string price as double
     */
    sscanf_s(priceStr, "%lf", &price);

    /**
     * Propagate struct fields
     */
    thisPresent.price = price;
    strcpy_s(thisPresent.description, sizeof(thisPresent.description), description);

    /**
     * Set present at index i to be thisPresent
     */
    presentList[i] = thisPresent;
  }
}

/**
 * A copy of `PropagatePresentList` with predefined values
 * for testing purposes.
 */
void PrefillPresentList() {
  char descriptions[10][64] = {
      "Doll",   "Board Game", "Rocking Horse", "Magic Kit", "24 Pack Toilet Paper",
      "Gift A", "Gift B",     "Gift C",        "Gift D",    "Gift E"};
  double prices[10] = {5.00, 12.99, 8.00, 5.49, 5.99, 6, 7, 8, 15, 11};

  for (int i = 0; i < PresentCount; i++) {
    Present thisPresent;

    strcpy_s(thisPresent.description, sizeof(thisPresent.description), descriptions[i]);
    thisPresent.price = prices[i];

    presentList[i] = thisPresent;
  }
}

/**
 * Populate `KidsInStreet` with 2D arrays of Houses.
 */
void FillKidsInStreet() {
  for (int street = 0; street < StreetCount; street++) {
    for (int house = 0; house < HouseCount; house++) {
      // get random number of children
      const int children = GenerateRandom(1, MaxChildrenPerHouse);

      // initialise new house variable
      House thisHouse;

      thisHouse.totalPresentCost = 0;
      thisHouse.childrenAtHouse = children;
      // reserve memory for the list of gifts
      // list contains one gift per child, so we reserve
      // a memory space equal to childCOunt * size of Present struct
      thisHouse.childGifts = calloc(sizeof(Present), children);

      // assign this House to the right KidsInStreet location
      KidsInStreet[street][house] = thisHouse;
    }
  }
}

House FillHouseWithPresents(int streetNum, int houseNum) {
  if (streetNum >= StreetCount || houseNum >= HouseCount) {
    // Invalid street number or house number
    House house;
    house.wasInvalid = 1;
    return house;
  }

  House thisHouse = KidsInStreet[streetNum][houseNum];

  if (thisHouse.childrenAtHouse == 0) {
    // No children? No presents!
    return thisHouse;
  } else if (thisHouse.childrenAtHouse == 1) {
    // 1 child -> any present
    thisHouse.childGifts[0] = ChooseRandomPresent();
    thisHouse.totalPresentCost = thisHouse.childGifts[0].price;

    return thisHouse;
  } else {
    int childCount = thisHouse.childrenAtHouse;
    double spend = 0;

    // children > 1
    // avg present cost must be below 9 per child
    Present* housePresents = (Present*)calloc(sizeof(Present), childCount);

    // while presents are invalid (>£9 on avg)
    do {
      // choose random presents for every child in the house
      for (int i = 0; i < childCount; i++) {
        housePresents[i] = ChooseRandomPresent();
      }
    } while (!IsValidPresentCombo(housePresents, childCount));

    // assign presents to house
    for (int i = 0; i < childCount; i++) {
      thisHouse.childGifts[i] = housePresents[i];
      spend += housePresents[i].price;
    }

    // add total present spend to house's info
    thisHouse.totalPresentCost = spend;

    return thisHouse;
  }
}

/**
 * Choose a random present from the list of available presents
 */
Present ChooseRandomPresent() {
  return presentList[GenerateRandom(0, PresentCount - 1)];
}

/**
 * Determines if the list of presents in a multi-child household
 * is a valid combination.
 *
 * @param presents list of presents in household
 * @param childCount number of children in household
 * @return truthy for valid, falsey for invalid
 */
int IsValidPresentCombo(Present* presents, int childCount) {
  double totalPrice = 0;

  for (int i = 0; i < childCount; i++) {
    totalPrice += presents[i].price;
  }

  // truthy if average cost is below max average cost per child
  return (totalPrice / childCount) <= MaxAvgPresentCostPerChild;
}

void DisplaySpendPerStreet() {
  for (int street = 0; street < StreetCount; street++) {
    // reserve enough memory for the list of houses on the street...
    House* thisStreet = calloc(sizeof(House), HouseCount);
    // ...so that we can copy the street data from the main array to thisStreet
    memcpy_s(thisStreet, sizeof(House) * HouseCount, KidsInStreet[street],
             sizeof(KidsInStreet[street]));

    printf("\n\n=== STREET %d ===\n", street + 1);

    double avgSpendPerHouse, avgSpendPerGift, totalSpend = 0;
    int giftCount = 0;

    // iterate through houses on the street
    for (int house = 0; house < HouseCount; house++) {
      House thisHouse = thisStreet[house];

      // track total present spend
      totalSpend += thisHouse.totalPresentCost;
      // we have 1 gift per child, so we can use the child count
      // as a substitution for the number of gifts
      giftCount += thisHouse.childrenAtHouse;
    }

    // calculate other info to display
    avgSpendPerHouse = totalSpend / HouseCount;
    avgSpendPerGift = totalSpend / giftCount;

    // display the super super cool info
    // for the totally-real santa
    printf("Total spend:          GBP %.2lf\n", totalSpend);
    printf("Avg spend per house:  GBP %.2lf\n", avgSpendPerHouse);
    printf("Avg spend per gift:   GBP %.2lf\n", avgSpendPerGift);
  }
}
