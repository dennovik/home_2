/*
 * 8.4.c
*E17
*Только один раз
*Дан массив из 10 элементов.
*В массиве найти элементы, которые в нем
* встречаются только один раз, и вывести их на экран. 
 
 */


#include <stdio.h>

int main() {
    int arr[10], freq[10];
    
   
    printf("Enter 10 elements into the array:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        freq[i] = -1; // Инициализация элементов массива
        // freq значением -1 означает, что количество
        // вхождений каждого элемента ещё не определено
        // и будет установлено в процессе работы программы.
    }

   
    for (int i = 0; i < 10; i++) {
        int count = 1;
        for (int j = i + 1; j < 10; j++) {
            if (arr[i] == arr[j]) {
                count++;
                freq[j] = 0; // после завершения внешнего цикла,
                // массив freq будет содержать информацию о 
                //количестве вхождений каждого элемента массива arr.
            }
        }
        if (freq[i] != 0) {
            freq[i] = count;
        }
    }

   
    printf("Elementsonly once in the array ar:\n");
    for (int i = 0; i < 10; i++) {
        if (freq[i] == 1) {
            printf("%d\t", arr[i]);
        }
    }

    return 0;
}
