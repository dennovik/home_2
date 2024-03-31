
#include <stdio.h>
//Вторая с конца ноль. E13 ДЗ 5
//Считать массив из 10 элементов и отобрать в другой массив все числа,
// у которых вторая с конца цифра (число десятков) – ноль. 

int main() {
    int arr[10];
    int selected[10];
    int count = 0;

    // читаем массив
    printf("Enter 10 elements:\n");
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &arr[i]);
    }

    // находим второй нулевой
    for (int i = 0; i < 10; ++i) {
        int tensPlace = (arr[i] / 10) % 10;
        if (tensPlace == 0) {
            selected[count] = arr[i];
            count++;
        }
    }

    //печатаем
    printf("Numbers  zero in the tens place:\n");
    for (int i = 0; i < count; ++i) {
        printf("%d\t", selected[i]);
    }

    return 0;
}
