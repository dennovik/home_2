

#include <stdio.h>

int main() {
    int number;
    printf("Enter a natural number: ");
    scanf("%d", &number);

    int even_count = 0;
    int odd_count = 0;

    while (number > 0) {
        int digit = number % 10;
        if (digit % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
        number /= 10;
    }

    printf("Number of even digits: %d\n", even_count);
    printf("Number of odd digits: %d\n", odd_count);

    return 0;
}
