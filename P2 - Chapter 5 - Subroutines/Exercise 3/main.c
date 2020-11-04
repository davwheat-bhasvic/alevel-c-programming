#include <stdio.h>
#include <ctype.h>

float add(float a, float b);

float sub(float a, float b);

float mult(float a, float b);

float div(float a, float b);

int main() {
    float user1 = 0, user2 = 0;
    char operation;

    printf("Enter first number:");
    scanf_s("%f", &user1);
    printf("Enter second number:");
    scanf_s("%f", &user2);

    printf("Choose your operation (+-*/):");
    scanf_s(" %c", &operation);

    switch (operation) {
        default:
            puts("Invalid operation");
            break;
        case '+':
            printf("%f + %f = %f", user1, user2, add(user1, user2));
            break;
        case '-':
            printf("%f - %f = %f", user1, user2, sub(user1, user2));
            break;
        case '*':
            printf("%f * %f = %f", user1, user2, mult(user1, user2));
            break;
        case '/':
            printf("%f / %f = %f", user1, user2, div(user1, user2));
            break;
    }

    return 0;
}

float add(float a, float b) {
    return a + b;
}

float sub(float a, float b) {
    return a - b;
}

float mult(float a, float b) {
    return a * b;
}

float div(float a, float b) {
    return a / b;
}