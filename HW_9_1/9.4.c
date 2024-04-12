
//F14
//Сумма в интервале

#include <stdio.h>

int sum_between_ab(int from, int to, int size, int a[]) {
    int sum = 0;

    //корректность введенных значений from и to
    if (from < 0 || from >= size || to < 0 || to >= size || from > to) {
        printf("Incorrect values from и to\n");
        return 0;
    }

    // сумма в интервале [from, to]
    for (int i = from; i <= to; i++) {
        sum += a[i];
    }

    return sum;
}

int main() {
    int size = 12;
 
    int a[size];
    printf("Enter array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    int from, to;
    printf("Enter the start and end of the interval [from, to]: ");
    scanf("%d %d", &from, &to);

    int result = sum_between_ab(from, to, size, a);
    printf("Sum of elements in interval [%d, %d]: %d\n", from, to, result);

    return 0;
}
