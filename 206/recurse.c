/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *aux(struct ListNode *head, struct ListNode **last) {
    if (head == NULL || head->next == NULL) {
        *last = head;
        return head;
    }

    struct ListNode *reversed = aux(head->next, last);

    (*last)->next = head;
    head->next = NULL;
    *last = head;
   
    return reversed;
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *last = NULL;
    return aux(head, &last);
}