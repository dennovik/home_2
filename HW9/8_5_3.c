
//E12
//По убыванию и по возрастанию
//Считать массив из 10 элементов и 
//отсортировать первую половину по возрастанию, а вторую – по убыванию. 


#include <stdio.h>

int main() {
    const int ARRAY_SIZE = 10; 
    int numbers[ARRAY_SIZE]; 
     printf("Enter 10 elements:\n");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
      scanf("%d", &numbers[i]);
    }

    // Сортировка  массива по возрастанию
    for (int i = 0; i < ARRAY_SIZE / 2; ++i) {
        for (int j = i + 1; j < ARRAY_SIZE / 2; ++j) {
            if (numbers[i] > numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    // Сортировка массива по убыванию
    for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; ++i) {
        for (int j = i + 1; j < ARRAY_SIZE; ++j) {
            if (numbers[i] < numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

     printf("Sorted array:\n");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%d ", numbers[i]);
    }

    return 0;
}

