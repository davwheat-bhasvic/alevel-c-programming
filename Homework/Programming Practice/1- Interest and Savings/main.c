#include <stdio.h>
#include <math.h>

#define ANNUAL_INTEREST 1.1

double CalculateInterest(double start, double interestPct, int period) {
    return start * pow(interestPct, period);
}

double MoneyRound(double num) {
    // round to 2 dp
    return round(num * 100) / 100;
}

int printTableHeader() {
    printf("%-10s%-10s%-10s%-10s%-10s\n", "Year", "Start", "Paid in", "Interest", "Final");
}

int printData(const int year, const double startingYearBalance, const double paidIn, const double endBalance) {
    printf("%-10d%-10.2lf%-10.2lf%-10.2lf%-10.2lf\n", year, MoneyRound( startingYearBalance), paidIn,
           endBalance - startingYearBalance - paidIn, endBalance);
}

int main() {
    double payIn = 0, currentBalance = 0;
    int years = 0;

    printf("How much will you pay in every year?");
    scanf("%lf", &payIn);

    printf("How many years will you save for?");
    scanf("%d", &years);

    payIn = MoneyRound(payIn);

    printTableHeader();

    for (int year = 1; year <= years; year++) {
        const double startingBalance = currentBalance;
        currentBalance += payIn;
        currentBalance = CalculateInterest(currentBalance, ANNUAL_INTEREST, 1);
        printData(year, startingBalance, payIn, currentBalance);
    }

    return 0;
}
