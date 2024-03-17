

#include <stdio.h>

int nod(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return nod(b, a % b);
    }
}

int main() {
    int a, b;
    printf("Enter two positive integers: ");
    scanf("%d %d", &a, &b);
    printf("Greatest common divisor: %d\n", nod(a, b));
    return 0;
}
