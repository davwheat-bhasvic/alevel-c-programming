#include <stdio.h>

void testCount(int max);

int main() {
    int loop = 0;
    puts("Enter number of times to loop.");

    scanf_s("%i", &loop);

    if (loop > 10e4) {
        puts("Ha, no I'm not looping for *that* long!");
    } else {
        testCount(loop);
    }

    return 0;
}

void testCount(const int max) {
    for (int i = 0; i < max; i++) {
        printf("Currently at %d\n", i + 1);
    }

    puts("Void function complete");
}