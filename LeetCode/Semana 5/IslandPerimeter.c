// https://leetcode.com/problems/island-perimeter/description/

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int perimeter = 0;
    for ( int i = 0; i < gridSize; i++ ) {
        for ( int j = 0; j < *gridColSize; j++ ) {
            if ( grid[i][j] == 1 ) {

                if ( i + 1 == gridSize ) {
                    perimeter++;
                }
                else if ( grid[i + 1][j] == 0 ) {
                    perimeter++;
                }

                if ( i - 1 < 0 ) {
                    perimeter++;
                }
                else if ( grid[i - 1][j] == 0 ) {
                    perimeter++;
                }

                if ( j + 1 == *gridColSize ) {
                    perimeter++;
                }
                else if ( grid[i][j + 1] == 0 ) {
                    perimeter++;
                }

                if ( j - 1 < 0 ) {
                    perimeter++;
                }
                else if ( grid[i][j - 1] == 0 ) {
                    perimeter++;
                }

            }
        }
    }

    return perimeter;

}