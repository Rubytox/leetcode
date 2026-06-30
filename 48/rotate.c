void rotate(int** matrix, int matrixSize, int* matrixColSize) {    
    int n = matrixSize;
    for (int i = 0; i < n/2; i++) {
        for (int j = i; j < n - 1 - i; j++) {
            int curr_i = i;
            int curr_j = j;
            int next_i = curr_j;
            int next_j = n - 1 - curr_i;
            
            int curr_val = matrix[curr_i][curr_j];

            do {
                int next_val = matrix[next_i][next_j];
                matrix[next_i][next_j] = curr_val;
                
                curr_i = next_i;
                curr_j = next_j;

                next_i = curr_j;
                next_j = n - 1 - curr_i;

                curr_val = next_val;
            } while (curr_i != i || curr_j != j);
        }
    }
}
