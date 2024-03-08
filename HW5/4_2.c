

#include <stdio.h>

int main() {
    int a, b, c;
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    
    int max = a;
    max =  a > b ?  a : b;
    max = max> c ? max: c;

    printf("Highest number: %d\n", max);

       return 0;
}
