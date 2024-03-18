
#include <stdio.h>


int count = 0;

void count_a() {
    char c;
    scanf("%c", &c);

    if (c == '.') {
        return;
    }

    if (c == 'a' || c == 'A') {
        count++;
    }

    count_a(); // Recursively call to process the next character
}

int main() {
    printf("Enter English: \n");
    count_a();

    printf("Number of 'a' : %d\n", count);

    return 0;
}
