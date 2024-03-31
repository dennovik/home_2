#include <stdio.h>

int main() {
    const int ARRAY_SIZE = 5; // Размер массива
    int numbers[ARRAY_SIZE]; // Объявление массива
    double sum = 0.0; 
    double average; 

  
    
    for (int i = 0; i < ARRAY_SIZE; ++i) {
   
        scanf("%d", &numbers[i]);
    }

    // Вычисление суммы элементов 
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        sum += numbers[i];
    }

    //  среднего арифметического
    average = sum / ARRAY_SIZE;


    printf("Average: %.3f\n", average);

    return 0;
}
