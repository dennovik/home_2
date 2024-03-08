
#include <stdio.h>

int main() {
    int a, b,  max;;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    max =  a > b ?  a : b;
     
    printf("%d", max); 


    return 0;
}
