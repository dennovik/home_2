
#include <stdio.h>

void print_num(int num) {
    if (num == 0) {
        return;
    } else {
        print_num(num / 10); //Рекурсивный вызов с оставшимися цифрами
        printf("%d ", num % 10); // Печатаем последнюю цифру
    }
}

int main() {
    int number;
    printf("Enter a natural number: ");
    scanf("%d", &number);

    printf("Digits in direct order: ");
    print_num(number);

    return 0;
}
