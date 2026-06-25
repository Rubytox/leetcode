/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    if (numRows == 0) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    int **triangle = calloc(numRows, sizeof(int *));
    *returnColumnSizes = calloc(numRows, sizeof(int));

    for (int row = 0; row < numRows; row++) {
        (*returnColumnSizes)[row] = row + 1;
        triangle[row] = calloc(row + 1, sizeof(int));
        triangle[row][0] = 1;
        triangle[row][row] = 1;
        for (int i = 1; i < row; i++) {
            triangle[row][i] = triangle[row - 1][i - 1] + triangle[row - 1][i];
        }
    }

    return triangle;
}