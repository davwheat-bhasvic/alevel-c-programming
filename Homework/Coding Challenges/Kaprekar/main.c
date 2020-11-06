#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define TO_INT(x) (int)(x + 0.5)

int splitDigits(int digitsArray[], int number, int digitCount) {
  int tempNum = number;

  // split each digit of the number into the array
  for (int d = digitCount; d > 0; d--) {
    digitsArray[d - 1] = tempNum % 10;
    tempNum /= 10;
  }

  return 0;
}

int getDigitCount(int number) {
  // algorithm mindlessly stolen from stackoverflow
  // https://stackoverflow.com/a/1068870/11091039
  return number == 0 ? 1 : TO_INT(floor(log10(abs(number))) + 1);
}

int reassembleNumberFromDigitArray(const int digits[], int digitCount) {
  int number = 0;
  int index = 0;

  for (int power = digitCount - 1; power >= 0; power--) {
    int multiplier = TO_INT(pow(10, power));
    number += digits[index] * multiplier;
    index++;
  }

  return number;
}

// Only used in debugging
// int printArray(int arr[], int length) {
//    for (int i = 0; i < length; i++) {
//        printf("%d ", arr[i]);
//    }
//
//    printf("\n");
//
//    return 0;
//}

int main() {
  int number = 0;

  printf("Enter a number to see if it is a Kaprekar number:");
  scanf("%d", &number);

  // get the amount of digits in the inputted number
  int digitCount = getDigitCount(number);
  int allDigits[digitCount];

  // split the number into an array of digits (allDigits)
  splitDigits(allDigits, number, digitCount);

  // square the number
  int numberSquared = TO_INT(pow(number, 2));
  int numberSquaredDigitCount = getDigitCount(numberSquared);

  // split the squared number into an array of digits
  int numberSquaredDigits[numberSquaredDigitCount];
  splitDigits(numberSquaredDigits, numberSquared, numberSquaredDigitCount);

  // find the index at which the squared number should be split at
  int splitNumberAtDigit = numberSquaredDigitCount - digitCount;

  // prepare the arrays for each halves of the split number
  int num1array[splitNumberAtDigit];
  int num2array[numberSquaredDigitCount - splitNumberAtDigit];

  // split the number into each array
  for (int i = 0; i < numberSquaredDigitCount; i++) {
    if (i < splitNumberAtDigit) {
      num1array[i] = numberSquaredDigits[i];
    } else {
      num2array[i - splitNumberAtDigit] = numberSquaredDigits[i];
    }
  }

  // turn the arrays into ints again
  int num1 = reassembleNumberFromDigitArray(num1array, ARRAY_SIZE(num1array));
  int num2 = reassembleNumberFromDigitArray(num2array, ARRAY_SIZE(num2array));

  //    printf("%d %d", num1, num2);

  // sum the numbers
  int sqNumsSum = num1 + num2;

  // if the sum is the same as the starting number, it's a Kaprekar number
  if (sqNumsSum == number) {
    printf("%d is a Kaprekar number!", number);
  } else {
    printf("%d is NOT a Kaprekar number.", number);
  }

  return 0;
}
