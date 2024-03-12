

#include <stdio.h>

int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);

    int length = snprintf(NULL, 0, "%d", number);
    int count_nines = 0;
    for (int i = 0; i < length; i++) {
        if (number % 10 == 9) {
            count_nines++;
        }
        number /= 10;
    }

    if (count_nines == 1) {
        printf("Yes, there is exactly one digit in the number 9\n");
    } else {
        printf("No, there is not exactly one digit in the number 9\n");
    }

    return 0;
}
