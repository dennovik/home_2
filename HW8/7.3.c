#include <stdio.h>

void print_odd_numbers(int* numbers, int size) {
    for (int i = 0; i < size; i++) {
        if (numbers[i] % 2 != 0) {
            printf("%d ", numbers[i]);
        }
    }
}

int main() {
    int numbers[100];
    int size = 0;
    int number;
    printf("Enter a sequence of space-separated integers ending with 0: ");
    while ((scanf("%d", &number) == 1) && (number != 0)) {
        numbers[size++] = number;
    }
    print_odd_numbers(numbers, size);
    return 0;
}
