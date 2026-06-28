int parent(int index) {
    return (index - 1) / 2;
}

int left_child(int index) {
    return (2 * index) + 1;
}

int right_child(int index) {
    return (2 * index) + 2;
}


int findKthLargest(int* nums, int numsSize, int k) {
    int heap[numsSize];
    memset(heap, 0, numsSize * sizeof(int));

    int nb_inserted_elements = 0;

    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];

        // Insert into heap at last position
        int pos = nb_inserted_elements;
        heap[pos] = val;
        while (pos > 0 && heap[parent(pos)] < val) {
            int tmp = heap[parent(pos)];
            heap[parent(pos)] = val;
            heap[pos] = tmp;
            pos = parent(pos);
        }

        nb_inserted_elements++;
    }

    // Remove the k largest elements of the heap
    int size = numsSize;
    int root;
    for (int i = 0; i < k; i++) { 
        root = heap[0];
        /// Replace root with last valid element of the heap
        heap[0] = heap[size - 1];
        size--;
        /// Percolate down
        int pos = 0;
        while (true) {
            int left_idx = left_child(pos);
            int right_idx = right_child(pos);
            int largest_idx = pos;

            if (left_idx < size && heap[left_idx] > heap[largest_idx])
                largest_idx = left_idx;
            if (right_idx < size && heap[right_idx] > heap[largest_idx])
                largest_idx = right_idx;

            if (largest_idx == pos)
                break;
            
            int tmp = heap[largest_idx];
            heap[largest_idx] = heap[pos];
            heap[pos] = tmp;
            pos = largest_idx;
        }
    }

    return root;
}
