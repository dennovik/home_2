
#include <stdio.h>

int main() {
    int number;
    printf("Input number: ");
    scanf("%d", &number);

    int digit1 = number % 10;
    int digit2 = (number / 10) % 10;
    int digit3 = (number / 100) % 10;

    int product = digit1 * digit2 * digit3;

    printf("product: %d\n", product);

    return 0;
}
