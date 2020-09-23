#include <stdio.h>
#include <time.h>
#include <stdlib.h>

srand((unsigned int)
time(NULL)
);

int getRandom(int min_incl = 0, int max_excl = 2) {
    int r = rand();
    return (r % max_excl) + min_incl;
}

bool isPrime(int num) {
    if (num == 2 || num == 3) return true;
    if (num == 0 || num == 1) return false;

    // handle negative nums
    int n = abs(num);

    if (n % 2 == 0) return false;

    // no need to check against even nums
    // as all even nums are divisible by 2
    // so above statement handles them
    for (int i = 3; i < num; i += 2) {
        if (i >= num) continue;

        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int primeOrCompositeTask() {
    printf("%d %d %d %d", isPrime(1), isPrime(2),
           isPrime(5),
           isPrime(15));

    return 0;
}
