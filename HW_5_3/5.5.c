

#include <stdio.h>

int main() {
    int number;
    printf("Enter a natural number: ");
    scanf("%d", &number);

    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }

    if (sum == 10) {
        printf("YES 10\n");
    } else {
        printf("NO 10\n");
    }

    return 0;
}
