/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct Stack {
    struct ListNode *node;
    struct Stack *next;
};

void put(struct Stack **stack, struct ListNode *node) {
    struct Stack *head = calloc(1, sizeof(struct Stack));
    head->node = node;
    head->next = *stack;

    *stack = head;
}

struct ListNode *pop(struct Stack **stack) {
    struct Stack *head = *stack;
    *stack = (*stack)->next;
    return head->node;
}


struct ListNode* reverseList(struct ListNode* head) {
    struct Stack *stack = NULL;
    while (head != NULL) {
        put(&stack, head);
        head = head->next;
    }

    if (stack == NULL)
        return NULL;

    head = pop(&stack);
    struct ListNode *last = head;
    while (stack != NULL) {
        struct ListNode *parent = pop(&stack);
        head->next = parent;

        head = parent;
    }
    head->next = NULL;
    return last;
}