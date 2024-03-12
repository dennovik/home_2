
#include <stdio.h>

int main() {
    int number;
    printf("Enter number: ");
    scanf("%d", &number);

    int min_digit = number % 10;
    int max_digit = min_digit;

    while (number > 0) {
        int digit = number % 10;
        if (digit < min_digit) {
            min_digit = digit;
        }
        if (digit > max_digit) {
            max_digit = digit;
        }
        number /= 10;
    }

    printf("Lowest number: %d\n", min_digit);
    printf("Highest figure:: %d\n", max_digit);

    return 0;
}
