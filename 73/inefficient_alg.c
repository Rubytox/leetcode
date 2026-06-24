typedef struct {
    int i;
    int j;
} coord_t;

typedef struct _list {
    coord_t coord;
    struct _list *next;
} list_t;

void put(list_t **list, coord_t coord) {
    list_t *node = calloc(1, sizeof(list_t));
    node->coord = coord;
    node->next = *list;
    *list = node;
}

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    // Loop over the matrix, find all zeroes
    // Add the coord of all 0 to a data structure
    list_t *list = NULL;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (matrix[i][j] == 0) {
                coord_t coord = {i, j};
                put(&list, coord);
            }
        }
    }

    while (list != NULL) {
        coord_t coord = list->coord;
        int i = coord.i;
        int j = coord.j;

        for (int x = 0; x < matrixSize; x++)
            matrix[x][j] = 0;
        for (int y = 0; y < *matrixColSize; y++)
            matrix[i][y] = 0;

        list = list->next;
    }
}