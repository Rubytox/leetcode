void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    int cols = *matrixColSize;

    bool rows_to_zero[rows];
    bool cols_to_zero[cols];
    memset(rows_to_zero, 0, rows);
    memset(cols_to_zero, 0, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                rows_to_zero[i] = true;
                cols_to_zero[j] = true;
            }
        }
    }

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (rows_to_zero[i] || cols_to_zero[j])
                matrix[i][j] = 0;
}