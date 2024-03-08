
#include <stdio.h>

int main() {
    int a, b, c;
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);
  
    printf((a <= b && b <= c) ? "YES\n" : "NO\n");
    return 0;
}

 
