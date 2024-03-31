
#include <stdio.h>
//Одно целое число - сумма положительных элементов массива

int main() {
	
    const int ARRAY_SIZE = 10; // Размер массива
    int numbers[ARRAY_SIZE]; // Объявление массива
    int sum = 0; 

    // Ввод массива
    printf("Enter 10 elements:\n");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
       
        scanf("%d", &numbers[i]);
    }

    // Подсчет суммы положительных элементов
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (numbers[i] > 0) {
            sum += numbers[i];
        }
    }

    // Вывод суммы элементов положительных
    printf("The sum of positive elements: %d\n", sum);

    return 0;
}
