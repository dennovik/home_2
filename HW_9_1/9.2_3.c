/*
 * 9.1_3.c
 * 
* F18
*Массив максимумов

 * 
 * 
 */


#include <stdio.h>

int findMaxInRow(int row[10]) {
    int max = row[0];

   
    for (int i = 1; i < 10; i++) {
        if (row[i] > max) {
            max = row[i];
        }
    }

    return max;
}

int main() {
    int matrix[10][10];

   
    printf("Enter 10 lines each consisting of 10 integers separated by spaces:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sumOfMaxElements = 0;

    
    for (int i = 0; i < 10; i++) {
        int maxInRow = findMaxInRow(matrix[i]);
        sumOfMaxElements += maxInRow;
    }


    printf("you will receive the data %d\n", sumOfMaxElements);

    return 0;
}
