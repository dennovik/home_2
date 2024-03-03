


#include <stdio.h>

int main() {
    int a, b;
    printf("Input number:  ");
    scanf("%d %d", &a, &b);

    int diff = a - b;

    printf("%d-%d=%d\n",a,b, diff);

    return 0;
}
