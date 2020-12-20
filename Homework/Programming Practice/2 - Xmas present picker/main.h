#ifndef INC_2___XMAS_PRESENT_PICKER_MAIN_H
#define INC_2___XMAS_PRESENT_PICKER_MAIN_H

#define PresentCount 10
#define StreetCount 10
#define HouseCount 10

// If a house has more than 10 children... eek!
#define MaxChildrenPerHouse 10
#define MaxAvgPresentCostPerChild 9

#define RemoveFinalNewLine(arr) (arr[strcspn(arr, "\n")] = '\0')
#define GenerateRandom(minIncl, maxIncl) ((rand() % (maxIncl - minIncl + 1)) + minIncl)

typedef struct {
  char description[64];
  double price;
  int wasInvalid;
} Present;

typedef struct {
  Present* childGifts;
  double totalPresentCost;
  int childrenAtHouse;
  int wasInvalid;
} House;

#endif  // INC_2___XMAS_PRESENT_PICKER_MAIN_H
