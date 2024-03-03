
#include <stdio.h>

int main() {
    int a, b, c;
    printf("Input number: ");
    scanf("%d %d %d", &a, &b, &c);

    int sum = a + b + c;
    int product = a * b * c;

    printf("%d+%d+%d=%d\n",a,b,c, sum);
    printf("%d*%d*%d=%d\n",a,b,c, product);

    return 0;
}
