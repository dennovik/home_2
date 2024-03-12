#include <stdio.h>

int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);

    int length = snprintf(NULL, 0, "%d", number);
    for (int i = 0; i < length - 1; i++) {
        if (number % 10 == (number / 10 % 10)) {
            printf("YES\n");
            return 0;
        }
        number /= 10;
    }

    printf("No\n");

    return 0;
}
