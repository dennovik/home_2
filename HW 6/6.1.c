#include <stdio.h>

int middle(int a, int b) {
    return (a + b) / 2;
}

int main() {
	int a, b;
    printf("Enter two non-negative integers: ");
    scanf("%d %d", &a, &b);
    printf("Average: %d\n", middle(a, b));
    return 0;
}
