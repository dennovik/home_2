
#include <stdio.h>

int main() {
    int a, b, c;
    printf("enter the sides of the triangle a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);

    printf((a < b + c && b < a + c && c < a + b) ? "YES\n" : "NO\n");

    return 0;
}
