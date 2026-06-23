#include <stddef.h>

typedef struct _node {
    int val;
    int count;
    struct _node *next;
} node_t;

void put(node_t **head, int val) {
    node_t *node = calloc(1, sizeof(node_t));
    node->val = val;
    node->count = 0;
    node->next = *head;
    *head = node;
}

node_t *is_in_list(node_t *head, int val) {
    while (head != NULL && head->val != val)
        head = head->next;

    return head;
}

int majorityElement(int* nums, int numsSize) {
    int condition = numsSize / 2 + 1;

    node_t *head = NULL;

    for (int i = 0; i < numsSize; i++) {
        node_t *node = is_in_list(head, nums[i]);
        if (!node) {
            put(&head, nums[i]);
            node = head;
        }
        
        node->count++;
        if (node->count >= condition)
            return node->val;
    }
    return nums[0]; // Actually we can't be here
}