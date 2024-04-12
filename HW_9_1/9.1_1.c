/*
 * 9.1.c
 * 
 *F17 
*След матрицы 

 * 
 */


#include <stdio.h>

int findTrace(int mat[5][5]) {
    int sum = 0;

  
    for (int i = 0; i < 5; i++) {
        sum += mat[i][i];
    }

    return sum;
}

int main() {
    int mat[5][5];

 
    printf("Enter 25 integers separated by spaces:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // Call the function to find the trace of the matrix
    int trace = findTrace(mat);

    // Print the trace of the matrix
    printf("%d\n", trace);

    return 0;
}
