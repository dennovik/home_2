
#include <stdio.h>

int sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int n;
    printf("Enter a positive integer N: ");
    scanf("%d", &n);
    printf("Sum of numbers from 1 to N: %d\n", sum(n));
    return 0;
}
