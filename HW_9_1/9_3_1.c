

//F9
//Поменять местами

//9.3.c

#include <stdio.h>

void swap_negmax_last(int size, int a[]) {
    int neg_max = -1; // переменная  максимального отрицательного элемента
    int neg_max_index = -1; //  переменная для хранения индекса 

    // Находим максимальный из отрицательных элементов и его индекс
    for (int i = 0; i < size; i++) {
        if (a[i] < 0 && (neg_max == -1 || a[i] > neg_max)) {
            neg_max = a[i];
            neg_max_index = i;
        }
    }

    // Если был найден отрицательный элемент,
    // меняем его с последним элементом массива
    if (neg_max_index != -1) {
        int temp = a[neg_max_index];
        a[neg_max_index] = a[size - 1];
        a[size - 1] = temp;
    }
}

int main() {
    int size = 10;
  

    int a[size];
    printf("Enter array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    swap_negmax_last(size, a);

    printf("\nArray after replacement:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
