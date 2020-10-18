#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr)     (sizeof(arr) / sizeof((arr)[0]))
#define TO_INT(x)           (int)(x + 0.5)

int splitDigits(int digitsArray[], int number, int digitCount) {
    int tempNum = number;

    // split each digit of the number into the allDigits array
    for (int d = digitCount; d > 0; d--) {
        digitsArray[d - 1] = tempNum % 10;
        tempNum /= 10;
    }

    return 0;
}

int getDigitCount(int number) {
    return number == 0 ? 1 : TO_INT(floor(log10(abs(number))) + 1);
}

int reassembleNumberFromDigitArray(const int digits[], int digitCount) {
    int number = 0;
    int index = 0;

    for (int power = digitCount - 1; power >= 0; power--) {
        int multiplier = TO_INT(pow(10, power));
//        int add = digits[index] * multiplier;
//        printf("%d * %d = %d\n", digits[index], multiplier, add);
        number += digits[index] * multiplier;
        index++;
    }

    return number;
}

int printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}

int main() {
    int number = 0;

    printf("Enter a number to see if it is a Kaprekar number:");
    scanf("%d", &number);

    // get the amount of digits in the inputted number
    int digitCount = getDigitCount(number);
    int allDigits[digitCount];

    splitDigits(allDigits, number, digitCount);

    int numberSquared = TO_INT (pow(number, 2));
    int numberSquaredDigitCount = getDigitCount(numberSquared);

    int numberSquaredDigits[numberSquaredDigitCount];
    splitDigits(numberSquaredDigits, numberSquared, numberSquaredDigitCount);

    int splitNumberAtDigit = numberSquaredDigitCount - digitCount;

    int num1array[splitNumberAtDigit];
    int num2array[numberSquaredDigitCount - splitNumberAtDigit];

    for (int i = 0; i < numberSquaredDigitCount; i++) {
        if (i < splitNumberAtDigit) {
            num1array[i] = numberSquaredDigits[i];
        } else {
            num2array[i - splitNumberAtDigit] = numberSquaredDigits[i];
        }
    }

    int num1 = reassembleNumberFromDigitArray(num1array, ARRAY_SIZE(num1array));
    int num2 = reassembleNumberFromDigitArray(num2array, ARRAY_SIZE(num2array));

//    printf("%d %d", num1, num2);

    int sqNumsSum = num1 + num2;

    if (sqNumsSum == number) {
        printf("%d is a Kaprekar number!", number);
    } else {
        printf("%d is NOT a Kaprekar number.", number);
    }

    return 0;
}
