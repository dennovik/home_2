

#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    printf("Enter a positive integer not greater than 20: ");
    scanf("%d", &n);
    printf("Factorial number: %d\n", factorial(n));
    return 0;
}
