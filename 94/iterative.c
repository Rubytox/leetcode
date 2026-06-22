/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct _stack {
    struct TreeNode *node;
    struct _stack *next;
} Stack;

void put(Stack **stack, struct TreeNode *node) {
    Stack *head = calloc(1, sizeof(Stack));
    head->node = node;
    head->next = *stack;
    *stack = head;
}

struct TreeNode *pop(Stack **stack) {
    if (*stack == NULL)
        return NULL;

    struct TreeNode *node = (*stack)->node;
    *stack = (*stack)->next;
    return node;
}

int numberOfNodes(struct TreeNode *root) {
    if (root == NULL)
        return 0;
    
    return 1 + numberOfNodes(root->left) + numberOfNodes(root->right);
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int n = numberOfNodes(root);
    printf("#Nodes: %d\n", n);

    int *output = calloc(n, sizeof(int));

    *returnSize = n;
    if (n == 0)
        return output;

    // Itérativement, on va le plus à gauche possible en ajoutant chaque noeud dans une stack jusqu'à ce qu'on soit sur une feuille
    // On ajoute la feuille au tableau de sortie
    // On récupère la dernière node pilée et on recommence jusqu'à ce que la stack soit vide
    Stack *stack = NULL;

    int i = 0;
    struct TreeNode *current = root;
    while (i != n) {
        while (current != NULL) {
            put(&stack, current);
            current = current->left;
        }
        struct TreeNode *node = pop(&stack);
        output[i++] = node->val;
        // Now continue to the right
        current = node->right;
    }

    return output;
}