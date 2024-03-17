

#include <stdio.h>

int is_happy_number(int n) {
    int sum = 0;
    int product = 1;
    while (n > 0) {
        int digit = n % 10;
        sum += digit;
        product *= digit;
        n /= 10;
    }
    return sum == product;
}

int main() {
    int n;
    printf("Enter two positive integers: ");
    scanf("%d", &n);
    if (is_happy_number(n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
