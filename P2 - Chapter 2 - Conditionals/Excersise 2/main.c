#include <stdio.h>
#include <ctype.h>

int main() {
    char whenChoice;
    int adultTickets = 0, childTickets = 0;

    // Group discount as a decimal (0.1 = 10%)
    float groupDiscountPct = 0.1;
    // Group discount minimum people (excl, not incl)
    int groupDiscountMinPeople = 8;

    printf("When would you like to go on holiday? Weekdays, Sat/Sun, or a bank holiday? (W/S/B)");
    scanf(" %c", &whenChoice);

    printf("\nHow many adult tickets do you need?", &adultTickets);
    scanf("%d", &adultTickets);
    printf("How many child tickets do you need?", &childTickets);
    scanf("%d", &childTickets);

    float childPrice, adultPrice;

    switch (tolower(whenChoice)) {
        default:
            printf("\nInvalid day selection! Assuming weekday.");
        case 'w':
            childPrice = 5, adultPrice = 8;
            break;
        case 's':
            childPrice = 7.5, adultPrice = 12;
            break;
        case 'b':
            childPrice = 7.5, adultPrice = 12;
            break;
    }

    int groupDiscount = adultTickets + childTickets > groupDiscountMinPeople;
    float totalAdultPrice = adultPrice * (float) adultTickets;
    float totalChildPrice = childPrice * (float) childTickets;

    if (groupDiscount) {
        adultPrice *= 1.0 - groupDiscountPct;
        childPrice *= 1.0 - groupDiscountPct;
    }

    printf("\nAdult price: GBP %f", adultPrice);
    printf("\nChild price: GBP %f", childPrice);
    groupDiscount && printf("\n(including the %f percent group discount)", groupDiscountPct * 100);

    printf("\n\n%d x Adult = GBP %f", adultTickets, totalAdultPrice);
    printf("\n%d x Child = GBP %f", childTickets, totalChildPrice);

    printf("\n\nTotal price: GBP %f", totalAdultPrice + totalChildPrice);

    return 0;
}
