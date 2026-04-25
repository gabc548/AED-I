// Exercício 59 LeetCode

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int **matrix = (int**)malloc(n * sizeof(int*));
    int x = 0, y = 0, m = n;
    for(int i = 0; i < n; i++){
        matrix[i] = (int*)calloc(n, sizeof(int));
    }

    for(int i = 0; i < n * 3 - 2; i++){
        matrix[x][y] = i + 1;
        printf("%d %d\n", x, y);
        if(x + 1 == m){
            y--;
        }
        else if(y + 1 == n){
            x++;
        }
        else if(x == 0){
            y++;
        }
    }
    
    return matrix;
}
