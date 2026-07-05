/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdio.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes);

int main(){
    int n, returnSize, *returnColumnSizes;
    n = 7;

    int **matrix = generateMatrix(n, &returnSize, &returnColumnSizes);

    for(int i = 0; i < returnSize; i++){
        for(int j = 0; j < returnColumnSizes[i]; j++){
            printf("[%3d] ", matrix[i][j]);
        }
        printf("\n");
    }

    free(returnColumnSizes);
    for(int i = n - 1; i >= 0; i--){
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}


int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {

    int **matrix;
    matrix = ( int** )malloc( n * sizeof( int* ) );
    for ( int i = 0; i < n; i++ ) {
        matrix[i] = ( int* )calloc( n, sizeof( int* ) );
    }

    *returnSize = n;

    *returnColumnSizes = ( int* )malloc( n * sizeof( int ) );
    for(int i = 0; i < n; i++){
        ( *returnColumnSizes )[i] = n;
    }

    int x = 0, y = 0, up = 0, down = 0, left = 0, right = 1;

    for ( int i = 0; i < n * n; i++ ) {

        matrix[x][y] = i + 1;

        if ( right == 1 ) {
            if ( y + 1 == n ) {
                right = 0;
                down = 1;
            } else if ( matrix[x][y + 1] != 0 ) {
                right = 0;
                down = 1;
            } else{
                y++;
            }
        }

        if ( down == 1 ) {
            if ( x + 1 == n ) {
                down = 0;
                left = 1;
            } else if ( matrix[x + 1][y] != 0 ) {
                down = 0;
                left = 1;
            } else{
                x++;
            }
        }

        if ( left == 1 ) {
            if ( y - 1 < 0 ) {
                left = 0;
                up = 1;
            } else if ( matrix[x][y - 1] != 0 ) {
                left = 0;
                up = 1;
            } else{
                y--;
            }
        }

        if ( up == 1 ) {
            if ( x - 1 < 0 ) {
                up = 0;
                right = 1;
                y++;
            } else if ( matrix[x - 1][y] != 0 ) {
                up = 0;
                right = 1;
                y++;
            } else{
                x--;
            }
        }

    }

    return matrix;
}
