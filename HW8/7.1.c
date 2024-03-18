
#include <stdio.h>

void printDit(int N) {// функция , которая принимает одно в обратном порядке
    if (N == 0) // ! 
    {
       return;// что мы достигли конца
    } else {
        printf("%d ", N % 10); // Печатаем последнюю цифру
        printDit(N / 10); // Рекурсивный вызов с оставшимися цифрами
    }
}

int main() {
    int number;
    printf("Enter  integer: ");
    scanf("%d", &number);

    printf("Digits in reverse order: ");
    printDit(number);

    return 0;
}
