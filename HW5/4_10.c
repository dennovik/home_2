


#include <stdio.h>

int main() {
    int month;
    printf("Enter the month number from 1 to 12: ");
    scanf("%d", &month);

    switch (month) {
        case 1:
        case 2:
        case 12:
            printf("winter\n");
            break;
        case 3:
        case 4:
        case 5:
            printf("spring\n");
            break;
        case 6:
        case 7:
        case 8:
            printf("summer\n");
            break;
        case 9:
        case 10:
        case 11:
            printf("autumn\n");
            break;
    
    }

    return 0;
}

