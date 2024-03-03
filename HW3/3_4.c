

#include <stdio.h>

int main() {
    int a, b, c;
    printf("Input number: ");
    scanf("%d %d %d", &a, &b, &c);

    float sum = (float)a + (float)b + (float)c;
    float average = sum / 3.0;

    printf("average = : %f\n", average);

    return 0;
}
