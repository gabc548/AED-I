// https://leetcode.com/problems/search-a-2d-matrix/description/
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    for(int i = 0, j = 1; j < matrixSize; i++, j++){
        if(matrix[i][0] <= target && matrix[j][0] > target){

            for(int n = 0; n < *matrixColSize; n++){
                if(matrix[i][n] == target){
                    return true;
                }
            }

        }
        if(j == matrixSize - 1){

            for(int n = 0; n < *matrixColSize; n++){
                if(matrix[j][n] == target){
                    return true;
                }
            }

        }
    }

    for(int i = 0; i < matrixSize; i++){ //In case the matrix is only one line
        for(int j = 0; j < *matrixColSize; j++){
            if(matrix[i][j] == target){
                return true;
            }
        }
    }

    return false;
}
