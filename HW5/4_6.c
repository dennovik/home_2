

#include <stdio.h>

int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

   printf((a > b) ? "Above\n" : ((a < b) ? "Less\n" : "Equal\n")); 
    return 0;
}
