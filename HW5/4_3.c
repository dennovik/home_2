#include <stdio.h>

int main() {
    int number;
    printf("Enter number: ");
    scanf("%d", &number);

    int a = number % 10;
    int b = (number / 10) % 10;
    int c = (number / 100) % 10;

    int max_digit = a;
    max_digit =  a > b ?  a : b;
    max_digit = max_digit> c ? max_digit: c;
    
    printf("Max digit: %d\n", max_digit);

    return 0;
}

